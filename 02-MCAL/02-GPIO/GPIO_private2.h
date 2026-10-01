/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 30  APRIL   2026 ---------------------- */
/* --------------- Version      : V02             ---------------------- */
/* --------------- Description  : GPIO_PRIVATE_H  ---------------------- */
/*************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

typedef struct{

	volatile u32 CRL  ;//0x00
	volatile u32 CRH  ;//0x04
	volatile u32 IDR  ;//0x08
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO;

#define MGPIOA ((volatile GPIO*)0x40010800)
#define MGPIOB ((volatile GPIO*)0x40010C00)
#define MGPIOC ((volatile GPIO*)0x40011000)


#endif
