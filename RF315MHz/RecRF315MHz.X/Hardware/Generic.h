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

#define     GDO0            PORTAbits.RA4
#define     GDO2            PORTCbits.RC2

#define     LED             PORTCbits.RC7
#define     TRIS_LED        TRISCbits.TRISC7

#define     BUTTON          PORTBbits.RB0
#define     TRIS_BUT        TRISBbits.TRISB0

#endif	/* GENERIC_H */

