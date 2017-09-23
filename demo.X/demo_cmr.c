/* 
 * File:   Lednhay.c
 * Author: bienphongvnn
 *
 * Created on August 1, 2015, 11:22 AM
 */

#include "generic.h"
//#include "Demo.def"

#if defined(__PIC24F__)
    // Configure by dat_a3cbq91
    _CONFIG1(JTAGEN_OFF & GCP_OFF & GWRP_OFF  & ICS_PGx1 & WINDIS_OFF &  FWPSA_PR128 & WDTPS_PS512);
    _CONFIG2(IESO_ON & FNOSC_FRC & FCKSM_CSECME & IOL1WAY_OFF );

#endif

#include "console.h"
#include "delay.h"
#include "C06.h"


int main() {
    OSCCON = 0x2001;//current osc HS, new osc FRC
    CLKDIV = 0x0000;//Fcy = Fosc/2
          /*------UART1-----*/
    // RX1 >> RP22
    RPINR18bits.U1RXR = 22;
    // TX1 >> RP25
    RPOR12bits.RP25R  = 3;

    /*------UART2-----*/
    // RX2 >> RP24
    RPINR19bits.U2RXR = 24;
    // TX2 >> RP23
    RPOR11bits.RP23R  = 5;

    CLRWDT();
    ENABLE_WDT();

    WORD length_data;
    BYTE data[256];
    ConsoleInit();
    
    DelayMs(250);// delay 2,5s
    cmr_size(SIZE_QVGA);//cau hinh kich thuoc anh 320x240
    cmr_init_baud_rate(X_19200, Y_19200);//thiet lap toc do truyen
    /******bat dau chup anh******/
    cmr_clear_cache();                  // xoa cache
    cmr_chupanh();                      //lenh chup anh
    cmr_length();                       //lenh y.c gui do dai Data
    cmr_send_data(length_data,data[256]);                    //lenh y.c gui data
    

}

