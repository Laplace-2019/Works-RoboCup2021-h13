/*
 * Timer.c
 *
 *  Created on: 2021��6��8��
 *      Author: h13
 */
#include "Timer.h"

#include "MotionControl.h"
#include "ArmControl.h"

/**
 * @brief: Timer Interrupt Handler.
 * @note:
 * 		Responsible for PID calculation.
 * 		**Call frequency: 100Hz.**
 */
__attribute__((always_inline)) inline void TimerHandler(void)
{
	DirectionPIDCalculateHandler();
	ForwardPIDCalculateHandler();
}

/**
 * @brief: Timer for LVGL.
 * @note:
 * 		Responsible for refreshing UI.
 * 		**Call frequency: 30Hz.**
 */
__attribute__((always_inline)) inline void LVGLHandler(void)
{

}
