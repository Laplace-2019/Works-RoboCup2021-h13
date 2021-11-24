/*
 * PrepareArmPosition.c
 *
 *  Created on: 2021��11��22��
 *      Author: h13
 */
#include "PrepareArmPosition.h"
#include "RobotConfigs.h"

void PrepareArmPosition(uint16_t RotationAngle)
{
	SmoothMoveTo(MoveAxialLength, AL_AxisZeroPoint, 5);
	SmoothMoveTo(MoveRotationAngle, RotationAngle, 15);
	SmoothMoveTo(MoveZ_AxisHeight, ApproachHeight, 5);
}
