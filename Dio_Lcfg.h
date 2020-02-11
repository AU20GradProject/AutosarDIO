/*

Written by : Bebo
DATE : 16/9/2019
AUTOSAR Version : 4.3.1
DOC Name : AUTOSAR_SRS_DIODriver.pdf
Target : ARM TIVA_C TM4C123GH6PM
Module ID : 020
*/

#ifndef DIO_LCFG_H

#define DIO_LCFG_H

/* arrays provided by configuration tools to link time configurations */
extern  CONST( uint8, DIO_CONFIG_DATA ) DioPortMask [] ;
extern CONST( uint8_least, DIO_CONFIG_DATA ) DioPortOffset [] ;

#endif  /* DIO_LCFG_H */
