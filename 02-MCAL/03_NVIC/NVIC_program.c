/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 1  MAY   2026   ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : NVIC_Program_C  ---------------------- */
/*************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{
    #define SCB_AIRCR *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUB_SUB_DISTRIBUTION;
}

void MNVIC_voidSetPriority(u8 copy_PeripheralIdx, u8 copy_u8Priority)
{
	if(copy_PeripheralIdx < 60)
	{
		NVIC_IPR[copy_PeripheralIdx] = copy_u8Priority;

	}
	else{

		/* Report Error  */

	}

}

void MNVIC_voidEnableInterrupt(u8 copy_u8InterruptNumber)
{

   if(copy_u8InterruptNumber <= 31)
   {
       NVIC_ISER0 = (1 << copy_u8InterruptNumber);
   }

   else if(copy_u8InterruptNumber <= 59)
   {
       copy_u8InterruptNumber -= 32;
      NVIC_ISER1 = (1 << copy_u8InterruptNumber);
   }
   
   else
   {
      /* Return Error */
   }
}
 


void MNVIC_voidDisableInterrupt(u8 copy_u8InterruptNumber)
{

   if(copy_u8InterruptNumber <= 31)
   {
       NVIC_ICER0 = (1 << copy_u8InterruptNumber);
   }

   else if(copy_u8InterruptNumber <= 59)
   {
       copy_u8InterruptNumber -= 32;
      NVIC_ICER1 = (1 << copy_u8InterruptNumber);
   }
   
   else
   {
      /* Return Error */
   }
}



void MNVIC_voidSetpendingflag(u8 copy_u8InterruptNumber)
{


   if(copy_u8InterruptNumber <= 31)
   {
       NVIC_ISPR0 = (1 << copy_u8InterruptNumber);
   }

   else if(copy_u8InterruptNumber <= 59)
   {
       copy_u8InterruptNumber -= 32;
      NVIC_ISPR1 = (1 << copy_u8InterruptNumber);
   }
   
   else
   {
      /* Return Error */
   }

}


void MNVIC_voidClearpendingflag(u8 copy_u8InterruptNumber)
{


   if(copy_u8InterruptNumber <= 31)
   {
       NVIC_ICPR0 = (1 << copy_u8InterruptNumber);
   }

   else if(copy_u8InterruptNumber <= 59)
   {
       copy_u8InterruptNumber -= 32;
      NVIC_ICPR1 = (1 << copy_u8InterruptNumber);
   }
   
   else
   {
      /* Return Error */
   }

}




u8 MNVIC_u32GetActiveflag(u8 copy_u8InterruptNumber)
{
       u8 Locals_u8Result1;

  if(copy_u8InterruptNumber <= 31)
  {
       Locals_u8Result1 = GET_BIT(NVIC_IABR0, copy_u8InterruptNumber);
  }

  else if(copy_u8InterruptNumber <= 59)
  {
      copy_u8InterruptNumber -= 32;
      Locals_u8Result1 = GET_BIT(NVIC_IABR1, copy_u8InterruptNumber);
  }

  else
  {
     /* Return Error */
  }

}

