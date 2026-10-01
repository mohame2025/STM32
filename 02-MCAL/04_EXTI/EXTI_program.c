/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 1  MAY   2026   ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : EXTI_Program_C  ---------------------- */
/*************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



void MEXTI_voidInit()
{

   #if EXTI_MODE == RISING
   SET_BIT(EXTI  -> RTSR , EXTI_LINE); 
   #elif EXTI_MODE == FALING 
   SET_BIT(EXTI   -> FTSR , EXTI_LINE);
   #elif EXTI_MODE  ==  ON_ChANGE
   SET_BIT(EXTI   -> RTSR , EXTI_LINE);
   SET_BIT(EXTI   -> FTSR , EXTI_LINE);
   #else
   #error "Wrong Mode and Line choice"
   #endif
   /* Disable interrupt */
   CLR_BIT(EXTI  -> IMR , EXTI_LINE);
   
}


void MEXTI_voidEnableEXTI(u8 copy_u8Line)
{
    SET_BIT(EXTI -> IMR , copy_u8Line);

}

void MEXTI_voidDisableEXTI(u8 copy_u8Line)
{
    CLR_BIT(EXTI -> IMR , copy_u8Line);

}
void MEXTI_voidSwTrigger(u8 copy_u8Line)
{

    SET_BIT(EXTI -> SWIER ,  copy_u8Line);

}
void MEXTI_voidSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode)
{

   switch(copy_u8Mode)
  {
    case RISING       :  SET_BIT(EXTI  -> RTSR , EXTI_LINE); break;
    case  FALLING_EDGE :	 SET_BIT(EXTI  -> FTSR , EXTI_LINE); break;
    case ON_ChANGE    :  SET_BIT(EXTI  -> RTSR , EXTI_LINE);
                         SET_BIT(EXTI  -> FTSR , EXTI_LINE); break;
  }
}


void MEXTI_voidClearPendingFlag(u8 copy_u8Line)
{
	SET_BIT(EXTI -> PR ,  copy_u8Line);

}
