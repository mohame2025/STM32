/**************************************************************************/
/* --------------- Author       : Mohamed Mahrous  ---------------------- */
/* --------------- Date         : 1  OCTOBER 2026 ---------------------- */
/* --------------- Version      : V01              ---------------------- */
/* --------------- Description  : I2C_INTERFACE_H ---------------------- */
/**************************************************************************/

#ifndef _I2C_INTERFACE_H
#define _I2C_INTERFACE_H



void I2C_VidInit  (u8 Copy_u8I2C, I2C_Config_t  *Copy_pConfig);
void I2C_VidStop  ( void );
void I2C_VidEnable ( void );
void I2C_VidDisable( void );
void I2C_VidStart ( void );
void I2C_VidReset ( void );


#endif