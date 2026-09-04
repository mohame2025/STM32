/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 2  APRIL   2026 ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : GPIO_Program_C  ---------------------- */
/*************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetpinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA : 
		           if(copy_u8PIN <= 7)         /* register LOW */
				   {
					   GPIOA_CRL  &= ~ ((0b1111) << copy_u8PIN * 4);         // reset or CLR  BIT shft left
					   GPIOA_CRL  |=   ((copy_u8Mode) << copy_u8PIN * 4);    // SIT_BIT or ENBLE_BIT
				   }   
				   else if(copy_u8PIN <= 15)    /* register HIGH */
				   {           
				       copy_u8PIN = copy_u8PIN - 8; 
					   GPIOA_CRH  &= ~ ((0b1111) << copy_u8PIN * 4);       // reset or CLR  BIT sheft left
					   GPIOA_CRH  |=   ((copy_u8Mode) << copy_u8PIN * 4);  // SIT_BIT or ENBLE_BIT
				   }   
				   break;
				    
				   
				   
		case GPIOB : 
		          if(copy_u8PIN <= 7)         /* register LOW */
				   {
					   GPIOB_CRL  &= ~ ((0b1111) << copy_u8PIN * 4);         /* reset or CLR  BIT sheft left*/
					   GPIOB_CRL  |=   ((copy_u8Mode) << copy_u8PIN * 4);         /* SIT_BIT or ENBLE_BIT  */
				   }   
				   else if(copy_u8PIN <= 15)    /* register HIGH */
				   {           
				       copy_u8PIN = copy_u8PIN - 8; 
					   GPIOB_CRH  &= ~ ((0b1111) << copy_u8PIN * 4);         /* reset or CLR  BIT sheft left*/
					   GPIOB_CRH  |=   ((copy_u8Mode) << copy_u8PIN * 4);         /* SIT_BIT or ENBLE_BIT  */
				   }   
				   break;
				   
		
		case GPIOC :
		          if(copy_u8PIN <= 7)         /* register LOW */
				   {
					   GPIOC_CRL  &= ~ ((0b1111) << copy_u8PIN * 4);         /* reset or CLR  BIT sheft left*/
					   GPIOC_CRL  |=   ((copy_u8Mode) << copy_u8PIN * 4);         /* SIT_BIT or ENBLE_BIT  */
				   }   
				   else if(copy_u8PIN <= 15)    /* register HIGH */
				   {           
				       copy_u8PIN = copy_u8PIN - 8; 
					   GPIOC_CRH  &= ~ ((0b1111) << copy_u8PIN * 4);         /* reset or CLR  BIT sheft left*/
					   GPIOC_CRH  |=   ((copy_u8Mode) << copy_u8PIN * 4);         /* SIT_BIT or ENBLE_BIT  */
				   }   
				   break;
		default :  break;
	}
	
}

void MGPIO_voidSetpinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value)
{
	 switch(copy_u8PORT)
	   {
			  case GPIOA : 
			        if(copy_u8Value == GPIO_HIGH)
					{
					  SET_BIT(GPIOA_ODR , copy_u8PIN);
					}
					else if (copy_u8Value == GPIO_LOW)
					{
                      CLR_BIT(GPIOA_ODR , copy_u8PIN);
					}
			        break;
					
			  case GPIOB :
				  if(copy_u8Value == GPIO_HIGH)
				 	{
				      SET_BIT(GPIOB_ODR , copy_u8PIN);
				    }
					  else if (copy_u8Value == GPIO_LOW)
					{
				      CLR_BIT(GPIOB_ODR , copy_u8PIN);
					}
				       break;
			  
			  case GPIOC :
			        if(copy_u8Value == GPIO_HIGH)
					{
					  SET_BIT(GPIOC_ODR , copy_u8PIN);
					}
					else if (copy_u8Value == GPIO_LOW)
					{
                      CLR_BIT(GPIOC_ODR , copy_u8PIN);
					}
			        break;
		  default : break;
	   }
}



u8 MGPIO_u8GetpinValue(u8 copy_u8PORT , u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0;             // input data register
	switch(copy_u8PORT)
		{
            case GPIOA :LOC_u8Result = GET_BIT(GPIOA_IDR , copy_u8PIN);
                       break;
            case GPIOB :LOC_u8Result = GET_BIT(GPIOB_IDR , copy_u8PIN);
                       break;
	        case GPIOC :LOC_u8Result = GET_BIT(GPIOC_IDR , copy_u8PIN);
                       break;
            default : break;
		}	
	    return LOC_u8Result;
} 
