/*

Written by : Bebo
DATE : 16/9/2019
AUTOSAR Version : 4.3.1
DOC Name : AUTOSAR_SRS_DIODriver.pdf
Target : ARM TIVA_C TM4C123GH6PM
Module ID : 020
*/

#include "Dio.h"
#include "Dio_MemMap.h"

 /*********************************************************************/

 /* 10.1.6 */
 /* those array is used to link time configuration of channel groups created by user using configuration tool */

CONST( uint8, DIO_CONFIG_DATA ) DioPortMask [] = { 0x0F, 0x1E, 0x3C, 0x78, 0xF0, 0xE0 } ;
CONST( uint8_least, DIO_CONFIG_DATA ) DioPortOffset [] = { 0, 1, 2, 3, 4, 5 } ;

/*********************************************************************/
