/* 
 * File:   Compiler.h
 * Author: TrongKhanhHD
 *
 * Created on September 13, 2015, 9:11 PM
 */

#ifndef COMPILER_H
#define	COMPILER_H
// define FOSC
#define CLOCK_FREQ 8000000ul

 //Baudrate of UARTx module
#define BAUD_RATE 19200ul
#define BAUD_RATE_UART1 19200ul
#if defined(MCHP_C18)
    #include <p18cxxx.h>    // p18cxxx.h must have current processor
                            // defined.
    #include <stdlib.h>
#elif defined(__PIC24F__)	// Microchip C30 compiler
	// PIC24F processor
	#include <p24Fxxxx.h>
#elif defined(__PIC24H__)	// Microchip C30 compiler
	// PIC24H processor
	#include <p24Hxxxx.h>
#elif defined(__dsPIC33F__)	// Microchip C30 compiler
	// dsPIC33F processor
	#include <p33Fxxxx.h>
#else
    #error "Unknown processor or compiler"
#endif
#if defined(MCHP_C18)
    #define ROM                 rom

    #define NOP()               Nop()
    #define CLRWDT()            ClrWdt()
    #define RESET()             Reset()
    #define SLEEP()             Sleep()
    #define DISABLE_WDT()       (WDTCONbits.SWDTEN = 0)
    #define ENABLE_WDT()        (WDTCONbits.SWDTEN = 1)
    #define TBLWTPOSTINC()      _asm tblwtpostinc _endasm



#elif defined(__C30__)
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
#endif	/* COMPILER_H */

