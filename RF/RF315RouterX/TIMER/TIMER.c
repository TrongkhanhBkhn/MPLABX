#include "TIMER.h"

void Timer0_config(void)
{
	T0CON=0x82;// prescaler = 1:8
	TMR0H=0xF0;
	TMR0L=0x00;
        INTCONbits.GIEL=1;// disable global interrupt
	INTCONbits.GIEH=1;
	INTCONbits.TMR0IE=1;
	INTCONbits.TMR0IF=0;
}
void Timer1_config(void)
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
void Timer3_config(void)
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
