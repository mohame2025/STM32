/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 2 APRIL 2026 --------------------------- */
/* --------------- Version      : V01 ----------------------------------- */
/* --------------- Description  : DAC_Program_C ------------------------- */
/*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"


#include "DAC_INTERFACE.h"
#include "DAC_privet.h"
#include "DAC_confg.h"
#include "song.h"


volatile u32 Song_Counter = 0;

void DAC_CALLBACK( void ){

	MGPIO_VidSetPortValue( DAC_PORT , DAC_PORT_LH , Song_Array[ Song_Counter ] );
	Song_Counter++;

	if( Song_Counter == Song_Length ){
		Song_Counter = 0;
	}

}

void MDAC_VidInit( void ){

	MGPIO_VidSetPortDirection( DAC_PORT , DAC_PORT_LH , OUTPUT_SPEED_10MHZ_PP );
	MSTK_VidInit();

}

void MDAC_VidPlay( void ){

	MSTK_VidSetCallBack( DAC_CALLBACK );
	MSTK_VidStart( 125 );

}
