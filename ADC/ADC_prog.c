/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 2 APRIL 2026 --------------------------- */
/* --------------- Version      : V01 ----------------------------------- */
/* --------------- Description  : ADC_Program_C ------------------------- */
/*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_INTERFACE.h"
#include "ADC_privet.h"
#include "ADC_confg.h"


void ADC_Init(void)
{
    /* ADC Enable */
    SET_BIT(ADC_CR2, ADON);

    /* Single Conversion */
    CLR_BIT(ADC_CR2, CONT);

    /* Right Alignment */
    CLR_BIT(ADC_CR2, ALIGN);

    /* Select SWSTART as trigger source */
    ADC_CR2 &= ~(0x7 << 17);
    ADC_CR2 |=  (0x7 << 17);

    /* Reset Calibration */
    SET_BIT(ADC_CR2, RSTCAL);
    while(GET_BIT(ADC_CR2, RSTCAL) == 1);

    /* Start Calibration */
    SET_BIT(ADC_CR2, CAL);
    while(GET_BIT(ADC_CR2, CAL) == 1);
}


void ADC_SetSampleTime(u8 channel, u8 sampleTime)
{
    u8 shift;

    /* Check Channel */
    if(channel <= 17)
    {
        /* Check Sample Time */
        if(sampleTime <= 7)
        {
            if(channel <= 9)
            {
                /* Channels 0 -> 9 are in SMPR2 */
                shift = channel * 3;

                ADC_SMPR2 &= ~(0x7 << shift);
                ADC_SMPR2 |=  ((u32)sampleTime << shift);
            }
            else
            {
                /* Channels 10 -> 17 are in SMPR1 */
                shift = (channel - 10) * 3;

                ADC_SMPR1 &= ~(0x7 << shift);
                ADC_SMPR1 |=  ((u32)sampleTime << shift);
            }
        }
    }
}


void ADC_StartConversion(u8 channel)
{
    /* Select Channel as SQ1 */
    ADC_SQR3 &= ~(0x1F);
    ADC_SQR3 |= channel;

    /* Start Regular Conversion */
    SET_BIT(ADC_CR2, SWSTART);
}


u16 ADC_GetResult(void)
{
    /* Wait until conversion is complete */
    while(GET_BIT(ADC_SR, EOC) == 0);

    /* Read ADC Result */
    return (u16)ADC_DR;
}




/*
ADC_Init();

ADC_SetSampleTime(3, ADC_SAMPLE_239_5);

ADC_StartConversion(3);

u16 result = ADC_GetResult();
 
*/