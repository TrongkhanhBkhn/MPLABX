#include <xc.h>


//set the configuration bits: internal OSC, everything off except MCLR
#pragma config FOSC =INTRC_CLKOUT
#pragma config WDTE=OFF
#pragma config PWRTE=OFF
#pragma config MCLRE=ON
 #pragma config CP=OFF

#pragma config CPD=OFF
#pragma config BOREN=OFF
#pragma config IESO=OFF
#pragma config FCMEN=OFF

#define _XTAL_FREQ 4000000

int flag = 0;
void interrupt isr()
{ 
        //reset the interrupt flag
        INTCONbits.INTF = 0;
        flag =1;
}

int main()
{
    TRISA = 0xFF;   //set all digital I/O to inputs
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISD = 0x00;
    ANSEL = 0x00;   //disable all analog ports
    ANSELH = 0x00;
    TRISCbits.TRISC7 = 0;
    PORTD =0x00;
    INTCONbits.INTF = 0;        //reset the external interrupt flag
    OPTION_REGbits.INTEDG = 1; //interrupt on the rising edge
    INTCONbits.INTE = 1;        //enable the external interrupt
    INTCONbits.GIE = 1;         //set the Global Interrupt Enable

    while(1)
    {
        if(flag){
            PORTD = 0x01;
            for(float j =0;j<1000;j++);
             PORTD = 0x02;
            for(float j =0;j<1000;j++);
                PORTD = 0x04;
            for(float j =0;j<1000;j++);
             PORTD = 0x08;
            for(float j =0;j<1000;j++);
                PORTD = 0x04;
            for(float j =0;j<1000;j++);
             PORTD = 0x02;
            for(float j =0;j<1000;j++);
            PORTD = 0x01;
            for(float j =0;j<1000;j++);
            PORTD = 0x00;
            flag = 0;

        }
        
    }

    return 0;
}