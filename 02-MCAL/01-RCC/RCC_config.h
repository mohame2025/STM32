/**********************************************************************************/
/* Author      : Mohamed Mahrous                                                  */
/* Date        : 7  MARCH   2026                                                  */
/* Version     : V01                                                              */
/**********************************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H



/* Options:    RCC_HSE_CRYSTAL 
	           RCC_HSE_RC      
	           RCC_HSI         
	           RCC_PLL         
	                         */

#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL     


/* OPions:         RCC_PLL_IN_HSI_DIV-2
                   RCC_PLL_IN_HSE_DIV-2
                   RCC_PLL_IN_HSE          */


/* Note : select value only if you have PLL as input clock source  */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT       RCC_PLL_IN_HSE_DIV-2
#endif

/* Options 2 to 16 */
/* Note : select value only if you have PLL as input clock source  */
#if RCC_CLOCK_TYPE == RCC_PLL 
#define RCC_PLL_MUL_VAL       4
#endif


#endif
