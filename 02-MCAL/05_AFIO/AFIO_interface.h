/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 1  MAY   2026    ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : EXTI_INTERFACE_H ---------------------- */
/**************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

void MAFIO_voidSetEXTIConfiguration(u8 copy_u8EXTILine , u8 copy_u8PortMap);

#define AFIO_PA     0
#define AFIO_PB     1
#define AFIO_PC     2

#endif
