#include "CONFIG.h"
#include "PORT.h"
#include "SCH_CONFIG.h"
#include "SCH.h"
#include "TMR.h"
#include "IR.h"
#include "US.h"
#include "MTR.h"
#include "SDC.h"

int main(void)
{
	SCH_Init();
	TMR1_Init();
	IR_Init();
	US_Init();
	MTR_Init();
	SCH_Add_Task(IR_Update, 0, 50);
	SCH_Add_Task(US_Update_T2, 5, 50);
	SCH_Add_Task(SDC_Update, 40, 50);
	SCH_Add_Task(MTR_Update, 45, 50);
	SCH_Start();
	while(1)
	{
		SCH_Dispatch_Tasks();
	}
	return 0;
}
