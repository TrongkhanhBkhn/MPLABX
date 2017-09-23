/* ***************************************************************************
**  File Name    : adc.c
**  Version      : 1.0
**  Description  : MCU will take analog signal from sensor LM35 through RA0 pin,
**				   so this pin must beconfigure analog input. It also use reference
**				   voltage is external supply (3.3V). The result will be processed
**				   to display temperature in 2 7-seg led.
**  Author       : Chu Trong Khanh
*   Class          : DT5 - K55
**  Compiler     : Microchip C18 v3.40 C Compiler
**  IDE          : Microchip MPLAB IDE v8.83
**  Programmer   : Microchip PICKit2 Programmer
**  Last Updated : 30 April 2012
** ***************************************************************************/
#include "p18f14k50.h"
#include "LCD.h"
#include "Console.h"
#include "stdlib.h"
#include "math.h"

#pragma config FOSC = XT
#pragma config FCMEN = OFF, BOREN = OFF
#pragma config WDTEN = OFF, MCLRE = ON, LVP = OFF

//declare globle variable
//#define temperature result
char display_enable;

//prototype function
void init_ADC(void);
void ADC_isr(void);


//main function
char str1[] = "Cam bien mau";
char str2[] = "mau do  ";
char str3[] = "--> Do mau";
char *c;
char *b;
void main(void)
{

	int result =0,temperature =0;

	unsigned char a,b;
	init_ADC();
	Init_PORTS();
	Init_LCD();

        Init_UART(BAUDRATE);
        Init_Tran_UART();
        Init_Rec_UART();
        Delay1KTCYx(10);
        lcd_clear();
        lcd_gotoxy(1,1);
        lcd_putstr(str1);
        Tran_String_UART(str1);
	ADCON0bits.GO = 1;//Start conversion by setting the GO/~DONE bit

	while(1)
	{
		if(display_enable)
		{
			//get result from registers ADRESH & ADRESL
			result = ADRESH;
			result = result << 8;
			result = result | ADRESL;
			temperature = 5*result/ 10;
                       // b = itoa(temperature, a);
                         c = itoa(temperature,b);
                        if(temperature >10)
                        {
                              Tran_String_UART(str2);
                              lcd_gotoxy(1,2);
                              lcd_putstr(str2);
                               lcd_gotoxy(7,2);
                              lcd_putstr(str3);
                        }
                
			display_enable = 0;
			ADCON0bits.GO = 1;//Start conversion by setting the GO/~DONE bit
		}
	}
}

//Initialize ADC module
void init_ADC(void)
{
	/***************************Configure port***************************/
	TRISCbits.TRISC7 = 1;
	ANSEL = 0x01;		// Set PORT RA0 is analog input
	ANSELH = 0;			// Set PORT AN8 to AN12 as Digital I/O
	
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
	ADCON0 = 0x24;	//CHS<3:0> = 1001 => select channel AN9
	
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
	display_enable = 1;	
	//clear flag to re-enable interrupt
	PIR1bits.ADIF = 0;
}
