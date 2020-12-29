#ifndef _US_H
#define _US_H

#include "CONFIG.h"
#include "PORT.h"
#include "TMR.h"
#include "IR.h"
#include "US.h"
#include "MTR.h"
#include "SDC.h"

void US_Init(void);
void US_Update_T1(void);
void US_Update_T2(void);
uint8 US_GetDistance(uint8 STATE);

#endif /* _US_H */
