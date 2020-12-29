#include "SCH.h"

sTask SCH_tasks[SCH_MAX_TASKS];
tByte Error_code_G = 0;

static void SCH_Go_To_Sleep(void);

static tWord Error_tick_count_G;
static tByte Last_error_code_G;

tByte SCH_Add_Task(void(*pFunction)(void), const tWord DELAY, const tWord PERIOD)
{
	tByte Index;
	for(Index = 0; (SCH_tasks[Index].pTask !=0) && (Index < SCH_MAX_TASKS); Index++);
	if(Index == SCH_MAX_TASKS)
	{
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return SCH_MAX_TASKS;
	}
	SCH_tasks[Index].pTask = pFunction;
	SCH_tasks[Index].Delay = DELAY;
	SCH_tasks[Index].Period = PERIOD;
	SCH_tasks[Index].RunMe = 0;
	return Index;
}

tByte SCH_Delete_Task(const tByte INDEX)
{
	tByte Return_code;
	if(SCH_tasks[INDEX].pTask == 0)
	{
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		Return_code = RETURN_ERROR;
	}
	else
	{
		Return_code = RTURN_NORMAL;
	}
	SCH_tasks[INDEX].pTask = 0x0000;
	SCH_tasks[INDEX].Delay = 0;
	SCH_tasks[INDEX].Period = 0;
	SCH_tasks[INDEX].RunMe = 0;
	return Return_code;
}

void SCH_Report_Status(void)
{
#ifdef SCH_REPORT_ERROR
	if(Error_code_G != Last_error_code_G)
	{
		Error_port = 255 - Error_code_G;
		Last_error_code_G = Error_code_G;
		if(Error_code_G != 0)
		{
			Error_tick_count_G = 60000;
		}
		else
		{
			Error_tick_count_G = 0;
		}
	}
	else
	{
		if(Error_tick_count_G != 0)
		{
			if(--Error_tick_count_G == 0)
			{
				Error_code_G = 0;
			}
		}
	}
#endif
}

void SCH_Go_To_Sleep(void)
{

}

void SCH_Dispatch_Tasks(void)
{
	tByte Index;
	for(Index = 0; Index < SCH_MAX_TASKS; Index++)
	{
		if(SCH_tasks[Index].RunMe > 0)
		{
			(*SCH_tasks[Index].pTask)();
			SCH_tasks[Index].RunMe -=1;
			if(SCH_tasks[Index].Period == 0)
			{
				SCH_Delete_Task(Index);
			}
		}
	}
	SCH_Report_Status();
	SCH_Go_To_Sleep();
}
