/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 30  MAY   2026   ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : LEDMRX_Program_C  ---------------------- */
/*************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"



void HLEDMRX_voidInit(void)
{
   MGPIO_voidSetpinDirection(LEDMRX_ROW0_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_ROW1_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_ROW2_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_ROW3_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_ROW4_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_ROW5_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_ROW6_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_ROW7_PIN, 0b0010);
   
   MGPIO_voidSetpinDirection(LEDMRX_COL0_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_COL1_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_COL5_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_COL6_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_COL7_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_COL8_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_COL9_PIN, 0b0010);
   MGPIO_voidSetpinDirection(LEDMRX_COL10_PIN, 0b0010);
}


void HLEDMRX_voiDisplay(u8 *copy_u8Date)
{
    while(1)
	{
    
   /*  columns 0*/
   DisableAllCols();
   /* Enable all columns */ 
   SetRowValues(copy_u8Date[0]);
   MGPIO_voidSetpinValue(LEDMRX_COL0_PIN, GPIO_LOW);
   MSTK_voidSetBusWait(2500);//2.5 MSEC
  
  /*  columns 1*/
  DisableAllCols();
  /* Enable all columns */ 
  SetRowValues(copy_u8Date[1]);
  MGPIO_voidSetpinValue(LEDMRX_COL1_PIN, GPIO_LOW);
  MSTK_voidSetBusWait(2500);//2.5 MSEC
  
  
  
  /*  columns 2*/
  DisableAllCols();
  /* Enable all columns */ 
  SetRowValues(copy_u8Date[2]);
  MGPIO_voidSetpinValue(LEDMRX_COL2_PIN, GPIO_LOW);
  MSTK_voidSetBusWait(2500);//2.5 MSEC
  
  
  
  /*  columns 3*/
  DisableAllCols();
  /* Enable all columns */ 
  SetRowValues(copy_u8Date[3]);
  MGPIO_voidSetpinValue(LEDMRX_COL3_PIN, GPIO_LOW);
  MSTK_voidSetBusWait(2500);//2.5 MSEC
  
  
  
  /*  columns 4*/
  DisableAllCols();
  /* Enable all columns */ 
  SetRowValues(copy_u8Date[4]);
  MGPIO_voidSetpinValue(LEDMRX_COL4_PIN, GPIO_LOW);
  MSTK_voidSetBusWait(2500);//2.5 MSEC
  
  
  /*  columns 5*/
  DisableAllCols();
  /* Enable all columns */ 
  SetRowValues(copy_u8Date[5]);
  MGPIO_voidSetpinValue(LEDMRX_COL5_PIN, GPIO_LOW);
  MSTK_voidSetBusWait(2500);//2.5 MSEC
  
  
  /*  columns 6*/
  DisableAllCols();
  /* Enable all columns */ 
  SetRowValues(copy_u8Date[6]);
  MGPIO_voidSetpinValue(LEDMRX_COL6_PIN, GPIO_LOW);
  MSTK_voidSetBusWait(2500);//2.5 MSEC
  
  /*  columns 7*/
  DisableAllCols();
  /* Enable all columns */ 
 }SetRowValues(copy_u8Date[7]);
  MGPIO_voidSetpinValue(LEDMRX_COL7_PIN, GPIO_LOW);
  MSTK_voidSetBusWait(2500);//2.5 MSEC
  
 } 
}  
  
static void DisableAllCols(void)
{

    /* Disable all columns */ 

  MGPIO_voidSetpinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
  MGPIO_voidSetpinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
  MGPIO_voidSetpinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
  MGPIO_voidSetpinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
  MGPIO_voidSetpinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
  MGPIO_voidSetpinValue(LEDMRX_COL8_PIN, GPIO_HIGH);
  MGPIO_voidSetpinValue(LEDMRX_COL9_PIN, GPIO_HIGH);
  MGPIO_voidSetpinValue(LEDMRX_COL10_PIN,GPIO_HIGH);

}

static void SetRowValues(u8 copy_u8Value)

{
   u8 Local_u8BIT;

  Local_u8BIT = GET_BIT(copy_u8Value,0)
  MGPIO_voidSetpinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
  
  Local_u8BIT = GET_BIT(copy_u8Value,1)
  MGPIO_voidSetpinValue(LEDMRX_ROW1_PIN, Local_u8BIT);
  
  Local_u8BIT = GET_BIT(copy_u8Value,2)
  MGPIO_voidSetpinValue(LEDMRX_ROW2_PIN, Local_u8BIT);
  
  Local_u8BIT = GET_BIT(copy_u8Value,3)
  MGPIO_voidSetpinValue(LEDMRX_ROW3_PIN, Local_u8BIT);
  
  Local_u8BIT = GET_BIT(copy_u8Value,4)
  MGPIO_voidSetpinValue(LEDMRX_ROW4_PIN, Local_u8BIT);
  
  Local_u8BIT = GET_BIT(copy_u8Value,5)
  MGPIO_voidSetpinValue(LEDMRX_ROW5_PIN, Local_u8BIT);
  
  Local_u8BIT = GET_BIT(copy_u8Value,6)
  MGPIO_voidSetpinValue(LEDMRX_ROW6_PIN, Local_u8BIT);
  
  Local_u8BIT = GET_BIT(copy_u8Value,7)
  MGPIO_voidSetpinValue(LEDMRX_ROW7_PIN, Local_u8BIT);
  
  
}  
  