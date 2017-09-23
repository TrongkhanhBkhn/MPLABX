#include<p18f46k20.h>
#pragma config  FOSC=HS,WDTEN=OFF,PBADEN=OFF,MCLRE=ON,LVP=OFF
//predefine global LookupTableay for display on led 7 segment
char LookupTable[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
char index = -1;

//function prototype
void config_ExINT(void);//funtion use to configure intterrupt module
void ExINT_isr(void);//interrupt service program

void main()
{
	config_ExINT();
	TRISC = 0;
	while(1)
	{
		//other applications
	}
}
void config_ExINT(void)
{
        INTCON2bits.INTEDG0=0;
	INTCON2bits.INTEDG1=0;
	INTCON = 0xD2;
	INTCON3 = 0x08;
}

#pragma code interrupt_vector=0x08
void interrupt_vector()
{
	_asm
	goto ExINT_isr
	_endasm
}

#pragma interrupt ExINT_isr
void  ExINT_isr(void)
{
	if(INTCONbits.INT0IF)
	{
		index++;
		INTCONbits.INT0IF = 0;
		if(index == 10)
		index = 0;
	}
	if(INTCON3bits.INT1IF)
	{
		index--;
		INTCON3bits.INT1IF = 0;
		if(index == -1)
		index = 9;
	}
	LATC = LookupTable[index];
}
