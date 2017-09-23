/* 
 * File:   CC1101.h
 * Author: Chu Trong Khanh
 *
 * Created on April 30, 2014, 7:03 PM
 */

#ifndef __CC1101_H
#define __CC1101_H
#include "delays.h"

#define CONFIG_CC1101     1
// CAC THANH GHI DIEU KHIEN - TRANG THAI - LENH TREN CC1101
// Tuong thich voi ca cac con chip CC2500 va CC1100

// Cac thanh ghi cau hinh, cho phep doc ghi, cho phep che do doc ghi liep tiep.
#define CC1101_IOCFG2           0x00        // Cau hinh dau ra cho GDO2
#define CC1101_IOCFG1           0x01        // Cau hinh dau ra cho GDO1
#define CC1101_IOCFG0           0x02        // Cau hinh dau ra cho GDO0
#define CC1101_FIFOTHR          0x03        // Nguong cua bo dem RX FIFO - TX FIFO
#define CC1101_SYNC1            0x04        // Byte dong bo cao
#define CC1101_SYNC0            0x05        // Byte dong bo thap
#define CC1101_PKTLEN           0x06        // Do dai cua goi tin
#define CC1101_PKTCTRL1         0x07        // Dieu khien tu dong goi tin
#define CC1101_PKTCTRL0         0x08        // Dieu khien tu dong goi tin
#define CC1101_ADDR             0x09        // Dia chi cua thiet bi
#define CC1101_CHANNR           0x0A        // So luong kenh
#define CC1101_FSCTRL1          0x0B        // Dieu khien ket hop tan so
#define CC1101_FSCTRL0          0x0C        // Dieu khien ket hop tan so
#define CC1101_FREQ2            0x0D        // Byte dieu khien tan so. Byte cao.
#define CC1101_FREQ1            0x0E        // Byte dieu khien tan so. Byte giua.
#define CC1101_FREQ0            0x0F        // Byte dieu khien tan so. Byte thap.
#define CC1101_MDMCFG4          0x10        // Cau hinh Modem
#define CC1101_MDMCFG3          0x11        // Cau hinh Modem
#define CC1101_MDMCFG2          0x12        // Cau hinh Modem
#define CC1101_MDMCFG1          0x13        // Cau hinh Modem
#define CC1101_MDMCFG0          0x14        // Cau hinh Modem
#define CC1101_DEVIATN          0x15        // Thiet lap do sai lech Modem
#define CC1101_MCSM2            0x16        // Cau hinh dieu khien trang thai Radio chinh.
#define CC1101_MCSM1            0x17        // Cau hinh dieu khien trang thai Radio chinh.
#define CC1101_MCSM0            0x18        // Cau hinh dieu khien trang thai Radio chinh.
#define CC1101_FOCCFG           0x19        // Cau hinh tan so Offet them.
#define CC1101_BSCFG            0x1A        // Cau hinh dong bo hoa bit.
#define CC1101_AGCCTRL2         0x1B        // Dieu khien AGC.
#define CC1101_AGCCTRL1         0x1C        // Dieu khien AGC.
#define CC1101_AGCCTRL0         0x1D        // Dieu khien AGC.
#define CC1101_WOREVT1          0x1E        // Byte cao gia tri timeout su kien 0.
#define CC1101_WOREVT0          0x1F        // Byte thap gia tri timeout su kien 1.
#define CC1101_WORCTRL          0x20        // Dieu khien danh thuc tren kenh Radio.
#define CC1101_FREND1           0x21        // Cau hinh Front End RX
#define CC1101_FREND0           0x22        // Cau hinh Front end TX
#define CC1101_FSCAL3           0x23        // Hieu chuan ket hop tan so.
#define CC1101_FSCAL2           0x24        // Hieu chuan ket hop tan so.
#define CC1101_FSCAL1           0x25        // Hieu chuan ket hop tan so.
#define CC1101_FSCAL0           0x26        // Hieu chuan ket hop tan so.
#define CC1101_RCCTRL1          0x27        // Cau hinh bo dao dong RC.
#define CC1101_RCCTRL0          0x28        // Cau hinh bo dao dong RC.
#define CC1101_FSTEST           0x29        // Dieu khien hieu chuan ket hop tan so.
#define CC1101_PTEST            0x2A        // Kiem tra san pham
#define CC1101_AGCTEST          0x2B        // Kiem tra AGC
#define CC1101_TEST2            0x2C        // Thay doi cau hinh kiem tra.
#define CC1101_TEST1            0x2D        // Thay doi cau hinh kiem tra.
#define CC1101_TEST0            0x2E        // Thay doi cau hinh kiem tra.

