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
#define     SCK_SOFT        PORTCbits.RC3
#define     MISO_SOFT       PORTCbits.RC4
#define     MOSI_SOFT       PORTCbits.RC5
#define     CC1101_CS       PORTAbits.RA1
#define     CC1101_MOSI     MOSI_SOFT
#define     CC1101_MISO     MISO_SOFT
#define     CC1101_CLK      SCK_SOFT

#define     GDO0            PORTCbits.RC2
#define     GDO2            PORTCbits.RC1

#define     LED             PORTAbits.RA2
#define     TRIS_LED        TRISAbits.TRISA2

#endif	/* GENERIC_H */

