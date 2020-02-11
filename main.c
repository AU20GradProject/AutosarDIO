
#include "Dio.h"
#include "tm4c123gh6pm.h"

int main (void)
{
    /* initialization */

    SYSCTL_RCGCGPIO_R |= 0x3F ;     /* all ports accessed through AHB */
    SYSCTL_GPIOHBCTL_R |= 0x1E ;     /* enable clock for all ports */

    /* unlock ports pins with NMI*/

    GPIO_PORTD_AHB_LOCK_R |= 0x4C4F434B ;
    GPIO_PORTF_LOCK_R |= 0x4C4F434B ;

    GPIO_PORTD_AHB_CR_R |= 0x80 ;
    GPIO_PORTF_CR_R |= 0x1 ;


    /* configure all ports as output */
    GPIO_PORTA_DIR_R |= 0xFF ;
    GPIO_PORTB_AHB_DIR_R |= 0xFF ;
    GPIO_PORTC_AHB_DIR_R |= 0xFF ;
    GPIO_PORTD_AHB_DIR_R |= 0xFF ;
    GPIO_PORTE_AHB_DIR_R |= 0x3F ;
    GPIO_PORTF_DIR_R |= 0x1F ;

    /* configure all ports as gpio */
    GPIO_PORTA_AFSEL_R &= ~0xFF ;
    GPIO_PORTB_AHB_AFSEL_R &= ~0xFF ;
    GPIO_PORTC_AHB_AFSEL_R &= ~0xFF ;
    GPIO_PORTD_AHB_AFSEL_R &= ~0xFF ;
    GPIO_PORTE_AHB_AFSEL_R &= ~0x3F ;
    GPIO_PORTF_AFSEL_R &= ~0x1F ;

    /* configure driver pad with 8 mA */
    GPIO_PORTA_DR8R_R |= 0xFF ;
    GPIO_PORTB_AHB_DR8R_R |= 0xFF ;
    GPIO_PORTC_AHB_DR8R_R |= 0xFF ;
    GPIO_PORTD_AHB_DR8R_R |= 0xFF ;
    GPIO_PORTE_AHB_DR8R_R |= 0xFF ;
    GPIO_PORTF_DR8R_R |= 0xFF ;

    /* enable all pins */
    GPIO_PORTA_DEN_R |= 0xFF ;
    GPIO_PORTB_AHB_DEN_R |= 0xFF ;
    GPIO_PORTC_AHB_DEN_R |= 0xFF ;
    GPIO_PORTD_AHB_DEN_R |= 0xFF ;
    GPIO_PORTE_AHB_DEN_R |= 0x3F ;
    GPIO_PORTF_DEN_R |= 0x1F ;

    /* initialization end */

    GPIO_PORTA_DATA_R = 0x00 ;
    GPIO_PORTB_AHB_DATA_R = 0x00 ;
    GPIO_PORTC_AHB_DATA_R = 0x00 ;
    GPIO_PORTD_AHB_DATA_R = 0x00 ;
    GPIO_PORTE_AHB_DATA_R = 0x00 ;
    GPIO_PORTF_DATA_R = 0x00 ;

    /*
    Dio_WriteChannel (DioConf_Channel_7 , STD_HIGH ) ;
    Dio_WriteChannel (DioConf_Channel_15 , STD_HIGH ) ;
    Dio_WriteChannel (DioConf_Channel_23 , STD_HIGH ) ;
    Dio_WriteChannel (DioConf_Channel_31 , STD_HIGH ) ;
    Dio_WriteChannel (DioConf_Channel_36 , STD_HIGH ) ;
    Dio_WriteChannel (DioConf_Channel_41 , STD_HIGH ) ;
    */

    /*
    Dio_WritePort  (DioConf_PortA, 0xAA ) ;
    Dio_WritePort  (DioConf_PortB, 0xAA ) ;
    Dio_WritePort  (DioConf_PortC, 0xAA ) ;
    Dio_WritePort  (DioConf_PortD, 0xAA ) ;
    Dio_WritePort  (DioConf_PortE, 0xAA ) ;
    Dio_WritePort  (DioConf_PortF, 0xAA ) ;
    */


    Dio_WriteChannelGroup ( &MyDioGroupArray[0] , 0xFF) ;
    Dio_WriteChannelGroup ( &MyDioGroupArray[1] , 0xFF) ;
    Dio_WriteChannelGroup ( &MyDioGroupArray[2] , 0xFF) ;
    Dio_WriteChannelGroup ( &MyDioGroupArray[3] , 0xFF) ;
    Dio_WriteChannelGroup ( &MyDioGroupArray[4] , 0xFF) ;
    Dio_WriteChannelGroup ( &MyDioGroupArray[5] , 0xFF) ;
    Dio_WritePort  (DioConf_PortF, 0xAA ) ;

    /*
    if ( Dio_ReadChannel(DioConf_Channel_7) )
        Dio_WriteChannel (DioConf_Channel_6 , STD_HIGH ) ;

    if ( Dio_ReadChannel(DioConf_Channel_15) )
        Dio_WriteChannel (DioConf_Channel_14 , STD_HIGH ) ;

    if ( Dio_ReadChannel(DioConf_Channel_23) )
        Dio_WriteChannel (DioConf_Channel_22 , STD_HIGH ) ;

    if ( Dio_ReadChannel(DioConf_Channel_31) )
        Dio_WriteChannel (DioConf_Channel_30 , STD_HIGH ) ;

    if ( Dio_ReadChannel(DioConf_Channel_36) )
        Dio_WriteChannel (DioConf_Channel_35 , STD_HIGH ) ;

    if ( Dio_ReadChannel(DioConf_Channel_41) )
        Dio_WriteChannel (DioConf_Channel_40 , STD_HIGH ) ;
    */

    /*
    if ( 0xAA == Dio_ReadPort(DioConf_PortA) )
        Dio_WritePort  (DioConf_PortA, 0x55 ) ;
    if ( 0xAA == Dio_ReadPort(DioConf_PortB) )
            Dio_WritePort  (DioConf_PortB, 0x55 ) ;
    if ( 0xAA == Dio_ReadPort(DioConf_PortC) )
            Dio_WritePort  (DioConf_PortC, 0x55 ) ;
    if ( 0xAA == Dio_ReadPort(DioConf_PortD) )
            Dio_WritePort  (DioConf_PortD, 0x55 ) ;
    if ( 0x02A == Dio_ReadPort(DioConf_PortE) )
            Dio_WritePort  (DioConf_PortE, 0x55 ) ;
    if ( 0x0A == Dio_ReadPort(DioConf_PortF) )
            Dio_WritePort  (DioConf_PortF, 0x55 ) ;
    */

    if ( 0x0F == Dio_ReadChannelGroup(&MyDioGroupArray[0]) )
        Dio_WritePort  (DioConf_PortA, 0xFF ) ;

    Dio_FlipChannel (DioConf_Channel_7) ;
    int i =1000000 ;
    while (i--) ;
    Dio_FlipChannel (DioConf_Channel_7) ;

    while (1);

    return 0 ;
}
