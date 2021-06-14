#include "mpuiic.h"

#ifdef STM32F407xx
#include "stm32f4xx_hal.h"
#endif

#if defined(STM32F103xC) || defined(STM32F103xD) || defined(STM32F103xE)
#include "stm32f1xx_hal.h"
#endif

static I2C_HandleTypeDef *i2cport = NULL;

/**
 * @brief: �趨I2C�˿�
 * @return: void
 */
void MPU_Set_IIC_Port(I2C_HandleTypeDef *port) {
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
uint8_t MPU_Write_Byte(uint8_t address, uint8_t reg, uint8_t data) {
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

/**
 * @brief: I2C��һ���ֽ�
 * @param:
 * 		uint8_t address: Ŀ��I2C��ַ
 * 		uint8_t reg: �Ĵ�����ַ
 * @return: ��ȡ��������
 */

uint8_t MPU_Read_Byte(uint8_t address, uint8_t reg) {
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
uint8_t MPU_Write_Len(uint8_t address, uint8_t reg, uint8_t len, uint8_t *buf) {
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
uint8_t MPU_Read_Len(uint8_t address, uint8_t reg, uint8_t len, uint8_t *buf) {
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
