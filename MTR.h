#ifndef _MTR_H
#define _MTR_H

#include "CONFIG.h"
#include "PORT.h"
#include "TMR.h"
#include "IR.h"
#include "US.h"
#include "MTR.h"
#include "SDC.h"

#define STOP 0
#define FORWARD 1
#define RIGHT 2
#define LEFT 3
#define REVERSE 4

void MTR_Init(void);
void MTR_Update(void);
void MTR_SetState(uint8 STATE);

#endif /* _MTR_H */
