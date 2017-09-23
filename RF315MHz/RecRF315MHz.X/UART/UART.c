#include"UART/UART.h"
void UART_Init(int SPBRG_SET)
{

	/* relates crystal freq to baud rate - see above and PIC18f26k20 data sheet under async 'USART'

	BRGH=1, Fosc=3.6864MHz		BRGH=1, Fosc=4MHz      		BRGH=1, Fosc=8MHz    	BRGH=1, Fosc=16MHz
	----------------------	  	---------------------    	-----------------   	 ------------------
	Baud		SPBRG             Baud		SPBRG          Baud	SPBRG         Baud		SPBRG
	1200		191               1200		207.3          1200	415.7         9600		103
	2400		95                2400		103.2          2400	207.3         19200		51
	4800		47                4800		51.1           4800	103.2         38400		25
	9600		23                9600		25.0           9600	51.1          57600		16
	19200		11                19200		12.0           19200	25.0          115200		8
	38400		5                 38400		5.5            38400	12.0
	57600		3                 57600		3.3            57600	7.7
	115200		1                 115200	1.2            115200	3.3

	*/

	//you can comment these #assert statements out if you dont want error checkin
	BAUDCONbits.BRG16 =1;//16-bit Baud Rate Generator is used (SPBRGH:SPBRG)
	SPBRGH:SPBRG = SPBRG_SET;//
	TXSTAbits.BRGH = 1;	  		//data rate for sending/receiving
	TXSTAbits.SYNC =0;						//Truyen khong dongbo
	RCSTAbits.SPEN =1;						//enable serial port pin						// Enable transmitter
	TRISCbits.TRISC6 = 0;						// RC6 is pin trasmit
	TRISCbits.TRISC7 = 1; 						//RC7 is pin receive
	TXREG =0x00;                                //lam rong bo truyen
}
void Init_Tran_UART(void)
{
    BAUDCONbits.CKTXP=0; // Idle state for transmit (TX) is high
    TXSTAbits.TXEN =1;   // cho phep truyen uart
    TXREG = 0x00;        // lam rong thanh ghi truyen
}
void Init_Rec_UART(void)
{
	RCONbits.IPEN=1;
	IPR1bits.RCIP=0;
	PIE1bits.RCIE=1;     // cho phep ngat khi nhan uart
	INTCONbits.GIE=1;    // cho phep ngat toan cuc khi IPEN =1 set boi thanh ghi RCON
	INTCONbits.PEIE=1;   // cho phep ngat ngoai vi
	RCSTAbits.CREN =1;   // cho phep nhan uart khong dong bo
	PIR1bits.RCIF=0;//tat co ngat
	RCREG = 0x00;
}
void uart_putc(unsigned char c)
{
	while(!TXSTAbits.TRMT);//bo truyen rong
	TXREG = c;//gui ky tu
}
void uart_puts(const unsigned char *s)
{
	while(*s != '\0')
	{
		uart_putc(*s);
		s++;
	};
}
unsigned char uart_getc()
{
	while(!PIE1bits.RCIE);
	return RCREG;//cho phep nhap du lieu
}
void uart_gets(unsigned char *s)
{
	*s = uart_getc();
	while(*s!='\0')
	{
		s++;
		*s = uart_getc();
	};
}
