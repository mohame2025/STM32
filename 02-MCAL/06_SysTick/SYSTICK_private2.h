/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 12  MAY   2026   ---------------------- */
/* --------------- Version      : V02             ---------------------- */
/* --------------- Description  : SYSTICK_PRIVATE_H  ---------------------- */
/*************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


typedef struct{

  volatile u32  STK_CTRL;
  volatile u32  STK_LOAD;
  volatile u32  STK_VAL;
  volatile u32  STK_CALIB ;

}SYSTICK_t;

 
#define SYSTICK ((volatile SYSTICK_t *)0xE000E010)


#define STK_ENABLE             0
#define STK_TICKINT            1
#define STK_CLKSOURCE          2
#define STK_COUNTFLAG          16


#endif
