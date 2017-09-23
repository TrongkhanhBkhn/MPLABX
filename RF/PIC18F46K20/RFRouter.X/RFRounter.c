/* 
 * File:   TranRF315.c
 * Author: Chu
 *
 * Created on May 1, 2014, 12:57 AM
 */
#include "RFRounter.h"


// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 18        // Brown Out Reset Voltage bits (VBOR set to 1.8 V nominal)

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT is controlled by SWDTEN bit of the WDTCON register)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config HFOFST = OFF     // HFINTOSC Fast Start-up (The system clock is held off until the HFINTOSC is stable.)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (008000-00BFFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (00C000-00FFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (008000-00BFFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (00C000h-00FFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

void OSC_config(void);
void Timer_Isr(void);
unsigned char wsan[] = "WSAN";
char str1[]="Setting";
char str2[]="DemoSPI";
char warning[]="WARNING-ERROR";
char temp[] = "Chu Trong Khanh";
/*************khai bao cac bien toan cuc **************/
unsigned char chip_status_rx, chip_status_tx;
unsigned char buffer[48];
unsigned char  Ok;
struct Wsan_data Wsan;
struct RF_Flag flag;

unsigned char success[]="Gui Thanh cong";
void main(void) {
    /*******************Init PORT************************/
    TRIS_LED =0;
    TRIS_BUT = 1;
    BUTTON = 1;
    TRISAbits.TRISA4 = 1;
    LED = 0;
    /**************Init Timer 1**************************/
    Timer1_Config();
     /********************LCD*****************************/
    Init_PORTS();
    Init_LCD();
    lcd_clear();
    Delay10TCYx(10);
    lcd_gotoxy(1,1);
    lcd_putstr(str1);
    Delay10TCYx(10);
    /********************UART****************************/
    #ifdef DEBUG_UART
    ConsoleInit();

    #endif
    /******************PORT CC1101***********************/
    SPI_Config_Master();
    MOSI_SOFT = 0;
    MISO_SOFT = 0;
    SCK_SOFT = 0;
    CC1101_CS = 1;
    GDO0 = 0;

    /**************CC1101_Init***************************/
    CC1101_Init();
    CC1101_RXMode();
    Delay10TCYx(10);
    lcd_clear();
    lcd_gotoxy(1,1);
    lcd_int(CC1101_ReadStatus(CC1101_IOCFG0));
    lcd_gotoxy(1,2);
    lcd_int(CC1101_ReadReg(CC1101_PKTCTRL0));
    while(1)
    {
        switch(flag.RF315_Flag) // nhan du lieu tu uart
        {
            case 1:
            {
                ConsoleGet(Wsan.data, 10);
                lcd_gotoxy(1,1);
                lcd_putstr(Wsan.data);
                  ConsolePutString(Wsan.data);
                if((*Wsan.data == 0xAA)&&(*(Wsan.data + 1) == 0x00))// nhan ban tin demo truyen nhan RF
                {
                    CC1101_SendPacket(Wsan.data);

                }
                if((*Wsan.data == 0xAA)&&(*(Wsan.data + 1) == 0x01))// ban tin dieu khien may bom
                {
                    if(*(Wsan.data +2)== 0x81)// gui ban tin bat van so 1
                    {
                        /* cau truc cua 1 ban tin gui di
                           Header gui 2 byte heade A, B
                           buffer[0] = MAC_LSB;
                           buffer[1] = MAC_MSP;
                           buffer[2]= address node mang
                           buffer[3] = command;// ma lenh yeu cau
                         */
                        SendData(wsan,NUT1, BAT_V1);
                    }
                }
               if((*Wsan.data == 0xAA)&&(*(Wsan.data + 1) == 0x02)) // gui ban yeu cau lay nhiet do, do am
                {
                      SendData(wsan,NUT2, NHIETDO_DOAM);
                }

            }break;
        }

            if(GDO0)
            {
               while(GDO0);
               Wsan.length= sizeof(buffer);
               if(CC1101_ReceivePacket(buffer,&Wsan.length) ==1) // doc du lieu
               {
                Ok=CC1101_ReadReg(CC1101_RXFIFO);
                buffer[Wsan.length]=0;
                lcd_clear();
                CC1101_ReceivePacket(buffer,&Wsan.length) ;
                lcd_gotoxy(1,2);
              //lcd_putstr((unsigned char *)buffer);
                LED =1;
                CC1101_RXMode();
               Delay10TCYx(100);
           }
         };
         
    };
}
#pragma code interrupt_vector = 0x18
void interrupt_vector(void)
{
    _asm
            goto Timer_Isr
    _endasm
}
#pragma code
#pragma interrupt Timer_Isr
void Timer_Isr(void)
{
    if(PIR1bits.TMR1IF == 1){
        Wsan.count++;
       PIR1bits.TMR1IF=0;
       TMR1H =0x00;
       TMR1L = 0x00;
       ConsolePutString((unsigned char *)str1);
     if(Wsan.count == 3){
         LED = ~LED;
          Wsan.count =0;
            chip_status_rx = CC1101_ReadChipStatusRX();  // check the rx status
            if ((chip_status_rx & CHIP_STATE_MASK) == CHIP_STATE_RXFIFO_OVERFLOW)   // if rx overflow flush the rx fifo
             CC1101_FlushRX();
            if ((chip_status_rx & CHIP_STATE_MASK) == CHIP_STATE_IDLE)              // if state is idle go to rx state again
             CC1101_RXMode();
            chip_status_tx = CC1101_ReadChipStatusTX();  // check the tx sttus
            if ((chip_status_tx & CHIP_STATE_MASK) == CHIP_STATE_TXFIFO_UNDERFLOW)  // if tx underflow flush the tx fifo
             CC1101_FlushTX();
       } 
    }
    if(PIR1bits.RCIF == 1)
    {
        flag.RF315_Flag = TRUE;// set co UART
        PIR1bits.RCIF = 0;// xoa co ngat UART
        lcd_clear();
       ConsolePutString((unsigned char *)str1);
       
    }
}
void SendData(unsigned char data[],unsigned char addr,  unsigned char command)
{
    unsigned char TxBuffer = 4;
    unsigned char buffer[];
    unsigned char length;
    buffer[0] = RF_MAC_LSB;
    buffer[1] = RF_MAC_MSB;
    buffer[2] = addr;
    buffer[3] = command;
    buffer[TxBuffer++] = data[TxBuffer - 4];
    length = sizeof(buffer);
    CC1101_SendPackets(buffer, length);
}
