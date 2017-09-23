#include "C06.h"
#include "console.c"
#include "delay.h"

#define CMD_TIMEOUT 20
#define RXBUF_LEN   256  //320*240+10 so byte toi da cua data
BYTE rxbuf[256];
WORD rxbuf_len = 0;
WORD timeout_clk = 1;
BYTE length_image[2];


 //void cmr_tick(void)//dinh nghia 1 tich tac
//{
//	if(timeout_clk) timeout_clk--;
//}


void tx_byte(BYTE x)
{
    ConsolePut(x);
}
char cmr_tx(BYTE cmd,BYTE a1, BYTE a2, BYTE a3, BYTE a4)
{
    tx_byte(cmd);
    tx_byte(a1);
    tx_byte(a2);
    tx_byte(a3);
    tx_byte(a4);

} 
char cmr_rx(WORD i)
{
        rxbuf_len = 0;
	//timeout_clk = timeout;
	while(timeout_clk)
	{
		rxbuf[rxbuf_len++] = ConsoleGet();
		if(rxbuf_len == i) break;
	}
	if(rxbuf[0] != CMD_CMR) return(0); /* All responses should begin 0x76 */

}
char reset(void)
{
    
    cmr_tx(CMD_HOST,0x00,0x26,0x00,0x00);
    cmr_rx(4);
    
   // while(rxbuf[2]!=0x26);
if(rxbuf[2]!=0x26)
    return 0;
}
char cmr_chupanh(void)
{   
  cmr_tx(CMD_HOST,0x00,0x36,0x01,0x00);
    cmr_rx(5);
    if(rxbuf[2]!=0x36)
    return 0;
}
char cmr_length(void)
{
    cmr_tx(CMD_HOST,0x00,0x34,0x01,0x00);
    cmr_rx(9);
    if(rxbuf[2]!=0x34) return(0);
    else{
        length_image[0]= rxbuf[7];
        length_image[1]= rxbuf[8];
    }
    //return length_image[2];
}
char cmr_clear_cache(void)
{   //unsigned error=0;
    cmr_tx(CMD_HOST,0x00,0x36,0x01,0x03);
    cmr_rx(5);
    if(rxbuf[2]!=0x36)
        return 0;
}
char cmr_send_data(WORD length,BYTE data[length])
{
    //byte data[240][320];
    
    cmr_tx(CMD_HOST,0x00,0x32,0x0C,0x00);
    tx_byte(0x0A);
    tx_byte(0x00);
    tx_byte(0x00);
    tx_byte(0x00);
    tx_byte(0x00);
    tx_byte(0x00);
    tx_byte(0x00);
    tx_byte(length_image[0]);
    tx_byte(length_image[1]);
    tx_byte(0x00);
    tx_byte(0xFF);
    cmr_rx(RXBUF_LEN);
    int  i=0;
    int m=256, n=0;
    while(1)
    {
        if((rxbuf[i]==0xFF)&&(rxbuf[i+1]==0xD8))
        {
             n = i+2;
            continue;
        }
         if((rxbuf[i]==0xFF)&&(rxbuf[i+1]==0xD9))
         {
             m = i;
            break;
         }
        i++;
    }
    length=(m-n);
    while(length!=0)
    {
        int a =0;
        data[a]=rxbuf[n+a];
        a++;
        length--;
    }
       /* for(int k=0;k<10;k++)
        {
            int a;
            a=1;
                //data[k]=rxbuf[n+k];
        }*/
}
void cmr_nen()
{

}
char cmr_size(BYTE cmd_size)
{
    unsigned error=0;
    cmr_tx(CMD_HOST,0x00,0x31,0x05,0x01);
    tx_byte(0x01);
    tx_byte(0x00);
    tx_byte(0x19);
    tx_byte(cmd_size);
    cmr_rx(5);
    
    if(rxbuf[2]!=0x31)error=1;
    return error;

}
char cmr_init_baud_rate(BYTE x,BYTE y)
{   unsigned error=0;
    cmr_tx(CMD_HOST,0x00,0x31,0x06,0x04);
    tx_byte(0x02);
    tx_byte(0x00);
    tx_byte(0x08);
    tx_byte(x);
    tx_byte(y);
    cmr_rx(4);
    if (rxbuf[2]!=0x31)error=1;
    return error;
}

/*char cmr_main(WORD x, BYTE y[x])
{
    DelayMs(250);// delay 2,5s
    cmr_size(SIZE_QVGA);//cau hinh kich thuoc anh 320x240
    cmr_init_baud_rate(X_19200, Y_19200);//thiet lap toc do truyen
    /******bat dau chup anh******/
  /*  cmr_clear_cache();                  // xoa cache
    cmr_chupanh();                      //lenh chup anh
    cmr_length();                       //lenh y.c gui do dai Data
    cmr_send_data(x,y[x]);                    //lenh y.c gui data
*/

