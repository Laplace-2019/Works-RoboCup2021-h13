#ifndef __MPUIIC_H
#define __MPUIIC_H

#define I2C_RETRY   3
#define I2C_TIMEOUT 1000

#ifdef STM32F407xx
#include "stm32f4xx_hal.h"
#endif

#if defined(STM32F103xC) || defined(STM32F103xD) || defined(STM32F103xE)
#include "stm32f1xx_hal.h"
#endif

/**
 * @brief: �趨I2C�˿�
 * @return: void
 */
void MPU_Set_IIC_Port(I2C_HandleTypeDef *port);


/**
 * @brief: I2Cдһ���ֽ�
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * 		uint8_t data: ��д������
 * @return: ������, �ɹ�Ϊ0
 */
uint8_t MPU_Write_Byte(uint8_t address, uint8_t reg, uint8_t data);

/**
 * @brief: I2C��һ���ֽ�
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * @return: ��ȡ��������
 */

uint8_t MPU_Read_Byte(uint8_t address, uint8_t reg);

/**
 * @brief: I2C����д
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * 		uint8_t len: Ҫд��ĳ���
 * 		uint8_t *buf: Ҫд�������
 * @return: ������, �ɹ�Ϊ0
 */
uint8_t MPU_Write_Len(uint8_t address, uint8_t reg, uint8_t len, uint8_t *buf);

/**
 * @brief: I2C������
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * 		uint8_t len: Ҫ��ȡ�ĳ���
 * 		uint8_t *buf: Ҫ��ȡ�����ݻ�����
 * @return: ������, �ɹ�Ϊ0
 */
uint8_t MPU_Read_Len(uint8_t address, uint8_t reg, uint8_t len, uint8_t *buf);

#endif
