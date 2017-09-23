/* 
 * File:   Generic.h
 * Author: Chu Trong Khanh
 *
 * Created on April 30, 2014, 10:32 PM
 */

#ifndef GENERIC_H
#define	GENERIC_H
#include "p18f26k20.h"

/*********PIN SPI*************/
#define     SCK_SOFT        LATCbits.LATC3  // ket noi toi SCK cua CC1101
#define     MISO_SOFT       PORTCbits.RC4   // Ket noi toi
#define     MOSI_SOFT       LATCbits.LATC5
#define     CC1101_CS       LATAbits.LATA5
#define     CC1101_MOSI     MOSI_SOFT
#define     CC1101_MISO     MISO_SOFT
#define     CC1101_CLK      SCK_SOFT

#define     LED             LATBbits.LATB4
#define     TRIS_LED        TRISBbits.TRISB4
#define     GDO2            PORTCbits.RC1

#define     GDO0             PORTAbits.RA2
#define     TRIS_GDO0        TRISAbits.TRISA2

#endif	/* GENERIC_H */

