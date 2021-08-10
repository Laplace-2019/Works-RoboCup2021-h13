/*
 * ImageProcessingModule.c
 *
 *  Created on: 2021��8��10��
 *      Author: h13
 */
#include "ImageProcessingModule.h"
#include "ports.h"
#include "RobotConfigs.h"
#include "SimpleProtocolPraise.h"
#include "FastMatch.h"

static ImageProcessingModuleWorkingMode_t currentMode = 0;
static Coordinates_t appleCoordinates = { 0 };

static void updateTimeStamp(void)
{
	appleCoordinates.TimeStamp = GetCurrentTimeMillisecond();
}

static void binaryProtocolPraise(char *data, uint8_t length)
{
	MatchKeyInt8_t(data, length, "WM:", 3, currentMode, return);

	MatchKeyFloat(data, length, "AppCenX:", 8, appleCoordinates.X, updateTimeStamp(); return);
	MatchKeyFloat(data, length, "AppCenY:", 8, appleCoordinates.Y, updateTimeStamp(); return);


}

/**
 * @brief: Image processing module serial handler.
 * @param: data.
 */
__attribute__((always_inline)) inline void ImageProcessingModuleHandler(uint8_t data)
{
	static char buffer[ImageProcessingSerialBufferLength] = { '\0' };
	static uint8_t length = 0;
	static char* bufferPtr = buffer;
	GeneratePraiseWithSuffixMethod(data, "\r\n", 2, bufferPtr, ImageProcessingSerialBufferLength, length, binaryProtocolPraise(bufferPtr, length - 2));
}

/**
 * @brief: Switch the working mode of image processing module.
 * @param: Working mode.
 */
__attribute__((always_inline)) inline void SwitchImageProcessingModuleWorkingMode(ImageProcessingModuleWorkingMode_t Mode)
{

}

/**
 * @brief:  Get the current mode of image processing module.
 * @return: ImageProcessingModuleWorkingMode_t.
 */
__attribute__((always_inline)) inline ImageProcessingModuleWorkingMode_t GetImageProcessingModuleWorkingMode(void)
{
	return currentMode;
}

/**
 * @brief: Get the coordinates of apple.
 * @param: Pointer of coordinates.
 */
__attribute__((always_inline)) inline void GetAppleCoordinates(Coordinates_t *Coordinates)
{
	*Coordinates = appleCoordinates;
}
