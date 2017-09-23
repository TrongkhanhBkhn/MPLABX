/* 
 * File:   main.h
 * Author: TrongKhanh
 *
 * Created on February 23, 2015, 11:39 PM
 */

#ifndef MAIN_H
#define	MAIN_H
#include <p18f46k20.h>
#include <delays.h>
#ifdef	__cplusplus
extern "C" {
#endif
#define INIT_TRIS TRISBbits.TRISB0
#define INIT_LAT LATBbits.LATB0
#define ECHO_TRIS TRISBbits.TRISB1
#define ECHO_PORT PORTBbits.RB1
#define LED_TRIS TRISBbits.TRISB2
#define LED_LAT LATBbits.LATB2

void setup(void);
void init_timer(void);
int flag = 0;


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

