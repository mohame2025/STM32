/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 1  MAY   2026    ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : NVIC_INTERFACE_H ---------------------- */
/**************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt(u8 copy_u8InterruptNumber);
void MNVIC_voidDisableInterrupt(u8 copy_u8InterruptNumber);
void MNVIC_voidSetpendingflag(u8 copy_u8InterruptNumber);
void MNVIC_voidClearpendingflag(u8 copy_u8InterruptNumber);
u8 MNVIC_u8GetActiveflag(u8 copy_u8InterruptNumber);
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 copy_PeripheralIdx, u8 copy_u8Priority);

#endif
