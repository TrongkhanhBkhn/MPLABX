/* 
 * File:   Generic.h
 * Author: Chu Trong Khanh
 *
 * Created on April 30, 2014, 10:32 PM
 */

#ifndef GENERIC_H
#define	GENERIC_H
#include "p18f46k20.h"

/**********define *********/
typedef unsigned char BYTE;
#define TRUE 1
#define FALSE 0
/****************cac gia tri cua co ngat khi xay ra ngat***********************/
#define UART_INT_VALUE 1
#define TIMER_INT_VALUE 2
/*********Define Clock***************/

struct RF_Flag{
    unsigned int RF315_Flag:4;

};
struct Wsan_data{
    BYTE buffer[];
    BYTE length;
    BYTE count:4;
    BYTE *data;
    BYTE result;

};
/*********PIN SPI*************/
#define     SCK_SOFT        LATCbits.LATC3  // ket noi toi SCK cua CC1101
#define     MISO_SOFT       PORTCbits.RC4   // Ket noi toi
#define     MOSI_SOFT       LATCbits.LATC5
#define     CC1101_CS       LATAbits.LATA5
#define     CC1101_MOSI     MOSI_SOFT
#define     CC1101_MISO     MISO_SOFT
#define     CC1101_CLK      SCK_SOFT

#define     GDO0            PORTCbits.RC2
#define     TRIS_G0         TRISCbits.TRISC2
#define     GDO2            PORTCbits.RC1
#define     TRIS_G2         TRISCbits.TRISC1


#define     LED1             PORTAbits.RA3
#define     TRIS_LED1        TRISAbits.TRISA3

#define     LED2            PORTAbits.RA4
#define     TRIS_LED2       TRISAbits.TRISA4


#endif	/* GENERIC_H */

