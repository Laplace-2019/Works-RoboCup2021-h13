/*
 * Timer.h
 *
 *  Created on: 2021��6��8��
 *      Author: h13
 */

#ifndef APP_TIMER_TIMER_H_
#define APP_TIMER_TIMER_H_

/**
 * @brief: Timer Interrupt Handler.
 * @note:
 * 		Responsible for PID calculation.
 * 		**Call frequency: 100Hz.**
 */
void TimerHandler(void);

/**
 * @brief: Timer for LVGL.
 * @note:
 * 		Responsible for refreshing UI.
 * 		**Call frequency: 30Hz.**
 */
void LVGLHandler(void);

#if(ArmType == LiftingPlatform)

/**
 * @brief: Timer for Stepper motor pulse.
 * @note:
 * 		**Call frequency: 1000Hz.**
 */
void StepperTimerInterruptHandler(void);

#endif

#endif /* APP_TIMER_TIMER_H_ */
