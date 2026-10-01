/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 2  APRIL   2026 ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : GPIO_PRIVATE_H  ---------------------- */
/*************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

#define      GPIOA_BASE_ADDRESS          0x40010800 
#define      GPIOB_BASE_ADDRESS          0x40010C00        
#define      GPIOC_BASE_ADDRESS          0x40011000

                  /*   REGISTERS ADDRESSES FOR PORTA */
#define      GPIOA_CRL          *((u32 *)(GPIOA_BASE_ADDRESS  + 0x00)) //  LOW   
#define      GPIOA_CRH          *((u32 *)(GPIOA_BASE_ADDRESS  + 0x04)) //  HIGH
#define      GPIOA_IDR          *((u32 *)(GPIOA_BASE_ADDRESS  + 0x08)) //  GET_BIT
#define      GPIOA_ODR          *((u32 *)(GPIOA_BASE_ADDRESS  + 0x0C)) // SET_BIT
#define      GPIOA_BSRR         *((u32 *)(GPIOA_BASE_ADDRESS  + 0x10))
#define      GPIOA_BRR          *((u32 *)(GPIOA_BASE_ADDRESS  + 0x14))
#define      GPIOA_LCKR         *((u32 *)(GPIOA_BASE_ADDRESS  + 0x18))


                  /*   REGISTERS ADDRESSES FOR PORTB */
#define      GPIOB_CRL          *((u32 *)(GPIOB_BASE_ADDRESS  + 0x00))
#define      GPIOB_CRH          *((u32 *)(GPIOB_BASE_ADDRESS  + 0x04))
#define      GPIOB_IDR          *((u32 *)(GPIOB_BASE_ADDRESS  + 0x08))
#define      GPIOB_ODR          *((u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define      GPIOB_BSRR         *((u32 *)(GPIOB_BASE_ADDRESS  + 0x10))
#define      GPIOB_BRR          *((u32 *)(GPIOB_BASE_ADDRESS  + 0x14))
#define      GPIOB_LCKR         *((u32 *)(GPIOB_BASE_ADDRESS  + 0x18))


                 /*   REGISTERS ADDRESSES FOR PORTC */
#define      GPIOC_CRL          *((u32 *)(GPIOC_BASE_ADDRESS  + 0x00))
#define      GPIOC_CRH          *((u32 *)(GPIOC_BASE_ADDRESS  + 0x04))
#define      GPIOC_IDR          *((u32 *)(GPIOC_BASE_ADDRESS  + 0x08))
#define      GPIOC_ODR          *((u32 *)(GPIOC_BASE_ADDRESS  + 0x0C))
#define      GPIOC_BSRR         *((u32 *)(GPIOC_BASE_ADDRESS  + 0x10))
#define      GPIOC_BRR          *((u32 *)(GPIOC_BASE_ADDRESS  + 0x14))
#define      GPIOC_LCKR         *((u32 *)(GPIOC_BASE_ADDRESS  + 0x18))


#endif
