/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 2  APRIL   2026 ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : GPIO_PRIVATE_H  ---------------------- */
/*************************************************************************/



#ifndef _OS_PRIVATE_H
#define _OS_PRIVATE_H


#define   NULL    (void *)0
/* Arre of tasks "Arre of Structure"     */
static Task OS_Tasks[NUMBER_OF_TASKS]  = { NULL };


typedef struct
{
  u16 priodicity        ;
  void (*Fptr) (void)   ;
  u8 firstDelay;
  u8 State ;

}Task;




#endif