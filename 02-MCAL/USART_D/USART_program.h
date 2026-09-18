/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 30 APRIL 2026 --------------------------- */
/* --------------- Version      : V01 ----------------------------------- */
/* --------------- Description  : USART_Program_C ------------------------- */
/*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_INTERFACE.h"
#include "USART_privet.h"
#include "USART_confg.h"


while(GET_BIT(MUSART1->SR, USART_SR_TXE) == 0)
{
	
}

SET_BIT(MUSART1->CR1,USART_CR1_UE);
SET_BIT(MUSART1->CR1,USART_CR1_TE);
SET_BIT(MUSART1->USART_CR1_RE);


