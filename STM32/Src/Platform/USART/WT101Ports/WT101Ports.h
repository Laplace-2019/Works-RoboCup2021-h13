/*
 * WT101Ports.h
 *
 *  Created on: 2021��6��23��
 *      Author: h13
 */

#ifndef PLATFORM_USART_WT101PORTS_WT101PORTS_H_
#define PLATFORM_USART_WT101PORTS_WT101PORTS_H_

#include <stdint.h>

/**
 * @brief: Send data to WT101 through serialPort
 * @param: data
 */
void WT101_SerialSend(uint8_t data);

#endif /* PLATFORM_USART_WT101PORTS_WT101PORTS_H_ */
