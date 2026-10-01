/*************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 8 MAY 2026 --------------------------- */
/* --------------- Version      : V01 ---------------------------------- */
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

void MSTK_voidInit(void)
{
	/* Disable SysTick First */

	CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

	/* Clock Source = AHB */

	SET_BIT(SYSTICK->STK_CTRL, STK_CLKSOURCE);

	/* Enable Interrupt */

	SET_BIT(SYSTICK->STK_CTRL, STK_TICKINT);
}

/*************************/
/* Function : MSTK_voidStart                                             */
/* Description : Start SysTick                                           */
/*************************/

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

void MSTK_voidDelayMs(u32 Copy_u32TimeMs)
{
	u32 Local_u32Ticks;

	/* Assuming AHB = 8MHz */

	Local_u32Ticks = Copy_u32TimeMs * 8000;

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
