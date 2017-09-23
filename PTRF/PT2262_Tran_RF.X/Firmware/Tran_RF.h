/* 
 * File:   Tran_RF.h
 * Author: trongkhanh
 *
 * Created on March 27, 2014, 1:22 PM
 */

#ifndef TRAN_RF_H
#define	TRAN_RF_H
#define _PIC18FXXX
#if defined _PIC18FXXX
#include "p18f14k50.h"
//#include "p18f26k20.h"
#include "delays.h"
#endif
//transmition 4 bit data 8 bit address
#define DATA_4BIT
#if defined DATA_4BIT
    //define pin data RF
    #define DATA1 LATCbits.LATC6
    #define DATA2 LATCbits.LATC3
    #define DATA3 LATCbits.LATC4
    #define DATA4 LATCbits.LATC5
#endif
// transmition 1 bit data, 11 bit address
//#define DATA_1BIT
#if defined DATA_1BIT
    #define DATA LATCbits.LATC6

#endif

// fucntion tran data
void IOConfig(void);
void Tran_Data_Start(void);
void Tran_Pulse_Start(void);
void Tran_Pulse_Finish(void);
void Tran_Char_RF(unsigned char data);
void Tran_String_RF(unsigned char *data);
void Tran_Frame_RF(unsigned char *data);
#endif	/* TRAN_RF_H */

