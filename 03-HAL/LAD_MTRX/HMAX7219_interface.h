/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 30  MAY   2026    ---------------------- */
/* --------------- Version      : V02              ---------------------- */
/* --------------- Description  : LEDMRX_INTERFACE_H ---------------------- */
/**************************************************************************/

#ifndef HMAX7219_INTERFACE_H
#define HMAX7219_INTERFACE_H

void HMAX7219_voidInit(void);
void HMAX7219_voidSendData(u8 Copy_u8Address , u8 Copy_u8Data);
void HMAX7219_voidClearDisplay(void);
void HMAX7219_voidDisplayPattern(u8 *Copy_u8Pattern);

#endif