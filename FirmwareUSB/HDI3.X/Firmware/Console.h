/* 
 * File:   Console.h
 * Author: trongkhanh
 *
 * Created on February 24, 2014, 1:22 PM
 */

#ifndef CONSOLE_H
#define	CONSOLE_H
#include "p18f14k50.h"
void Init_UART(int bauddate);
void Init_Tran_UART(void);
void Init_Rec_UART(void);
void Tran_UART(unsigned char ch);
void Tran_String_UART(unsigned char *str);
#endif	/* CONSOLE_H */

