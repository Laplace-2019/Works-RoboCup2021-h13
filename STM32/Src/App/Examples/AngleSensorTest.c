/*
 * AngleSensorTest.c
 *
 *  Created on: 2021��8��12��
 *      Author: h13
 */
#include "AngleSensorTest.h"
#include "Drivers.h"
#include "MotionControl.h"
#include "AppLog.h"

void AngleSensorTest(void)
{
	StraightUntill(1000);

	TurnTo(Left);

	StraightUntill(1000);

	TurnTo(Left);

	StraightUntill(1000);

	TurnTo(Left);

	StraightUntill(1000);

	while(1)
	{
		LogJustFloat(GetYawValue());
	}
}
