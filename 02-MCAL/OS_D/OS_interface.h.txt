/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 2  APRIL   2026  ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : GPIO_INTERFACE_H ---------------------- */
/**************************************************************************/

#ifndef _OS_INTERFACE_H
#define _OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Priodicity ,   void (*ptr) (void) , u8 Copy_u8firstDelay );
void SOS_voidStart(void);


#endif