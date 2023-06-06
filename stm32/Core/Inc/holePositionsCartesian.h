/*
 * holePositionsCartesian.h
 *
 *  Created on: Jun 6, 2023
 *      Author: msi1
 */

#ifndef INC_HOLEPOSITIONSCARTESIAN_H_
#define INC_HOLEPOSITIONSCARTESIAN_H_
#include "arm_math.h"

void SetTwoPointsForCalibrate();
void HolePositionsCartesian(float32_t* bottomleft, float32_t rotationAngleRadian);

#endif /* INC_HOLEPOSITIONSCARTESIAN_H_ */
