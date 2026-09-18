/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 7  MARCH  2026  ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : RCC_PRIVATE_H   ---------------------- */
/*************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/* Register Definitions */
#define RCC_CR         *((u32*)0x40021000) // input enabule clock   
#define RCC_CFGR       *((u32*)0x40021004) // input enabule clock   
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014) //   enabule desuble clock
#define RCC_APB2ENR    *((u32*)0x40021018) //   enabule desuble clock
#define RCC_APB1ENR    *((u32*)0x4002101C) //   enabule desuble clock
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC__CSR       *((u32*)0x40021024)


/* Clock Types*/
#define  RCC_HSE_CRYSTAL       0
#define  RCC_HSE_RC            1
#define	 RCC_HSI               2
#define	 RCC_PLL               3
	           
/* PLL Option */
#define RCC_PLL_IN_HSI_DIV_2   0
#define RCC_PLL_IN_HSE_DIV_2   1 
#define RCC_PLL_IN_HSE         2


#endif
