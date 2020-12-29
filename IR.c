#include "IR.h"

static uint8 IR_state_G;

void IR_Init(void)
{
	IR_state_G = 0;
	IR_DREG = IR_DREG & (~(SENSOR_L | SENSOR_R));
}

void IR_Update(void)
{
	IR_state_G = (IR_IREG & (SENSOR_L | SENSOR_R));
}

uint8 IR_GetState(void)
{
	return IR_state_G;
}
