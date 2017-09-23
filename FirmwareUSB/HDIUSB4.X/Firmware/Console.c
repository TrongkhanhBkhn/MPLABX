#include "Console.h"

void Init_UART(int baudrate)
{
    TXSTAbits.BRGH = 1;
    BAUDCONbits.BRG16 = 1;//16-bit Baud Rate Generator is used (SPBRGH:SPBRG)
    SPBRGH:SPBRG = baudrate;// tra bang 18-5 toc do baurate 19200

    TRISBbits.TRISB5 = 1;// RB5 la chan rx
    TRISBbits.TRISB7 = 0;// RB7 la chan tx

    TXSTAbits.SYNC =0;
    RCSTAbits.SPEN=1;  // cho phep noi tiep voi cac cong o che do uart

   // BAUDCONbits.CKTXP=0; // Idle state for transmit (TX) is high

    TXSTAbits.TXEN =1;   // cho phep truyen uart
    TXREG = 0x00;        // lam rong thanh ghi truyen

    PIE1bits.RCIE=1;     // cho phep ngat khi nhan uart
    INTCONbits.GIE=1;    // cho phep ngat toan cuc khi IPEN =1 set boi thanh ghi RCON
    INTCONbits.PEIE=1;   // cho phep ngat ngoai vi
    RCSTAbits.CREN =1;   // cho phep nhan uart khong dong bo
}

void Init_Tran_UART(void)
{
    BAUDCONbits.CKTXP=0; // Idle state for transmit (TX) is high
    TXSTAbits.TX9 =1;   //transmit 9 bit
    TXSTAbits.TXEN =1;   // cho phep truyen uart
    TXREG = 0x00;        // lam rong thanh ghi truyen
}

void Init_Rec_UART(void)
{
    PIE1bits.RCIE=1;     // cho phep ngat khi nhan uart
    INTCONbits.GIE=1;    // cho phep ngat toan cuc khi IPEN =1 set boi thanh ghi RCON
    INTCONbits.PEIE=1;   // cho phep ngat ngoai vi
    RCSTAbits.CREN =1;   // cho phep nhan uart khong dong bo
}

void Tran_UART(unsigned char ch)
{
    while(!TXSTAbits.TRMT);
    TXREG = ch;
}
void Tran_String_UART(unsigned char *str){
    while(*str !='\0'){
        Tran_UART(*str);
        str++;
    };
}

