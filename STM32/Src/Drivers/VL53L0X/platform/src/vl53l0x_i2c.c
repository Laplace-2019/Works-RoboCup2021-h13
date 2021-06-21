#include "vl53l0x_i2c.h"

#if defined(STM32F103xC) || defined(STM32F103xD) || defined(STM32F103xE)
#include "stm32f1xx_hal.h"
#endif

#define I2C_RETRY   3
#define I2C_TIMEOUT 1000

static I2C_HandleTypeDef *i2cport = NULL;

/**
 * @brief:
 * @param:
 */
void VL53L0X_SetI2C_Port(I2C_HandleTypeDef *port)
{
	i2cport = port;
}

//IICдһ���ֽ�����
uint8_t VL_I2C_WriteByte(uint8_t SlaveAddress, uint8_t REG_Address,uint8_t REG_data)
{
	if (HAL_I2C_IsDeviceReady(i2cport, SlaveAddress*2, I2C_RETRY, I2C_TIMEOUT) == HAL_OK)
	{
		if (HAL_I2C_Mem_Write(i2cport, SlaveAddress*2, REG_Address, I2C_MEMADD_SIZE_8BIT, &REG_data, 1, I2C_TIMEOUT) == HAL_OK)
		{
			return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}
}

//IIC��һ���ֽ�����
uint8_t VL_I2C_ReadByte(uint8_t SlaveAddress, uint8_t REG_Address,uint8_t *REG_data)
{
	if(HAL_I2C_IsDeviceReady(i2cport, (SlaveAddress * 2) + 1, I2C_RETRY, I2C_TIMEOUT) == HAL_OK)
	{
		if(HAL_I2C_Mem_Read(i2cport, (SlaveAddress * 2) + 1, REG_Address, I2C_MEMADD_SIZE_8BIT, REG_data, 1, I2C_TIMEOUT) == HAL_OK)
		{
			return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}
}

//IICдn�ֽ�����
uint8_t VL_IIC_WriteLen(uint8_t SlaveAddress, uint8_t REG_Address,uint16_t len, uint8_t *buf)
{
	if (HAL_I2C_IsDeviceReady(i2cport, SlaveAddress * 2, I2C_RETRY, I2C_TIMEOUT) == HAL_OK)
	{
		if (HAL_I2C_Mem_Write(i2cport, SlaveAddress * 2, REG_Address, I2C_MEMADD_SIZE_8BIT, buf, len, I2C_TIMEOUT) == HAL_OK)
		{
			return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}
}

//IIC��n�ֽ�����
uint8_t VL_IIC_ReadLen(uint8_t SlaveAddress, uint8_t REG_Address,uint16_t len,uint8_t *buf)
{
	if (HAL_I2C_IsDeviceReady(i2cport, (SlaveAddress * 2) + 1, I2C_RETRY, I2C_TIMEOUT) == HAL_OK)
	{
		if (HAL_I2C_Mem_Read(i2cport, (SlaveAddress * 2) + 1, REG_Address, I2C_MEMADD_SIZE_8BIT, buf, len, I2C_TIMEOUT) == HAL_OK)
		{
			return 0;
		} else {
			return 1;
		}
	} else {
		return 2;
	}
}

//VL53L0X д�������
//address:��ַ
//index:ƫ�Ƶ�ַ
//pdata:����ָ��
//count:���� ���65535
uint8_t VL53L0X_write_multi(uint8_t address, uint8_t index,uint8_t *pdata,uint16_t count)
{
	uint8_t status = STATUS_OK;

	if(VL_IIC_WriteLen(address, index, count, pdata))
	{
	   status = STATUS_FAIL;
	}

	return status;
}


//VL53L0X ���������
//address:��ַ
//index:ƫ�Ƶ�ַ
//pdata:����ָ��
//count:���� ���65535
uint8_t VL53L0X_read_multi(uint8_t address,uint8_t index,uint8_t *pdata,uint16_t count)
{
	uint8_t status = STATUS_OK;

	if(VL_IIC_ReadLen(address,index,count,pdata))
	{
	  status  = STATUS_FAIL;
	}

	return status;
}

//VL53L0X д1������(���ֽ�)
//address:��ַ
//index:ƫ�Ƶ�ַ
//data:����(8λ)
uint8_t VL53L0X_write_byte(uint8_t address,uint8_t index,uint8_t data)
{
	uint8_t status = STATUS_OK;

	status = VL53L0X_write_multi(address,index,&data,1);

	return status;
}

//VL53L0X д1������(˫�ֽ�)
//address:��ַ
//index:ƫ�Ƶ�ַ
//data:����(16λ)
uint8_t VL53L0X_write_word(uint8_t address,uint8_t index,uint16_t data)
{
	uint8_t status = STATUS_OK;
	
	uint8_t buffer[2];
	
	//��16λ���ݲ�ֳ�8λ
	buffer[0] = (uint8_t)(data>>8);//�߰�λ
	buffer[1] = (uint8_t)(data&0xff);//�Ͱ�λ
	
	if(index%2==1)
	{  
		//����ͨ�Ų��ܴ���Է�2�ֽڶ���Ĵ������ֽ�
		status = VL53L0X_write_multi(address,index,&buffer[0],1);
		status = VL53L0X_write_multi(address,index,&buffer[0],1);
	}else
	{
		status = VL53L0X_write_multi(address,index,buffer,2);
	}
	
	return status;
}

//VL53L0X д1������(���ֽ�)
//address:��ַ
//index:ƫ�Ƶ�ַ
//data:����(32λ)
uint8_t VL53L0X_write_dword(uint8_t address,uint8_t index,uint32_t data)
{
	
    uint8_t status = STATUS_OK;

    uint8_t buffer[4];
	
	//��32λ���ݲ�ֳ�8λ
	buffer[0] = (uint8_t)(data>>24);
	buffer[1] = (uint8_t)((data&0xff0000)>>16);
	buffer[2] = (uint8_t)((data&0xff00)>>8);
	buffer[3] = (uint8_t)(data&0xff);
	
	status = VL53L0X_write_multi(address,index,buffer,4);
	
	return status;
}


//VL53L0X ��1������(���ֽ�)
//address:��ַ
//index:ƫ�Ƶ�ַ
//data:����(8λ)
uint8_t VL53L0X_read_byte(uint8_t address,uint8_t index,uint8_t *pdata)
{
	uint8_t status = STATUS_OK;
	 
	status = VL53L0X_read_multi(address,index,pdata,1);
	
	return status;
}

//VL53L0X ��������(˫�ֽ�)
//address:��ַ
//index:ƫ�Ƶ�ַ
//data:����(16λ)
uint8_t VL53L0X_read_word(uint8_t address,uint8_t index,uint16_t *pdata)
{
	uint8_t status = STATUS_OK;
	
	uint8_t buffer[2];
	
	status = VL53L0X_read_multi(address,index,buffer,2);
	
	*pdata = ((uint16_t)buffer[0]<<8)+(uint16_t)buffer[1];
	
	return status;
}

//VL53L0X ��1������(���ֽ�)
//address:��ַ
//index:ƫ�Ƶ�ַ
//data:����(32λ)
uint8_t VL53L0X_read_dword(uint8_t address,uint8_t index,uint32_t *pdata)
{
	uint8_t status = STATUS_OK;
	
	uint8_t buffer[4];
	
	status = VL53L0X_read_multi(address,index,buffer,4);
	
	*pdata = ((uint32_t)buffer[0]<<24)+((uint32_t)buffer[1]<<16)+((uint32_t)buffer[2]<<8)+((uint32_t)buffer[3]);
	
	return status;
}
