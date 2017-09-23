#include "Recieve_RF.h"

void IOConfig(void)
{
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB6 = 1;
    TRISBbits.TRISB7 = 1;
}
unsigned char Get_Byte_RF(void)
{
    int i_ ;
    unsigned char data;
    bit a;
    for(i_ = 0; i_ < 8; i++)
    {
        a = DATA;
        data |= (a &0x01)<<(7 - i);
        if(a)
            while(a);
        else
            while(!a);
    }
    return data;
}
unsigned char Get_Char_RF(void)
{
    unsigned char data1 = 0, data2 = 0, data;
    int i;
    //1 byte chia lam 2 lan nhan
    for(i = 0; i<2 ; i++)
    {
       data1 = (DATA1)||(DATA2<<1)||(DATA3<<2)||(DATA4<<3);// nhan 4 bit cao truoc
       data |= (data1<< (4 - 4*i));
    }

    return data;
}

unsigned char Get_Pulse_Start(void)
{
    bit a;
    int i_;
    a = DATA;
    if(a) while(a);

}
unsigned char Get_Pulse_Finish(void)
{

}
unsigned char Get_Data_Start(void)
{

}
unsigned char Get_Frame_RF(void)
{

}