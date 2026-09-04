/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 2  APRIL   2026  ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : ADC_INTERFACE_H ---------------------- */
/**************************************************************************/

#ifndef _ADC_INTERFACE_H
#define _ADC_INTERFACE_H
#include "STD_TYPES.h"



void ADC_Init(void);
void ADC_SetSampleTime(u8 channel, u8 sampleTime);
void ADC_StartConversion(u8 channel);
u16 ADC_GetResult(void);


#endif






