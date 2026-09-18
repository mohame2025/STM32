/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 8  MAY   2026    ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : SYSTICK_INTERFACE_H ---------------------- */
/**************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


void MSTK_voidInit(void);
void MSTK_voidStart(u32 copy_u32Load);
void MSTK_voidStop(void);
void MSTK_voidDelayMs(u32 Copy_u32TimeMs);

#endif
