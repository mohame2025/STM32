/*************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 12 MAY 2026 --------------------------- */
/* --------------- Version      : V02 ---------------------------------- */
/* --------------- Description  : SYSTICK_Program_C -------------------- */
/*************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

void(*callback)(void);

void MSTK_voidInit(void)
{
	/* Disable SysTick First */

	CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

	/* Clock Source = AHB */

	SET_BIT(SYSTICK->STK_CTRL, STK_CLKSOURCE);

	/* Enable Interrupt */

	SET_BIT(SYSTICK->STK_CTRL, STK_TICKINT);
	
}

void MSTK_voidSetBusWait(u32 copy_u32Ticks)
{
	
	Load_Reg = copy_u32Ticks;
     /* enable systick */
	while(flag == 0);  
	  
}


void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*ptr)(void)
{
	
	Load_Reg = copy_u32Ticks;
    /*Enable of interrupt and enable systick */	
	callback = ptr;
	
}


void SysTick_Handler(void)
{
	callback();
	
}


void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr)(void)
{

}
void MSTK_voidStopInterval(void)
{
	
	
}
u32 MSTK_u32GetElapsedTime(void)
{
	
	
}
u32 MSTK_u32GetRemainingTime(void)
{
	
	
}



#endif




main
--------
void funk(void)
{
	
	/* code */
}

MSTK_voidSetIntervalSingle(1000, func);
MSTK_voidSetIntervalSingle(2000, fun3);
MSTK_voidSetIntervalSingle(3000, fun4);

