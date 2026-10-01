/*****************************************************/
/* Author   : Mohamed Mahrous                        */
/* Version  : V01                                    */
/* Date     : 14 SEP 2026                            */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "STP_interface.h"
#include "STP_privet.h"
#include "STP_config.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
    s8 Local_s8Counter;
    u8 Local_u8Bit;

    for(Local_s8Counter = 5; Local_s8Counter > 0; Local_s8Counter--)
    {
        /* MSB first */
        Local_u8Bit = GET_BIT(Copy_u8DataToSend, Local_s8Counter  -1 ); //-1

        /* DATA */
        MGPIO_voidSetpinValue(HSTP_SERIAL_DATA, Local_u8Bit);

        /* SHIFT CLOCK */
        MGPIO_voidSetpinValue(HSTP_SHIFT_CLOCK, GPIO_HIGH);
        MSTK_voidSetBusyWait(1);
        MGPIO_voidSetpinValue(HSTP_SHIFT_CLOCK, GPIO_LOW);
        MSTK_voidSetBusyWait(1);
    }

    /* STORE / LATCH CLOCK */
    MGPIO_voidSetpinValue(HSTP_STORE_CLOCK, GPIO_HIGH);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSetpinValue(HSTP_STORE_CLOCK, GPIO_LOW);
    MSTK_voidSetBusyWait(1);
}