// Cac thanh ghi trang thai(chi cho phep doc), lenh dieu khien va cac thanh ghi da chuc nang.

#define CC1101_PARTNUM          0x30        // Chip IP
#define CC1101_VERSION          0x31        // Phien ban cua CHIP
#define CC1101_FREQEST          0x32        // Tan so Offset mong muon tu bo giai dieu che
#define CC1101_LQI              0x33        // So luong ket noi mong muon cua bo giai dieu che
#define CC1101_RSSI             0x34        // Chi thi muc do tin hieu nhan
#define CC1101_MARCSTATE        0x35        // Trang thai dieu khien Radio chinh.
#define CC1101_WORTIME1         0x36        // Byte cao cua bo timer trong modulse WOR
#define CC1101_WORTIME0         0x37        // Byte thap cua bo timer trong modulse WOR
#define CC1101_PKTSTATUS        0x38        // Trang thai cua goi tin va cac chan GDO
#define CC1101_VCO_VC_DAC       0x39        // Thiet lap hien tai cua bo hieu chinh PLL
#define CC1101_TXBYTES          0x3A        // Thong bao tran duoi va so luong Bytes FIFO TX
#define CC1101_RXBYTES          0x3B        // Thong bao tran duoi va so luong Bytes FIFO RX
#define CC1101_RCCTRL1_STATUS   0x3C        // Ket qua hieu chinh cuoi cung bo dao dong RC
#define CC1101_RCCTRL0_STATUS   0x3D        // Ket qua hieu chinh cuoi cung bo dao dong RC
#define CC1101_PATABLE          0x3E
#define CC1101_TXFIFO           0x3F
#define CC1101_RXFIFO           0x3F

#define CC1101_SRES             0x30        // Reset chip.
#define CC1101_SFSTXON          0x31        // Kich hoat va hieu chinh tan so ket hop. (neu MCSM0.FS_AUTOCAL=1).
                                            // Neu dang o trang thai RX/TX: Tro ve trang thai cho, khi do                                            // chi so bo ket hop duoc hoat dong.( danh cho viec quay vong RX/TX nhanh chong)
#define CC1101_SXOFF            0x32        // Tat bo dao dong thach anh.
#define CC1101_SCAL             0x33        // Hieu chinh tan so ket hop va sau do tat no.(kich hoat khoi dong nhanh).
#define CC1101_SRX              0x34        // Kich hoat nhan du lieu. Thuc hien viec hieu chinh dau tien neu dang vao tu che do IDLE
                                            // va MCSM0.FS_AUTOCAL=1.
#define CC1101_STX              0x35        // O che cho IDLE. Cho phep gui du lieu. Thuc hien viec hieu chinh dau tien neu
                                            // MCSM0.FS_AUTOCAL=1.Neu trong che do RX va CCA duoc kich hoat: chi toi che do TX neu kenh duoc xoa
#define CC1101_SIDLE            0x36        // Thoat khoi che do RX / TX, Tat bo ket hop tan so va thoat khoi che do Wake On Radio neu duoc ap dung.
#define CC1101_SAFC             0x37        // Thuc hien hieu chinh AFC cho bo ket hop tan so
#define CC1101_SWOR             0x38        // Bat dau doc tuan tu du lieu(Wake-on-Radio).
#define CC1101_SPWD             0x39        // Truy nhap che do tiet kiem nang luong neu CS len muc cao.
#define CC1101_SFRX             0x3A        // Giai phong bo dem FIFO nhan.
#define CC1101_SFTX             0x3B        // Giai phong bo dem FIFO gui.
#define CC1101_SWORRST          0x3C        // Khoi dong lai dong ho thoi gian thuc..
#define CC1101_SNOP             0x3D        // Khong hoat dong. Co the duoc su dung de No operation.


