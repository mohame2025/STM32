/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 1  MAY   2026    ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : EXTI_INTERFACE_H ---------------------- */
/**************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Line nd Mode */
void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 copy_u8Line);
void MEXTI_voidDisableEXTI(u8 copy_u8Line);
void MEXTI_voidSwTrigger(u8 copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 copy_u8Line, u8 copy_u8Mode);
void MEXTI_voidClearPendingFlag(u8 copy_u8Line);

#define  RISING       0
#define  FALLING_EDGE       1
#define  ON_ChANGE    2

#endif
