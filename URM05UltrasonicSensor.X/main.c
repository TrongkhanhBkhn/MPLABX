#include "main.h"
#pragma config FOSC=HS,WDTEN=OFF,LVP=OFF,PBADEN=OFF,MCLRE=ON
int time_diff = 0;
void TMR0_isr(void);
void setup(void){
    INIT_TRIS = 0;
    ECHO_TRIS = 1;
    ECHO_PORT = 1;
    LED_TRIS = 0;
    LED_LAT = 1;
}
void init_timer(void)
{
    T0CON = 0x17;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    TMR0H = 0x00;
    TMR0L = 0x00;
}
void main(void){
    setup();
    init_timer();
    Delay10TCY();
    T0CONbits.TMR0ON = 1;
    while(1){
        if(!ECHO_PORT){
            time_diff = (TMR0L>>8)|TMR0H;
            if(time_diff >100){
                LED_LAT =~LED_LAT;
                time_diff = 0;
            }
        }
    }
    
}
#pragma code interrupt_vector = 0x08
void interrupt_vector(void){
    _asm
            goto TMR0_isr
    _endasm
}
#pragma interrupt TMR0_isr
void TMR0_isr(void){
    if(INTCONbits.TMR0IF == 1){
       // flag = 1;
        time_diff +=0xFFFF;
        INTCONbits.TMR0IF = 0;
    }
}

