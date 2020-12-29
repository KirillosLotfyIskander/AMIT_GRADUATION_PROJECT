#ifndef _SCH_H
#define _SCH_H

#include "CONFIG.h"
#include "PORT.h"
#include "SCH_CONFIG.h"
#include "SCH.h"

typedef struct
{
	void (*pTask)(void);
	tWord Delay;
	tWord Period;
	tByte RunMe;
}sTask;

#define SCH_MAX_TASKS (5)

tByte SCH_Add_Task(void(*pFunction)(void), const tWord DELAY, const tWord PERIOD);
tByte SCH_Delete_Task(const tByte INDEX);
void SCH_Report_Status(void);
void SCH_Dispatch_Tasks(void);

#endif /* _SCH_H */
