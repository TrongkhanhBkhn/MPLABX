#include"p18f26k20.h"
#include"lcd.h"
#include"pwm.h"
#include"timers.h"
#include"uart.h"
#include"stdlib.h"
#include"math.h"

 
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

#define TMR2_period 249 // set register PR2 = 249
#define LED1 LATAbits.LATA4
#define LED2 LATAbits.LATA5
//#define KEYPAD_TRIS TRISC
//#define KEYPAD_LAT LATC
//#define KEYPAD_PORT PORTC

#define ON 1
#define OFF 0 


void OSC_config(void);
//void Wait(unsigned int delay);
void ControlRemote(void);
void Display(void);
char NumberToChar(unsigned int param);
unsigned int CharToNumber(char param_char);
void Func_interrupt(void);
void Speed(void);
void Wait(unsigned int delay);
char str1[]="Setting";
char str2[]="Turning Left";
char str3[]="Turning Right";
char str4[]="N =";
char str5[]="Start";
char str6[]="Rotation Motor!";
char str7[]="Bluetooth";
char str8[]="Button";
char str9[]="MODE =";
char str10[]="Select mode";
char warning[]="WARNING-ERROR";
unsigned char duty_cycles1[2]={58,143};
unsigned char duty_cycles2[3]={58,101,143};
unsigned char duty_cycles3[4]={58,88,114,143};
unsigned char duty_cycles4[5]={58,82,101,121,143};
unsigned char duty_cycles5[6]={58,78,94,109,125,143};
unsigned char duty_cycles6[7]={58,75,88,101,114,127,143};
unsigned char duty_cycles7[8]={58,74,85,96,107,119,130,143};
unsigned char duty_cycles8[9]={58,72,82,92,101,102,111,121,143};
unsigned char duty_cycles9[10]={58,74,80,88,97,106,115,124,133,143};
unsigned char duty_cycles10[11]={58,71,80,88,96,103,111,120,127,135,143};
unsigned char duty_cycles15[16]={58,67,74,78,84,89,95,100,105,110,115,120,126,131,137,143};
int duty_cycles18[19]={58,63,68,73,77,82,86,91,95,100,105,110,114,119,124,129,133,139,143};
int duty_cycles19[5]={0, 150, 249};
volatile char data_uart;
int speed1 = 0, speed2 = 0;
int temp=0;
int i=0,j=0;
int dem = 0;
char *b;
char *c;
// main

