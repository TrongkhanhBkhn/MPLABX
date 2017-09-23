#include "p18f46k20.h"
#pragma config FOSC=HS 
#pragma config WDTEN=OFF
#pragma config LVP=OFF
#pragma config PBADEN=OFF
#pragma config MCLRE=ON

void timer_isr();
void init_timer(void);
#define LED  LATAbits.LATA0
void init_timer(void){
    INTCONbits.TMR0IE = 1;//Enable TMR0 interrupt
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.TMR0IF = 0;
    T0CON = 0x85;				
    TMR0L = 0x55;
}
void main(void){
    init_timer();
    TRISA= 0x00;
    LED = 1;
    while(1){

    };
}
#pragma code InterruptVector = 0x08
void InterruptVector()
{
	_asm
	goto timer_isr
	_endasm
}
#pragma interrupt timer_isr
void timer_isr(){
    if(INTCONbits.TMR0IF){
        LED = 0;
        TMR0L = 0x55;
       INTCONbits.T0IF == 0;
    }
  
}

