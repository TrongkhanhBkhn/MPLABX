#include "Console.h"
  void ConsoleInit(void)
    {
        U2BRG  = (CLOCK_FREQ/2/16)/BAUD_RATE-1;
        U2MODE = 0x8000;//enable UART2
                        //U2TX and U2RX pins are enabled and used
                        //Standard Speed mode (16 BRG clock cycles per bit)
                        //8-bit data, no parity
                        //One Stop bit

        U2STA = 0x2400;//Transmit is enabled, U2TX pin is controlled by UART2
        IEC1bits.U2RXIE = 1;
        IFS1bits.U2RXIF = 0;         /*clear interrupt flag*/
        U2MODEbits.UARTEN = 1;
        U2STAbits.UTXEN = 1;
    }

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
