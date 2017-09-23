#include"p24fj128ga110.h"
#include "libpic30.h"
#include"stdio.h"
#include"stdlib.h"
#include "lcd.h"
 

 void mapping_pin(void);
 void Capture1_config(void);
 void Timer2_config(void);
unsigned long pre_count=0,past_count=0,temp=0;
char str1[]= " INTPUT CAPTURE";
 int frequence;
 void mapping_pin(void)
 {
	  // mapping pin RP1 is Input Capture Pin
	  RPINR7bits.IC1R=1;
    /* RPINR7bits.IC1R5=0;
     RPINR7bits.IC1R4=0;
     RPINR7bits.IC1R3=0;
     RPINR7bits.IC1R2=0;
     RPINR7bits.IC1R1=0;
     RPINR7bits.IC1R0=1;*/
	} 
 void Capture1_config(void)
 {
	TRISBbits.TRISB1=1;
	IC1CON1=0x2413;	// IC1CON1=0b0010010000010011
					/* Input capture module Halts in CPU Idle mode
					 * Input Capture Timer2
					 * Interrupt on every capture event
					 * Input capture overflow has occurred
					 * Input capture buffer is empty
					 * Simple Capture mode: capture on every rising edge
					*/	
	 IC1CON2 = 0x0050; 			
	 IFS0bits.IC1IF=0;
	 IEC0bits.IC1IE=1;
	 IC1BUF=0;
 } 
 void Timer2_config(void)
 {
	T2CON = 0x0000;//T2CON=0b1000000000000000
			/* 			
				*/
	//Interrupt priority: 1
	//IPC1bits.T2IP = 0;
	IEC0bits.T2IE = 1;
	IFS0bits.T2IF = 0;		
	IC2TMR=0;
	TMR2=0;
	T2CONbits.TON=1;			
 }
int main(void)
 {
	 TRISCbits.TRISC1=0;
	 TRISCbits.TRISC2=0;
	 TRISCbits.TRISC3=0;
 	 TRISCbits.TRISC4=0;
	 Init_PORTS();
	 Init_LCD();
	 
 	 Capture1_config();
	 Timer2_config();
	 mapping_pin();	 
	 
	 __delay32(1);
	 lcd_clear();
	 lcd_putstr(str1);
	 while(1)
	 {	
		 LATCbits.LATC3=1; 
		 frequence = 500000/pre_count;
		 lcd_gotoxy(10,2);
		 lcd_int(frequence);
	 	if(frequence >40)
	 	{
		 LATCbits.LATC4=1;
		} 
		else LATCbits.LATC4=0;
	 }; 
 } 
void __attribute__((interrupt, auto_psv)) _IC1Interrupt(void)
 {
	 pre_count = IC1BUF + temp - past_count;
	 past_count = IC1BUF;
	 temp =0;
	 LATCbits.LATC1 = 1;
	 IFS0bits.IC1IF=0;	 
}
void __attribute__((interrupt, shadow, auto_psv)) _T2Interrupt(void)
 {
	 LATCbits.LATC2=1;
	 temp +=0xffff;
	 IFS0bits.T2IF=0;
 } 	 
	 