#define WRITE_SINGLE            0x00
#define WRITE_BURST             0x40
#define READ_SINGLE             0x80
#define READ_BURST              0xC0

#define CRC_OK                  0x80
#define RSSI                    0
#define LQI                     1
#define BYTES_IN_RXFIFO         0x7F

//Dinh nghia trang thai cho chip
#define CHIP_RDY                        0x80
#define CHIP_STATE_MASK                 0x70
#define CHIP_STATE_IDLE                 0x00
#define CHIP_STATE_RX                   0x10
#define CHIP_STATE_TX                   0x20
#define CHIP_STATE_FSTON                0x30
#define CHIP_STATE_CALIBRATE            0x40
#define CHIP_STATE_SETTLING             0x50
#define CHIP_STATE_RXFIFO_OVERFLOW      0x60
#define CHIP_STATE_TXFIFO_UNDERFLOW     0x70
#define FIFO_BYTES_MASK                 0x0F

#define MAIN_RADIO_CPNTROL_STATE_MACHINE_STATE    0x1F
#define SLEEP                                     0x00
#define IDLE                                      0x01
#define XOFF                                      0x02
#define VCOON_MC                                  0x03
#define REGON_MC                                  0x04
#define MANCAL                                    0x05
#define VCOON                                     0x06
#define REGON                                     0x07
#define STARTCAL                                  0x08
#define BWBOOST                                   0x09
#define FS_LOCK                                   0x0A
#define IFADCON                                   0x0B
#define ENDCAL                                    0x0C
#define RX                                        0x0D
#define RX_END                                    0x0E
#define RX_RST                                    0x0F
#define TXRX_SWITCH                               0x10
#define RXFIFO_OVERFLOW                           0x11
#define FSTXON                                    0x12
#define TX                                        0x13
#define TX_END                                    0x14
#define RXTX_SWITCH                               0x15
#define TXFIFO_UNDERFLOW                          0x16

typedef struct
{
   unsigned char FSCTRL1;   // Frequency synthesizer control.
   unsigned char IOCFG0;    // GDO0 output pin configuration
   unsigned char FSCTRL0;   // Frequency synthesizer control.
   unsigned char FREQ2;     // Frequency control word, high byte.
   unsigned char FREQ1;     // Frequency control word, middle byte.
   unsigned char FREQ0;     // Frequency control word, low byte.
   unsigned char MDMCFG4;   // Modem configuration.
   unsigned char MDMCFG3;   // Modem configuration.
   unsigned char MDMCFG2;   // Modem configuration.
   unsigned char MDMCFG1;   // Modem configuration.
   unsigned char MDMCFG0;   // Modem configuration.
   unsigned char CHANNR;    // Channel number.
   unsigned char DEVIATN;   // Modem deviation setting (when FSK modulation is enabled).
   unsigned char FREND1;    // Front end RX configuration.
   unsigned char FREND0;    // Front end RX configuration.
   unsigned char MCSM0;     // Main Radio Control State Machine configuration.
   unsigned char FOCCFG;    // Frequency Offset Compensation Configuration.
   unsigned char BSCFG;     // Bit synchronization Configuration.
   unsigned char AGCCTRL2;  // AGC control.
   unsigned char AGCCTRL1;  // AGC control.
   unsigned char AGCCTRL0;  // AGC control.
   unsigned char FSCAL3;    // Frequency synthesizer calibration.
   unsigned char FSCAL2;    // Frequency synthesizer calibration.
   unsigned char FSCAL1;    // Frequency synthesizer calibration.
   unsigned char FSCAL0;    // Frequency synthesizer calibration.
   unsigned char FSTEST;    // Frequency synthesizer calibration control
   unsigned char TEST2;     // Various test settings.
   unsigned char TEST1;     // Various test settings.
   unsigned char TEST0;     // Various test settings.
   unsigned char FIFOTHR;   // RXFIFO and TXFIFO thresholds.
   unsigned char IOCFG2;    // GDO2 output pin configuration
   unsigned char PKTCTRL1;  // Packet automation control.
   unsigned char PKTCTRL0;  // Packet automation control.
   unsigned char ADDR;      // Device address.
   unsigned char PKTLEN;    // Packet length.
   unsigned char MCSM1;     // Main Radio Control State Machine configuration.
} RF_SETTINGS;

