/*
 * nineholes.c
 *
 *  Created on: 12 มิ.ย. 2566
 *      Author: msi1
 */

#include "arm_math.h"
#include "nineholes.h"


#include <stdio.h>
#include <math.h>

extern float32_t Degrees;
extern float32_t rotationAngle;
extern float32_t rotated[9][2];
extern int reference[2];
extern int opposite[2];
extern int GoalReadyFlag;

void SetTwoPointsForCalibrate()
{
	int x0 = 0, y0 = 0, x1 = 45, y1 = 79;
    reference[0] = x0;
    reference[1] = y0;
    opposite[0] = x1;
    opposite[1] = y1;

    if(y1 > y0)
    {
        reference[0] = x0;
        reference[1] = y0;
        opposite[0] = x1;
        opposite[1] = y1;
    }
    else if(y0 > y1)
    {
        reference[0] = x1;
        reference[1] = y1;
        opposite[0] = x0;
        opposite[1] = y0;
    }
    else if(x1 > x0 && y0 == y1)
    {
        reference[0] = x0;
        reference[1] = y0;
        opposite[0] = x1;
        opposite[1] = y1;
    }
    else if(x0 > x1 && y0 == y1)
    {
        reference[0] = x1;
        reference[1] = y1;
        opposite[0] = x0;
        opposite[1] = y0;
    }

    rotationAngle = atan2(50, 60) - atan2((opposite[1] - reference[1]), (opposite[0] - reference[0]));
//    rotationAngle = atan2(opposite[1] - reference[1], opposite[0] - reference[0]) - atan2(50, 60);
    Degrees = rotationAngle * (180.0 / M_PI);
}

void HolePositionsCartesian(float32_t* reference, float32_t rotationAngle)
{
	if (GoalReadyFlag == 0)
	{
		static float32_t nineholes[9][2] = {
				{10, 10},
				{30, 10},
				{50, 10},
				{10, 25},
				{30, 25},
				{50, 25},
				{10, 40},
				{30, 40},
				{50, 40}
		};

		float32_t rotationMatrix[2][2] = {{arm_cos_f32(rotationAngle), arm_sin_f32(rotationAngle)},
										  {-arm_sin_f32(rotationAngle), arm_cos_f32(rotationAngle)}};

		static uint8_t i = 0;
		rotated[i][0] = ((rotationMatrix[0][0] * nineholes[i][0]) + (rotationMatrix[0][1] * nineholes[i][1])) + reference[0];
		rotated[i][1] = ((rotationMatrix[1][0] * nineholes[i][0]) + (rotationMatrix[1][1] * nineholes[i][1])) + reference[1];
		i++;
		if (i == 9)
		{
			GoalReadyFlag = 1;
			i = 0;
		}
	}
}

