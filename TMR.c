#include "TMR.h"

void TMR1_Init(void)
{
	//Set fast PWM mode
	//Set none-inverting mode
	//Set prescaler clk/256 and start PWM
	TCCR1A = TCCR1A | (0xA1);
	TCCR1B = TCCR1B | (0x0C);
}

void PWM1A_SetDutyCycle(uint16 dutyCycle)
{
	//Set PWM for duty cycle from 0 to 255
	OCR1A = dutyCycle;
}

void PWM1B_SetDutyCycle(uint16 dutyCycle)
{
	//Set PWM for duty cycle from 0 to 255
	OCR1B = dutyCycle;
}