typedef struct
{
   unsigned char IOCFG2;   //0
   unsigned char IOCFG1;   //1
   unsigned char IOCFG0;   //2
   unsigned char FIFOTHR;  //3
   unsigned char SYNC1;    //4
   unsigned char SYNC0;    //5
   unsigned char PKTLEN;   //6
   unsigned char PKTCTRL1; //7
   unsigned char PKTCTRL0; //8
   unsigned char ADDR;     //9
   unsigned char CHANNR;   //10
   unsigned char FSCTRL1;
   unsigned char FSCTROL0;
   unsigned char FREQ2;
   unsigned char FREQ1;
   unsigned char FREQ0;
   unsigned char MDMCFG4;
   unsigned char MDMCFG3;
   unsigned char MDMCFG2;
   unsigned char MDMCFG1;
   unsigned char MDMCFG0;
   unsigned char DEVIATN;
   unsigned char MCSM2;
   unsigned char MCSM1;
   unsigned char MCSM0;
   unsigned char FOCCFG;
   unsigned char BSCFG;
   unsigned char AGCCTRL2;
   unsigned char AGCCTRL1;
   unsigned char AGCCTRL0;
   unsigned char WOREVT1;
   unsigned char WOREVT0;
   unsigned char WORCTRL;
   unsigned char FREND1;
   unsigned char FREND0;
   unsigned char FSCAL3;
   unsigned char FSCAL2;
   unsigned char FSCAL1;
   unsigned char FSCAL0;
   unsigned char RCCTRL1;
   unsigned char RCCTRL0;
   unsigned char FSTEST;
   unsigned char PTEST;
   unsigned char AGCTEST;
   unsigned char TEST2;
   unsigned char TEST1;
   unsigned char TEST0;
}CC1101_CONFIG;

void writeRFSettings(void);
/*******************************************************************************
Noi Dung    :   Gui tin hieu RESET toi CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_Reset(void);
/*******************************************************************************
Noi Dung    :   Thiet lap cap nguon hoat dong cho CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_PowerUp(void);
/*******************************************************************************
Noi Dung    :   Gui mot lenh thuc thi toi CC1101.
Tham Bien   :   strobe    :   Ma lenh thuc thi.
Tra Ve      :   Gia tri doc duoc khi gui ma lenh.
********************************************************************************/
unsigned char CC1101_Strobe(unsigned char strobe);
/*******************************************************************************
Noi Dung    :   Doc gia tri cua mot thanh ghi trang thai.
Tham Bien   :   addr    :   Dia chi cua thanh ghi.
Tra Ve      :   Gia tri hien tai cua thanh ghi.
********************************************************************************/
unsigned char CC1101_ReadStatus(unsigned char addr);
/*******************************************************************************
Noi Dung    :   Viet cau hinh cai dat ao CC1101.
Tham Bien   :   pRfSettings    :   Cau hinh cai dat
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_Config(CC1101_CONFIG* Config);
void CC1101_WriteRfSettings(RF_SETTINGS *pRfSettings);
/*******************************************************************************
Noi Dung    :   Khoi tao chip CC1101.
Tham Bien   :   pRfSettings    :   Cau hinh cai dat
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_Init(void);
/*******************************************************************************
Noi Dung    :   Doc gia tri cua mot thanh ghi.
Tham Bien   :   addr    :   Dia chi cua thanh ghi.
Tra Ve      :   Gia tri doc duoc khi gui ma lenh..
********************************************************************************/
unsigned char CC1101_ReadReg(unsigned char addr);
/*******************************************************************************
Noi Dung    :   Doc lien tiep nhieu thanh ghi.
Tham Bien   :   addr    :   Dia chi cua thanh ghi dau tien.
                buffer  :   Bo dem luu tru gia tri cua cac thanh ghi.
                count   :   So luong thanh ghi can doc.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_ReadBurstReg(unsigned char addr,unsigned char *buffer,unsigned char count);

/*******************************************************************************
Noi Dung    :   Viet vao thanh ghi cua CC1101.
Tham Bien   :   addr    :   Dia chi cua thanh ghi.
                value   :   Gia tri can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_WriteReg(unsigned char addr,unsigned char value);
/*******************************************************************************
Noi Dung    :   Ghi lien tiep nhieu thanh ghi.
Tham Bien   :   addr    :   Dia chi cua thanh ghi dau tien.
                buffer  :   Bo dem luu tru gia tri cua can ghi vao cac thanh ghi.
                count   :   So luong thanh ghi can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_WriteBurstReg(unsigned char addr,unsigned char *buffer,unsigned char count);
/*******************************************************************************
Noi Dung    :   Doc gia tri RSSI dua tren goi tin nhan duoc moi nhat.
Tham Bien   :   Khong.
Tra Ve      :   gia tri RSSI.
********************************************************************************/
unsigned char CC1101_RdRSSI(void);
/*******************************************************************************
Noi Dung    :   Doc gia tri LQI dua tren goi tin nhan duoc moi nhat.
Tham Bien   :   Khong.
Tra Ve      :   gia tri LQI.
********************************************************************************/
unsigned char CC1101_RdLQI(void);

