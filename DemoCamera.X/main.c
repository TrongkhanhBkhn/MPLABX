#include "p24FJ128GA306.h"
#include "console.h"
#include "PTC06.h"
    _CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF & LPCFG_OFF & ICS_PGx1 & WINDIS_OFF & FWDTEN_WDT_SW &  FWPSA_PR128 & WDTPS_PS512);
    _CONFIG2(IESO_ON & FNOSC_FRC & FCKSM_CSECME & OSCIOFCN_OFF & IOL1WAY_OFF & POSCMD_HS);
    _CONFIG3(BOREN_ON);
int main(void){
    BYTE rxbuffer[255];
    OSCCON = 0x2001;//current osc HS, new osc FRC
    CLKDIV = 0x0000;//Fcy = Fosc/2

    /************Maping Pins************/
    //unlock registers
    asm volatile ("mov #OSCCONL, w1  \n"
        "mov #0x46, w2     \n"
        "mov #0x57, w3     \n"
        "mov.b w2, [w1]    \n"
        "mov.b w3, [w1]    \n"
        "bclr OSCCON, #6");
        /*------UART2-----*/
    // RX2 >> RP24
    RPINR19bits.U2RXR = 24;
    // TX2 >> RP23
    RPOR11bits.RP23R  = 5;
   /*------UART1-----*/
    // RX1 >> RP22
    RPINR18bits.U1RXR = 22;
    // TX1 >> RP25
    RPOR12bits.RP25R  = 3;

    asm volatile ("mov #OSCCONL, w1  \n"
        "mov #0x46, w2     \n"
        "mov #0x57, w3     \n"
        "mov.b w2, [w1]    \n"
        "mov.b w3, [w1]    \n"
        "bset OSCCON, #6");
    CLRWDT();
    ENABLE_WDT();
    WSAN_LED_TRIS = 0;
    WSAN_LED = 1;
    ConsoleInit();
    UART1Init();
    UART1PrintChar(sendReset());
    while(1){
       
    };
    return 0;
}
void _ISR __attribute__((interrupt, auto_psv)) _U2RXInterrupt(void)
{
    IFS1bits.U2RXIF = 0;
    WSAN_LED = ~WSAN_LED;
    LATFbits.LATF3 = ~LATFbits.LATF3;
}
