/*************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 1  MAY   2026   ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : AFIO_Program_C  ---------------------- */
/*************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIConfiguration(u8 copy_u8Line , u8 copy_u8PORTMap)
{
    u8 Local_u8RegIndex = 0;
    u8 Local_u8LineIndex = copy_u8Line % 4;

    if(copy_u8Line <= 3)
    {
        Local_u8RegIndex = 0;
    }
    else if(copy_u8Line <= 7)
    {
        Local_u8RegIndex = 1;
    }
    else if(copy_u8Line <= 11)
    {
        Local_u8RegIndex = 2;
    }
    else if(copy_u8Line <= 15)
    {
        Local_u8RegIndex = 3;
    }

    AFIO->EXTICR[Local_u8RegIndex] &= ~(0b1111 << (Local_u8LineIndex * 4));
    AFIO->EXTICR[Local_u8RegIndex] |=  (copy_u8PORTMap << (Local_u8LineIndex * 4));
}
