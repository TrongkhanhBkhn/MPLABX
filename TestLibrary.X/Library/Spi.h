/* 
 * File:   Spi.h
 * Author: TrongKhanhHD
 *
 * Created on September 13, 2015, 10:44 PM
 */

#ifndef SPI_H
#define	SPI_H
//#define USE_EXTERNAL_NVM
#include "Compiler.h"
#include "Generic.h"
#define USE_SPI2
//#define USE_SPI1
#if defined(__dsPIC33F__) || defined(__PIC24F__) || defined(__PIC24H__)
    void unlockSPIPin(void);
    void spiInit(void);
    #if defined(USE_SPI2)
        #define EE_SSPIF_BIT IFS2bits.SPI2IF
        #define EE_SSPBUF_REG SPI2BUF
        void EE_SPIPut(BYTE v);
        BYTE EE_SPIGet(void);
        #define EE_SPIInit()   EE_SSPIF_BIT = 1
    #endif
    #if defined USE_SPI1
        #define WCOL_BIT SSPCON1bits.WCOL 
        #define SSPIF_BIT PIR1bits.SSPIF 
        #define SSPBUF_REG SSPBUF
        #define SPIInit()   SSPIF_BIT = 1
        void SPIPut(BYTE v);
        BYTE SPIGet(void);
    #endif
#elif defined(__18CXX)
    #define SSPIF_BIT IFS0bits.SPI1IF
    #define SSPBUF_REG SPI1BUF
    void spiInit(void);
    void SPIPut(BYTE v);
    BYTE SPIGet(void);
#else
    #error "Unknow Compiler"
#endif

#endif	/* SPI_H */

