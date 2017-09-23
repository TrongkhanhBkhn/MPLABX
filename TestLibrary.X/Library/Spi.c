#include "Spi.h"
#if defined(__dsPIC33F__) || defined(__PIC24F__) || defined(__PIC24H__)
    void unlockSPIPin(void){
        #if defined(USE_SPI1)
                /*------SPI1------*/
            // SCK1 >> RP26
            RPINR20bits.SCK1R = 26;
            RPOR13bits.RP26R  = 8;
            // SDO1 >> RP19
            RPOR9bits.RP19R   = 7;
            // SDI1 >> RP27
            RPINR20bits.SDI1R = 27;
        #elif defined(USE_SPI2)
            /*------SPI2------*/
            // SCK2 >> RP3
            RPINR22bits.SCK2R = 3;
            RPOR1bits.RP3R    = 11;
            //SDO2 >> RP2
            RPOR1bits.RP2R    = 10;
            // SDI2 >> RP4
            RPINR22bits.SDI2R = 4;
        #else
        #error "Unknow Spi Pin"

        #endif
    }
    void spiInit(void)
    {
         /*Configure for SPI communication*/
        #if(CLOCK_FREQ < 1000000)
            #if defined(USE_SPI1)
                //SPI1 for RF transceiver
                SPI1CON1 = 0b0000000100111111;      // CLOCK_FREQ as SPI CLOCK
                SPI1STAT = 0x8000;
            #endif
            #if defined(USE_SPI2)
                //SPI2 for EEPROM
                SPI2CON1 = 0b0000000100111111;      // CLOCK_FREQ as SPI CLOCK
                SPI2STAT = 0x8000;
            #endif
        #else
            #if defined(USE_SPI1)
                    /* SPI1 for RF transceiver */
                    SPI1CON1 = 0b0000000100111110;  //PIC24FJ128GA306 is Master, MRF24J40 is Slaver
                                                    //Internal SPI clock is enabled
                                                    //SDO1 pin is controlled by the module
                                                    //Communication is byte-wide (8 bits)
                                                    //Input data is sampled at the middle of data output time
                                                    //Serial output data changes on transition from active clock state to Idle clock state
                                                    //~SS1 pin is not used by the module; pin is controlled by the port function
                                                    //Idle state for the clock is a low level; active state is a high level
                                                    //Secondary prescale 1:1
                                                    //Primary prescale 4:1 -> CLOCK_FREQ/2/4 as SPI CLOCK

                    //Enables module and configures SCKx, SDOx, SDIx and ~SSx as serial port pins
                    //Interrupt when the last data in the receive buffer is read; as a result, the buffer is empty (SRXMPT bit is set)
                    SPI1STAT = 0x8000;
            #endif
            #if defined(USE_SPI2)
                    /* SPI2 for EEPROM */
                    //same as configuration SPI1 module
                    SPI2CON1 = 0b0000000100111110;
                    SPI2STAT = 0x8000;
            #endif
        #endif
    }
    #if defined(USE_SPI1)
        void SPIPut(BYTE v){
            BYTE dummy;
            SSPIF_BIT = 0;
            dummy = SPI1BUF;
            SSPBUF_REG = v;
            while(SSPIF_BIT == 0) {}
        }
        BYTE SPIGet(void){
            SPIPut(0x00);
            return SSPBUF_REG;
        }
    #endif
    #if defined(USE_SPI2)
            void EE_SPIPut(BYTE v)
            {
                    BYTE dummy;

                    EE_SSPIF_BIT = 0;
                    dummy = EE_SSPBUF_REG;
                    EE_SSPBUF_REG = v;
                    while(EE_SSPIF_BIT == 0 );
            }

            BYTE EE_SPIGet(void)
            {
                    EE_SPIPut(0x00);
                    return EE_SSPBUF_REG;
            }
    #endif
#elif defined(__18CXX)
       void spiInit(void){
            SSPSTAT = 0xC0;// CKE = 0;
            SSPCON1 = 0x31;// CKP = 0, Fsck = FOSC/4
            SSPBUF = 0x00;
            TRISCbits.TRISC3 = 0; //-> define clock pin as output
            TRISCbits.TRISC4 = 1 ;//-> define SDI pin as input
            TRISCbits.TRISC5 = 0; //-> define SDO pin as output
            TRISAbits.TRISA5 = 0;// chan CS la chan out

       }
       void SPIPut(BYTE v)
        {
            SSPIF_BIT = 0;
            do
            {
                WCOL_BIT = 0;
                SSPBUF_REG = v;
            }
            while (WCOL_BIT);
            while(SSPIF_BIT == 0){}
        }

        BYTE SPIGet(void)
        {
            SPIPut(0x00);
            return SSPBUF_REG;
        }
#else
#error "Unknow Compiler"
#endif