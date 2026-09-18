/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 30  APRIL   2026  ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : USART_INTERFACE_H ---------------------- */
/**************************************************************************/

#ifndef _USART_INTERFACE_H
#define _USART_INTERFACE_H

#define  USART1      1
#define  USART2      2
#define  USART3      3


#define  USART_BAUDRATE_9600           9600
#define  USART_BAUDRATE_19200          19200
#define  USART_BAUDRATE_38400          38400
#define  USART_BAUDRATE_57600          57600
#define  USART_BAUDRATE_115200         115200


#define  USART_DATA_8_BITS     8
#define  USART_DATA_9_BITS     9


#define  USART_STOP_1_BIT      1
#define  USART_STOP_2_BIT      2

#define  USART_PARITY_DISABLED      0 
#define  USART_PARITY_EVEN          1
#define  USART_PARITY_ODD           2
#define  USART_STOP_2_ODD           3

#define USART_DMA_DISABLED          0
#define USART_DMA_RX                1  
#define USART_DMA_TX                2
#define USART_DMA_RX_TX             3

   /* USART APIS  */

void USART_Init(u8 Copy_u8USART, u32 Copy_u32BaudRate, u8 Copy_u8DataBits, u8 Copy_u8StopBits, u8 Copy_u8Parity);
void USART_SendChar(u8 Copy_u8USART, u8 Copy_u8Data);
u8 USART_ReceiveChar(u8 Copy_u8USART);
void USART_SendString(u8 Copy_u8USART, const char *Copy_pchString);


#endif