void main(void)
{
    char period =249;
    TRISCbits.TRISC2=0;
    TRISCbits.TRISC1=0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA5 = 0;
    LED1=1;
    LED2=1;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB1 = 1;
    //KEYPAD_TRIS =0x79;
   // KEYPAD_LAT=0x00;
    
    INTCON2bits.RBPU = 0;//PB0-->PB1 have weak pull-up to Vcc
    WPUB = 0x0f;
	OSC_config();
	
  
    //----------------------open TMR2 before Open PWM2--------------------------------------------
	OpenTimer2(TIMER_INT_OFF&T2_PS_1_16&T2_POST_1_1);
	
	//-------------------------Configure pwm -----------------------------------------------------
	OpenPWM1(period);			//Configure PWM module and initialize PWM period
		//-------------------------Configure pwm -----------------------------------------------------
	OpenPWM2(period);			//Configure PWM module and initialize PWM period
	
	//---------------------set duty cycle---------------------------------------------------------
	
    Init_PORTS();
    Init_LCD();
    Delay1KTCYx(10);
    lcd_clear();
    lcd_gotoxy(1,1);
    lcd_putstr(str6);
    lcd_gotoxy(1,2);
    lcd_putstr(str5);
    SetDCPWM1(0);
    SetDCPWM2(0);
    
    UART_Config(25);
    Init_Tran_UART();
    Init_Rec_UART();
    Delay1KTCYx(10);
    while(1){
          if (PORTBbits.RB1 == 0){
               Delay1KTCYx(5);
                 if (PORTBbits.RB1 == 0){
                     dem ++;
                     if(dem >=3){
                         dem = 0;
                     }
                 }
          }
         if(dem ==2){
              lcd_clear();
              lcd_gotoxy(1,1);
              lcd_putstr(str7);
                if((data_uart == '0') || data_uart == '1' || data_uart == '2' || data_uart == '3'){
                    switch(data_uart){
                        case '0':
                        {
                             lcd_clear();
                             lcd_gotoxy(1,1);
                             lcd_putstr(str5);
                             lcd_gotoxy(1,2);
                             lcd_putstr(str2);
                             SetDCPWM1(150);
                             SetDCPWM2(0);
                             RCREG=0x00;
                        }break;
                        case '1':
                        {
                             lcd_clear();
                             lcd_gotoxy(1,1);
                             lcd_putstr(str5);
                             lcd_gotoxy(1,2);
                             lcd_putstr(str2);
                            SetDCPWM1(249);
                            SetDCPWM2(0);
                            RCREG=0x00;
                        }break;
                        case '2':
                        {
                             lcd_clear();
                             lcd_gotoxy(1,1);
                             lcd_putstr(str5);
                             lcd_gotoxy(1,2);
                             lcd_putstr(str3);
                             SetDCPWM1(0);
                             SetDCPWM2(150);
                             RCREG=0x00;
                        }break;
                        case '3':
                        {
                             lcd_clear();
                             lcd_gotoxy(1,1);
                             lcd_putstr(str5);
                             lcd_gotoxy(1,2);
                             lcd_putstr(str3);
                             SetDCPWM1(0);
                             SetDCPWM2(249);
                             RCREG=0x00;
                        }break;
                        default :{
                            SetDCPWM1(0);
                            SetDCPWM2(0);
                            RCREG=0x00;
                        }break;
                    }
                }
          }
          if(dem ==1){
              RCREG=0x00;
             lcd_clear();
             lcd_gotoxy(1,1);
             lcd_putstr(str8);
            Speed();
          }
    };	
}


void OSC_config(void)
{
    // cau hinh dao dong tan so 1MHz trong thanh ghi OSCCON
    OSCCONbits.IRCF0=1;
    OSCCONbits.IRCF1=1;
    OSCCONbits.IRCF2=0;
}

unsigned int CharToNumber(char param_char)
{
    unsigned int number;
    if (param_char == '0') number = 0;
    if (param_char == '1') number = 1;
    if (param_char == '2') number = 2;
    if (param_char == '3') number = 3;
    if (param_char == '4') number = 4;
    if (param_char == '5') number = 5;
    if (param_char == '6') number = 6;
    if (param_char == '7') number = 7;
    if (param_char == '8') number = 8;
    if (param_char == '9') number = 9;
    return number;
}
/************************************
 * Funtion: Change data from number type
 * to a character
 * Input: A number from 0 to 9
 * Output: a character from '0' to '9'
 * Date: 21102013
 * By: Engineer's Life
 ***********************************/
