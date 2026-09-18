/*************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 8 MAY 2026 --------------------------- */
/* --------------- Version      : V03 ---------------------------------- */
/* --------------- Description  : SYSTICK_Program_C -------------------- */
/*************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

/*************************/
/* Function : MSTK_voidInit                                              */
/* Description : Initialize SysTick                                      */
/*************************/
static void (*MSTK_CallBack)(void) = 0;

void MSTK_voidInit(void)
{
    /* Disable SysTick First */
    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    /* Clock Source = AHB / 8 = 1 MHz */
    CLR_BIT(SYSTICK->STK_CTRL, STK_CLKSOURCE);

    /* Enable Interrupt */
    SET_BIT(SYSTICK->STK_CTRL, STK_TICKINT);
}

/*************************/
/* Function : MSTK_voidStart                                             */
/* Description : Start SysTick                                           */
/*************************/

void MSTK_VidSetCallBack( void (*ptr)(void) ){

	MSTK_CallBack = ptr;
}

void MSTK_VidInit( void ){

	// Enable Systick Interrupt  -  Clock = AHB / 8 - Stop Systic
	MSTK->CTRL = 0x00000002;

}

void MSTK_voidStart(u32 copy_u32Load)
{
	/* SysTick is 24-bit */

	if(copy_u32Load <= 0xFFFFFF)
	{
		/* Load Value */

		SYSTICK->STK_LOAD = copy_u32Load - 1;

		/* Clear Current Value */

		SYSTICK->STK_VAL = 0;

		/* Enable SysTick */

		SET_BIT(SYSTICK->STK_CTRL, STK_ENABLE);
	}
}

/*************************/
/* Function : MSTK_voidStop                                              */
/* Description : Stop SysTick                                            */
/*************************/

void MSTK_voidStop(void)
{
	CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

	SYSTICK->STK_LOAD = 0;

	SYSTICK->STK_VAL = 0;
}

/*************************/
/* Function : MSTK_voidDelayMs                                           */
/* Description : Blocking Delay in ms                                    */
/*************************/

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load ticks to load register */
	SYSTICK -> STK_LOAD = Copy_u32Ticks;
	/* Start Timer */
	SET_BIT(SYSTICK->STK_CTRL, 0);

	/* wait till flag is raised */
   while((GET_BIT(SYSTICK->STK_CTRL,16)) == 0);

   /* Stop Timer */
	SET_BIT(SYSTICK->STK_CTRL, 0);

	SYSTICK->STK_LOAD = 0;

	SYSTICK->STK_VAL = 0;


}

u32 MSTK_u32GetCounterValue( void )
{
	return SYSTICK->STK_VAL ;
}


void MSTK_voidDelayMs(u32 Copy_u32TimeMs)
{
	u32 Local_u32Ticks;

	/* Assuming AHB = 8MHz */

	Local_u32Ticks = Copy_u32TimeMs * 1000;

	SYSTICK->STK_LOAD = Local_u32Ticks - 1;

	SYSTICK->STK_VAL = 0;

	/* Disable Interrupt */

	CLR_BIT(SYSTICK->STK_CTRL, STK_TICKINT);

	/* Enable */

	SET_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

	/* Wait Until COUNTFLAG = 1 */

	while(GET_BIT(SYSTICK->STK_CTRL, STK_COUNTFLAG) == 0);

	/* Stop */

	CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

	/* Enable Interrupt Again */

	SET_BIT(SYSTICK->STK_CTRL, STK_TICKINT);
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{

    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    SYSTICK->STK_VAL = 0;

    SYSTICK-> STK_LOAD = Copy_u32Ticks - 1;

    MSTK_CallBack = Copy_ptr;

    SET_BIT(SYSTICK->STK_CTRL, STK_TICKINT);

    SET_BIT(SYSTICK->STK_CTRL, STK_ENABLE);
}

void SysTick_Handler(void)
{
//    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    if(MSTK_CallBack != 0)
    {
        MSTK_CallBack();
    }
}
u32 MSTK_u32GetElapsedTime(void)
{
    u32 Local_u32Load;
    u32 Local_u32Current;

    Local_u32Load = SYSTICK->STK_LOAD;
    Local_u32Current = SYSTICK->STK_VAL;

    return (Local_u32Load - Local_u32Current);
}


void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    SYSTICK->STK_VAL = 0;

    SYSTICK->STK_LOAD = Copy_u32Ticks - 1;

    MSTK_CallBack = Copy_ptr;

    SET_BIT(SYSTICK->STK_CTRL, STK_TICKINT);

    SET_BIT(SYSTICK->STK_CTRL, STK_ENABLE);
}


u8 MSTK_u8ReadFlag( void ){

	return ( GET_BIT( MSTK->CTRL , 16 ) );

}
