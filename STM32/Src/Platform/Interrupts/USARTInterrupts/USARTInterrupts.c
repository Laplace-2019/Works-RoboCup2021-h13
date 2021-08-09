/*
 * USARTInterrupts.c
 *
 *  Created on: 2021��6��12��
 *      Author: h13
 */
#include "USARTInterrupts.h"
#include "SKTOF.h"
#include "WT101.h"
#include "Debug.h"

/**
 * @brief: Serial Debug Interrupt Handler.
 * @param: data.
 */
__attribute__((always_inline)) inline void SerialDebugInterruptHandler(uint8_t data)
{
	DebugHandler(data);
}

/**
 * @brief: TOF Interrupt Handler.
 * @param: data.
 */
__attribute__((always_inline)) inline void TOFInterruptHandler(uint8_t data)
{
	TOF_Handler(data);
}

__attribute__((always_inline)) inline void WT101InterruptHandler(uint8_t data)
{
	WT101Handler(data);
}

__attribute__((always_inline)) inline void ImageProcessingModuleInterruptHandler(uint8_t data)
{

}

