/* 
 * File:   UART.h
 * Author: Chu
 *
 * Created on April 30, 2014, 7:07 PM
 */

#ifndef __UART_H
#define __UART_H
#include "p18f26k20.h"
#define DEBUG_UART
#define BAUD_RATE 25
void UART_Init(int SPBRG_SET);
void uart_puts(const unsigned char *s);
void uart_putc(unsigned char c);
unsigned char uart_getc();
void uart_gets(unsigned char *s);
void UART_isr();
void uart_interrupt();
void Init_Rec_UART(void);
void Init_Tran_UART(void) ;

#endif


