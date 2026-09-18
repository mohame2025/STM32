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



static volatile USART_t *USART_Select(u8 Copy_u8USART)
{
	volatile USART_t *Local_pUSART = 0;
	
	switch(Copy_u8USART)
	{
		case USART1:
		     Local_pUSART = MUSART1 ;break;
		case USART2:
		     Local_pUSART = MUSART2 ;break;
		case USART3:
		     Local_pUSART = MUSART3 ;break;
		
		default:
		  Local_pUSART = 0 ;break;
	}	
    return Local_pUSART;	
}


static u16 USART_CalculateBRR(u32 Copy_u32ClockHZ, u32 Copy_u32BaudRate)
{
	u32 Local_u32USARTDIV_X16;
	u16 Local_u16BBR;
	
	   Local_u32USARTDIV_X16 = (Copy_u32ClockHZ +(Copy_u32BaudRate / 2UL)) / Copy_u32BaudRate;

       Local_u16BBR = (u16)Local_u32USARTDIV_X16;         
       
	   return Local_u16BBR;
}     

static void USART_ConfigureCR1(volatile USART_t *Copy_pUSART, u8 Copy_u8DataBits, u8 Copy_u8Parity)
{
	 /* Disable USART before configuration */
	 CLR_BIT(Copy_pUSART->CR1,USART_CR1_UE);
	
	 /* Data Bits 8 or 9 */
    if(Copy_u8DataBits == USART_DATA_9_BITS)	
	{
	 SET_BIT(Copy_pUSART->CR1,USART_CR1_M);	
	}
    else
	{
      CLR_BIT(Copy_pUSART->CR1,USART_CR1_M);
	}

   /* parity configuration */
   
	if(Copy_u8Parity == USART_PARITY_DISABLED)
	{
	  CLR_BIT(Copy_pUSART->CR1,USART_CR1_PCE);	
	}
	else
	{
		SET_BIT(Copy_pUSART->CR1,USART_CR1_PCE);
	
	if(Copy_u8Parity == USART_PARITY_ODD)
	{
		SET_BIT(Copy_pUSART->CR1,USART_CR1_PS);
	}	
	
	else
	{
		CLR_BIT(Copy_pUSART->CR1,USART_CR1_PS);
		
	}
  }	
}


static void USART_ConfigureCR2(volatile USART_t *Copy_pUSART, u8 Copy_u8StopBits)
{
    Copy_pUSART->CR2 &=~ USART_CR2_STOP_MASK;
   
   if(Copy_u8StopBits == USART_STOP_2_BIT)
   {
	 Copy_pUSART->CR2 |= (2U << USART_CR2_STOP_POS)   
   }
   else
   {
	   Copy_pUSART->CR2 |= (0U << USART_CR2_STOP_POS)
   }
}



void USART_Init(u8 Copy_u8USART, u32 Copy_u32BaudRate, u8 Copy_u8DataBits, u8 Copy_u8StopBits, u8 Copy_u8Parity)
{
	
	   volatile USART_t *Local_pUSART;
	   u16 Local_u16BBR;
	   
	   Local_pUSART = USART_Select(Copy_u8USART);
	  
   if(Local_pUSART == 0)
    {
		return;
    }	
   
     Local_u16BBR =  USART_CalculateBRR(USART_DEFAULT_CLOCk_HZ, Copy_u32BaudRate);
     Local_pUSART->BRR = Local_u16BBR;	
	
	USART_ConfigureCR1(volatile USART_t *Copy_pUSART, u8 Copy_u8DataBits, u8 Copy_u8Parity);
	USART_ConfigureCR2(volatile USART_t *Copy_pUSART, u8 Copy_u8StopBits);
	
	/* Enable Transmitter */
	SET_BIT(Local_pUSART->CR1, USART_CR1_TE);
	/* Enable Receiver */
	SET_BIT(Local_pUSART->CR1, USART_CR1_RE);
	/* Enable USART */
	SET_BIT(Local_pUSART->CR1, USART_CR1_UE);
}


void USART_SendChar(u8 Copy_u8USART, u8 Copy_u8Data)
{
	volatile USART_t *Local_pUSART;
	
	/* Select USART */
	Local_pUSART = USART_Select(Copy_u8USART);
	
	if(Local_pUSART == 0)
	{
		return;
	}
	
	/* wait until  Transmit Data Regiser is Empty*/
	while(GET_BIT(Local_pUSART->SR, USART_SR_TXE ) == 0)
	{
	}
	
	/* Send Data */
	Local_pUSART->DR = Copy_u8Data ;
}

u8 USART_ReceiveChar(u8 Copy_u8USART)
{
  	volatile USART_t *Local_pUSART;
    u8 Local_u8Data;
  
  /* Select USART*/
	Local_pUSART = USART_Select(Copy_u8USART);
	
	if(Local_pUSART == 0)
	{
		return;
	}

	/* wait until  Transmit Data Regiser is Empty*/
	while(GET_BIT(Local_pUSART->SR, USART_SR_RXNE ) == 0)
	{
	}

   /* Read received data */
   Local_u8Data = (u8)Local_pUSART->DR;
   return Local_u8Data;
 }

void USART_SendString(u8 Copy_u8USART, const char *Copy_pchString)
{
	/* Send characters until NULL character */
	while(*Copy_pchString != '\0')
	{
	  USART_SendChar(Copy_u8USART,	*Copy_pchString);
	  Copy_pchString++;
		
	}
}

/* USART_SendString(USART1, "Hello Mohamed");