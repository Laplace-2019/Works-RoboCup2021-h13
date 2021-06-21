/*
 * I2C.c
 *
 *  Created on: 2021��6��14��
 *      Author: h13
 */

#if defined(STM32F103xC) || defined(STM32F103xD) || defined(STM32F103xE)
#include "stm32f1xx_hal.h"
#endif

static I2C_HandleTypeDef *i2cport = NULL;

/**
 * @brief: Set I2C Port.
 * @param: I2C Handle.
 */
void SetI2CPort(I2C_HandleTypeDef *port)
{
	i2cport = port;
}

/**
 * @brief: I2Cдһ���ֽ�
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * 		uint8_t data: ��д������
 * @return: ������, �ɹ�Ϊ0
 */
/*
uint8_t I2CWriteByte(uint8_t address, uint8_t reg, uint8_t data)
{
	if (HAL_I2C_IsDeviceReady(i2cport, address*2, I2C_RETRY, I2C_TIMEOUT)
			== HAL_OK) {
		if (HAL_I2C_Mem_Write(i2cport, address*2, reg, I2C_MEMADD_SIZE_8BIT,
				&data, 1, I2C_TIMEOUT) == HAL_OK) {
			return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}

}
*/
/**
 * @brief: I2C��һ���ֽ�
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * @return: ��ȡ��������
 */
/*
uint8_t I2CReadByte(uint8_t address, uint8_t reg) {
	uint8_t data = 0;
	HAL_I2C_IsDeviceReady(i2cport, (address * 2) + 1, I2C_RETRY, I2C_TIMEOUT);
	HAL_I2C_Mem_Read(i2cport, (address * 2) + 1, reg, I2C_MEMADD_SIZE_8BIT, &data, 1,
	I2C_TIMEOUT);
	return data;
}

/**
 * @brief: I2C����д
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * 		uint8_t len: Ҫд��ĳ���
 * 		uint8_t *buf: Ҫд�������
 * @return: ������, �ɹ�Ϊ0
 */
/*
uint8_t I2CWriteBytes(uint8_t address, uint8_t reg, uint8_t len, uint8_t *buf) {
	if (HAL_I2C_IsDeviceReady(i2cport, address * 2, I2C_RETRY, I2C_TIMEOUT)
			== HAL_OK) {
		if (HAL_I2C_Mem_Write(i2cport, address * 2, reg,
		I2C_MEMADD_SIZE_8BIT, buf, len, I2C_TIMEOUT) == HAL_OK) {
			return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}
}

/**
 * @brief: I2C������
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * 		uint8_t len: Ҫ��ȡ�ĳ���
 * 		uint8_t *buf: Ҫ��ȡ�����ݻ�����
 * @return: ������, �ɹ�Ϊ0
 */
/*
uint8_t I2CReadBytes(uint8_t address, uint8_t reg, uint8_t len, uint8_t *buf) {
	if (HAL_I2C_IsDeviceReady(i2cport, (address * 2) + 1, I2C_RETRY, I2C_TIMEOUT)
			== HAL_OK) {
		if (HAL_I2C_Mem_Read(i2cport, (address * 2) + 1, reg,
		I2C_MEMADD_SIZE_8BIT, buf, len, I2C_TIMEOUT) == HAL_OK) {
			return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}
}
*/
