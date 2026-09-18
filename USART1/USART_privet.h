/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 30 APRIL 2026 --------------------------- */
/* --------------- Version      : V01 ---------------------------------- */
/* --------------- Description  : USART_PRIVET_H -------------------------- */
/*************************************************************************/

#ifndef _USART_PRIVET_H
#define _USART_PRIVET_H


typedef struct
{
	
   volatile	 u32 SR;
   volatile  u32 DR;
   volatile  u32 BRR;
   volatile  u32 CR1;
   volatile  u32 CR2;
   volatile  u32 CR3;
   volatile  u32 GTPR;
   
}USART_t;


#define  MUSART1  ((volatile  USART_t *)0x40013800) 
#define  MUSART2  ((volatile  USART_t *)0x40004400)

#define  MUSART3  ((volatile  USART_t *)0x40004800)
#define  MUSART4  ((volatile  USART_t *)0x40004C00)

#define  MUSART5  ((volatile  USART_t *)0x40005000)

/********************************************/

 /*  Status register (USART_SR) */
 
#define   USART_SR_PE       0
#define   USART_SR_FE       1
#define   USART_SR_NE       2
#define   USART_SR_ORE      3
#define   USART_SR_IDLE     4
#define   USART_SR_TXE      5
#define   USART_SR_TC       6
#define   USART_SR_RXNE     7
#define   USART_SR_LBD      8
#define   USART_SR_CTS      9

/******************************************/

/* Baud rate register (USART_BRR) */
  /* DIV : BIT 3:0   */
#define    USART_BRR_DIV_Fraction_POS            0
#define    USART_BRR_DIV_Fraction_MASK          0x000F
 
   /* DIV : BIT 15:4   */
#define    USART_BRR_DIV_Mantissa_POS            4
#define    USART_BRR_DIV_Mantissa_MASK          0xFFF0

/*******************************************/

/*  Control register 1 (USART_CR1) */        

#define   USART_CR1_SBK           0
#define   USART_CR1_RWU           1
#define   USART_CR1_RE            2
#define   USART_CR1_TE            3
#define   USART_CR1_IDLEIE        4
#define   USART_CR1_RXNEIE        5
#define   USART_CR1_TCIE          6
#define   USART_CR1_TXEIE         7
#define   USART_CR1_PEIE          8
#define   USART_CR1_PS            9
#define   USART_CR1_PCE           10
#define   USART_CR1_WAKE          11
#define   USART_CR1_M             12
#define   USART_CR1_UE            13

/**********************************************/

 /*  Control register 2 (USART_CR2) */

  /* ADD : BIT 3:0   */
#define   USART_CR2_ADD_POS            0
#define   USART_CR2_ADD_MASK           0x000F


#define   USART_CR2_LBDL            5
#define   USART_CR2_LBDIE           6
#define   USART_CR2_LBCL            8
#define   USART_CR2_CPHA            9
#define   USART_CR2_CPOL            10
#define   USART_CR2_CLKEN           11


  /* ADD : BIT 13:12   */
#define   USART_CR2_STOP_POS            12
#define   USART_CR2_STOP_MASK           0x3000

#define   USART_CR2_LINEN            14

/*************************************************/


/* Control register 3 (USART_CR3) */

#define   USART_CR3_EIE             0
#define   USART_CR3_IREN            1
#define   USART_CR3_IRLP            2
#define   USART_CR3_HDSEL           3
#define   USART_CR3_NACK            4
#define   USART_CR3_SCEN            5
#define   USART_CR3_DMAR            6
#define   USART_CR3_DMAT            7
#define   USART_CR3_RTSE            8
#define   USART_CR3_CTSE            9
#define   USART_CR3_CTSIE           10


#endif