/*
 * joyStick.c
 *
 *  Created on: Jun 6, 2023
 *      Author: msi1
 */

#include "joyStick.h"

uint64_t _micros = 0;
extern int64_t currentTime;
extern ModbusHandleTypedef hmodbus;
extern u16u8_t registerFrame[200];
extern uint32_t adcRawData[20];
extern uint32_t IN0[10]; //Y
extern uint32_t IN1[10]; //X
extern int JoyStickSwitch;
extern int X_axis, Y_axis;
extern int joystickXaxis, joystickYaxis;
extern float PulseWidthModulation;
extern float encoderX, encoderY;
extern void HAL_TIM_PeriodElasedCallback(TIM_HandleTypeDef *htim);

extern TIM_HandleTypeDef htim5;

void GetJoystickXYaxisValue()
{
	int before;
	unsigned long StartTime = 0;
	unsigned long currentTime = 0;

	JoyStickSwitch = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);

	if (JoyStickSwitch == 0)
	{
		if (before == 1 && JoyStickSwitch == 0)
		{
			// Keep encoder position xy
			registerFrame[32].U16 = 0; //encoderx
			registerFrame[33].U16 = 0; //encodery
		}
		else if (before == 0 && JoyStickSwitch == 0)
		{
			if (before == 1)
			{
				StartTime = micros();
				JoyStickSwitch = 0;
			}
			else
			{
				currentTime = micros();
				if ((currentTime - StartTime) >= 2000000)
				{
					//set home and encoder x y = 0
					registerFrame[1].U16 = 2; //encoderx //set home x-axis
					registerFrame[33].U16 = 0; //encodery
				}
			}
		}before = JoyStickSwitch;
	}

	for(int i = 0; i < 20; i++)
	{
		if(i % 2 == 0)
		{
			IN1[i/2] = adcRawData[i];
			Y_axis += IN1[i/2];
			if(i == 18){joystickYaxis = Y_axis/10;}
		}
		else if(i % 2 == 1)
		{
			IN0[(i-1)/2] = adcRawData[i];
			X_axis += IN0[(i-1)/2];
			if(i == 19){joystickXaxis = X_axis/10;}
		}
	} X_axis = 0; Y_axis = 0;
}

void JoyStickControlCartesian(TIM_HandleTypeDef htim1)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);

	//X-axis
	if(joystickXaxis > 2500) //Left
	{registerFrame[64].U16 = 4;}

	else if(joystickXaxis < 1900) //Right
	{registerFrame[64].U16 = 8;}

	else{registerFrame[64].U16 = 0;}

	//Y-axis
	if(joystickYaxis < 1900) //Front
	{PulseWidthModulation = 1000;}

	else if(joystickYaxis > 2500) //Back
	{PulseWidthModulation = -1000;}

	else{PulseWidthModulation = 0;}

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, PulseWidthModulation);
}

void HAL_TIM_PeriodElasedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim5)
	{
		_micros += UINT32_MAX;
	}
}

uint64_t micros()
{
	return __HAL_TIM_GET_COUNTER(&htim5) + _micros;
}
