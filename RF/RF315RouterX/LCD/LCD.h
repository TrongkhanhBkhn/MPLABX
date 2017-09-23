/* 
 * File:   LCD.h
 * Author: Chu
 *
 * Created on April 30, 2014, 7:06 PM
 */

#ifndef LCD_H
#define	LCD_H

#include"p18f46k20.h"
#include"delays.h"

#define LCD_RS LATAbits.LATA0
#define LCD_RW LATAbits.LATA1
#define LCD_E  LATAbits.LATA2

#define	LCD_D4 LATBbits.LATB4
#define	LCD_D5 LATBbits.LATB5
#define	LCD_D6 LATBbits.LATB6
#define	LCD_D7 LATBbits.LATB7
//#define lcd_busy LATBbits.LATB7

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
void lcd_int(char a);
void lcd_putch(char data);

#endif	/* LCD_H */

