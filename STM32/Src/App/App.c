/*
 * App.c
 *
 *  Created on: 2021��5��29��
 *      Author: h13
 */
#include "App.h"
#include "RobotConfigs.h"
#include "Examples.h"

#include <stdio.h>
//Drivers
#include "ports.h"

#include "Drivers.h"

//App
//Motion Control
#include "MotionControl.h"
//Arm Control
#include "ArmControl.h"
//Voice player
#include "VoicePlayer.h"

int App(void)
{
	//Init all modules and peripherals.
	//Current posture: ��
	AllInit();

	ConnectToBluetoothDevice();

	ReleaseClaw();

	//Go to the refrigerator.
	StraightUntill(325 + 150);

	TurnTo(Left);

	StraightUntill(1750 - 150);

	TurnTo(Right);

	StraightUntill(275);

	TurnTo(Right);

	StraightUntill(3820);

	//Arrival refrigerator.
	//Current posture: ��
	TurnOnTheBluetoothLight();

	//Identify fruit.
	ReleaseClaw();
	PrepareArmPosition(180);
	IdentifyFruit();
	PrepareArmPosition(180);

	CatchApple(CatchMaximumApple);
	PrepareArmPosition(0);

	//Go to the pool.
	StraightUntill(150);

	//Arrival pool.
	//Current posture: ��
	WashApple();

	//Go to the desk.
	StraightUntill(1200);

	TurnTo(Right);

	StraightUntill(1500);

	TurnTo(Left);

	StraightUntill(DisktopDistanceBeforeTurn);

	TurnTo(Left);

	StraightUntill(2170);

	//Arrival Desktop.
	//Current posture: ��
	//Place apple.
	PrepareArmPosition(90);
	uint16_t angle = PlaceApple();

	//Catch another apple.
	PrepareArmPosition(90);
	ReleaseClaw();
	if(angle > 90)
	{
		PrepareArmPosition(60);
		CatchApple(CatchLeftApple);
	} else {
		PrepareArmPosition(120);
		CatchApple(CatchRightApple);
	}

	PrepareArmPosition(0);

	//Go to the trash can.
	//Current posture: ��
	StraightUntill(325 + 150);

	TurnTo(Left);

	StraightUntill(1450);

	TurnTo(Right);

	StraightUntill(3515);

	//Arrive trash can.
	//Current posture: ��
	ThrowApple();
	CatchTrashCan();

	StraightUntill(4400);

	EmptyTrash();

	TurnTo(Left);

	StraightUntill(500);

	PlaceTrashCan();

	TurnTo(Right);

	StraightUntill(2600);

	while(1);
}
