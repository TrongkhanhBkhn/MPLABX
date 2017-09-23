/* 
 * File:   Recieve_RF.h
 * Author: trongkhanh
 *
 * Created on March 27, 2014, 2:18 PM
 */

#ifndef RECIEVE_RF_H
#define	RECIEVE_RF_H

#include "p18f26k20.h"
#include "delays.h"

//#define DATA_4BIT
#if defined DATA_4BIT
#define	LCD_D4 LATBbits.LATB4
#define	LCD_D5 LATBbits.LATB5
#define	LCD_D6 LATBbits.LATB6
#define	LCD_D7 LATBbits.LATB7
#endif

#define DATA_1BIT
#define DATA LATBbits.LATB7
#endif


void IOConfig(void);
unsigned char Get_Char_RF(void);
unsigned char Get_String_RF(void);
unsigned char Get_Pulse_Start(void);
unsigned char Get_Pulse_Finish(void);
unsigned char Get_Data_Start(void);
unsigned char Get_Frame_RF(void);
unsigned char Get_Byte_RF(void);

//define pin data recieve
#define
#endif	/* RECIEVE_RF_H */

