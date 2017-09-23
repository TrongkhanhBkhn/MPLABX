/* 
 * File:   SPI.h
 * Author: Chu
 *
 * Created on April 30, 2014, 7:04 PM
 */

#ifndef SPI_H
#define	SPI_H
//#include "C:\Program Files (x86)\Microchip\mplabc18\v3.47\h\spi.h"
#include "delays.h"
#define SPI_MODE          0
//#define USE_SPI_H
/* CKE = 0, CKP =0;
 * Chan SCK o muc thap
 * De lieu se duoc ghi theo suon duong cua chan SCK*/
//#define SPI_MODE        1
/* CKE = 0, CKP = 1
 * Chan SCK o muc cao
 * Du lieu se duoc ghi theo suon am cua chan SCK  */
//#define SPI_MODE        2
/* CKE = 1, CKP =0
 * Chan SCK o muc thap
 * Du lieu se duoc ghi thep suon am cua chan SCK*/
//#define SPI_MODE        3
/* CKE = 1, CKP =1
 * Chan SCK o muc cao
 * Du lie se duoc ghi theo suong duong cua chan SCK*/
#ifndef SPI_MODE
  #define  SPI_MODE        0
  #warning Ban chua chon che do SPI. Che do mac dinh la 0
#endif
void SPI_Config_Master(void);
/****************************************************
 * Noi dung: Cau hinh SPI cho pic
 * Bien : khong
 * Tra ve :Khong
 * *************************************************/
unsigned char SPI_Write(unsigned char data);
/****************************************************
 * Noi dung: ghi 1 byte
 * Bien : data chua du lieu can ghi
 * Tra ve: Trang thai tren chan SI
*****************************************************/
unsigned char SPI_Read(void);
/**************************************************
 * Noi dung : Ham doc gia tri
 * Tra ve   :Gia tri tra ve la du lieu doc duoc
 **************************************************/

#endif	/* SPI_H */

