#include "PID.h"
#include <math.h>

float PosPIDCalc(PositionPID_t *PID_t, float currentPoint) {
	volatile float error = PID_t->setpoint - currentPoint;

	volatile float result;

	PID_t->_sum_error = PID_t->_sum_error + error;

	result =

			PID_t->proportion * (error) +                //P ��������

			PID_t->integral * PID_t->_sum_error +           //I ��������

			PID_t->derivative * (error - PID_t->_error);    //D ΢������

	PID_t->_error = error;

	//��У�����
	if (isnan(result))
		return 0;
	else if (isinf(result) == 1)
		return 0;
	else if (isinf(result) == -1)
		return 0;

	return result;
}

float IncPIDCalc(IncrementalPID_t *PID_t, float currentPoint) {
	volatile float error = PID_t->setpoint - currentPoint;

	volatile float result;

	result =

			//��������, P * һ�׵��� -> p * (error - _lastError)
			(PID_t->proportion) * (error - PID_t->_lastError) +

			//��������, I * ԭ���� -> I * error
			(PID_t->integral) * (error) +

			//΢������, D * ���׵��� -> D * [(error + _previousError) - 2 * _lastError]
			(PID_t->derivative) * ((error + PID_t->_previousError) - 2 * (PID_t->_lastError));

	//����Error
	PID_t->_previousError = PID_t->_lastError;
	PID_t->_lastError = error;

	//��У�����
	if (isnan(result))
		return 0;
	else if (isinf(result) == 1)
		return 0;
	else if (isinf(result) == -1)
		return 0;

	return result;
}
