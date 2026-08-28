
/* =========================================================
   STM32F103 - ADC1 Registers
   ========================================================= */

#define RCC_APB2ENR     *((volatile u32*)0x40021018)
#define RCC_CFGR        *((volatile u32*)0x40021004)

#define ADC1_SR         *((volatile u32*)0x40012400)
#define ADC1_CR1        *((volatile u32*)0x40012404)
#define ADC1_CR2        *((volatile u32*)0x40012408)
#define ADC1_SMPR2      *((volatile u32*)0x40012410)
#define ADC1_SQR1       *((volatile u32*)0x4001242C)
#define ADC1_SQR3       *((volatile u32*)0x40012434)
#define ADC1_DR         *((volatile u32*)0x4001244C)


/* =========================================================
   ADC Thresholds
   ========================================================= */

#define WARNING_LEVEL   300
#define DANGER_LEVEL    500


/* =========================================================
   ADC1 Initialization
   ========================================================= */

void ADC1_Init(void)
{
    /* Enable ADC1 Clock */

    SET_BIT(RCC_APB2ENR, 9);


    /* ADC Clock = PCLK2 / 6 */

    RCC_CFGR &= ~(3 << 14);
    RCC_CFGR |=  (2 << 14);


    /* PA0 = Analog Input */

    (*(volatile u32*)0x40010800) &= ~(0xF << 0);


    /* One conversion */

    ADC1_SQR1 &= ~(0xF << 20);


    /* Channel 0 */

    ADC1_SQR3 = 0;


    /* Sampling time Channel 0 = 239.5 cycles */

    ADC1_SMPR2 &= ~(7 << 0);
    ADC1_SMPR2 |=  (7 << 0);


    /* Enable ADC */

    SET_BIT(ADC1_CR2, 0);


    /* Wait */

    MSTK_voidDelayMs(1);


    /* Reset Calibration */

    SET_BIT(ADC1_CR2, 3);

    while(GET_BIT(ADC1_CR2, 3))
    {
    }


    /* Start Calibration */

    SET_BIT(ADC1_CR2, 2);

    while(GET_BIT(ADC1_CR2, 2))
    {
    }
}

/* =========================================================
   ADC1 Read Channel 0
   ========================================================= */

u16 ADC1_Read(void)
{
    /* Clear End Of Conversion flag */
   // SET_BIT(ADC1_SR, 1);


    /* Start Conversion */
    SET_BIT(ADC1_CR2, 22);


    /* Wait until conversion complete */
    while(GET_BIT(ADC1_SR, 1) == 0);


    /* Return ADC value */

    return (u16)ADC1_DR;
}
