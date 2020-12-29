#include "SCH_CONFIG.h"

extern sTask SCH_tasks[SCH_MAX_TASKS];
extern tByte Error_code_G;

void TMR0_Init(void)
{
	//Set Timer0 in CTC mode
	//Set OC0 Normal Port Operation
	//Set prescaler clk/64
	TCCR0 = TCCR0 | (0x8B);
	//Set counter value
	TCNT0 = 0;
	//Set compare value
	OCR0 = 249;
	//Set Timer0 compare match interrupt
	TIMSK = TIMSK | (0x02);
	//Set Timer0 overflow interrupt
	//TIMSK = TIMSK | (0x01);
}

void SCH_Init(void)
{
	tByte Index;
	for(Index = 0; Index < SCH_MAX_TASKS; Index++)
	{
		SCH_Delete_Task(Index);
	}
	Error_code_G = 0;
	TMR0_Init();
}

void SCH_Start(void)
{
	GIE();
}

ISR(INTERRUPT_Timer_0_Comparematch) //void SCH_Update(void)
{
	tByte Index;
	for(Index = 0; Index < SCH_MAX_TASKS; Index++)
	{
		if(SCH_tasks[Index].pTask)
		{
			if(SCH_tasks[Index].Delay == 0)
			{
				SCH_tasks[Index].RunMe +=1;
				if(SCH_tasks[Index].Period)
				{
					SCH_tasks[Index].Delay = SCH_tasks[Index].Period;
				}
			}
			else
			{
				SCH_tasks[Index].Delay -=1;
			}
		}
	}
}
