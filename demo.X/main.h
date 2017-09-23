/* 
 * File:   main.h
 * Author: bienphongvnn
 *
 * Created on August 1, 2015, 11:20 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#if defined(__PIC24F__)	// Microchip C30 compiler
	// PIC24F processor
	#include <p24Fxxxx.h>
	//#error Unknown processor or compiler.  See Compiler.h
#endif
#if defined(__C30__)
	#define ROM					const
	#define memcmppgm2ram(a,b,c)	memcmp(a,b,c)
	#define memcpypgm2ram(a,b,c)	memcpy(a,b,c)
	#define strcpypgm2ram(a, b)		strcpy(a,b)
	#define Reset()					asm("reset")
	#define SLEEP()					Sleep()
	#define CLRWDT()				ClrWdt()
	#define NOP()					Nop()
	#define DISABLE_WDT()			(RCONbits.SWDTEN = 0)
	#define ENABLE_WDT()			(RCONbits.SWDTEN = 1)

#endif

#if defined(__C30__)

	#define TMRL		TMR2
	#define TMRH		TMR3

#endif

  //Frequency ocsilator and baudrate of UART modules
    #define CLOCK_FREQ 8000000ul

    //Baudrate of UARTx module
    #define BAUD_RATE 19200ul
    #define BAUD_RATE_UART1 19200ul

#endif

