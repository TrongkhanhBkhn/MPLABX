/* 
 * File:   RFRounter.h
 * Author: trongkhanh
 *
 * Created on May 19, 2014, 1:20 PM
 */

#ifndef RFCOORDINATOR_H
#define	RFCOORDINATOR_H

#include "CC1101/CC1101.h"
#include "LCD/LCD.h"
#include "SPI/SPI.h"
#include "Hardware/Generic.h"
#include "TIMER/TIMER.h"
#include "UART/UART.h"
#include "RFConfig.h"

#define DEBUG_UART
void Timer_Isr(void);
void SendData(unsigned char data[], unsigned char addr,  unsigned char command);
void OSC_config(void);

#endif	/* RFROUNTER_H */

