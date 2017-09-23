/* 
 * File:   RFRounter.h
 * Author: trongkhanh
 *
 * Created on May 19, 2014, 1:20 PM
 */

#ifndef RFROUNTER_H
#define	RFROUNTER_H

#include "Hardware/Generic.h"
#include "CC1101/CC1101.h"
#include "LCD/LCD.h"
#include "SPI/SPI.h"
#include "UART/UART.h"
#include "TIMER/TIMER.h"
#include "stdio.h"
#include "RFRounter.h"
#define DEBUG_UART

void SendData(unsigned char data[], unsigned char addr,  unsigned char command);

#endif	/* RFROUNTER_H */

