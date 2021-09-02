/*
 * ArmControl.c
 *
 *  Created on: 2021��8��25��
 *      Author: h13
 */
#include "ArmControl.h"
#include "RobotConfigs.h"
#include "Servo.h"

/**
 * @brief: Closure the claw.
 * @TODO:  Use current to judge whether it is firmly grasped.
 */
void ClosureClaw(void)
{
	SetArmNodeAngle(ClawGrab, MaximumRotationAngleOfGraspingApple);
}

/**
 * @brief: Release the claw.
 */
void ReleaseClaw(void)
{
	SetArmNodeAngle(ClawGrab, 0);
}
