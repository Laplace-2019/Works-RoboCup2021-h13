/*
 * CatchApple.h
 *
 *  Created on: 2021��8��14��
 *      Author: h13
 */

#ifndef APP_EXAMPLES_CATCHAPPLE_H_
#define APP_EXAMPLES_CATCHAPPLE_H_

typedef enum
{
	MaximumTarget,
	LeftTarget,
	RightTarget,
} TargetType_t;

void CatchApple(TargetType_t Target);

#endif /* APP_EXAMPLES_CATCHAPPLE_H_ */
