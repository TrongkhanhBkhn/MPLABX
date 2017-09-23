/*
 * File:   TranRF315.c
 * Author: Chu
 *
 * Created on May 1, 2014, 12:57 AM
 */
#include "LCD.h"
#include "stdlib.h"
#include "stdio.h"
#include "Timer.h"
#include "UART.h"


//// CONFIG1H
//#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
//#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
//#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)
//
//// CONFIG2L
//#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
//#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
//#pragma config BORV = 18        // Brown Out Reset Voltage bits (VBOR set to 1.8 V nominal)
//
//// CONFIG2H
//#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT is controlled by SWDTEN bit of the WDTCON register)
//#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)
//
//// CONFIG3H
//#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
//#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
//#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
//#pragma config HFOFST = OFF     // HFINTOSC Fast Start-up (The system clock is held off until the HFINTOSC is stable.)
//#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
//
//// CONFIG4L
//#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
//#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
//#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))
//
//// CONFIG5L
//#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-003FFFh) not code-protected)
//#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (004000-007FFFh) not code-protected)
//#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (008000-00BFFFh) not code-protected)
//#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (00C000-00FFFFh) not code-protected)
//
//// CONFIG5H
//#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
//#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)
//
//// CONFIG6L
//#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-003FFFh) not write-protected)
//#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (004000-007FFFh) not write-protected)
//#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (008000-00BFFFh) not write-protected)
//#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (00C000h-00FFFFh) not write-protected)
//
//// CONFIG6H
//#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
//#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
//#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)
//
//// CONFIG7L
//#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
//#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
//#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
//#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)
//
//// CONFIG7H
//#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)
#pragma config FOSC = HS
#pragma config FCMEN = OFF, BOREN = OFF
#pragma config WDTEN = OFF, MCLRE = ON, LVP = OFF
#define GREEN LATAbits.LATA4
#define BLUE LATCbits.LATC3
#define RED  LATCbits.LATC4
#define USE_ADC_H
void init_ADC(void);
void  ADC_isr(void);
char title[] = "BLT - Cam bien va ky thuat do luong - Phat hien do mau";
char temp[] = "Phat Hien Do Mau";
char reds[] = "Mau do  ";
char warning[] = "Phat hien do mau  ";
char error[] = "Other    ";
char str1[] = "Do mau";
char str2[] = "XLC    ";
unsigned int result;
unsigned int temperature;
unsigned char a,b;
unsigned char flag = 0;
unsigned int red, green, blue;
int count = 0;
void main(void) {
    /*******************Init PORT************************/
   INTCON2bits.RBPU = 0;//PB0-->PB7 have weak pull-up to Vcc
    WPUB = 0x0f;
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC3 = 0;
    TRISAbits.TRISA4 = 0;
    RED =0;
    GREEN =0;
    BLUE =0 ;

    timer0_config(); 
    /***************************Init LCD**************************/
    Init_PORTS();
    Init_LCD();
    Delay10TCYx(10);
    lcd_clear();
    lcd_gotoxy(1,1);
    lcd_putstr(temp);
    /***************************Init ADC*************************/
    init_ADC();
      /***************************UART*************************/
   
    ConsoleInit();
    uart_puts(title);
   Delay10TCYx(10);
    ADCON0bits.GO = 1;//Start conversion by setting the GO/~DONE bit
    while(1)
    {
        if(flag)
        {
           count++;
           if((count >0) && (count<=4))
                {
                   RED =1;
                   GREEN =0;
                   BLUE =0 ;
                   red = ADRESH;
                   red = red << 8;
		   red = red | ADRESL;
                   ADCON0bits.GO = 1;
                }

                if((count >4) && (count<=8))
                {
                   RED =0;
                   GREEN =1;
                   BLUE =0 ;
                   green = ADRESH;
                   green = green << 8;
		   green = green | ADRESL;
                  ADCON0bits.GO = 1;
                }
               if((count >8) && (count<=12))
                {
                   RED =0;
                   GREEN =0;
                   BLUE =1;
                   blue = ADRESH;
                   blue = blue << 8;
		   blue = blue | ADRESL;
                   ADCON0bits.GO = 1;
               }
            if(count > 12) count =0;
           result = red +green + blue;
           lcd_gotoxy(8,2);
           LCD_IN_INTER(result);
              if(result < 400)
              {
                  lcd_gotoxy(1,2);
                  lcd_putstr(str1);
              }
              else
              {
                  lcd_gotoxy(1,2);
                  lcd_putstr(error);
              }
              flag = 0;
      }    
    };
}
void init_ADC(void)
{
	/***************************Configure port***************************/
	TRISBbits.TRISB2 = 1;
	ANSEL = 0x00;		// Set PORT RA0 is analog input
	ANSELH = 0x01;			// Set PORT AN8 to AN12 as Digital I/O

	/************************Configure ADC module************************/
	//Select ADC conversion clock
	//Select result format
	//Select acquisition delay
	ADCON2 = 0x91;	//ADCS<2:0> = 001 => Conversion clock = Fosc/8
					//Right justified
					//ACQT<2:0> = 010 => Acquisition Time = 4 Tad

	//Configure voltage reference
	ADCON1 = 0x00;	//negative voltage reference supplied by Vss
					//positive voltage reference supplied by VREF+ = 3.3V

	//Select ADC input channel
	ADCON0 = 0x20;	//CHS<3:0> = 0000 => select channel AN8

	//Turn on ADC module
	ADCON0bits.ADON = 1;

	/******************Configure ADC interrupt (optional)*****************/
	//Clear ADC interrupt flag
	PIR1bits.ADIF = 0;

	//Enable ADC interrupt
	PIE1bits.ADIE = 1;

	//Enable peripheral interrupt
	INTCONbits.PEIE = 1;

	//Enable global interrupt
	INTCONbits.GIE = 1;
}


#pragma code interrupt_vector=0x08
void interrupt_vector()
{
	_asm
	goto ADC_isr
	_endasm
}
#pragma interrupt ADC_isr
void  ADC_isr(void)
{
        if(PIR1bits.ADIF == 1)
        {
            PIR1bits.ADIF = 0;
        }
        if( INTCONbits.TMR0IF ==1)
        {
             flag = 1;
            TMR0H=0xF0;
            TMR0L=0x00;
            INTCONbits.TMR0IF=0;
        }
}
