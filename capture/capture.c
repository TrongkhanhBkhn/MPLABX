#include"p18f46k20.h"
#include"delays.h"
#include"lcd_lcd.h"
#include"stdio.h"
#pragma config FOSC = HS   // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
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
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)

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
 
 
void interrupt_isr(void);
void capture_mode1(void);
void capture_mode2(void);
void timer1_config(void);
void timer3_config(void);
unsigned long value_count=0,last_value=0,temp=0,count=0,data=0,value_count_sum=0,value_count_last=0;
unsigned long  tanso;
char str1[]="INPUT CAPTURE";

void capture_mode1(void)
{
	CCP1CON=0x04;
	/*
	CCP1CONbits.CCP1M3=0;
	CCP1CONbits.CCP1M2=1;
	CCP1CONbits.CCP1M1=0;
	CCP1CONbits.CCP1M0=0;
	*/
	RCONbits.IPEN = 1;
	IPR1bits.CCP1IP =0;
	INTCONbits.GIEL=1;
	INTCONbits.GIEH=1;
	PIR1bits.CCP1IF=0;
	PIE1bits.CCP1IE=1;
	CCPR1=0x0000;	
}
void capture_mode2(void)
{
	CCP2CON=0x04;
	/*
	CCP2CONbits.CCP1M3=0;
	CCP2CONbits.CCP1M2=1;
	CCP2CONbits.CCP1M1=0;
	CCP2CONbits.CCP1M0=0;
	*/
	RCONbits.IPEN = 1;
	INTCONbits.GIEL=1;
	INTCONbits.GIEH=1;
	IPR1bits.CCP1IP = 0;
	PIR2bits.CCP2IF=0;
	PIE2bits.CCP2IE=1;	
}
void timer1_config(void)
{
	T1CON=0x81;
	/*
		T1CONbits.T1CKPS1=0;
		T1CONbits.T1CKPS0=0;
		T1CONbits.TMR1CS=0;
	*/
	RCONbits.IPEN = 1;
	IPR1bits.TMR1IP = 0;
	INTCONbits.GIEL=1;
	INTCONbits.GIEH=1;
	PIR1bits.TMR1IF=0;
	PIE1bits.TMR1IE=1;
	TMR1H=0x00;
	TMR1L=0x00;
}
void timer3_config(void)
{
	T3CON=0x81;
	/*
	T3CONbits.RD16=1;
	T3CONbits.T3CCP2=0;
	T3CONbits.T3CCP1=1;
	T3CONbits.T3CKPS1=0;
	T3CONbits.T3CKPS0=0;
	T3CONbits.TMR3CS=0;
	*/
	INTCONbits.GIE=1;
	INTCONbits.PEIE=1;
	PIR2bits.TMR3IF=0;
	PIE2bits.TMR3IE=1;
	TMR3H=0x00;
	TMR3L=0x00;
	T3CONbits.TMR3ON=1;
}
void main(void)
{
	TRISCbits.TRISC2=1;
	Init_PORTS();
	Init_LCD();
	Delay1KTCYx(10);
	capture_mode1();
	timer1_config();
	Delay1KTCYx(10);
	lcd_clear();
	lcd_gotoxy(1,1);
	lcd_putstr(str1);
	while(1)
	{
		
		tanso =1000000/count;
		lcd_gotoxy(9,2);
		LCD_IN_INTER(tanso);
	};
}
#pragma code low_vector=0x18
void low_vector(void)
{
	_asm
	goto interrupt_isr
	_endasm
}
#pragma code 
#pragma interrupt interrupt_isr
void interrupt_isr(void)
{
	if(PIR1bits.CCP1IF==1)
	{
		count = CCPR1 + temp - last_value;
		last_value = CCPR1;
		temp=0;	
		PIR1bits.CCP1IF=0;
	}	
	if(PIR1bits.TMR1IF==1)
	{
		temp +=0xffff;	
		PIR1bits.TMR1IF=0;
	}
}
