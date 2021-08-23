/*
 * BluetoothPorts.h
 *
 *  Created on: 2021��8��23��
 *      Author: h13
 */

#ifndef PLATFORM_USART_BLUETOOTHPORTS_BLUETOOTHPORTS_H_
#define PLATFORM_USART_BLUETOOTHPORTS_BLUETOOTHPORTS_H_

#include <stdint.h>

/**
 * @brief: Send data to bluetooth through serial port.
 * @param: data
 */
void BluetoothSerialSend(uint8_t data);

#endif /* PLATFORM_USART_BLUETOOTHPORTS_BLUETOOTHPORTS_H_ */