char NumberToChar(unsigned int param)
{
    char character;
    if (param == 0) character = '0';
    if (param == 1) character = '1';
    if (param == 2) character = '2';
    if (param == 3) character = '3';
    if (param == 4) character = '4';
    if (param == 5) character = '5';
    if (param == 6) character = '6';
    if (param == 7) character = '7';
    if (param == 8) character = '8';
    if (param == 9) character = '9';
    if (param == 10) character = 'A';
    if (param == 11) character = 'B';
    if (param == 12) character = 'C';
    if (param == 13) character = 'D';
    if (param == 14) character = 'E';
    if (param == 15) character = 'F';
    if (param == 16) character = 'G';
    if (param == 17) character = 'H';
    if (param == 18) character = 'I';
    return character;
}
void ControlRemote(void)
{		                   
						                    lcd_clear();
						                    lcd_gotoxy(1,1);
						                    lcd_putstr(str3);
						                    lcd_gotoxy(1,2);
						                    lcd_putstr(str4);
						                    lcd_putch(data_uart);
						                    lcd_gotoxy(11,2);
						                    lcd_putstr(str5);
						                    Delay1KTCYx(5);
						                    switch(data_uart)
						                    {
								                  case '1':
								                  {
									                for(i=0;i<=1;i++)
									                {
									                SetDCPWM1(duty_cycles1[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                  case '2':
								                  {
									                for(i=0;i<=2;i++)
									                {
									                SetDCPWM1(duty_cycles2[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case '3':
								                  {
									                for(i=0;i<=3;i++)
									                {
									                SetDCPWM1(duty_cycles3[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case '4':
								                  {
									                for(i=0;i<=4;i++)
									                {
									                SetDCPWM1(duty_cycles4[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case '5':
								                  {
									                for(i=0;i<=5;i++)
									                {
									                SetDCPWM1(duty_cycles5[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case '6':
								                  {
									                for(i=0;i<=6;i++)
									                {
									                SetDCPWM1(duty_cycles6[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case '7':
								                  {
									                for(i=0;i<=7;i++)
									                {
									                SetDCPWM1(duty_cycles7[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case '8':
								                  {
									                for(i=0;i<=8;i++)
									                {
									                SetDCPWM1(duty_cycles8[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case '9':
								                  {
									                for(i=0;i<=9;i++)
									                {
									                SetDCPWM1(duty_cycles9[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }
									                
								                  }
								                  break;
								                 case 'a':
								                  {
									                for(i=0;i<=10;i++)
									                {
									                SetDCPWM1(duty_cycles10[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }     
								                  } 
								                  break;
										        case 'b':
								                  {
									                for(i=0;i<=15;i++)
									                {
									                SetDCPWM1(duty_cycles15[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }     
								                  } 
								                  break;
								                  case 'c':
								                  {
									                for(i=0;i<=18;i++)
									                {
									                SetDCPWM1(duty_cycles18[i]);
									                LATAbits.LATA3=1;
									                Delay1KTCYx(1000);
									                LATAbits.LATA3=0;
									                Delay1KTCYx(100);
									                }     
								                  } 
								                  break;
								                  default : break;
								             };

						              
}
void Speed(void){
     if (PORTBbits.RB2 == 0){
         Delay1KTCYx(5);
          if (PORTBbits.RB2 == 0){
              speed2 = 0;
              speed1 ++;             
              if(speed1 >=3){
                  speed1 = 0;
              }
              SetDCPWM1(duty_cycles19[speed1]);
              SetDCPWM2(speed2);
          }
         lcd_clear();
         lcd_gotoxy(1,1);
         lcd_putstr(str5);
         lcd_gotoxy(1,2);
         lcd_putstr(str2);

     }
     if (PORTBbits.RB3 == 0){      
         Delay1KTCYx(5);
          if (PORTBbits.RB3 == 0){
              speed1= 0;
              speed2 ++;
               if(speed2 >=3){
                  speed2 = 0;
              }
              SetDCPWM2(duty_cycles19[speed2]);
              SetDCPWM1(speed1);
          }
         lcd_clear();
         lcd_gotoxy(1,1);
         lcd_putstr(str5);
         lcd_gotoxy(1,2);
         lcd_putstr(str3);
     }
}
void Display(void)
{
	int spin_times=0;
	int set_mode =0;
    if (PORTBbits.RB2 == 0)
    {
                Delay1KTCYx(20);
                if (PORTBbits.RB2 == 0)
                {
	                lcd_clear();
	                lcd_gotoxy(1,1);
                    lcd_putstr(str10);
                    lcd_gotoxy(1,2);
                    lcd_putstr(str9);
                    while(PORTBbits.RB1 == 1)
                    {
	                    Delay1KTCYx(20);
	                    if (PORTBbits.RB3 == 0)
	                    {
	                             Delay1KTCYx(20);
	                             if (PORTBbits.RB3 == 0)
	                             {                     
		                                Delay1KTCYx(30);
		                                set_mode++;
		                                if(set_mode>=4)
		                                {
			                                set_mode=1;
		                                }
	                                    lcd_gotoxy(8,2);
	                                    lcd_putch(NumberToChar(set_mode));
	                              } 
	    				}
	                    if (PORTBbits.RB0 == 0)
	                    {
	                               Delay1KTCYx(20);
	                               if (PORTBbits.RB0 == 0)
	                               {
		                                Delay1KTCYx(30);
		                                set_mode--;
		                                if(set_mode==0)
		                                {
			                                set_mode=3;
		                                }
	                                    lcd_gotoxy(8,2); 
	                                    lcd_putch(NumberToChar(set_mode));
	                                }
	                      }
                   	  } ; 
                   	  lcd_clear();
                   	  lcd_gotoxy(1,1);
                   	  lcd_putstr(str8);
                   	  lcd_gotoxy(15,1);
                   	  lcd_putch(NumberToChar(set_mode));
                   	  lcd_gotoxy(1,2); 
                   	  lcd_putstr(str2) ;                 	  
                      switch(set_mode)
                      {
	                            case 1:
	                            {
		                                         
						         while (PORTBbits.RB1 == 1)
				                 {		
					                 	Delay1KTCYx(20);		                 
				                           if (PORTBbits.RB3 == 0)
				                           {
				                                Delay1KTCYx(20);
				                                if (PORTBbits.RB3 == 0)
				                                {                       
					                                Delay1KTCYx(30);
					                                spin_times++; 
					                                if(spin_times>18)
					                                {
						                                spin_times=18;
					                                }
				                                    lcd_gotoxy(15,2);
				                                    lcd_putch(NumberToChar(spin_times));
				                                }     
				                            }
				                            if (PORTBbits.RB0 == 0)
				                            {
				                                Delay1KTCYx(20);
				                               if (PORTBbits.RB0 == 0)
				                               {
					                                Delay1KTCYx(30);
					                                spin_times--;
					                                if(spin_times<=0)
					                                {
						                                spin_times=1;
					                                }
				                                    lcd_gotoxy(15,2); 
				                                    lcd_putch(NumberToChar(spin_times));
				                                }
				                            }
				
				                      };
				                    lcd_clear();
				                    lcd_gotoxy(1,1);
				                    lcd_putstr(str3);
				                    lcd_gotoxy(1,2);
				                    lcd_putstr(str4);
				                    lcd_putch(NumberToChar(spin_times));
				                    lcd_gotoxy(11,2);
				                    lcd_putstr(str5);
				                    Delay1KTCYx(5);
				                    switch(spin_times)
				                    {
						                 case 1:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles1[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                  case 2:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles2[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 3:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles3[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 4:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles4[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 5:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles5[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 6:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles6[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 7:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles7[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 8:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles8[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 9:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles9[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                
						                  }
						                  break;
						                 case 10:
						                  {
							                for(i=0;i<=spin_times;i++)
							                {
							                SetDCPWM1(duty_cycles10[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }     
						                  } 
						                  break;
								        case 11:
						                  {
							                for(i=0;i<=15;i++)
							                {
							                SetDCPWM1(duty_cycles15[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }     
						                  } 
						                  case 12:
						                  {
							                for(i=0;i<=18;i++)
							                {
							                SetDCPWM1(duty_cycles18[i]);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
							                LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }     
						                  } 
						                  break;
						                  default : break;
				                     };                
		                            
	                            };
	                            break;
	                            case 2: 
	                            {
		                            
		                            while (PORTBbits.RB1 == 1)
				                    {
				                           if (PORTBbits.RB3 == 0)
				                           {
				                                Delay1KTCYx(10);
				                                if (PORTBbits.RB3 == 0)
				                                {
					                                spin_times++;                        
					                                Delay1KTCYx(30);
					                                if(spin_times>18)
					                                {
						                                spin_times=18;
					                                }
				                                    lcd_gotoxy(15,2);
				                                    lcd_putch(NumberToChar(spin_times));
				                                }     
				                            }
				                            if (PORTBbits.RB0 == 0)
				                            {
				                                Delay1KTCYx(10);
				                               if (PORTBbits.RB0 == 0)
				                               {
					                                spin_times--;
					                                Delay1KTCYx(30);
					                                if(spin_times<0)
					                                {
						                                spin_times=0;
					                                }
				                                    lcd_gotoxy(15,2); 
				                                    lcd_putch(NumberToChar(spin_times));
				                                }
				                            }
				
				                       };
				                    lcd_clear();
				                    lcd_gotoxy(1,1);
				                    lcd_putstr(str3);
				                    lcd_gotoxy(1,2);
				                    lcd_putstr(str4);
				                    lcd_putch(NumberToChar(spin_times));
				                    lcd_gotoxy(11,2);
				                    lcd_putstr(str5);
				                    Delay1KTCYx(5);
				                    switch(spin_times)
				                    {
						                  case 1:
						                  {
							                for(i=0;i<49;i++)
							                {
							             	SetDCPWM2(145.5);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(145);
						                  }
						                  break;
						                  case 2:
						                  {
 											for(i=0;i<60;i++)
							                {
							             	SetDCPWM2(146);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(200);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(145);
						                  }
						                  break;
						                 case 3:
						                  {
							                 for(i=0;i<65;i++)
							                {
							             	SetDCPWM2(146.5);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(200);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                	SetDCPWM2(145);
						                  }
						                  break;
						                 case 4:
						                  {
											 for(i=0;i<49;i++)
							                {
							             	SetDCPWM2(144.5);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							               SetDCPWM2(145);
						                  }
						                  break;
						                 case 5:
						                  {
							                 for(i=0;i<60;i++)
							                {
							             	SetDCPWM2(144);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(200);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(145);
						                  }
						                  break;
						                 case 6:
						                  {
							                for(i=0;i<65;i++)
							                {
							             	SetDCPWM2(143.5);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(200);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(147);
						                  }
						                  break;
						                 case 7:
						                  {
							                for(i=0;i<36;i++)
							                {
							             	SetDCPWM2(143);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(200);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(143);
						                  }
						                  break;
						                 case 8:
						                  {
											 for(i=0;i<36;i++)
							                {
							             	SetDCPWM2(151);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(143);
						                  }
						                  break;
						                 case 9:
						                  {
							                for(i=0;i<36;i++)
							                {
							             	SetDCPWM2(152);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(143);
						                  }
						                  break;
						                 case 10:
						                  {
							                for(i=0;i<36;i++)
							                {
							             	SetDCPWM2(153);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }
							                SetDCPWM2(143); 
						                  } 
						                  break;
						                   
						                 case 11:
						                  {
							                for(i=0;i<36;i++)
							                {
							             	SetDCPWM2(154);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                }  
							                SetDCPWM2(143); 
						                  } 
						                  break;
						                  case 12:
						                  {
							                for(i=0;i<36;i++)
							                {
							             	SetDCPWM2(155);
							                LATAbits.LATA3=1;
							                Delay1KTCYx(1000);
						                    LATAbits.LATA3=0;
							                Delay1KTCYx(100);
							                } 
							                SetDCPWM2(143); 
						                  } 
						                  break;
						                  default : break;
				                     };              
	                            };
	                            break;                               
	                            break;
	                            default :break;
                            }
               }
    } 
}
#pragma code interrupt_vector=0x18
void interrupt_vector(void)
{
	_asm
	goto Func_interrupt
	_endasm
}
#pragma code
#pragma interrupt Func_interrupt
void Func_interrupt(void)
{
		PIR1bits.RCIF=0;
		data_uart = RCREG;
		uart_putc(data_uart);			
}
