/*
 * IdentifyFruit.c
 *
 *  Created on: 2021��11��22��
 *      Author: h13
 */
#include "IdentifyFruit.h"
#include "Drivers.h"

void IdentifyFruit(void)
{
	SwitchImageProcessingModuleWorkingMode(FruitDetection);
	SleepMillisecond(2500);



	while(1);
}
