#include "UART.h"

#define USART_USE_BRGH_HIGH
#define CLOCK_FREQ 80000000ul
#define BAUD_RATE 19200ul
#if defined(USART_USE_BRGH_LOW)
    #define SPBRG_VAL   ( ((CLOCK_FREQ/BAUD_RATE)/64) - 1)
#else
   #define SPBRG_VAL   ( ((CLOCK_FREQ/BAUD_RATE)/16) - 1)
#endif

void ConsoleInit(void)
{

    RCSTAbits.SPEN = 1;   // (RCSTA<7>) must be set (= 1),
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;

#if defined(USART_USE_BRGH_HIGH)
    TXSTA = 0x24;
#else
    TXSTA = 0x20;
#endif

    RCSTA = 0x90; // 0b10010000;
    SPBRG = SPBRG_VAL;
    BAUDCON = 0x40;
}

void ConsolePutROMString(ROM char* str)
{
    BYTE c;

    while( c = *str++ )
        ConsolePut(c);

    // Since this function is mostly for debug, we'll block here to make sure
    // the last character gets out, in case we have a breakpoint on the
    // statement after the function call.
    while( !ConsoleIsPutReady() );
}


BYTE ConsoleGetString(char *buffer, BYTE bufferLen)
{
    BYTE v;
    BYTE count;

    count = 0;
    do
    {
        if ( bufferLen-- == 0 )
            break;

        while( !ConsoleIsGetReady() );

        v = RCREG;

        if ( v == '\r' || v == '\n' )
            break;

        count++;
        *buffer++ = v;
        *buffer = '\0';
    } while(1);
    return count;
}

void ConsolePut(BYTE c)
{
    while( !ConsoleIsPutReady() );
    TXREG = c;
}


void ConsolePutString(BYTE *s)
{
    BYTE c;

    while( (c = *s++) )
        ConsolePut(c);
    while( !ConsoleIsPutReady() );
}


BYTE ConsoleGet(void)
{
    // Clear overrun error if it has occured
    // New bytes cannot be received if the error occurs and isn't cleared
    if(RCSTAbits.OERR)
    {
        RCSTAbits.CREN = 0;   // Disable UART receiver
        RCSTAbits.CREN = 1;   // Enable UART receiver
    }

    return RCREG;
}