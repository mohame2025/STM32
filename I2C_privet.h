/*************************************************************************/
/* --------------- Author       : Mohamed Mahrous ---------------------- */
/* --------------- Date         : 1  OCTOBER   2026 ---------------------- */
/* --------------- Version      : V01             ---------------------- */
/* --------------- Description  : I2C_PRIVATE_H  ---------------------- */
/*************************************************************************/



#ifndef _I2C_PRIVATE_H
#define _I2C_PRIVATE_H



typedef struct
{

   volatile  u32   CR1  ;
   volatile  u32   CR2  ;
   volatile  u32   OAR1 ;
   volatile  u32   OAR2 ;
   volatile  u32   DR   ;
   volatile  u32   SR1  ;
   volatile  u32   SR2  ;
   volatile  u32   CCR  ;
   volatile  u32   TRISE;

}I2C_t;


#define  MI2C1  ((volatile  I2C_t *) 0x40005400 ) 
#define  MI2C2  ((volatile  I2C_t *) 0x40005800 ) 


/**********************************************/

/*  I2C Control register 1 (I2C_CR1)  */
/* Bits 2 and Bits 14 Reserved */

#define   I2C_CR1_PE             0
#define   I2C_CR1_SMBUS          1
#define   I2C_CR1_SMBTYPE        3
#define   I2C_CR1_ENARP          4
#define   I2C_CR1_ENPEC          5
#define   I2C_CR1_ENGC           6
#define   I2C_CR1_NOSTRETCH      7
#define   I2C_CR1_START          8
#define   I2C_CR1_STOP           9
#define   I2C_CR1_ACK            10
#define   I2C_CR1_POS            11
#define   I2C_CR1_PEC            12
#define   I2C_CR1_ALERT         13
#define   I2C_CR1_SWRST          15


/*****************************************/
/*  I2C Control register 2 (I2C_CR2) */
 
/* FREQ    Bits 5:0 */
#define   I2C_CR2_FREQ_POS        0
#define   I2C_CR2_FREQ_MASK       (0x003FU << I2C_CR2_FREQ_POS) 
//#define   I2C_CR2_FREQ_MASK       0x003F

/* Bits 7:6 Reserved */

/* Bit 8 ...12   */
#define   I2C_CR2_ITERREN         8
#define   I2C_CR2_ITEVTEN         9
#define   I2C_CR2_ITBUFEN         10
#define   I2C_CR2_DMAEN           11
#define   I2C_CR2_LAST            12 
/* Bits 15:13 Reserved  */
/************************************/

/* I2C Own address register 1 (I2C_OAR1) */

/* ADD Bits 9:0 */
#define   I2C_OAR1_ADD_POS         0
#define   I2C_OAR1_ADD_MASK   (0x03FFU << I2C_OAR1_ADD_POS)

// #define   I2C_OAR1_ADD_MASK        0x03FF
/* or  Macro */
// #define   I2C_OAR1_GET_ADD(REG)   ((REG) & 0x03FF)

/* Bits 13:10 Reserved 
 Bit 14 Should always be kept at 1 by software.*/

#define   I2C_OAR1_ADDMODE            15 

/**********************************************/

/*  I2C Own address register 2 (I2C_OAR2)  */

#define   I2C_OAR2_ENDUAL              0

/* ADD2 Bits 7:1 */
#define   I2C_OAR2_ADD2_POS         1
#define   I2C_OAR2_ADD2_MASK        0x00FE

/* Bits 15:8 Reserved */

/***********************************************/

/* I2C Data register (I2C_DR) */

/* DR Bits 7:0 */
#define   I2C_DR_DR_POS         0
#define   I2C_DR_DR_MASK        0x00FF
/* or  Macro */
// #define   I2C_DR_GET_DR(REG)   ((REG) & 0x00FF)

/* Bits 15:8 Reserved */
/*******************************************************/

/*  I2C Status register 1 (I2C_SR1) */

/*   Bit 13 and Bit 5  Reserved  */
#define   I2C_SR1_SB             0
#define   I2C_SR1_ADDR           1
#define   I2C_SR1_BTF            2
#define   I2C_SR1_ADD10          3
#define   I2C_SR1_STOPF          4
#define   I2C_SR1_RxNE           6
#define   I2C_SR1_TxE            7
#define   I2C_SR1_BERR           8
#define   I2C_SR1_ARLO           9
#define   I2C_SR1_AF             10
#define   I2C_SR1_OVR            11
#define   I2C_SR1_PECERR         12
#define   I2C_SR1_TIMEOUT        14
#define   I2C_SR1_SMBALERT       15

/*******************************************/

/*  I2C Status register 2 (I2C_SR2) */

/*   Bit 3   Reserved  */

#define   I2C_SR2_MSL            0
#define   I2C_SR2_BUSY           1
#define   I2C_SR2_TRA            2
#define   I2C_SR2_GENCALL        4
#define   I2C_SR2_SMBDEFAULT     5
#define   I2C_SR2_SMBHOST        6
#define   I2C_SR2_DUALF          7

/* PEC Bits 15:8 */
#define   I2C_SR2_PEC_POS         8
#define   I2C_SR2_PEC_MASK        0xFF00

/********************************************/

/* I2C Clock control register (I2C_CCR) */ 

/* PEC Bits 11:0 */
#define   I2C_CCR_CCR_POS         0
#define   I2C_CCR_CCR_MASK        0x0FFF

/* Bits 13:12 Reserved */

#define   I2C_CCR_DUTY            14
#define   I2C_CCR_FS              15

/***********************************/

/* I2C TRISE register (I2C_TRISE) */

/* PEC Bits 5:0 */
#define   I2C_TRISE_TRISE_POS         0
#define   I2C_TRISE_TRISE_MASK        0x003F

/* Bits 15:6 Reserved */


#endif