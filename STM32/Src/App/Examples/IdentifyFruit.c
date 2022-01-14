/*
 * IdentifyFruit.c
 *
 *  Created on: 2021��11��22��
 *      Author: h13
 */
#include "IdentifyFruit.h"
#include "Drivers.h"
#include "Examples.h"

void IdentifyFruit(void)
{
	SwitchImageProcessingModuleWorkingMode(FruitIdentify);
	SleepMillisecond(2500);



	while(1);
	FruitIdentifyResult_t result = GetFruitDetectionResult();

	SendResultViaMessage(&result);
}
