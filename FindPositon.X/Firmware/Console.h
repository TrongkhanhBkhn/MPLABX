/* 
 * File:   Console.h
 * Author: TrongKhanh
 *
 * Created on March 20, 2015, 1:34 AM
 */

#ifndef CONSOLE_H
#define	CONSOLE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "General.h"
void UART_Config(int SPBRG_SET);
void uart_puts(const char *s);
void uart_putc(char c);
char uart_getc();
void uart_gets(char *s);
void UART_isr();
void uart_interrupt();
void Init_Rec_UART(void);
void Init_Tran_UART(void) ;


#ifdef	__cplusplus
}
#endif

#endif	/* CONSOLE_H */

