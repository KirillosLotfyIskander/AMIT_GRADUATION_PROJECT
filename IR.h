#ifndef _IR_H
#define _IR_H

#include "CONFIG.h"
#include "PORT.h"
#include "TMR.h"
#include "IR.h"
#include "US.h"
#include "MTR.h"
#include "SDC.h"

void IR_Init(void);
void IR_Update(void);
uint8 IR_GetState(void);

#endif /* _IR_H */
