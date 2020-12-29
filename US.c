#include "US.h"

static uint8 US_distance_R_G;
static uint8 US_distance_L_G;

void US_Init(void)
{
	US_distance_R_G = 0;
	US_distance_L_G = 0;
	US_DREG = US_DREG | TRIG_L | TRIG_R;
	US_OREG = US_OREG & (~(TRIG_L | TRIG_R));
	US_DREG = US_DREG & (~(ECHO_L | ECHO_R));
}
/*
void US_Update_T1(void)
{
	while(!(TIFR & 0x20));
	US_distance_G = ICR1;
	US_distance_G = (US_distance_G / 2) / 58;
	TIFR = TIFR | (0x20);
	TCCR1B = TCCR1B | (0x42);

	US_OREG = US_OREG | TRIG;
	SW_DELAY_us(10);
	US_OREG = US_OREG & (~TRIG);
	while(!(TIFR & 0x20));
	TCNT1 = 0;
	TIFR = TIFR | (0x20);
	TCCR1B = TCCR1B & (~0x40);
}
*/
void US_Update_T2(void)
{
	uint8 Count_R = 0;
	US_OREG = US_OREG | TRIG_R;
	SW_DELAY_us(10);
	US_OREG = US_OREG & (~TRIG_R);
	while(!(US_IREG & ECHO_R));
	TCNT2 = 0;
	TIFR = TIFR | (0x40);
	TCCR2 = TCCR2 | (0x02);
	while(US_IREG & ECHO_R)
	{
		if(TIFR & 0x40)
		{
			Count_R++;
			TIFR = TIFR | (0x40);
		}
	}
	TCCR2 = TCCR2 & (~0x02);
	US_distance_R_G = TCNT2;
	US_distance_R_G = ((US_distance_R_G + (Count_R*256)) / 2) / 58;

	uint8 Count_L = 0;
	US_OREG = US_OREG | TRIG_L;
	SW_DELAY_us(10);
	US_OREG = US_OREG & (~TRIG_L);
	while(!(US_IREG & ECHO_L));
	TCNT2 = 0;
	TIFR = TIFR | (0x40);
	TCCR2 = TCCR2 | (0x02);
	while(US_IREG & ECHO_L)
	{
		if(TIFR & 0x40)
		{
			Count_L++;
			TIFR = TIFR | (0x40);
		}
	}
	TCCR2 = TCCR2 & (~0x02);
	US_distance_L_G = TCNT2;
	US_distance_L_G = ((US_distance_L_G + (Count_L*256)) / 2) / 58;
}

uint8 US_GetDistance(uint8 STATE)
{
	switch(STATE)
	{
		case 0:
			return US_distance_R_G;
		case 1:
			return US_distance_L_G;
		default:
			return 0;
	}
}
