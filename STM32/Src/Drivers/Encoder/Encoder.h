/*
 * Encoder.h
 *
 *  Created on: 2021��8��27��
 *      Author: h13
 */

#ifndef DRIVERS_ENCODER_ENCODER_H_
#define DRIVERS_ENCODER_ENCODER_H_

#include <stdint.h>

void EncoderInit(void);

int32_t GetLeftEncoderSpeed(void);

int32_t GetRightEncoderSpeed(void);

#endif /* DRIVERS_ENCODER_ENCODER_H_ */
