#include "MTR.h"

static uint8 MTR_state_G;

void MTR_Init(void)
{
	MTR_state_G = 0;
	MTR_DREG1 = MTR_DREG1 | (OUT4 | OUT3 | OUT2 | OUT1);
	MTR_OREG1 = MTR_OREG1 & ~((OUT4 | OUT3 | OUT2 | OUT1));
	MTR_DREG2 = MTR_DREG2 | (ENB | ENA);
}

void MTR_Update(void)
{
	switch(MTR_state_G)
	{
		case STOP:
		{
			MTR_OREG1 = MTR_OREG1 & (~(OUT4 | OUT3 | OUT2 | OUT1));
			break;
		}
		case FORWARD:
		{
			MTR_OREG1 = MTR_OREG1 & (~(OUT3 | OUT2));
			MTR_OREG1 = MTR_OREG1 | (OUT4 | OUT1);
			break;
		}
		case RIGHT:
		{
			MTR_OREG1 = MTR_OREG1 & (~(OUT3 | OUT1));
			MTR_OREG1 = MTR_OREG1 | (OUT4 | OUT2);
			break;
		}
		case LEFT:
		{
			MTR_OREG1 = MTR_OREG1 & (~(OUT4 | OUT2));
			MTR_OREG1 = MTR_OREG1 | (OUT3 | OUT1);
			break;
		}
		case REVERSE:
		{
			MTR_OREG1 = MTR_OREG1 & (~(OUT4 | OUT1));
			MTR_OREG1 = MTR_OREG1 | (OUT3 | OUT2);
			break;
		}
	}
}

void MTR_SetState(uint8 STATE)
{
	MTR_state_G = STATE;
}
