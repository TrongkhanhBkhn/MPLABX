#include "SPI.h"

void SPI_Config_Master(void)
{
	TRISC = 0x10;//TRISCbits.TRISC3 = 0 -> define clock pin as input
                     //TRISCbits.TRISC4 = 1 -> define SDI pin as input
                     //TRISCbits.TRISC5 = 0 -> define SDO pin as output

        /* To find out more about 2 command the following, please review datasheet */
        /* Use SPI_MODE = 0*/
        SSPSTAT = 0x00;
        SSPCON1 = 0x21;
}
unsigned char SPI_SendByte(unsigned char data)
{
	unsigned char ret_val;
    unsigned char ReadOldData = SSPBUF;// Clears BF
   	PIR1bits.SSPIF = 0;//Clear interrupt flag for next check
   	SSPCON1bits.WCOL = 0;//Clear any previous write collision

    SSPBUF = data;//write a byte data to SSPBUF register
   	while( !PIR1bits.SSPIF );//wait until write data completly
   	ret_val = SSPBUF;
	return ret_val;
}
unsigned char SPI_SOFT_ReadWrite(unsigned char DataWrite)
{
    unsigned char i;
	#if((SPI_MODE==0)||(SPI_MODE==1))
		SCK_SOFT=0;
	#else
		SCK_SOFT=1;
	#endif
    for(i=8;i>0;i--)                 // Truyen 8 bit du lieu
    {
	    #if((SPI_MODE==0)||(SPI_MODE==3))
		SCK_SOFT = 0;                     // Thiet lap muc thap cho chan SCK_SOFT
		#else
		SCK_SOFT = 1;                     // Thiet lap muc cao cho chan SCK_SOFT
		#endif
        Delay1TCY();
        if(DataWrite & 0x80)
            MOSI_SOFT =1;                 // truyen du lieu bit MSB truyen qua MOSI_SOFT
        else
		    MOSI_SOFT=0;
        DataWrite <<=1;              // dich trai du lieu..
        Delay1TCY();
		#if((SPI_MODE==0)||(SPI_MODE==3))
        SCK_SOFT = 1;                     //Thiet lap muc cao cho chan  SCK_SOFT  tin hieu duoc dua vao
        #else
        SCK_SOFT = 0;                     //Thiet lap muc thap cho chan  SCK_SOFT  tin hieu duoc dua vao
        #endif
        Delay1TCY();
        if(MISO_SOFT)
            DataWrite |=1;        // Lay gia tri bit hien tai cua day MISO_SOFT
   }
    return(DataWrite);               // Tra ve gia tri du lieu nhan duoc
}
unsigned char SPI_Write(unsigned char data)
{
   unsigned char i;
   unsigned char buff;
   unsigned char status;
#if(SPI_MODE == 0)
   SCK_SOFT = 0;
#else
   SCK_SOFT = 1;
#endif
   for(i = 8; i>0; i--)
   {
#if(SPI_MODE == 0)
       SCK_SOFT = 0;
#else
       SCK_SOFT = 1;
#endif
       Delay1TCY();
       buff = data & 0x80;
       if(buff != 0x00){
           MOSI_SOFT = 1;
       }
       else{
           MOSI_SOFT = 0;
       }
       data<<1;
       status <<1;
       Delay1TCY();
       if(MISO_SOFT == 1){
           status |= 0x01;
       }
       else if(MISO_SOFT == 0){
           status &= 0xFE;
       }
       Delay1TCY();
   }
   SCK_SOFT = 0;
   return status;
}
unsigned char SPI_Read(void)
{
    unsigned char data;
    unsigned char i;

#if(SPI_MODE  ==0)
    SCK_SOFT = 0;
#else
    SCK_SOFT = 1;
#endif
    for(i = 0; i <8; i++)
    {
#if(SPI_MODE == 0)
        SCK_SOFT = 1;
#else
        SCK_SOFT = 0;
#endif
        data<<1;
        if(MISO_SOFT ==1)
        {
            data |=0x01;
        }
        else if(MISO_SOFT == 0){
            data &=0xFE;
        }
        Delay1TCY();
    }
    SCK_SOFT = 0;
    return data;

}
