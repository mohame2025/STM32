/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 1  OCTOBER   2026 ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : I2C_CONFIG_H  ---------------------- */
/*************************************************************************/




#ifndef _I2C_CONFIG_H
#define _I2C_CONFIG_H

typedef struct
{
	
	u32 ClockSpeed;
	u16 OwnAddress;
	u8   ACK      ;
	u8   Mode     ;
	
}I2C_Config_t;



#define  I2C_ACK_ENABLE      1
#define  I2C_ACK_DISABLE     0

#define  I2C_ACK_STANDARD_MODE     0
#define  I2C_ACK_FAST_MODE         1

#endif
