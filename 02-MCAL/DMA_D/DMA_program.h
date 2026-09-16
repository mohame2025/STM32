/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 2 APRIL 2026 --------------------------- */
/* --------------- Version      : V01 ----------------------------------- */
/* --------------- Description  : DAM_Program_C ------------------------- */
/*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DAM_INTERFACE.h"
#include "DAM_privet.h"
#include "DAM_confg.h"


void  MDMA_voidChannelInit(void)
{
	/*  
      1- mem to mem
	  2- very high
	  3- source size , destination size =32 bit
      4- MIN , PINK activated
	  5- no circuiler
	  6- direction 
	  7- transfer interrupt enable
	  */
	  
	#if  CHANNLE_ID   == 1
	 DMA -> Channel[0].CCR = 
	
	
	
}

void  MDMA_voidChannelStart(u32 * Copy_Pu32SorceAdress, u32 * Copy_Pu32DestinationAdress, u16  Copy_u16BlockLength)
{
	
	/* Make sure channel is disabled   */
	CLR_BIT(DMA -> Channle[0].CCR , 0);
	/*  write the address  */
	DMA -> Channel[0].CPAR = Copy_Pu32SorceAdress ;
	DMA -> Channel[0].CMAR = Copy_Pu32DestinationAdress ;
	/*  Block length  */
	DMA -> Channel[0].CNDTR = Copy_u16BlockLength;
	
	/* Make sure channel is disabled   */
	SET_BIT(DMA -> Channle[0].CCR , 0);
}

