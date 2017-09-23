#include "SPI.h"
#include "../Hardware/Generic.h"
void SPI_Config_Master(void)
{
	TRISCbits.TRISC3 = 0; //-> define clock pin as output
        TRISCbits.TRISC4 = 1 ;//-> define SDI pin as input
        TRISCbits.TRISC5 = 0; //-> define SDO pin as output
        TRISAbits.TRISA5 = 0;// chan CS la chan out
        /* To find out more about 2 command the following, please review datasheet */
        /* Use SPI_MODE = 0*/
#ifdef USE_SPI_H
        OpenSPI(SPI_FOSC_4, MODE_01, SMPMID);
#endif
#ifndef USE_SPI_H
        SSPSTAT = 0xC0;// CKE = 0;
        SSPCON1 = 0x31;// CKP = 0, Fsck = FOSC/4
        SSPBUF = 0x00;
#endif
}
unsigned char SPI_Write(unsigned char data)
{
	unsigned char ret_val;
        unsigned char ReadOldData = SSPBUF;// Clears BF
   	PIR1bits.SSPIF = 0;//Clear interrupt flag for next check
   	SSPCON1bits.WCOL = 0;//Clear any previous write collision
        SSPBUF = data;//write a byte data to SSPBUF register
   	while(!PIR1bits.SSPIF );//wait until write data completly
        ret_val = SSPBUF;
      //  ret_val = WriteSPI(data);
	return ret_val;
}
unsigned char SPI_Read(void)
{
    unsigned char ReadOldData = SSPBUF;// Clear SSPBUF
    PIR1bits.SSPIF = 0;      // Clear interrupt flag
    SSPBUF = 0x00;           // refresh SSPBUF
    while ( !SSPSTATbits.BF );// wait until have data in SSPBUF register
    return ( SSPBUF );       // return with a byte have just read
}
