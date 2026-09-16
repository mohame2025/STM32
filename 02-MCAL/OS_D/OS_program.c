/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 2  APRIL   2026 ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : OS_Program_C  ---------------------- */
/*************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"


#include "OS_interface.h"
#include "OS_privet.h"
#include "OS_config.h"



void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Priodicity ,   void (*ptr) (void) )
{
        OS_Tasks[Copy_u8ID].priodicity  = Copy_u16Priodicity ;
        OS_Tasks[Copy_u8ID].Fptr  = ptr ;
}

void SOS_voidStart(void)
{
   /*  Intialization  */
     MSTK_voidInit();
     
   /*  Tick  => msec  */
   /* HSE  8MHZ / 8  ===> 1000 Micro sec  ===> 1m sec    */
   MSTK_voidSetintervalPeriodic(1000,Scheduler)   
   
}
volatile u16 TickCounts = 0 ; 

/*
void Scheduler(void)
{
   

  for(u8 i = 0; i < NUMBER_OF_TASKS; i++)
  {
     if(TickCounts % OS_Tasks[i].priodicity == 0)
      {
	    OS_Tasks[i].Fptr();
	  }
  }
  TickCounts++;
}
*/


void Scheduler(void)
{

   for(u8 i = 0; i < NUMBER_OF_TASKS; i++)
   {
      if((OS_Tasks[i].Fptr != NULL) && (OS_Tasks[i].state == TASK_READY))
       {
	     if(OS_Tasks[i].firstDelay == 0)
		 { 
           OS_Tasks[i].firstDelay = OS_Tasks[i].priodicity-1; 		
	       OS_Tasks[i].Fptr();
	     }
	     else
	     {
		 
	      OS_Tasks[i].firstDelay--;
	     }
       } 
   } 
}







