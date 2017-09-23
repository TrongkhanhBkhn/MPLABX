/* 
 * File:   UART.h
 * Author: Chu
 *
 * Created on April 30, 2014, 7:07 PM
 */

#ifndef __UART_H
#define __UART_H
#include "F:\PROJECT\MPLABX\RF\PIC18F46K20\RFRouter.X\Hardware\Generic.h"
#define ROM rom
#define ConsoleIsGetReady()     (PIR1bits.RCIF)
#define ConsoleIsPutReady()     (TXSTAbits.TRMT)

//#if defined(__18CXX)

    void ConsoleInit(void);
    
    void ConsolePut(BYTE c);
    void ConsolePutString(BYTE *s);
    void ConsolePutROMString(ROM char* str);   
    BYTE ConsoleGet(void);
    BYTE ConsoleGetString(char *buffer, BYTE bufferLen);
//#endif

#endif


