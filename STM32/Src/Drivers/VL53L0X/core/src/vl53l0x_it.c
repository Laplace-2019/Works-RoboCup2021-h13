#include "vl53l0x_it.h"
#include "vl53l0x_easy_api.h"

#if defined(STM32F103xC) || defined(STM32F103xD) || defined(STM32F103xE)
#include "stm32f1xx_hal.h"
#endif

#define delay_ms HAL_Delay

//�ж�ģʽ�����ṹ��
typedef struct
{
    const int VL53L0X_Mode;//ģʽ
    uint32_t ThreshLow;    //����ֵ
    uint32_t ThreshHigh;   //����ֵ
} AlrmMode_t;

AlrmMode_t AlarmModes = {
    VL53L0X_GPIOFUNCTIONALITY_THRESHOLD_CROSSED_OUT,// value < thresh_low OR value > thresh_high
    Thresh_Low  << 16,
    Thresh_High << 16
};

typedef __packed struct
{
    uint8_t  isApertureSpads;             //ApertureSpadsֵ
    uint8_t  VhvSettings;                 //VhvSettingsֵ
    uint8_t  PhaseCal;                    //PhaseCalֵ
    uint32_t XTalkCalDistance;            //XTalkCalDistanceֵ
    uint32_t XTalkCompensationRateMegaCps;//XTalkCompensationRateMegaCpsֵ
    uint32_t CalDistanceMilliMeter;       //CalDistanceMilliMeterֵ
    int32_t  OffsetMicroMeter;            //OffsetMicroMeterֵ
    uint32_t refSpadCount;                //refSpadCountֵ

} _vl53l0x_adjust;

extern _vl53l0x_adjust Vl53l0x_adjust;

//vl53l0xģʽ���ò�����
typedef __packed struct
{
    FixPoint1616_t signalLimit;    //Signal������ֵ
    FixPoint1616_t sigmaLimit;     //Sigmal������ֵ
    uint32_t timingBudget;         //����ʱ������
    uint8_t preRangeVcselPeriod ;  //VCSEL��������
    uint8_t finalRangeVcselPeriod ;//VCSEL�������ڷ�Χ

} mode_data;


//�ⲿ�жϷ�����
void EXTI4_IRQHandler(void)
{
    printf("TOF Raised the interrupt\r\n");
	//�Ҳ�֪����Ҫ�Ҷ����豸 ��������������Լ�ȥ���ð�
    //VL53L0X_ClearInterruptMask(dev,0);
}

extern mode_data Mode_data[];

//vl53l0x�жϲ���ģʽ����
//dev:�豸I2C�����ṹ��
//mode: 0:Ĭ��;1:�߾���;2:������;3:����
VL53L0X_Error vl53l0x_interrupt_start(VL53L0X_Dev_t *dev,uint8_t mode)
{
    VL53L0X_Error status=VL53L0X_ERROR_NONE;//����״̬

    //exti_init();//�жϳ�ʼ��

    VL53l0X_Reset(dev);//��λvl53l0x(Ƶ���л�����ģʽ���׵��²ɼ��������ݲ�׼���������һ����)
    status = VL53L0X_StaticInit(dev);
    if(status!=VL53L0X_ERROR_NONE) return status;

    status= VL53L0X_SetReferenceSpads(dev,Vl53l0x_adjust.refSpadCount,Vl53l0x_adjust.isApertureSpads);//�趨SpadsУ׼ֵ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status= VL53L0X_SetRefCalibration(dev,Vl53l0x_adjust.VhvSettings,Vl53l0x_adjust.PhaseCal);//�趨RefУ׼ֵ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status=VL53L0X_SetOffsetCalibrationDataMicroMeter(dev,Vl53l0x_adjust.OffsetMicroMeter);//�趨ƫ��У׼ֵ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status=VL53L0X_SetXTalkCompensationRateMegaCps(dev,Vl53l0x_adjust.XTalkCompensationRateMegaCps);//�趨����У׼ֵ
    if(status!=VL53L0X_ERROR_NONE) return status;

    status = VL53L0X_SetDeviceMode(dev,VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);//ʹ����������ģʽ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetInterMeasurementPeriodMilliSeconds(dev,Mode_data[mode].timingBudget);//�����ڲ����ڲ���ʱ��
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetLimitCheckEnable(dev,VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE,1);//ʹ��SIGMA��Χ���
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetLimitCheckEnable(dev,VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE,1);//ʹ���ź����ʷ�Χ���
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetLimitCheckValue(dev,VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE,Mode_data[mode].sigmaLimit);//�趨SIGMA��Χ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetLimitCheckValue(dev,VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE,Mode_data[mode].signalLimit);//�趨�ź����ʷ�Χ��Χ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetMeasurementTimingBudgetMicroSeconds(dev,Mode_data[mode].timingBudget);//�趨��������ʱ��
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetVcselPulsePeriod(dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, Mode_data[mode].preRangeVcselPeriod);//�趨VCSEL��������
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetVcselPulsePeriod(dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, Mode_data[mode].finalRangeVcselPeriod);//�趨VCSEL�������ڷ�Χ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_StopMeasurement(dev);//ֹͣ����
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetInterruptThresholds(dev,VL53L0X_DEVICEMODE_CONTINUOUS_RANGING,AlarmModes.ThreshLow, AlarmModes.ThreshHigh);//�趨�����ж��ϡ�����ֵ
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_SetGpioConfig(dev,0,VL53L0X_DEVICEMODE_CONTINUOUS_RANGING,AlarmModes.VL53L0X_Mode,VL53L0X_INTERRUPTPOLARITY_LOW);//�趨�����ж�ģʽ �½���
    if(status!=VL53L0X_ERROR_NONE) return status;
    delay_ms(2);
    status = VL53L0X_ClearInterruptMask(dev,0);//���VL53L0X�жϱ�־λ
    return status;
}
