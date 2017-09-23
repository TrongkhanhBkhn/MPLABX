#include"timer.h"

void timer2_init(void)
{
    T2CONbits.TMR2ON = 1;	//start timer2
	T2CONbits.T2OUTPS3=0;//potscale =1:1
	T2CONbits.T2OUTPS2=0;
	T2CONbits.T2OUTPS1=0;
	T2CONbits.T2OUTPS0=0;
	T2CONbits.T2CKPS0 = 1;		
	T2CONbits.T2CKPS1 = 0;	//prescaler 1:16
	PIE1bits.TMR2IE = 1;
    IPR1bits.TMR2IP = 1;
    PIR1bits.TMR2IF = 0;
}
