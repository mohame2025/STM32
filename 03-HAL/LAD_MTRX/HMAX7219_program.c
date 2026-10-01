/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 30  MAY   2026   ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : LEDMRX_Program_C  ---------------------- */
/*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"

#include "HMAX7219_interface.h"
#include "HMAX7219_private.h"
#include "HMAX7219_config.h"

static void HMAX7219_voidLatch(void);

void HMAX7219_voidSendData(u8 Copy_u8Address , u8 Copy_u8Data)
{
	u16 Local_u16Packet;

	Local_u16Packet =
		((u16)Copy_u8Address << 8)
		| Copy_u8Data;

	MGPIO_VidSetPinValue(HMAX7219_CS_PORT,
			             HMAX7219_CS_PIN,
			             GPIO_LOW);

	MSPI1_voidSendReceive(Local_u16Packet);

	MGPIO_VidSetPinValue(HMAX7219_CS_PORT,
			             HMAX7219_CS_PIN,
			             GPIO_HIGH);
}

void HMAX7219_voidInit(void)
{
	HMAX7219_voidSendData(MAX7219_SHUTDOWN , 0x01);

	HMAX7219_voidSendData(MAX7219_DECODE_MODE , 0x00);

	HMAX7219_voidSendData(MAX7219_SCAN_LIMIT , 0x07);

	HMAX7219_voidSendData(MAX7219_INTENSITY , 0x07);

	HMAX7219_voidSendData(MAX7219_DISPLAY_TEST , 0x00);

	HMAX7219_voidClearDisplay();
}

void HMAX7219_voidClearDisplay(void)
{
	u8 Local_u8Counter;

	for(Local_u8Counter = 1 ;
		Local_u8Counter <= 8 ;
		Local_u8Counter++)
	{
		HMAX7219_voidSendData(Local_u8Counter , 0x00);
	}
}

void HMAX7219_voidDisplayPattern(u8 *Copy_u8Pattern)
{
	u8 Local_u8Counter;

	for(Local_u8Counter = 0 ;
		Local_u8Counter < 8 ;
		Local_u8Counter++)
	{
		HMAX7219_voidSendData(Local_u8Counter + 1 ,
				              Copy_u8Pattern[Local_u8Counter]);
	}
}