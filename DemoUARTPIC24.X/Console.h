/* 
 * File:   Console.h
 * Author: TrongKhanh
 *
 * Created on August 29, 2015, 8:44 PM
 */

#ifndef CONSOLE_H
#define	CONSOLE_H
typedef unsigned char BYTE;                 // 8-bit
#define CLOCK_FREQ 8000000ul
 #define BAUD_RATE 19200ul
#define UART2BRG   (CLOCK_FREQ/2/16)/BAUD_RATE-1
#define ROM	const
#include "p24FJ128GA306.h"
        #define WSAN_LED_TRIS 		TRISFbits.TRISF3
        #define WSAN_LED 		LATFbits.LATF3
typedef unsigned short int WORD;            // 16-bit
 void ConsoleInit(void);
    #define ConsoleIsPutReady()     (U2STAbits.TRMT)
    #define ConsoleIsGetReady()		(IFS1bits.U2RXIF)
    void ConsolePut(BYTE c);
    void ConsolePutROMString(ROM char* str);
    BYTE ConsoleGet(void);
    void PrintChar(BYTE);
void PrintWord(WORD);//programming by dat_a3cbq91
#define printf(x)	ConsolePutROMString((ROM char *)x)
#endif	/* CONSOLE_H */

