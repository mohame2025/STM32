#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

/* ===== numbers ===== */
u8 numbers[10][7] = {
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1}, //3
    {0,1,1,0,0,1,1}, //4
    {1,0,1,1,0,1,1}, //5
    {1,0,1,1,1,1,1}, //6
    {1,1,1,0,0,0,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}  //9
};

/* ===== functions ===== */
void delay_ms(u32 time);
void display_number(u8 num);
void enable_digit(u8 d);
void display_time(u8 h, u8 m, u8 s);



/* ===== time ===== */
u8 seconds = 0;
u8 minutes = 0;
u8 hours   = 0;

int main(void)
{
    RCC_voidInitSysClock();

    RCC_voidEableClock(RCC_APB2 , 2); // GPIOA
    RCC_voidEableClock(RCC_APB2 , 3); // GPIOB

    /* segments */
    for(int i = 0; i < 7; i++)
        MGPIO_voidSetpinDirection(GPIOA , i , OUTPUT_SPEED_10MHZ_PP);

    /* digits */
    MGPIO_voidSetpinDirection(GPIOB , PIN0 , OUTPUT_SPEED_10MHZ_PP);  // sec
    MGPIO_voidSetpinDirection(GPIOB , PIN1 , OUTPUT_SPEED_10MHZ_PP);  // min
    MGPIO_voidSetpinDirection(GPIOB , PIN10 , OUTPUT_SPEED_10MHZ_PP); // hour

    while(1)
    {
        /* عرض الوقت */
    	for(int i = 0; i < 70; i++)
    	        {
    	display_time(hours, minutes, seconds);
    	       }

      //  delay_ms(200);

        /* زيادة الثواني */
        seconds++;

        if(seconds > 9)
        {
            seconds = 0;
            delay_ms(200);
            minutes++;
        }

        if(minutes > 4)
        {
            minutes = 0;
            delay_ms(1000);
            hours++;
        }

        if(hours > 3)
        {
            hours = 0;
            delay_ms(1000);
        }
    }
}

/* ===== display number ===== */
void display_number(u8 num)
{
    for(u8 i = 0; i < 7; i++)
    {
        MGPIO_voidSetpinValue(GPIOA , i , numbers[num][i]);
    }
}

/* ===== enable digit ===== */
void enable_digit(u8 d)
{
    MGPIO_voidSetpinValue(GPIOB , PIN0 , 0);
    MGPIO_voidSetpinValue(GPIOB , PIN1 , 0);
    MGPIO_voidSetpinValue(GPIOB , PIN10 , 0);

    if(d == 0) MGPIO_voidSetpinValue(GPIOB , PIN0 , 1);   // seconds
    if(d == 1) MGPIO_voidSetpinValue(GPIOB , PIN1 , 1);   // minutes
    if(d == 2) MGPIO_voidSetpinValue(GPIOB , PIN10 , 1);  // hours
}

/* ===== display time (H M S) ===== */
void display_time(u8 h, u8 m, u8 s)
{
    enable_digit(0);
    display_number(s);
    delay_ms(2);

    enable_digit(1);
    display_number(m);
    delay_ms(2);

    enable_digit(2);
    display_number(h);
    delay_ms(2);
}

/* ===== delay ===== */
void delay_ms(u32 time)
{
    for(u32 i = 0; i < time; i++)
        for(u32 j = 0; j < 500; j++)
            asm("NOP");
}
