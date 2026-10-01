/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 20 APRIL 2026 --------------------------- */
/* --------------- Version      : V01 ---------------------------------- */
/* --------------- Description  : DAM_PRIVET_H -------------------------- */
/*************************************************************************/

#ifndef _DAM_PRIVET_H
#define _DAM_PRIVET_H

typedef struct
{
	volatile	 u32 CCR;
	volatile	 u32 CNDTR;
	volatile	 u32 CPAR;
	volatile	 u32 CMAR;
	volatile	 u32 Reserved;
	
}DMA_Channel;

typedef struct
{
	
   volatile	 u32 DMA_ISR;
   volatile  u32 DMA_IFCR;
   DMA_Channel Channel[7];
}DMA_t;


#define  DMA  ((volatile  DMA_t *)0x4002 0000) 

/*
#define DMA_ISR          ((volatile u32)0x40012400)
#define DMA_IFCR         ((volatile u32)0x40012404)
#define DMA_CCR1         ((volatile u32)0x40012408)
#define DMA_CNDTR1       ((volatile u32)0x4001240C)
#define DMA_CPAR1        ((volatile u32)0x40012410)
#define DMA_CMAR1        ((volatile u32)0x40012414)
#define DMA_CCR2         ((volatile u32)0x40012418)
#define DMA_CNDTR2       ((volatile u32)0x4001241C)
#define DMA_CPAR2        ((volatile u32)0x40012420)
#define DMA_CMAR2        ((volatile u32)0x40012424)
#define DMA_CCR3         ((volatile u32)0x40012428)
#define DMA_CNDTR3       ((volatile u32)0x4001242C)
#define DMA_CPAR3        ((volatile u32)0x40012430)
#define DMA_CMAR3        ((volatile u32)0x40012434)
#define DMA_CCR4         ((volatile u32)0x40012438)
#define DMA_CNDTR4       ((volatile u32)0x4001243C)
#define DMA_CPAR4        ((volatile u32)0x40012440)
#define DMA_CMAR4        ((volatile u32)0x40012444)
#define DMA_CCR5         ((volatile u32)0x40012448)
#define DMA_CNDTR5       ((volatile u32)0x4001244C)
#define DMA_CPAR5        ((volatile u32)0x4001244C)
#define DMA_CMAR5        ((volatile u32)0x4001244C)
#define DMA_CCR6         ((volatile u32)0x4001244C)
#define DMA_CNDTR6       ((volatile u32)0x4001244C)
#define DMA_CPAR6        ((volatile u32)0x4001244C)
#define DMA_CMAR6        ((volatile u32)0x4001244C)
#define DMA_CCR7         ((volatile u32)0x4001244C)
#define DMA_CNDTR7       ((volatile u32)0x4001244C)
#define DMA_CPAR7        ((volatile u32)0x4001244C)
#define DMA_CMAR7        ((volatile u32)0x4001244C)
*/



#endif