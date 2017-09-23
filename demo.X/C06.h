/*
 * File:   C06.h
 * Author: bienphongvnn
 *
 * Created on August 20, 2015, 6:31 PM
 */

#ifndef C06_H
#define	C06_H

#include "generic.h"

/*************BYTE dau tien mac dinh cua host or cmr******/
#define CMD_HOST 0x56
#define CMD_CMR  0x76

/*************size anh*******/
#define SIZE_QQVGA 0x22 //160x120
#define SIZE_QVGA  0x11 //320x240
#define SIZE_VGA   0x00 //640x480

/************baud rate*************/
#define X_9600      0xAE
#define Y_9600      0xC8
#define X_19200     0x56
#define Y_19200     0xE4
#define X_38400     0x2A
#define Y_38400     0xF2
#define X_57600     0x1C
#define Y_57600     0x4C
#define X_115200    0x0D
#define Y_115200    0xA6

//void cmr_tick(void);//dem tick tac
void tx_byte(BYTE x);// gui 1 BYTE
char cmr_tx(BYTE cmd,BYTE a1, BYTE a2, BYTE a3, BYTE a4);//lenh tu host gui 5 BYTE lien tiep
char cmr_rx(WORD i);//lenh doc data tu cmr gui ve
char reset(void);       // lenh reset cmr
char cmr_chupanh(void);//lenh cho cmr chup anh
char cmr_length(void);  // lenh lay do dai anh
char cmr_clear_cache();// xoa cache
char cmr_send_data(WORD x, BYTE y[x]);//lenh yeu cau gui dl anh
void cmr_nen();      //nen dl
char cmr_size(BYTE cmd_size);//lenh config kt anh
char cmr_change_baud_rate(void); //thiet lap thay doi toc do truyen
char cmr_init_baud_rate(BYTE x,BYTE y);//
//char cmr_main(WORD x, BYTE y[x]);


#endif

