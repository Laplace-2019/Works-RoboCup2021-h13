/*
 * Drivers.c
 *
 *  Created on: 2021��9��2��
 *      Author: h13
 */
#include "Drivers.h"

/**
 * @brief: Init all drivers.
 */
void DriversInit(void)
{
	MotorInit();
	ServoInit();
	LCD_Init();
	EncoderInit();
	ResetYaw();
	LuatModuleInit();
}

//TODO: DeInit.
