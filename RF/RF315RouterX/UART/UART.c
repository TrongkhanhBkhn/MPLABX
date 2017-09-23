#include "UART.h"

#define USART_USE_BRGH_HIGH
#define USART_USE_BRG16_HIGH
#define USE_UART_H
#define CLOCK_FREQ 8000000ul
#define BAUD_RATE 19200ul
#if defined(USART_USE_BRGH_LOW)
    #define SPBRG_VAL   ( ((CLOCK_FREQ/BAUD_RATE)/64) - 1)
#elif defined USART_USE_BRG16_HIGH
   #define SPBRG_VAL   ( ((CLOCK_FREQ/BAUD_RATE)/4) - 1)
#else
    #define SPBRG_VAL   ( ((CLOCK_FREQ/BAUD_RATE)/16) - 1)
#endif
#if SPBRG_VAL >255
#error "Calculated SPBRG value is out of range for currnet CLOCK_FREQ."
#endif


void ConsoleInit(void)
{
#ifdef USE_UART_H
    TRISCbits.RC7 = 1;
    TRISCbits.RC6 = 0;
     OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE &
               USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW,11);
     baudUSART(BAUD_IDLE_CLK_LOW & BAUD_AUTO_OFF & BAUD_8_BIT_RATE &
             BAUD_IDLE_RX_PIN_STATE_HIGH);
#endif
#ifndef USE_UART_H
    RCSTAbits.SPEN = 1;
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;

#if defined(USART_USE_BRGH_HIGH)
    TXSTA = 0x06;
#else
    TXSTA = 0x04;
#endif
#ifdef USART_USE_BRG16_HIGH
     BAUDCON = 0x48;
     SPBRGH:SPBRG = SPBRG_VAL;
#else
     BAUDCON = 0x40;
     SPBRG = SPBRG_VAL;
#endif
    RCSTA = 0x90; // 0b10010000
    TXREG = 0x00;        // lam rong thanh ghi truyen
    RCREG = 0x00;
    RCONbits.IPEN=0;
    IPR1bits.RCIP=0;
    PIR1bits.RCIF = 0;
    PIE1bits.RCIE=1;     // cho phep ngat khi nhan uart
    INTCONbits.GIE=1;    // cho phep ngat toan cuc khi IPEN =1 set boi thanh ghi RCO
#endif

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
void ConsolePutInt(unsigned int val)
{
    char *a,*b;
    a = itoa(val,b);
    ConsolePutString((unsigned char)a);
}


