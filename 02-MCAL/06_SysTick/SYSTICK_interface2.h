/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 12  MAY   2026    ---------------------- */
/* --------------- Version      : V02              ---------------------- */
/* --------------- Description  : SYSTICK_INTERFACE_H ---------------------- */
/**************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


void(*callback)(void);
void MSTK_voidInit(void);
void MSTK_voidSetBusWait(u32 copy_u32Ticks);
void MSTK_voidSetIntervalSingle  (u32 copy_u32Ticks, void (*copy_ptr)(void);

void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr)(void);
void MSTK_voidStopInterval(void);
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);

#endif

