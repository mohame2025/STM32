/*
 * main.c
 *
 *  Created on: Apr 17, 2026
 *      Author: Mohamed
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

/* الأرقام (راجعها حسب نوع الشاشة عندك) */
u8 numbers[10][8] = {
    {0,1,1,1,0,0,0,0}, // 0
    {1,1,1,0,0,1,1,1}, // 1
    {0,1,0,1,1,0,1,0}, // 2
    {0,1,1,1,1,0,1,0}, // 3
    {1,1,1,0,1,1,0,0}, // 4
    {0,0,1,1,1,1,0,0}, // 5
    {0,0,1,1,1,1,1,0}, // 6 ✅ متصحح
    {0,1,1,0,0,0,0,0}, // 7
    {0,1,1,1,1,1,1,0}, // 8
    {0,1,1,1,1,1,0,0}  // 9
};

/* Delay */
void delay_ms(u32 time)
{
    for(u32 i = 0; i < time; i++)
    {
        for(u32 j = 0; j < 8000; j++)
        {
            asm("NOP");
        }
    }
}

/* عرض رقم */
void display_number(u8 num)
{
    for(u8 i = 0; i < 8; i++)
    {
        MGPIO_voidSetpinValue(GPIOA, i, numbers[num][i]);
    }
}

/* تشغيل شاشة واحدة */
void enable_digit(u8 digit)
{
    // اقفل الكل
    MGPIO_voidSetpinValue(GPIOB , PIN0 ,  OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetpinValue(GPIOB , PIN1 ,  OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetpinValue(GPIOB , PIN10 , OUTPUT_SPEED_10MHZ_PP);

    // افتح واحدة
    MGPIO_voidSetpinValue(GPIOB , digit , 1);
}

/* عرض 3 أرقام */
void display_3digits(u16 num)
{
    u8 d1 = num % 10;
    u8 d2 = (num / 10) % 10;
    u8 d3 = (num / 100) % 10;

    enable_digit(0);
    display_number(d1);
    delay_ms(100);

    enable_digit(1);
    display_number(d2);
    delay_ms(100);

    enable_digit(2);
    display_number(d3);
    delay_ms(100);
}

int main(void)
{
    RCC_voidInitSysClock();

    /* Enable RCC */
    RCC_voidEableClock(RCC_APB2 , 2); // GPIOA
    RCC_voidEableClock(RCC_APB2 , 3); // GPIOB
    RCC_voidEableClock(RCC_APB2 , 4);
    /* إعداد pins */
    for(u8 i = 0; i < 8; i++)
    {
        MGPIO_voidSetpinDirection(GPIOA , i , OUTPUT_SPEED_10MHZ_PP);
    }

    MGPIO_voidSetpinDirection(GPIOB , PIN0 , OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetpinDirection(GPIOB , PIN1 , OUTPUT_SPEED_10MHZ_PP);
    MGPIO_voidSetpinDirection(GPIOB , PIN10 , OUTPUT_SPEED_10MHZ_PP);

    u16 counter = 0;

    while(1)
    {
        for(u16 t = 0; t < 50; t++) // تثبيت الرقم
        {
            display_3digits(counter);
        }

        counter++;

        if(counter == 1000)
        {
            counter = 0;
        }
    }
    return 0;
}


