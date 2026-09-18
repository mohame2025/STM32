/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 10  MAY   2026   ---------------------- */
/* --------------- Version      : V02             ---------------------- */
/* --------------- Description  : EXTI_Program_C  ---------------------- */
/*************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
 /*  arrer 2 faction */
//static void (*EXTI0_CallBack[16])(void) = NULL;

static void (* EXTI0_CallBack)(void) = 0;


void MEXTI_voidInit(void)

{
    #if   EXTI_LINE == EXTI_LINE0
         SET_BIT(EXTI -> IMR,  EXTI_LINE0);  
    #elif EXTI_LINE == EXTI_LINE1
          SET_BIT(EXTI -> IMR, EXTI_LINE1);
    #elif EXTI_LINE == EXTI_LINE2
          SET_BIT(EXTI -> IMR, EXTI_LINE2);
    #else 
         #error ("wrong Externl Intrrupt  Line !") 
    #endif
	
	
	
	
	#if   EXTI_SENSE_MODE == FALLING_EDGE
          SET_BIT(EXTI   -> FTSR , EXTI_LINE);
    #elif EXTI_SENSE_MODE == RISING
          SET_BIT(EXTI  -> RTSR , EXTI_LINE);
    #elif EXTI_SENSE_MODE == ON_CHANGE
          SET_BIT(EXTI   -> RTSR , EXTI_LINE);
          SET_BIT(EXTI   -> FTSR , EXTI_LINE);
	#else 
         #error ("wrong Externl Intrrupt  Line Sense Mode!") 
    #endif

}
void MEXTI_voidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode)
{
   switch(copy_u8EXTISenseMode)
  {
    case  RISING        :  SET_BIT(EXTI  -> RTSR , EXTI_LINE); break;
    case  FALLING_EDGE  :  SET_BIT(EXTI  -> FTSR , EXTI_LINE); break;
    case  ON_ChANGE     :  SET_BIT(EXTI  -> RTSR , EXTI_LINE);
                           SET_BIT(EXTI  -> FTSR , EXTI_LINE); break;
  }   
   SET_BIT(EXTI -> IMR, copy_u8EXTILine);
}


void MEXTI_voidEnableEXTI(u8 copy_u8EXTILine)
{
    SET_BIT(EXTI -> IMR , copy_u8EXTILine);
}

void MEXTI_voidDisableEXTI(u8 copy_u8EXTILine)
{
	CLR_BIT(EXTI -> IMR , copy_u8EXTILine);
}

void MEXTI_voidSwTrigger(u8 copy_u8EXTILine)
{
	SET_BIT(EXTI -> SWIER ,  copy_u8EXTILine);
	
}
void MEXTI_voidSetCallBack(void (*ptr) (void))
{
    EXTI0_CallBack = ptr; //ahmed
  
}

void EXTI0_IRQHandler(void)  //ISR
{
	EXTI0_CallBack();	//ahmed();
	
	/* ClearPendingBit */
	SET_BIT(EXTI -> PR ,  0);
}



