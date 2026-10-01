/*********/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 12 MAY 2026 --------------------------- */
/* --------------- Version      : V02 ---------------------------------- */
/* --------------- Description  : SYSTICK_Program_C -------------------- */
/*********/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


/============================================================/
/*                    Global Variables                        */
/============================================================/

static void (*MSTK_CallBack)(void) = NULL;

static u8 MSTK_Mode;


/============================================================/
/*                       MSTK_voidInit                        */
/============================================================/

void MSTK_voidInit(void)
{
    /* Disable SysTick */
    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    /* Clock Source = AHB */
    SET_BIT(SYSTICK->STK_CTRL, STK_CLKSOURCE);

    /* Enable SysTick Interrupt */
    SET_BIT(SYSTICK->STK_CTRL, STK_TICKINT);

    /* Clear Load Register */
    SYSTICK->STK_LOAD = 0;

    /* Clear Current Value Register */
    SYSTICK->STK_VAL = 0;
}


/============================================================/
/*                  MSTK_voidSetBusWait                      */
/============================================================/

void MSTK_voidSetBusWait(u32 copy_u32Ticks)
{
    /* Disable SysTick */
    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    /* Load ticks */
    SYSTICK->STK_LOAD = copy_u32Ticks;

    /* Clear current value */
    SYSTICK->STK_VAL = 0;

    /* Enable SysTick */
    SET_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    /* Wait until COUNTFLAG = 1 */
    while(GET_BIT(SYSTICK->STK_CTRL, STK_COUNTFLAG) == 0)
    {
        /* Busy Wait */
    }

    /* Disable SysTick */
    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);
}


/============================================================/
/*              MSTK_voidSetIntervalSingle                   */
/============================================================/

void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks,
                                void (*copy_ptr)(void))
{
    /* Disable SysTick */
    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    /* Set number of ticks */
    SYSTICK->STK_LOAD = copy_u32Ticks;

    /* Clear current value */
    SYSTICK->STK_VAL = 0;

    /* Set Callback */
    MSTK_CallBack = copy_ptr;

    /* Set Mode = Single */
    MSTK_Mode = SINGLE_INTERVAL;

    /* Enable SysTick */
    SET_BIT(SYSTICK->STK_CTRL, STK_ENABLE);
}


/============================================================/
/*             MSTK_voidSetIntervalPeriodic                  */
/============================================================/

void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks,
                                  void (*copy_ptr)(void))
{
    /* Disable SysTick */
    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    /* Set number of ticks */
    SYSTICK->STK_LOAD = copy_u32Ticks;

    /* Clear current value */
    SYSTICK->STK_VAL = 0;

    /* Set Callback */
    MSTK_CallBack = copy_ptr;

    /* Set Mode = Periodic */
    MSTK_Mode = PERIODIC_INTERVAL;

    /* Enable SysTick */
    SET_BIT(SYSTICK->STK_CTRL, STK_ENABLE);
}


/============================================================/
/*                 MSTK_voidStopInterval                     */
/============================================================/

void MSTK_voidStopInterval(void)
{
    /* Disable SysTick */
    CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

    /* Clear Load Register */
    SYSTICK->STK_LOAD = 0;

    /* Clear Current Value */
    SYSTICK->STK_VAL = 0;

    /* Clear Callback */
    MSTK_CallBack = NULL;
}


/============================================================/
/*              MSTK_u32GetElapsedTime                       */
/============================================================/

u32 MSTK_u32GetElapsedTime(void)
{
    u32 Local_u32Load;
    u32 Local_u32Current;

    Local_u32Load = SYSTICK->STK_LOAD;
    Local_u32Current = SYSTICK->STK_VAL;

    return (Local_u32Load - Local_u32Current);
}


/============================================================/
/*             MSTK_u32GetRemainingTime                      */
/============================================================/

u32 MSTK_u32GetRemainingTime(void)
{
    return SYSTICK->STK_VAL;
}


/============================================================/
/*                    SysTick Handler                         */
/============================================================/

void SysTick_Handler(void)
{
    if(MSTK_CallBack != NULL)
    {
        /* Call Function */
        MSTK_CallBack();

        /* Check Single Interval */
        if(MSTK_Mode == SINGLE_INTERVAL)
        {
            /* Disable SysTick */
            CLR_BIT(SYSTICK->STK_CTRL, STK_ENABLE);

            /* Clear Callback */
            MSTK_CallBack = NULL;
        }
    }
}

أضف في "SYSTICK_private.h"

#define SINGLE_INTERVAL       0
#define PERIODIC_INTERVAL     1

والـ "main.c"

void func(void)
{
    /* Code */
}

void fun3(void)
{
    /* Code */
}

void fun4(void)
{
    /* Code */
}


int main(void)
{
    MSTK_voidInit();

    MSTK_voidSetIntervalSingle(1000, func);

    while(1)
    {
        
    }
}


MSTK_voidSetIntervalSingle(1000, func);
MSTK_voidSetIntervalSingle(2000, fun3);
MSTK_voidSetIntervalSingle(3000, fun4);
