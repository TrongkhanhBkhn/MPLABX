/* 
 * File:   FindPosition.c
 * Author: TrongKhanh
 *
 * Created on March 20, 2015, 1:41 AM
 */

#include "FindPosition.h"
#include "Console.h"
#pragma config FOSC = INTIO67   // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
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
#define PERIOD 249
#define LAT_TRIGGER LATBbits.LATB0
#define TRIS_TRIGGER TRISBbits.TRISB0
#define PORT_ECHO PORTBbits.RB1
#define TRIS_ECHO TRISBbits.TRISB1
/*
 * 
 */
unsigned char duty_cycles[16]={58,67,74,78,84,89,95,100,105,110,115,120,126,131,137,143};
char str[]="Rada Detect Motion!";
char str1[] = "Detect Motion!";
void OSC_config(void)
{
    // cau hinh dao dong tan so 1MHz trong thanh ghi OSCCON
    OSCCONbits.IRCF0=1;
    OSCCONbits.IRCF1=1;
    OSCCONbits.IRCF2=0;
}
void delay_4us(){
    Delay1TCY();
}
void delay_15ms(){
    Delay10KTCYx(250);
    Delay1KTCYx(250);
    Delay1TCY();
}
void config_ExINT(void)
{
    INTCONbits.GIE=1;			//Enables all unmasked interrupts
    INTCONbits.PEIE=1;		//Enables all unmasked peripheral interrupts
    INTCON3bits.INT1IE=1;		//Enables the INT1 external interrupt
    INTCON3bits.INT1IF=0;		//The INT1 external interrupt did not occur. It mean I refresh this flag
    INTCON2bits.INTEDG0=1;	//External Interrupt 0 Edge Select bit_interrupt on falling edge
    INTCON2bits.INTEDG1=1;	//External Interrupt 1 Edge Select bit_Interrupt on falling edge
    INTCON3 = 0x08;
}
float getDistance(void){
    LAT_TRIGGER = 0;
    delay_4us();
    LAT_TRIGGER = 1;
    delay_15ms();
    while(!PORT_ECHO){
        T0CONbits.TMR0ON = 1;
        delay_15ms();
    }
}
void initTimer(char mode){
    T0CON = mode;
    TMR0L = 0x00;
    #ifdef USE_TIMER_16BITS
    TMR0H = 0x00;
    #endif
    #ifdef USE_INTERRUPT_PERIOD
	INTCONbits.TMR0IE = 1;//Enable TMR0 interrupt
	INTCON2bits.TMR0IP = 0;//TMR0 interrupt is low level
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
        INTCONbits.TMR0IE = 1;//Enable TMR0 interrupt
	INTCON2bits.TMR0IP = 0;//TMR0 interrupt is low level
    #endif
    //clear flag interrupt
    INTCONbits.TMR0IF = 0;
}
void main(void) {
    char mode;
    mode = STOP_TMR0& MODE_16_BITS& TIMER_MODE& USE_PRESCALE& PRES_256;
    TRISCbits.TRISC2=0;
    TRISCbits.TRISC1=0;
    TRIS_ECHO = 1;
    TRIS_TRIGGER = 0;
    LAT_TRIGGER = 0;
    PORT_ECHO = 1;
    INTCON2bits.RBPU = 0;//PB0-->PB1 have weak pull-up to Vcc
    WPUB = 0x0f;
    OSC_config();
    //----------------------open TMR2 before Open PWM2-------------
    OpenTimer2(TIMER_INT_OFF&T2_PS_1_16&T2_POST_1_1);
    initTimer(mode);
    //-------------------------Configure pwm ----------------------
    OpenPWM1(PERIOD);	//Configure PWM module and initialize PWM period
    //-------------------------Configure pwm ----------------------
    OpenPWM2(PERIOD);	//Configure PWM module and initialize PWM period
    //---------------------set duty cycle--------------------------
    Init_PORTS();
    Init_LCD();
    Delay1KTCYx(10);
    lcd_clear();
    lcd_gotoxy(1,1);
    lcd_putstr(str1);
    SetDCPWM1(58);
    SetDCPWM2(58);
    UART_Config(25);
    Init_Tran_UART();
    Init_Rec_UART();
    Delay1KTCYx(10);
    uart_puts(str);
    T0CONbits.TMR0ON = 1;
    while(1){
        
    };
}
#pragma code interrupt_vector=0x08
void interrupt_vector(void)
{
	_asm
	goto funcInterrupt
	_endasm
}
#pragma code
#pragma interrupt funcInterrupt
void funcInterrupt(void)
{
    if(PIR1bits.RCIF)
    {
        PIR1bits.RCIF=0;
        if(RCREG == '1'){
        uart_putc('1');
        lcd_clear();
        }
       
    }
    if(INTCONbits.TMR0IF)
    {
        lcd_clear();
        INTCONbits.TMR0IF = 0;
    }
//    if(INTCON3bits.INT1IF)
//    {
//       SetDCPWM1(100);
//       INTCON3bits.INT1IF = 0;
//    }
}

