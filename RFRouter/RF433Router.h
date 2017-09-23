
#ifndef __RF433ROUTER_H
#define __RF433ROUTER_H
#define PRO_DATA   flash
/*    Kieu So Nguyen Co Dau    */
typedef   signed          char int8_t;
typedef   signed            int int16_t;
typedef   signed long      int int32_t;

/*    Kieu So Nguyen Khong Dau */
typedef   unsigned         char uint8_t;
typedef   unsigned            int  uint16_t;
typedef   unsigned long    int  uint32_t;
/*    Kieu So Thuc */
typedef   float            float32_t;
#include "mega8.h"
#include "stdio.h"
#include "DEF_AVR.h"
#include "delay.h"
#include "spi/spi.h"
#include "CC1101/cc1101.h"
#include "key/key.h"
#include "uart/uart.h"

/*********** PORTB ************/
#define     SCK_SOFT        PORTB_5
#define     MISO_SOFT       PINB_4
#define     MOSI_SOFT       PORTB_3 
#define     CC1101_CS       PORTB_2 
#define     CC1101_MOSI     MOSI_SOFT
#define     CC1101_MISO     MISO_SOFT
#define     CC1101_CLK      SCK_SOFT
/*********** PORTC ************/
#define     LED1            PORTD_5
#define     LED2            PORTD_6
#define     LED3            PORTD_7
/*********** PORTD ************/ 
#define     BUTTON1         PINC_0
#define     BUTTON2         PINC_2

#define     GDO0            PIND_2
#define     GDO2            PIND_3
/**********************************************/  
#define   SPI_SOFT_ReadWrite(s)       SPI_SendByte(s)



#endif




