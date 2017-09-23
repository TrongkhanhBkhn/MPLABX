#include "Tran_RF.h"

void IOConfig(void)
{
#if defined DATA_4BIT
   TRISCbits.TRISC6 = 0;
   TRISCbits.TRISC5 = 0;
   TRISCbits.TRISC4 = 0;
   TRISCbits.TRISC3 = 0;
#endif
#if defined DATA_1BIT
   TRISCbits.TRISC2 = 0;
#endif
}
void Tran_Data_Start(void)
{
    Tran_Char_RF(0xFF);
    Tran_Char_RF(0xFF);
    Tran_Char_RF(0xFF);
}
void Tran_Pulse_Start(void)
{
#if defined DATA_4BIT
    Tran_Char_RF(0xFF);
    Delay10KTCYx(2);
    Tran_Char_RF(0x00);
    Delay10KTCYx(2);
#endif
#if defined DATA_1BIT
    DATA = 1;
    Delay1KTCYx(2);
    DATA = 0;
#endif
}
void Tran_Pulse_Finish(void)
{
#if defined DATA_4BIT
    Tran_Char_RF(0xFF);
    Delay10KTCYx(4);
    Tran_Char_RF(0x00);
    Delay10KTCYx(4);
#endif
#if defined DATA_1BIT
    DATA = 1;
    Delay1KTCYx(2);
    DATA = 0;
#endif
}
void Tran_Char_RF(unsigned char data)
{
       int i_ = 0;
#if defined DATA_4BIT
    unsigned char temp = data>>4;// temp = data>>4 lay 4 bits cao
    DATA1 = temp & 1;
    DATA2 = (temp & 2)>>1;
    DATA3 = (temp & 4)>>2;
    DATA4 = (temp & 8)>>3;
    Delay1KTCYx(1);
    temp = data & 0x0F;
    DATA1 = temp & 1;
    DATA2 = (temp & 2)>>1;
    DATA3 = (temp & 4)>>2;
    DATA4 = (temp & 8)>>3;
    Delay1KTCYx(1);
#endif
#if defined DATA_1BIT
    for(i_ = 0; i_ < 8; i_++)
    {
        // tran bit thap  toi cao
       // DATA = (data >> i_)& 0x01;
        // truyen tu cao toi thap
        DATA = (data << i_) & 0x80;
    }
#endif
}
void Tran_String_RF(unsigned char *data)
{
    while(*data !='\0')
    {
        Tran_Char_RF(*data);
        data++;
    }
}
void Tran_Frame_RF(unsigned char *data)
{
   // Tran_Pulse_Start();
   // Delay1KTCYx(10);
    Tran_String_RF(data);
    Tran_Pulse_Finish();
}
