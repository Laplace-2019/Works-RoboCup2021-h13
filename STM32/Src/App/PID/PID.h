#ifndef _PID_H_
#define _PID_H_

//λ��ʽPID
typedef struct {
	float setpoint;      //�趨Ŀ��

	float proportion;   //��������
	float integral;      //���ֳ���
	float derivative;    //΢�ֳ���

	float _sum_error;    //����ۼ�

	float _error;        //���һ�����
} PositionPID_t;

float PosPIDCalc(PositionPID_t *PID_t, float currentPoint);

//����ʽPID
typedef struct {
	float setpoint;      //�趨Ŀ��

	float proportion;   //��������
	float integral;      //���ֳ���
	float derivative;    //΢�ֳ���

	float _previousError;    //���ϴ����

	float _lastError;    //�ϴ����
} IncrementalPID_t;

float IncPIDCalc(IncrementalPID_t *PID_t, float currentPoint);

#endif
