#ifndef __LCD_H
#define __LCD_H

#include "p24fj128ga110.h"
#include"libpic30.h"

#define LCD_RS LATDbits.LATD0
#define LCD_RW LATDbits.LATD1
#define LCD_E  LATDbits.LATD2

#define	LCD_D4 LATDbits.LATD3
#define	LCD_D5 LATDbits.LATD4
#define	LCD_D6 LATDbits.LATD5
#define	LCD_D7 LATDbits.LATD6
#define lcd_busy LATDbits.LATD7


#define	LCD_clear	0x01	 //Xoa man hinh LCD
#define	LCD_home	0x02	 //Tro ve dau dong
#define	LCD_normal	0x06	 //Che do nhap du lieu binh thuong
#define	LCD_normal_s	0x07	//Che do nhap du lieu binh thuong, dich man hinh
#define	LCD_off 0x08	 //Tat man hinh
#define	LCD_on	 0x0C	 //Bat man hinh
#define	LCD_on_crsr 0x0E	 //Bat man hinh va con tro
#define	LCD_on_blink 0x0F	 //Bat man hinh va con tro (nhap nhay)
#define	LCD_4b2l	0x28	 //Che do 2 dong, giao tiep 4 bit du lieu
#define	LCD_homeL1	0x80	 //Ve dau dong 1
#define	LCD_homeL2	0xC0	 //Ve dau dong 2
#define lcd_line_two 0x40
#define lcd_line_one 0x00
//---------------------------------------------------------------------------------------------------------
//Cac prototype cho cac chuong trinh con
void Init_PORTS(void);
void Init_LCD(void);
void LCD_OK(void);
void LCD_CMD(unsigned char cmd);
void LCD_DATA(unsigned char dat);
void lcd_putstr(char *buffer);
void lcd_gotoxy(int x, int y);
void khoi_tao(void);
void LCD_IN_INTER(unsigned int d);
void LCD_IN_FLOAT( float d);
void lcd_clear(void);
void lcd_int(int val);
void timer_lcd(long k);

void Init_PORTS(void)
{
TRISDbits.TRISD0 = 0;
TRISDbits.TRISD1 = 0;
TRISDbits.TRISD2 = 0;
TRISDbits.TRISD3 = 0;
TRISDbits.TRISD4 = 0;
TRISDbits.TRISD5 = 0;
TRISDbits.TRISD6 = 0;	
}
void Init_LCD(void)
{
LCD_CMD(0x02);	 //Dat che do giao tiep 4-bit, man hinh 2 dong
__delay32(1);
LCD_CMD(0x28);	 //Tat man hinh
__delay32(1);
LCD_CMD(0x0C);	 //Che do nhap du lieu binh thuong
__delay32(1);
LCD_CMD(0x06 );	 //Bat man hinh, hien con tro nhap nhay
__delay32(1);
//LCD_CMD(0x01);	 //Xoa man hinh
__delay32(1);
}
void LCD_OK(void)
{
unsigned u;
LCD_E = 1; //Tao xung Enable
for (u = 0; u < 2; u++); //keo dai toi thieu 1 us
LCD_E = 0;
}
void LCD_CMD(unsigned char cmd) 
{
unsigned temp1;
LCD_RW = 0;
LCD_RS = 0; //Dat che do xuat lenh
temp1 = cmd >> 4; //Lay 4 bit cao
LCD_D4 = temp1 & 1; //Xuat 4 bit cao
LCD_D5 = (temp1 & 2) >>1;
LCD_D6 = (temp1 & 4) >>2;
LCD_D7 = (temp1 & 8) >>3;
LCD_OK();
temp1 = cmd & 0x0F; //Lay 4 bit thap
LCD_D4 = temp1 & 1; //Xuat 4 bit thap
LCD_D5 = (temp1 & 2) >>1;
LCD_D6 = (temp1 & 4) >>2;
LCD_D7 = (temp1 & 8) >>3;
LCD_OK();
__delay32(5);
}
void LCD_DATA (unsigned char dat) 
{
unsigned temp2;
LCD_RW = 0;
LCD_RS = 1; //Dat che do xuat du lieu
temp2 = dat >> 4; //Lay 4 bit cao
LCD_D4 = temp2 & 1; //Xuat 4 bit cao
LCD_D5 = (temp2 & 2) >>1;
LCD_D6 = (temp2 & 4) >>2;
LCD_D7 = (temp2 & 8) >>3;
LCD_OK();
temp2 = dat & 0x0F; //Lay 4 bit thap
LCD_D4 = temp2 & 1; //Xuat 4 bit thap
LCD_D5 = (temp2 & 2) >>1;
LCD_D6 = (temp2 & 4) >>2;
LCD_D7 = (temp2 & 8) >>3;
LCD_OK();
__delay32(5);
}	
void lcd_clear(void)
{
	LCD_CMD(0x01);
}
void lcd_putstr(char *buffer)
{
	while(*buffer != '\0')
	{
		LCD_DATA(*buffer); /* calling another function */
		/* to write each char to the lcd module */
		buffer++;
		__delay32(2);	
	};
}

//-----------Chuong trinh con nhay den cot x, dong y-------------------------------------------------------------------
void lcd_gotoxy(int x, int y)
{
	int address;
	if(y != 1) address = lcd_line_two;
	else address=0;
	address += x-1;
	LCD_CMD(0x80|address);
	__delay32(2);
}
void LCD_IN_INTER(unsigned int d)
{
unsigned i,j,k,l,m;
l=d/10000;//nghin
k=(d%10000)/1000;//tram
j=(d%1000)/100;//chuc
i=(d%100)/10;//donvi
m=d%10;
LCD_DATA(0x30+l);		
LCD_DATA(0x30+k);
LCD_DATA(0x30+j);
LCD_DATA(0x30+i);
LCD_DATA(0x30+m);
}
void lcd_int(int val)
{
	int a,b,c;
	a=val/100;
	b=(val%100)/10;
	c=val%10;
	if(a>=1)
	{
		LCD_DATA(0x30+a);
		LCD_DATA(0x30+b);
		LCD_DATA(0x30+c);
	}
	else
	{

		if(b>=1)
		{
			LCD_DATA(0x30+b);
			LCD_DATA(0x30+c);
		}
		else
		{
			LCD_DATA(0x30+c);
		}
	}
}
void LCD_IN_FLOAT( float d)
{
char ch[]=".";
unsigned int e, i,j,k,l;
// d=round(d,1);
e=(int)(d*10);
l=e/1000;//nghin
k=(e%1000)/100;//tram
j=((e%1000)%100)/10;//chuc
i=((e%1000)%100)%10;//donvi
LCD_DATA(0x30+l);
LCD_DATA(0x30+k);
LCD_DATA(0x30+j);
lcd_putstr(ch);
LCD_DATA(0x30+i);
}
				
void timer_lcd(long k)
{
int p,q,m,n,l;
p=k/10000;
q=(k-p*10000)/1000;
m=(k-p*10000-q*1000)/100;
n=(k-p*10000-q*1000-m*100)/10;
l=k-p*10000-q*1000-m*100-n*10;
lcd_clear();
lcd_gotoxy(0,0);
LCD_DATA(p+0x30);
LCD_DATA(q+0x30);
LCD_DATA(m+0x30);
LCD_DATA(n+0x30);
LCD_DATA(l+0x30);
}

#endif

