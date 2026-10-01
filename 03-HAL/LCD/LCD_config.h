/**********************************************************************************/
/***						Date: 17/8/2023	Day: Thursday						***/
/***			LCD display driver for the microcontroller STM32F401			***/
/***    			 Created By: Omar Abdul Qadir	 Version= 2.0	            ***/
/**********************************************************************************/
/***		         Note: All the data in the file is readable,				***/
/***			And any editing will affect the controller's behavior,			***/
/***				  So It's not recommended to edit any data,					***/
/***			Unless you are sure of what is the effect on behaviors.			***/
/**********************************************************************************/

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
	

/**********************************************************************************
 *******************	 	   LCD interfacing mode					***************
 **********************************************************************************/
	// LCD 8bit mode value
	#define _8bit_interface 0
	// LCD 4bit mode value
	#define _4bit_interface 1
	// LCD Selection of the mode
	#define _LCD_interface_ _4bit_interface
	
	
/**********************************************************************************
 *******************	 	   		Ports definition				***************
 **********************************************************************************/
	// Control port connection
	#define lcd_ctrl_port 	GPIOA
	// Data port connection
	#define lcd_data_port 	GPIOA


/**********************************************************************************
 *******************	 	   Control pins definition			***************
 **********************************************************************************/
	// Enable pin
	#define lcd_EN 			PIN2
	// Read/Write pin
	#define lcd_RW 			PIN3
	// Register select pin
	#define lcd_RS 			PIN4


/**********************************************************************************
 *******************	 	   Data pins definition					***************
 **********************************************************************************/
	// Pin data 0
	#define lcd_d0			PIN5
	// Pin data 1
	#define lcd_d1			PIN6
	// Pin data 2
	#define lcd_d2			PIN7
	// Pin data 3
	#define lcd_d3			PIN8
	// Pin data 4
	#define lcd_d4			PIN5
	// Pin data 5
	#define lcd_d5			PIN6
	// Pin data 6
	#define lcd_d6			PIN7
	// Pin data 7
	#define lcd_d7			PIN8
	
#endif	//End LCD_CONFIG_H
