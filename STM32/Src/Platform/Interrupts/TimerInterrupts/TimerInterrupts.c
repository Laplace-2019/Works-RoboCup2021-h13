/*
 * TimerInterrupts.c
 *
 *  Created on: 2021��6��17��
 *      Author: h13
 */

#include "TimerInterrupts.h"

#include "Timer.h"

/**
 * @brief: Timer Interrupt Handler.
 * @note:
 * 		Responsible for PID calculation.
 * 		**Call frequency: 100Hz.**
 */
__attribute__((always_inline)) inline void TimerInterruptHandler(void)
{
	TimerHandler();
}

/**
 * @brief: Timer for LVGL.
 * @note:
 * 		Responsible for refreshing UI.
 * 		**Call frequency: 30Hz.**
 */
__attribute__((always_inline)) inline void LVGLInterruptHandler(void)
{
	LVGLHandler();
}

