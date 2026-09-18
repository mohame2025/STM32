/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 30 APRIL 2026 --------------------------- */
/* --------------- Version      : V01 ---------------------------------- */
/* --------------- Description  : USART_CONFIG_H --------------------------- */
/*************************************************************************/

#ifndef _USART_CONFG_H
#define _USART_CONFG_H

/* USART Peripheral Clock */
#define USART_DEFAULT_CLOCk_HZ          8000000UL

/* Default USART */
#define USART_DEFAULT                   USART1

/* Default Baud Rate */
#define USART_DEFAULT_BAUDATE           9600

/* Default Date Bits */
#define USART_DEFAULT_STOP_BITS         USART_STOP_1_BIT

/* Default Parity */
#define USART_DEFAULT_PARITY            USART_PARITY_DISABLED

/* Default DMA configurtion  */
#define USART_DEFAULT_DMA               USART_DMA_RX_TX


#endif