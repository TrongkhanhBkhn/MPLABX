/* 
 * File:   Console.h
 * Author: TrongKhanhHD
 *
 * Created on September 13, 2015, 9:04 PM
 */

#ifndef CONSOLE_H
#define	CONSOLE_H
#include "Compiler.h"
#include "Generic.h"
#if defined(__dsPIC33F__) || defined(__PIC24F__) || defined(__PIC24H__)
//#define USE_UART1
    void unlockPin(void);
    void ConsoleInit(void);
    #define ConsoleIsPutReady()     (U2STAbits.TRMT)
    #define ConsoleIsGetReady()		(IFS1bits.U2RXIF)
    void ConsolePut(BYTE c);
    void ConsolePutROMString(ROM char* str);
    BYTE ConsoleGet(void);
    #ifdef USE_UART1
        void UART1Init(void);
        void UART1PutROMString(ROM char* str);
        void UART1Put(BYTE c);
        void UART1PrintChar(BYTE toPrint);
        void UART1PrintWord(WORD toPrint);
        BYTE UART1ConsoleGet(void);
    #endif
#elif defined(__18CXX)
#if 1   // Useful for disabling the console (saving power)
    void ConsoleInit(void);
    #define ConsoleIsPutReady()     (TXSTAbits.TRMT)
    void ConsolePut(BYTE c);
    void ConsolePutString(BYTE *s);
    void ConsolePutROMString(ROM char* str);

    #define ConsoleIsGetReady()     (PIR1bits.RCIF)
    BYTE ConsoleGet(void);
    BYTE ConsoleGetString(char *buffer, BYTE bufferLen);
#else
    #define ConsoleInit()
    #define ConsoleIsPutReady() 1
    #define ConsolePut(c)
    #define ConsolePutString(s)
    #define ConsolePutROMString(str)

    #define ConsoleIsGetReady() 1
    #define ConsoleGet()        'a'
    #define ConsoleGetString(buffer, bufferLen) 0
#endif

#endif

//TODO: remove test code
//<test code>
void PrintChar(BYTE);
void PrintWord(WORD);//programming by dat_a3cbq91
//</test code>
#define printf(x)	ConsolePutROMString((ROM char *)x)


#endif	/* CONSOLE_H */

