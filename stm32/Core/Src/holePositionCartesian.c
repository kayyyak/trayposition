/*
 * holePositionCartesian.c
 *
 *  Created on: Jun 6, 2023
 *      Author: msi1
 */
//#include "holePositionsCartesian.h"
//#include "stm32f4xx_hal.h"
//#include "arm_math.h"
//
//extern int reference[2];
//extern int opposite[2];
//extern float32_t rotationAngleRadian;
//extern float32_t Degrees;
//extern float32_t *matrixtest;
//extern float32_t holePositionsCartesian[18];
//extern float32_t holePositionsCartesianrotation[18];
//extern float32_t holePositionsCartesianadded[18];
//
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void SetTwoPointsForCalibrate()
//{
//	int x0 = 178, y0 = 100, x1 = 100, y1 = 100; //laser will give two points of tray
//
//	if(y0 > y1){swap(&x0, &x1); swap(&y0, &y1);}
//	else if(y0 == y1)
//	{
//		if (x0 > x1){swap(&x0, &x1); swap(&y0, &y1);}
//	}
//
//	reference[0] = x0; reference[1] = y0;
//	opposite[0] = x1; opposite[1] = y1;
//
//	rotationAngleRadian = atan2(y1 - y0, x1 - x0) - atan2(50, 60);
//	Degrees = rotationAngleRadian * (180 / M_PI);
//}
//void HolePositionsCartesian(float32_t* bottomleft, float32_t rotationAngleRadian)
//{
//  static float32_t holePositionsRelativetoBottomLeft[18] =
//  {
//	  10, 10,
//	  30, 10,
//	  50, 10,
//	  10, 25,
//	  30, 25,
//	  50, 25,
//	  10, 40,
//	  30, 40,
//	  50, 40
//  };
//
//  float32_t rotationMatrix[4] =
//  {
//	arm_cos_f32(rotationAngleRadian),  //0
//	arm_sin_f32(rotationAngleRadian),  //1
//	-arm_sin_f32(rotationAngleRadian), //2
//	arm_cos_f32(rotationAngleRadian)   //3
//  };
//
//  for (int i = 0; i < 9; i++)
//  {
//	//rotation
//	holePositionsCartesianrotation[i*2] = (holePositionsRelativetoBottomLeft[i*2] * rotationMatrix[0]) + (holePositionsRelativetoBottomLeft[i*2+1] * rotationMatrix[2]);
//	holePositionsCartesianrotation[i*2+1] = (holePositionsRelativetoBottomLeft[i*2] * rotationMatrix[1]) + (holePositionsRelativetoBottomLeft[i*2+1] * rotationMatrix[3]);
//
//	//translation
//	holePositionsCartesian[i*2] = holePositionsCartesianrotation[i*2] + bottomleft[0];
//	holePositionsCartesian[i*2+1] = holePositionsCartesianrotation[i*2+1] + bottomleft[1];
//  }
//}
