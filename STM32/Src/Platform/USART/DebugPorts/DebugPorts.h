/*
 * DebugPorts.h
 *
 *  Created on: 2021��6��23��
 *      Author: h13
 */

#ifndef PLATFORM_USART_DEBUGPORTS_DEBUGPORTS_H_
#define PLATFORM_USART_DEBUGPORTS_DEBUGPORTS_H_

#include <stdio.h>
#include <stdint.h>

/**
 * @brief: Send debug data through serialPort
 * @param: data
 */
void LogSerialSend(uint8_t data);

#endif /* PLATFORM_DEBUGPORTS_DEBUGPORTS_H_ */
