/* 
 * File:   FindPosition.h
 * Author: TrongKhanh
 *
 * Created on March 20, 2015, 1:43 AM
 */

#ifndef FINDPOSITION_H
#define	FINDPOSITION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "General.h"
void OSC_config(void);
void funcInterrupt(void);
float getDistance(void);
void delay_4us();
void delay_15ms();
void initTimer(char mode);
void config_ExINT(void);
#define USE_TIMER_16BITS
#define USE_INTERRUPT_PERIOD
#define ENABLE_TMR0 		0xFF
#define MODE_8_BITS		0xFF
#define COUNTER_MODE		0xFF
#define HIGH_TO_LOW		0xFF
#define NOT_USE_PRESCALE	0xFF
#define PRES_256		0xFF
#define STOP_TMR0		0b01111111
#define MODE_16_BITS		0b10111111
#define	TIMER_MODE		0b11011111
#define LOW_TO_HIGH		0b11101111
#define USE_PRESCALE		0b11110111
#define	PRES_128		0b11111110
#define	PRES_64			0b11111101
#define	PRES_32			0b11111100
#define	PRES_16			0b11111011
#define	PRES_8			0b11111010
#define	PRES_4			0b11111001
#define	PRES_2			0b11111000
#ifdef	__cplusplus
}
#endif

#endif	/* FINDPOSITION_H */

