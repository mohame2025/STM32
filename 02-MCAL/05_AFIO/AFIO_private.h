/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 1  MAY   2026   ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : EXTI_PRIVATE_H  ---------------------- */
/*************************************************************************/

/*************************************************************************/
/*  guard of file will call one time i .c                               **/
/*************************************************************************/


#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct{
 
    volatile u32 EVCR; 
    volatile u32 EXTICR[4];
	volatile u32 MAPR2;
	/*
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
    */

}AFIO_t;


#define AFIO ((volatile AFIO_t *) 0x40010000 )




#endif
