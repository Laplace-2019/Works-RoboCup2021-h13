/*
 * SPI.c
 *
 *  Created on: 2021��6��5��
 *      Author: h13
 */

#include "SPI.h"

#if defined(STM32F103xC) || defined(STM32F103xD) || defined(STM32F103xE)
#include "stm32f1xx_ll_spi.h"
#include "stm32f1xx_ll_gpio.h"
#endif

/**
 * @param: The SPI Port you selected.
 */
static SPI_TypeDef *target = SPI1;

/**
 * @ps:    �ⲿ�ֲ����һ��������Ľ��Ͱ�... ��Ȼûʲô�ر��, ֻ���ú궨���������ŵ���ɳ�ʱ����.
 * @group: ��ʱ�����غ�
 *
 * @usage:
 * 		CheckTimeOutInit();
 * 		CheckTimeOut() while (LL_SPI_IsActiveFlag_TXE(target) == SET) TimeLimit()
 * 		CheckTimeOut() while (...) TimeLimit()
 *
 * @param: errorTimeLimit ���ȴ�����
 * @parma: returnCode ������ʱ�󣬺�������ֵ��
 *
 * @note:
 * 		CheckTimeOutInit();
 * 		CheckTimeOut() while (LL_SPI_IsActiveFlag_TXE(target) == SET) TimeLimit()
 *
 * 		���յȼ���:
 *
 * 		uint16_t errorTimes = 0;
 * 		errorTimes = 0;   //���������Ϊ�˷�ֹ����ʹ��ʱ�Ķ��ض�������.
 * 		while (LL_SPI_IsActiveFlag_TXE(target) == SET)
 * 		{
 * 			errorTimes ++;
 * 			if(errorTimes > errorTimeLimit)
 * 			{
 * 				return;
 * 			}
 * 		}
 */
#define CheckTimeOutInit() uint16_t errorTimes = 0;
#define CheckTimeOut()     errorTimes = 0;
#define TimeLimit(errorTimeLimit) {errorTimes ++; if(errorTimes > errorTimeLimit) return;}

/**
 * @brief: Initialize the SPI interface.
 * @note:  If multiple devices are mounted under the SPI interface, be aware of SPI initialization sequence and repeated initialization issues.
 */
void SPIInit(void) {
	LL_SPI_Enable(target);
}

/**
 * @brief: SPI write 8-bit data.
 * @param: data.
 */
inline __attribute__((always_inline)) void SPIWriteByte(uint8_t data) {

	CheckTimeOutInit();

	CheckTimeOut() while (LL_SPI_IsActiveFlag_BSY(target) == SET) TimeLimit(1000)
	CheckTimeOut() while (LL_SPI_IsActiveFlag_TXE(target) == RESET) TimeLimit(1000)

	LL_SPI_TransmitData8(target, data);
}

/**
 * @group: Set and Reset Pins of LCD.
 */
inline __attribute__((always_inline)) void LCDSetRST(void)
{
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
}

inline __attribute__((always_inline)) void LCDResetRST(void)
{
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
}

inline __attribute__((always_inline)) void LCDSetCS(void)
{
	LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_4);
}

inline __attribute__((always_inline)) void LCDResetCS(void)
{
	LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_4);
}

inline __attribute__((always_inline)) void LCDSetDC(void)
{
	LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_5);
}

inline __attribute__((always_inline)) void LCDResetDC(void)
{
	LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_5);
}
