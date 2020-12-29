#ifndef _TMR_H
#define _TMR_H

#include "CONFIG.h"
#include "PORT.h"
#include "TMR.h"
#include "IR.h"
#include "US.h"
#include "MTR.h"
#include "SDC.h"

void TMR1_Init(void);
void PWM1A_SetDutyCycle(uint16 dutyCycle);
void PWM1B_SetDutyCycle(uint16 dutyCycle);

#endif /* _TMR_H */
