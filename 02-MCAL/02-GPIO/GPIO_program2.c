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



void MGPIO_VidSetPortDirection( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode ){

	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == LOW  ) { MGPIOA->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == HIGH ) { MGPIOA->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case GPIOB:

		if      ( Copy_u8Position == LOW  ) { MGPIOB->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == HIGH ) { MGPIOB->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;
	case GPIOC:

		if      ( Copy_u8Position == LOW  ) { MGPIOC->CRL = ( 0x11111111 * Copy_u8Mode ) ; }
		else if ( Copy_u8Position == HIGH ) { MGPIOC->CRH = ( 0x11111111 * Copy_u8Mode ) ; }

		break;

	}

}

void MGPIO_VidSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value ){

	switch( Copy_u8Port ){

	case GPIOA:

		if      ( Copy_u8Position == LOW  ){ MGPIOA->ODR = (MGPIOA->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == HIGH ){ MGPIOA->ODR = (MGPIOA->ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case GPIOB:

		if      ( Copy_u8Position == LOW  ){ MGPIOB->ODR = (MGPIOB->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == HIGH ){ MGPIOB->ODR = (MGPIOB->ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;
	case GPIOC:

		if      ( Copy_u8Position == LOW  ){ MGPIOC->ODR = (MGPIOC->ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
		else if ( Copy_u8Position == HIGH ){ MGPIOC->ODR = (MGPIOC->ODR & 0x00FF ) | (     Copy_u8Value ) ; }

		break;

	}

}

u16 MGPIO_u16GetPortValue( u8 Copy_u8Port , u8 Copy_u8Position ){

	u16 LOC_u16Result = 0;

	switch( Copy_u8Port ){

	case GPIOA:

		LOC_u16Result = MGPIOA->IDR;
		if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	case GPIOB:

		LOC_u16Result = MGPIOB->IDR;
		if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;
	case GPIOC:

		LOC_u16Result = MGPIOC->IDR;
		if      ( Copy_u8Position == LOW  ){ LOC_u16Result &= 0x00FF ; }
		else if ( Copy_u8Position == HIGH ){ LOC_u16Result &= 0xFF00 ; }

		break;

	}

	return LOC_u16Result ;

}





