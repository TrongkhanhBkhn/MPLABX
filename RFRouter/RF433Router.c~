/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : RF315Coordinator
Version : 1 
Date    : 9/11/2014
Author  : TrongKhanhBKHN
Company : BKA
Comments: 


Chip type               : ATmega8
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <RF433Router.h>

#ifndef RXB8
#define RXB8 1
#endif

#ifndef TXB8
#define TXB8 0
#endif

#ifndef UPE
#define UPE 2
#endif

#ifndef DOR
#define DOR 3
#endif

#ifndef FE
#define FE 4
#endif

#ifndef UDRE
#define UDRE 5
#endif

#ifndef RXC
#define RXC 7
#endif

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)

// USART Receiver buffer
#define RX_BUFFER_SIZE 255
char rx_buffer[RX_BUFFER_SIZE];
#if RX_BUFFER_SIZE <= 256
unsigned char rx_wr_index,rx_rd_index,rx_counter;
#else
unsigned int rx_wr_index,rx_rd_index,rx_counter;
#endif

// This flag is set on USART Receiver buffer overflow
bit rx_buffer_overflow;
volatile uint8_t i = 0, flag = 0, count = 0;
uint8_t buffer[30];  
// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void)
{       
    uint8_t status,data;
    status = UCSRA;
    data = UART_RecieveChar();  
    USART_Flush();
    if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0){ 
       buffer[i++] = data;  
       if((data == '1')||(data == '2'))
       { 
          CC1101_SendPacket(buffer);  
          puts(buffer);
          ClearBuffer(buffer,i);
          flag = 1;
          i = 0; 
       }       
    }
}
// Standard Input/Output functions

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Place your code here
 uint8_t chip_status_rx, chip_status_tx;
// Reinitialize Timer1 value
TCNT1=0xCF2C;
// Place your code here
LED3 = ~LED3;
    chip_status_rx = CC1101_ReadChipStatusRX();  // check the rx status 
    if ((chip_status_rx & CHIP_STATE_MASK) == CHIP_STATE_RXFIFO_OVERFLOW)   // if rx overflow flush the rx fifo
      CC1101_FlushRX();  
    if ((chip_status_rx & CHIP_STATE_MASK) == CHIP_STATE_IDLE)              // if state is idle go to rx state again
      CC1101_RXMode();  
    chip_status_tx = CC1101_ReadChipStatusTX();  // check the tx sttus
    if ((chip_status_tx & CHIP_STATE_MASK) == CHIP_STATE_TXFIFO_UNDERFLOW)  // if tx underflow flush the tx fifo
      CC1101_FlushTX(); 
}

void main(void)
{
uint8_t Key;
uint8_t Buffer[64],len,j;
// Declare your local variables here

// Input/Output Ports initialization
// Port B initialization
// Func7=In Func6=In Func5=Out Func4=In Func3=Out Func2=Out Func1=In Func0=In 
// State7=T State6=T State5=0 State4=T State3=0 State2=0 State1=T State0=T 
PORTB=0xFF;
DDRB=0x2C;

// Port C initialization
// Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0xFF;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0xE2;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
TCCR0=0x00;
TCNT0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: On
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x03;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
//INT2: OFF
MCUCR=0x00;
MCUCSR=0x00;
// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x04;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=0x00;
UCSRB=0x98;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 2*2000.000 kHz
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First
SPCR=0x50;
SPSR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Global enable interrupts
#asm("sei")
CC1101_Init();
Buffer[0]=CC1101_ReadReg(CC1101_IOCFG0);
if(Buffer[0]==0x06)
{
    for(i=0;i<6;i++) 
    {
        LED1=LED2=LED3=0; 
        delay_ms(100);
        LED1=LED2=LED3=1;
        delay_ms(100);
    }
    
}
ClearBuffer(Buffer, 64);
CC1101_RXMode(); 
while (1)
      {   
      if(flag == 1)
      { 
          LED1 = ~LED1;
          flag = 0;
      }
     /*  Key=GetKey(); 
        // Khi co nut nhan thi gui du lieu
        if(Key!=NO_BUTTON)
        {
            if(Key==KEY_1)
            {
                CC1101_SendPacket("BUTTON1");      

            }
            else if(Key==KEY_2)
            {
                CC1101_SendPacket("BUTTON2");  
      
            }
            while(Key) Key=GetKey();
            // Quay ve trang thai cho goi tin den
            CC1101_RXMode();
        } */
        // Khi co di lieu den
        if(GDO0)
        {   
            // Cho cho ket thuc goi tin
            while(GDO0);
            len=64;   
            // nhan goi tin
            CC1101_ReceivePacket(Buffer,&len); 
          //  Buffer[len]= 0;
            if(Buffer[0] == 'X')
            {
               if(Buffer[len-1]=='$')
               {
                   LED2=~LED2;
               }
               else if(Buffer[len-1]=='1')
               {
                   LED1=~LED1;
               } 
               CC1101_SendPacket(Buffer);
            } 
            puts(Buffer); 
            ClearBuffer(Buffer, len);  
            CC1101_RXMode();  
        } 

      }
}