/*******************************************************************************
Noi Dung    :   Giai phong bo dem FIFO nhan.
Tham Bien   :   Khong.
Tra Ve      :   Gia tri giai phong thanh cong hay that bai.
********************************************************************************/

unsigned char CC1101_RxFifoEmpty(void);
/*******************************************************************************
Noi Dung    :   Nhan mot goi tin.
Tham Bien   :   rxBuffer    :   Bo dem du lieu nhan.
                length      :   Do dai cua du lieu nhan duoc.
Tra Ve      :   1           :   co goi tin + CRC OK.
                0           :   CRC loi hay khong co goi tin nao den.
********************************************************************************/
unsigned char CC1101_ReceivePacket(unsigned char *rxBuffer,unsigned char *length);

/*******************************************************************************
Noi Dung    :   Giai phong bo dem FIFO gui.
Tham Bien   :   Khong.
Tra Ve      :   Gia tri giai phong thanh cong hay that bai.
********************************************************************************/
unsigned char CC1101_TxFifoEmpty(void);
/*******************************************************************************
Noi Dung    :   Gui mot goi tin qua CC1101.
Tham Bien   :   txBuffer    :    Buffer goi tin gui di.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_SendPacket(unsigned char *txBuffer);
/*******************************************************************************
 Noi dung  : Gui du lieu toi TXFIFO
 Tham bien: txBuffer buffer cua goi tin
             size kich thuoc goi tin
 Tra ve     : Khong
********************************************************************************/
void CC1101_SendPackets(unsigned char *txBuffer, unsigned char size);
/*******************************************************************************
Noi Dung    :   Doc trang thai truyen cua CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Gia tri trang thai truyen.
********************************************************************************/

unsigned char CC1101_ReadChipStatusTX(void);
/*******************************************************************************
Noi Dung    :   Doc trang thai nhan cua CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Gia tri trang thai nhan.
********************************************************************************/
unsigned char CC1101_ReadChipStatusRX(void);
/*******************************************************************************
Noi Dung    :   Giai phong du lieu o bo dem nhan.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_FlushRX(void);
/*******************************************************************************
Noi Dung    :   Giai phong du lieu o bo dem gui.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_FlushTX(void);
/*******************************************************************************
Noi Dung    :   Thiet lap che do nhan cho CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_RXMode(void);
/*******************************************************************************
Noi Dung    :   Thiet lap che do nhan cho CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void Delay2us(void);
/*******************************************************************************
Noi Dung    :   Tao tre 2us.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void Delay41us(void);
/*******************************************************************************
Noi dung : Tao tre time 4us
Tham bien : khong
Tra ve     : Khong
*******************************************************************************/
unsigned char CC1101_ReadRegs(unsigned char addr);
#endif

