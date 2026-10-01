/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 10  MAY   2026    ---------------------- */
/* --------------- Version      : V02              ---------------------- */
/* --------------- Description  : EXTI_INTERFACE_H ---------------------- */
/**************************************************************************/



#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Line nd Mode */
void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(u8 copy_u8EXTILine, u8 copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI(u8 copy_u8EXTILine);
void MEXTI_voidDisableEXTI(u8 copy_u8EXTILine);
void MEXTI_voidSwTrigger(u8 copy_u8EXTILine);
void MEXTI_voidSetCallBack(void (*ptr) (void));


// void MEXTI_voidClearPendingFlag(u8 copy_u8EXTILine);


#define  RISING             0
#define  FALLING_EDGE       1
#define  ON_ChANGE          2


#endif
