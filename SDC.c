#include "SDC.h"

#define NORMAL_PWM 100

void SDC_Update(void)
{
	uint8 Road_edge;
	uint8 Distance_L;
	uint8 Distance_R;
	Road_edge = IR_GetState();
	Distance_R = US_GetDistance(0);
	Distance_L = US_GetDistance(1);

	PWM1A_SetDutyCycle(NORMAL_PWM);
	PWM1B_SetDutyCycle(NORMAL_PWM);

	if(Road_edge & SENSOR_R)
	{
		MTR_SetState(LEFT);
	}else if(Road_edge & SENSOR_L)
	{
		MTR_SetState(RIGHT);
	}else if (Distance_R < 50)
	{
		MTR_SetState(LEFT);
	}else if(Distance_L < 50)
	{
		MTR_SetState(RIGHT);
	}else
	{
		MTR_SetState(FORWARD);
	}
}
