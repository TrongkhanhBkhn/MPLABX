#include "Console.h"
#if defined(__dsPIC33F__) || defined(__PIC24F__) || defined(__PIC24H__)
#define USART2_USE_BRGH_LOW
#define USART1_USE_BRGH_LOW
    void unlockPin(void){
    /*------UART2-----*/
    // RX2 >> RP24
    RPINR19bits.U2RXR = 24;
    // TX2 >> RP23
    RPOR11bits.RP23R  = 5;
    #ifdef USE_UART1
        /*------UART1-----*/
    // RX1 >> RP22
    RPINR18bits.U1RXR = 22;
    // TX1 >> RP25
    RPOR12bits.RP25R  = 3;
    #endif
    }
    void ConsoleInit(void)
    {
        #if defined(USART2_USE_BRGH_LOW)
            U2BRG  = (CLOCK_FREQ/2/16)/BAUD_RATE-1;
        #else
            U2BRG  = (CLOCK_FREQ/2/4)/BAUD_RATE-1;
        #endif
        #if defined(USART2_USE_BRGH_LOW)
            U2MODE = 0x8000;//enable UART2
                            //U2TX and U2RX pins are enabled and used
                            //Standard Speed mode (16 BRG clock cycles per bit)
                            //8-bit data, no parity
                            //One Stop bit
           
        #else
            U2MODE = 0x8008;//enable UART2
                            //U2TX and U2RX pins are enabled and used
                            //Standard Speed mode (16 BRG clock cycles per bit)
                            //8-bit data, no parity
                            //One Stop bit
            U2MODEbits.BRGH = 1;
        #endif

        U2STA = 0x2400;//Transmit is enabled, U2TX pin is controlled by UART2
        #if defined (ROUTER_EMB) || defined(USE_CONTROL_PUMP) || defined(USE_CONTROL_ALARM)
            IEC1bits.U2RXIE = 1;
            IFS1bits.U2RXIF = 0;         /*clear interrupt flag*/
        #endif
    }
    /* End by dat_a3cbq91 */

    void ConsolePutROMString(ROM char* str)
    {
        BYTE c;

        while( (c = *str++) != 0 )
        ConsolePut(c);
    }

    void ConsolePut(BYTE c)
    {
        while(U2STAbits.TRMT == 0);
        U2TXREG = c;
    }

    ROM unsigned char CharacterArray[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    void PrintChar(BYTE toPrint)
    {
        BYTE PRINT_VAR;
        PRINT_VAR = toPrint;
        toPrint = (toPrint>>4)&0x0F;
        ConsolePut(CharacterArray[toPrint]);
        toPrint = (PRINT_VAR)&0x0F;
        ConsolePut(CharacterArray[toPrint]);
        return;
    }

    //programming by dat_a3cbq91
    void PrintWord(WORD toPrint)
    {
        BYTE MSB,LSB;
        MSB = toPrint >> 8;
        LSB = toPrint & 0x00FF;
        PrintChar(MSB);
        PrintChar(LSB);
    }
    //end by dat_a3cbq91

    BYTE ConsoleGet(void)
    {
        char Temp;

//        while(IFS1bits.U2RXIF == 0);
        while(U2STAbits.URXDA == 0);
        Temp = U2RXREG;
//        IFS1bits.U2RXIF = 0;
        return Temp;
    }

    #ifdef USE_UART1
        void UART1Init(void)
        {
        #if defined(USART1_USE_BRGH_LOW)
            U1BRG  = (CLOCK_FREQ/2/16)/BAUD_RATE_UART1-1;
        #else
            U1BRG  = (CLOCK_FREQ/2/16)/BAUD_RATE_UART1-1
        #endif
            IEC0bits.U1RXIE = 1;
            IFS0bits.U1RXIF = 0;//enable UART1 interrupt
        #if defined(USART1_USE_BRGH_LOW)
            U1MODE = 0x8000;//enable UART1
                            //U1TX and U1RX pins are enabled and used
                            //Standard Speed mode (16 BRG clock cycles per bit)
                            //8-bit data, no parity
                            //One Stop bit

        #else
            U1MODE = 0x8008;//enable UART1
                                        //U1TX and U1RX pins are enabled and used
                                        //Standard Speed mode (16 BRG clock cycles per bit)
                                        //8-bit data, no parity
                                        //One Stop bit
            U1MODEbits.BRGH = 1;
        #endif
            U1STA = 0x0400;//Transmit is enabled, U1TX pin is controlled by UART1
        }

        void UART1Put(BYTE c)
        {
            while(U1STAbits.TRMT == 0);
            U1TXREG = c;
        }

        void UART1PutROMString(ROM char* str)
        {
            BYTE c;

            while( (c = *str++) != 0 )
            UART1Put(c);
        }


//	    ROM unsigned char CharacterArray[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        void UART1PrintChar(BYTE toPrint)
        {
            BYTE PRINT_VAR;
            PRINT_VAR = toPrint;
            toPrint = (toPrint>>4)&0x0F;
            UART1Put(CharacterArray[toPrint]);
            toPrint = (PRINT_VAR)&0x0F;
            UART1Put(CharacterArray[toPrint]);
            return;
        }

        void UART1PrintWord(WORD toPrint)
        {
            BYTE MSB,LSB;
            MSB = toPrint >> 8;
            LSB = toPrint & 0x00FF;
            UART1PrintChar(MSB);
            UART1PrintChar(LSB);
        }

        BYTE UART1ConsoleGet(void)
        {
            char Temp;

            while(IFS0bits.U1RXIF == 0);

            Temp = U1RXREG;
            IFS0bits.U1RXIF = 0;
            return Temp;
        }
    #endif
#elif defined(__18CXX)
#define USART_USE_BRGH_HIGH

#if defined(USART_USE_BRGH_LOW)
    #define SPBRG_VAL   ( ((CLOCK_FREQ/BAUD_RATE)/64) - 1)
#else
   	#define SPBRG_VAL   ( ((CLOCK_FREQ/BAUD_RATE)/16) - 1)
#endif
#if SPBRG_VAL > 255
    #error "Calculated SPBRG value is out of range for currnet CLOCK_FREQ."
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
    // the last character gets out, in case we have a breakpoint on
    the
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
ROM unsigned char CharacterArray[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void PrintChar(BYTE toPrint)
{
    BYTE PRINT_VAR;
    PRINT_VAR = toPrint;
    toPrint = (toPrint>>4)&0x0F;
    ConsolePut(CharacterArray[toPrint]);
    toPrint = (PRINT_VAR)&0x0F;
    ConsolePut(CharacterArray[toPrint]);
    return;
}
void PrintWord(WORD toPrint)
        {
            BYTE MSB,LSB;
            MSB = toPrint >> 8;
            LSB = toPrint & 0x00FF;
            UART1PrintChar(MSB);
            UART1PrintChar(LSB);
        }


#endif