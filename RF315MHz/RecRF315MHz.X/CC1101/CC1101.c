#include "CC1101.h"
#include "../SPI/SPI.h"
#include "../Hardware/Generic.h"
//#define RF_0db
static unsigned char rssi;
static unsigned char lqi;
#define RF_10db
//#define USE_RW
/*********************************su dung thach anh 8MHz************************/
/************************************************************************************************************/
void Delay2us(void)
{
    Delay1TCY();//0.5us
    Delay1TCY();
    Delay1TCY();
    Delay1TCY();
}
void Delay41us(void)
{
    Delay10TCYx(8);
    Delay1TCY();
    Delay1TCY();
}
// Product = CC1100
// Crystal accuracy = 40 ppm
// X-tal frequency = 26 MHz
// RF output power = 0 dBm
// RX filterbandwidth = 540.000000 kHz
// Deviation = 0.000000
// Return state:  Return to RX state upon leaving either TX or RX
// Datarate = 250.000000 kbps
// Modulation = (7) MSK
// Manchester enable = (0) Manchester disabled
// RF Frequency = 433.000000 MHz
// Channel spacing = 199.951172 kHz
// Channel number = 0
// Optimization = Sensitivity
// Sync mode = (3) 30/32 sync word bits detected
// Format of RX/TX data = (0) Normal mode, use FIFOs for RX and TX
// CRC operation = (1) CRC calculation in TX and CRC check in RX enabled
// Forward Error Correction = (0) FEC disabled
// Length configuration = (1) Variable length packets, packet length configured by the first received byte after sync word.
// Packetlength = 255
// Preamble count = (2)  4 bytes
// Append status = 1
// Address check = (0) No address check
// FIFO autoflush = 0
// Device address = 0
// GDO0 signal selection = ( 6) Asserts when sync word has been sent / received, and de-asserts at the end of the packet
// GDO2 signal selection = (11) Serial Clock
void writeRFSettings(void)
{
    // Write register settings
    CC1101_WriteReg(CC1101_IOCFG2,   0x0B); // GDO2 output pin config.
    CC1101_WriteReg(CC1101_IOCFG0,   0x06); // GDO0 output pin config.
    CC1101_WriteReg(CC1101_PKTLEN,   0xFF); // Packet length.
    CC1101_WriteReg(CC1101_PKTCTRL1, 0x04); // Packet automation control.
    CC1101_WriteReg(CC1101_PKTCTRL0, 0x05); // Packet automation control.
    CC1101_WriteReg(CC1101_ADDR,     0x02); // Device address.
    CC1101_WriteReg(CC1101_CHANNR,   0x00); // Channel number.
    CC1101_WriteReg(CC1101_FSCTRL1,  0x0B); // Freq synthesizer control.
    CC1101_WriteReg(CC1101_FSCTRL0,  0x00); // Freq synthesizer control.
    CC1101_WriteReg(CC1101_FREQ2,    0x10); // Freq control word, high byte
    CC1101_WriteReg(CC1101_FREQ1,    0xA7); // Freq control word, mid byte.
    CC1101_WriteReg(CC1101_FREQ0,    0x62); // Freq control word, low byte.

    CC1101_WriteReg(CC1101_MDMCFG4,  0x2D); // Modem configuration.
    CC1101_WriteReg(CC1101_MDMCFG3,  0x3B); // Modem configuration.
    CC1101_WriteReg(CC1101_MDMCFG2,  0x73); // Modem configuration.   ->OK
    CC1101_WriteReg(CC1101_MDMCFG1,  0x22); // Modem configuration.
    CC1101_WriteReg(CC1101_MDMCFG0,  0xF8); // Modem configuration.


    CC1101_WriteReg(CC1101_DEVIATN,  0x00); // Modem dev (when FSK mod en)

    CC1101_WriteReg(CC1101_MCSM1 ,   0x3F); //MainRadio Cntrl State Machine
    CC1101_WriteReg(CC1101_MCSM0 ,   0x18); //MainRadio Cntrl State Machine

    CC1101_WriteReg(CC1101_FOCCFG,   0x1D); // Freq Offset Compens. Config
    CC1101_WriteReg(CC1101_BSCFG,    0x1C); //  Bit synchronization config.

    CC1101_WriteReg(CC1101_AGCCTRL2, 0xC7); // AGC control.
    CC1101_WriteReg(CC1101_AGCCTRL1, 0x00); // AGC control.
    CC1101_WriteReg(CC1101_AGCCTRL0, 0xB2); // AGC control.

    CC1101_WriteReg(CC1101_FREND1,   0xB6); // Front end RX configuration.
    CC1101_WriteReg(CC1101_FREND0,   0x10); // Front end RX configuration.


    CC1101_WriteReg(CC1101_FSCAL3,   0xEA); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_FSCAL2,   0x0A); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_FSCAL1,   0x00); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_FSCAL0,   0x11); // Frequency synthesizer cal.

    CC1101_WriteReg(CC1101_FSTEST,   0x59); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_TEST2,    0x88); // Various test settings.
    CC1101_WriteReg(CC1101_TEST1,    0x31); // Various test settings.
    CC1101_WriteReg(CC1101_TEST0,    0x0B); // Various test settings.
}
RF_SETTINGS rfSettings =        // 433Mhz, 9600Bauds
{
    0x06,  // FSCTRL1       Frequency Synthesizer Control - IF:152.343Khz
    0x07,  // IOCFG0        GDO0 Output Pin Configuration - Packet received and CRC OK
    0x00,  // FSCTRL0       Frequency Synthesizer Control - Freq offset
    0x10,  // FREQ2         Frequency Control Word, High Byte - 433.999 Mhz
    0xB1,  // FREQ1         Frequency Control Word, Middle Byte
    0x3B,  // FREQ0         Frequency Control Word, Low Byte
    0xF8,  // MDMCFG4       Modem Configuration - BW: 58.035Khz
    0x83,  // MDMCFG3       Modem Configuration - 9595 Baud
    0x13,  // MDMCFG2       Modem Configuration - 30/32 sync word bits - Manchester disable - GFSK - Digital DC filter enable
    0x22,  // MDMCFG1       Modem Configuration - num of preamble bytes:4 - FEC disable
    0xF8,  // MDMCFG0       Modem Configuration - Channel spacing: 199.951Khz
    0x00,  // CHANNR        Channel Number
    0x15,  // DEVIATN       Modem Deviation Setting - 5.157Khz
    0x56,  // FREND1        Front End RX Configuration
    0x10,  // FREND0        Front End TX Configuration
    0x18,  // MCSM0         Main Radio Control State Machine Configuration - PO timeout: 64(149-155us) - Auto calibrate from idle to rx/tx
    0x16,  // FOCCFG        Frequency Offset Compensation Configuration
    0x6C,  // BSCFG         Bit Synchronization Configuration
    0x03,  // AGCCTRL2      AGC Control - target amplitude: 33dB - Maximum possible LNA + LNA 2 gain - All gain settings can be used
    0x40,  // AGCCTRL1      AGC Control - LNA gain decreased first
    0x91,  // AGCCTRL0      AGC Control - Medium hysterisis - Filter Samples: 16 - Normal AGC operation
    0xE9,  // FSCAL3        Frequency Synthesizer Calibration
    0x2A,  // FSCAL2        Frequency Synthesizer Calibration
    0x00,  // FSCAL1        Frequency Synthesizer Calibration
    0x1F,  // FSCAL0        Frequency Synthesizer Calibration
    0x59,  // FSTEST        Frequency Synthesizer Calibration Control
    0x88,  // TEST2         Various Test Settings
    0x31,  // TEST1         Various Test Settings
    0x09,  // TEST0         Various Test Settings
    0x07,  // FIFOTHR       RX FIFO and TX FIFO Thresholds - Bytes in TX FIFO:33 - Bytes in RX FIFO:32
    0x06,  // IOCFG2        GDO2 Output Pin Configuration - Sync word received/sent - end of packet
    0x04,  // PKTCTRL1      Packet Automation Control - No address check - Automatic flush of RX FIFO is disable - sync word is always accepted
    0x05,  // PKTCTRL0      Packet Automation Control - whitening is off - RX/TX data normal mode - CRC calculation in TX and CRC check in RX - Variable packet length
    0x00,  // ADDR          Device Address
    0xFF,  // PKTLEN        Packet Length
    0x3F,  // MCSM1         Main Radio Control State Machine Configuration
};

void writeRFConfig(void)
{
    CC1101_WriteReg(CC1101_IOCFG2,   0x29); // GDO2 output pin config.
    CC1101_WriteReg(CC1101_IOCFG0,   0x06); // GDO0 output pin config.
    CC1101_WriteReg(CC1101_PKTLEN,   0xFF); // Packet length.
    CC1101_WriteReg(CC1101_PKTCTRL1, 0x04); // Packet automation control.
    CC1101_WriteReg(CC1101_PKTCTRL0, 0x05); // Packet automation control.
    CC1101_WriteReg(CC1101_ADDR,     0x00); // Device address.
    CC1101_WriteReg(CC1101_CHANNR,   0x00); // Channel number.
    CC1101_WriteReg(CC1101_FSCTRL1,  0x06); // Freq synthesizer control.
    CC1101_WriteReg(CC1101_FSCTRL0,  0x00); // Freq synthesizer control.
    CC1101_WriteReg(CC1101_FREQ2,    0x10); // Freq control word, high byte
    CC1101_WriteReg(CC1101_FREQ1,    0xA7); // Freq control word, mid byte.
    CC1101_WriteReg(CC1101_FREQ0,    0x62); // Freq control word, low byte.

    CC1101_WriteReg(CC1101_MDMCFG4,  0xF8); // Modem configuration.
    CC1101_WriteReg(CC1101_MDMCFG3,  0x83); // Modem configuration.
    CC1101_WriteReg(CC1101_MDMCFG2,  0x43); // Modem configuration.   ->OK
    CC1101_WriteReg(CC1101_MDMCFG1,  0x22); // Modem configuration.
    CC1101_WriteReg(CC1101_MDMCFG0,  0xF8); // Modem configuration.


    CC1101_WriteReg(CC1101_DEVIATN,  0x15); // Modem dev (when FSK mod en)

    CC1101_WriteReg(CC1101_MCSM1 ,   0x30); //MainRadio Cntrl State Machine
    CC1101_WriteReg(CC1101_MCSM0 ,   0x18); //MainRadio Cntrl State Machine

    CC1101_WriteReg(CC1101_FOCCFG,   0x16); // Freq Offset Compens. Config
    CC1101_WriteReg(CC1101_BSCFG,    0x6C); //  Bit synchronization config.

    CC1101_WriteReg(CC1101_AGCCTRL2, 0x03); // AGC control.
    CC1101_WriteReg(CC1101_AGCCTRL1, 0x40); // AGC control.
    CC1101_WriteReg(CC1101_AGCCTRL0, 0x91); // AGC control.

    CC1101_WriteReg(CC1101_FREND1,   0x56); // Front end RX configuration.
    CC1101_WriteReg(CC1101_FREND0,   0x10); // Front end RX configuration.


    CC1101_WriteReg(CC1101_FSCAL3,   0xE9); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_FSCAL2,   0x2A); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_FSCAL1,   0x00); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_FSCAL0,   0x1F); // Frequency synthesizer cal.

    CC1101_WriteReg(CC1101_FSTEST,   0x59); // Frequency synthesizer cal.
    CC1101_WriteReg(CC1101_TEST2,    0x81); // Various test settings.
    CC1101_WriteReg(CC1101_TEST1,    0x35); // Various test settings.
    CC1101_WriteReg(CC1101_TEST0,    0x09); // Various test settings.
}
#ifdef RF_0db
// PATABLE (0 dBm output power)
    unsigned char PATABLE_VALUE[8]={0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
#endif
#ifdef RF_10db
// PATABLE (10 dBm output power)
       unsigned char PATABLE_VALUE[8]={0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
#endif

/*******************************************************************************
Noi Dung    :   Gui tin hieu RESET toi CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_Reset(void)
{
  CC1101_CS = 0;
  Delay2us();
  while (CC1101_MISO);              // cho cho chan MISO xuong muc thap
// SPI_SOFT_ReadWrite(CC1101_SRES);
  SPI_Write(CC1101_SRES);
  Delay2us();
  CC1101_CS=1;
}
/*******************************************************************************
Noi Dung    :   Thiet lap cap nguon hoat dong cho CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_PowerUp(void)
{
  CC1101_CS = 1;
  Delay1TCY();                 //  wait(1e-6);
  Delay1TCY();
  CC1101_CS = 0;
  Delay1TCY();
  Delay1TCY();
  CC1101_CS = 1;
  Delay41us();
  CC1101_Reset();
}
/*******************************************************************************
Noi Dung    :   Gui mot lenh thuc thi toi CC1101.
Tham Bien   :   strobe    :   Ma lenh thuc thi.
Tra Ve      :    Gia tri doc duoc khi gui ma lenh.
********************************************************************************/
unsigned char CC1101_Strobe(unsigned char strobe)
{
    unsigned char x;
#ifdef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    x = SPI_SOFT_ReadWrite(strobe);
    Delay2us();
    CC1101_CS = 1;
#endif
#ifndef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    x = SPI_Write(strobe);
    Delay2us();
    CC1101_CS = 1;
#endif
    return x;
}
/*******************************************************************************
Noi Dung    :   Doc gia tri cua mot thanh ghi trang thai.
Tham Bien   :   addr    :   Dia chi cua thanh ghi.
Tra Ve      :   Gia tri hien tai cua thanh ghi.
********************************************************************************/
unsigned char CC1101_ReadStatus(unsigned char addr)
{
    unsigned char x;
#ifdef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    SPI_SOFT_ReadWrite(addr | READ_BURST);
    x = SPI_SOFT_ReadWrite(0);
    Delay2us();
    CC1101_CS = 1;
#endif
#ifndef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    SPI_Write(addr | READ_BURST);
    x = SPI_Read();
    Delay2us();
    CC1101_CS = 1;
#endif
    return x;
}
/*******************************************************************************
Noi Dung    :   Viet cau hinh cai dat ao CC1101.
Tham Bien   :   pRfSettings    :   Cau hinh cai dat
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_Config( CC1101_CONFIG* Config)
{
    CC1101_WriteBurstReg(0x00, (unsigned char*) Config, 47);
}
void CC1101_WriteRfSettings(RF_SETTINGS *pRfSettings)
{
    // Write register settings
    CC1101_WriteReg(CC1101_FSCTRL1,  pRfSettings->FSCTRL1);
    CC1101_WriteReg(CC1101_FSCTRL0,  pRfSettings->FSCTRL0);
    CC1101_WriteReg(CC1101_FREQ2,    pRfSettings->FREQ2);
    CC1101_WriteReg(CC1101_FREQ1,    pRfSettings->FREQ1);
    CC1101_WriteReg(CC1101_FREQ0,    pRfSettings->FREQ0);
    CC1101_WriteReg(CC1101_MDMCFG4,  pRfSettings->MDMCFG4);
    CC1101_WriteReg(CC1101_MDMCFG3,  pRfSettings->MDMCFG3);
    CC1101_WriteReg(CC1101_MDMCFG2,  pRfSettings->MDMCFG2);
    CC1101_WriteReg(CC1101_MDMCFG1,  pRfSettings->MDMCFG1);
    CC1101_WriteReg(CC1101_MDMCFG0,  pRfSettings->MDMCFG0);
    CC1101_WriteReg(CC1101_CHANNR,   pRfSettings->CHANNR);
    CC1101_WriteReg(CC1101_DEVIATN,  pRfSettings->DEVIATN);
    CC1101_WriteReg(CC1101_FREND1,   pRfSettings->FREND1);
    CC1101_WriteReg(CC1101_FREND0,   pRfSettings->FREND0);
    CC1101_WriteReg(CC1101_MCSM0 ,   pRfSettings->MCSM0 );
    CC1101_WriteReg(CC1101_FOCCFG,   pRfSettings->FOCCFG);
    CC1101_WriteReg(CC1101_BSCFG,    pRfSettings->BSCFG);
    CC1101_WriteReg(CC1101_AGCCTRL2, pRfSettings->AGCCTRL2);
    CC1101_WriteReg(CC1101_AGCCTRL1, pRfSettings->AGCCTRL1);
    CC1101_WriteReg(CC1101_AGCCTRL0, pRfSettings->AGCCTRL0);
    CC1101_WriteReg(CC1101_FSCAL3,   pRfSettings->FSCAL3);
    CC1101_WriteReg(CC1101_FSCAL2,   pRfSettings->FSCAL2);
    CC1101_WriteReg(CC1101_FSCAL1,   pRfSettings->FSCAL1);
    CC1101_WriteReg(CC1101_FSCAL0,   pRfSettings->FSCAL0);
    CC1101_WriteReg(CC1101_FSTEST,   pRfSettings->FSTEST);
    CC1101_WriteReg(CC1101_TEST2,    pRfSettings->TEST2);
    CC1101_WriteReg(CC1101_TEST1,    pRfSettings->TEST1);
    CC1101_WriteReg(CC1101_TEST0,    pRfSettings->TEST0);
    CC1101_WriteReg(CC1101_FIFOTHR,  pRfSettings->FIFOTHR);
    CC1101_WriteReg(CC1101_IOCFG2,   pRfSettings->IOCFG2);
    CC1101_WriteReg(CC1101_IOCFG0,   pRfSettings->IOCFG0);
    CC1101_WriteReg(CC1101_PKTCTRL1, pRfSettings->PKTCTRL1);
    CC1101_WriteReg(CC1101_PKTCTRL0, pRfSettings->PKTCTRL0);
    CC1101_WriteReg(CC1101_ADDR,     pRfSettings->ADDR);
    CC1101_WriteReg(CC1101_PKTLEN,   pRfSettings->PKTLEN);
    CC1101_WriteReg(CC1101_MCSM1 ,   pRfSettings->MCSM1 );
    CC1101_RXMode();

}
/*****************************/
/*******************************************************************************
Noi Dung    :   Doc gia tri cua mot thanh ghi.
Tham Bien   :   addr    :   Dia chi cua thanh ghi.
Tra Ve      :    Gia tri doc duoc khi gui ma lenh.
********************************************************************************/
unsigned char CC1101_ReadReg(unsigned char addr)
{
    unsigned char x;
#ifdef USE_RW
    Delay10TCYx(1);//wait(0.000005);
    CC1101_CS = 0;
    Delay2us();//(0.000002);
    while (CC1101_MISO);
    SPI_SOFT_ReadWrite(addr | READ_SINGLE);
    x = SPI_SOFT_ReadWrite(0);
    Delay2us();
    CC1101_CS = 1;
#endif
#ifndef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
   SPI_Write(addr | READ_BURST);
   Delay2us();
    x = SPI_Read();
    Delay2us();
    CC1101_CS = 1;
#endif
    return x;
}
/*******************************************************************************
Noi Dung    :   Doc lien tiep nhieu thanh ghi.
Tham Bien   :   addr    :   Dia chi cua thanh ghi dau tien.
                buffer  :   Bo dem luu tru gia tri cua cac thanh ghi.
                count   :   So luong thanh ghi can doc.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_ReadBurstReg(unsigned char addr, unsigned char *buffer, unsigned char count)
{
    unsigned char i;
#ifdef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    SPI_SOFT_ReadWrite(addr | READ_BURST);
    for (i = 0; i < count; i++)
    {
        buffer[i] = SPI_SOFT_ReadWrite(0);
    }
    Delay2us();
    CC1101_CS = 1;
#endif
#ifndef USE_RW
    Delay10TCYx(10);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
   SPI_Write(addr | READ_BURST);
     Delay2us();
    for (i = 0; i < count; i++)
    {
       buffer[i] = SPI_Read();
       Delay2us();
    }
    Delay2us();
    CC1101_CS = 1;
#endif
}

/*******************************************************************************
Noi Dung    :   Viet vao thanh ghi cua CC1101.
Tham Bien   :   addr    :   Dia chi cua thanh ghi.
                value   :   Gia tri can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_WriteReg(unsigned char addr, unsigned char value)
{
#ifdef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    addr |= WRITE_SINGLE;
   SPI_SOFT_ReadWrite(addr);
   SPI_SOFT_ReadWrite(value);
    Delay2us();
    CC1101_CS = 1;
#endif
#ifndef USE_RW
     Delay10TCYx(1);
     CC1101_CS = 0;
     Delay2us();
    while (CC1101_MISO);
    SPI_Write(addr);
    SPI_Write(value);
    Delay2us();
    CC1101_CS = 1;
#endif
}

/*******************************************************************************
Noi Dung    :   Ghi lien tiep nhieu thanh ghi.
Tham Bien   :   addr    :   Dia chi cua thanh ghi dau tien.
                buffer  :   Bo dem luu tru gia tri cua can ghi vao cac thanh ghi.
                count   :   So luong thanh ghi can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_WriteBurstReg(unsigned char addr, unsigned char *buffer, unsigned char count)
{
    unsigned char i;
#ifdef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    SPI_SOFT_ReadWrite(addr | WRITE_BURST);
    for (i = 0; i < count; i++)
    {
        SPI_SOFT_ReadWrite(buffer[i]);
    }
    Delay2us();
    CC1101_CS = 1;
#endif
#ifndef USE_RW
    Delay10TCYx(1);
    CC1101_CS = 0;
    Delay2us();
    while (CC1101_MISO);
    SPI_Write(addr | WRITE_BURST);
    for (i = 0; i < count; i++)
    {
       SPI_Write(buffer[i]);
    }
    CC1101_CS = 1;
#endif
}
/*******************************************************************************
Noi Dung    :   Doc gia tri RSSI dua tren goi tin nhan duoc moi nhat.
Tham Bien   :   Khong.
Tra Ve      :   gia tri RSSI.
********************************************************************************/
unsigned char CC1101_RdRSSI(void)
{
    unsigned char crssi;
    if (rssi >= 128)
    {
        crssi = 255 - rssi;
        crssi /= 2;
        crssi += 74;
    }
    else
    {
        crssi = rssi/2;
        crssi += 74;
    }
    return crssi;
}

/*******************************************************************************
Noi Dung    :   Doc gia tri LQI dua tren goi tin nhan duoc moi nhat.
Tham Bien   :   Khong.
Tra Ve      :   gia tri LQI.
********************************************************************************/
unsigned char CC1101_RdLQI(void)
{
    unsigned char clqi;
    clqi = 0x3F - (lqi & 0x3F);

    return clqi;
}
/*******************************************************************************
Noi Dung    :   Doc trang thai cua bo dem FIFO nhan.
Tham Bien   :   Khong.
Tra Ve      :   1     :   Bo dem dang trong.
                0     :   Bo dem co chua du lieu.
********************************************************************************/

unsigned char CC1101_RxFifoEmpty(void)
{
    unsigned char RxFifoStatus;

    CC1101_Strobe(CC1101_SRX);
    RxFifoStatus = CC1101_ReadStatus(CC1101_RXBYTES);

    if (RxFifoStatus & 0x80)      // check for RXFIFO overflow
    {
        // Make sure that the radio is in IDLE state before flushing the FIFO
        // (Unless RXOFF_MODE has been changed, the radio should be in IDLE state at this point)
        CC1101_Strobe(CC1101_SIDLE);
        // Flush RX FIFO
        CC1101_Strobe(CC1101_SFRX);
    }
    if (RxFifoStatus & ~0x80)
    {
        return 0;
    }
    else
        return 1;
}


/*******************************************************************************
Noi Dung    :   Doc trang thai cua bo dem FIFO gui.
Tham Bien   :   Khong.
Tra Ve      :   1     :   Bo dem dang trong.
                0     :   Bo dem co chua du lieu.
********************************************************************************/
unsigned char CC1101_TxFifoEmpty(void)
{
    unsigned char TxFifoStatus;

    CC1101_Strobe(CC1101_STX);
    TxFifoStatus = CC1101_ReadStatus(CC1101_TXBYTES);

    if (TxFifoStatus & 0x80)      // check for TXFIFO underflow
    {
        // Make sure that the radio is in IDLE state before flushing the FIFO
         CC1101_Strobe(CC1101_SIDLE);
        // Flush TX FIFO
        CC1101_Strobe(CC1101_SFTX);
    }
    if (TxFifoStatus & ~0x80)
    {
        return 0;
    }
    else
        return 1;
}
/*******************************************************************************
Noi Dung    :   Gui mot goi tin qua CC1101.
Tham Bien   :   txBuffer    :    Buffer goi tin gui di.
Tra Ve      :   Khong.
********************************************************************************/


/*******************************************************************************
Noi Dung    :   Doc trang thai truyen cua CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Gia tri trang thai truyen.
********************************************************************************/

unsigned char CC1101_ReadChipStatusTX(void)
{
    return CC1101_Strobe(CC1101_SNOP);
}
/*******************************************************************************
Noi Dung    :   Doc trang thai nhan cua CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Gia tri trang thai nhan.
********************************************************************************/
unsigned char CC1101_ReadChipStatusRX(void)
{
    unsigned char x;
#ifdef USE_RW
    Delay10TCYx(1);
    CC1101_CS =0;
    Delay2us();
    while (CC1101_MISO);
    x = SPI_SOFT_ReadWrite(CC1101_PARTNUM | READ_BURST);
    Delay2us();
    CC1101_CS = 1;
#endif
#ifndef USE_RW
    Delay10TCYx(1);
    CC1101_CS =0;
    Delay2us();
    while (CC1101_MISO);
    x = SPI_Write(CC1101_PARTNUM | READ_BURST);
    Delay2us();
    CC1101_CS = 1;
#endif
    return x;
}
/*******************************************************************************
Noi Dung    :   Giai phong du lieu o bo dem nhan.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_FlushRX(void)
{
    // Make sure that the radio is in IDLE state before flushing the FIFO
    CC1101_Strobe(CC1101_SIDLE);
    // Flush RX FIFO
    CC1101_Strobe(CC1101_SFRX);
}
/*******************************************************************************
Noi Dung    :   Giai phong du lieu o bo dem gui.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_FlushTX(void)
{
    // Make sure that the radio is in IDLE state before flushing the FIFO
    CC1101_Strobe(CC1101_SIDLE);
    // Flush TX FIFO
    CC1101_Strobe(CC1101_SFTX);
}
/*******************************************************************************
Noi Dung    :   Thiet lap che do nhan cho CC1101.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_RXMode(void)
{
    CC1101_Strobe(CC1101_SIDLE);
    CC1101_Strobe(CC1101_SRX);
}
/*******************************************************************************
Noi Dung    :   Khoi tao chip CC1101.
Tham Bien   :   pRfSettings    :   Cau hinh cai dat
Tra Ve      :   Khong.
********************************************************************************/
void CC1101_Init(void)
{
    CC1101_PowerUp();
    Delay1TCY();
    #if (CONFIG_CC1101==1)
    writeRFSettings();
    #endif
    #if (CONFIG_CC1101==2)
    CC1101_WriteRfSettings(&rfSettings);
    #endif
    #if (CONFIG_CC1101==3)
     writeRFConfig();
    #endif
    CC1101_WriteReg(CC1101_PATABLE, PATABLE_VALUE[0]);
}
/*******************************************************************************
Noi Dung    :   Nhan mot goi tin.
Tham Bien   :   rxBuffer    :   Bo dem du lieu nhan.
                length      :   Do dai cua du lieu nhan duoc.
Tra Ve      :   1           :   co goi tin + CRC OK.
                0           :   CRC loi hay khong co goi tin nao den.
********************************************************************************/
unsigned char CC1101_ReceivePacket(unsigned char *rxBuffer, unsigned char *length)
{
  unsigned char status[2];
  unsigned char packetLength;

  CC1101_Strobe(CC1101_SRX);
//    // Wait for GDO0 to be set -> sync received
//    while (!GDO0);
//
//    // Wait for GDO0 to be cleared -> end of packet
//    while (GDO0);
    packetLength = CC1101_ReadStatus(CC1101_RXBYTES);
    if (packetLength & BYTES_IN_RXFIFO)
    {
        // Doc do dai du lieu
        packetLength = CC1101_ReadReg(CC1101_RXFIFO);
        // Doc du lieu tu bo dem FIFO.
        if (packetLength <= *length)
        {
            CC1101_ReadBurstReg(CC1101_RXFIFO, rxBuffer, packetLength);
            *length = packetLength;
            // Doc 2 Byte Read the 2 appended status bytes (status[0] = RSSI, status[1] = LQI)
            CC1101_ReadBurstReg(CC1101_RXFIFO, status, 2);

            rssi = status[RSSI];
            lqi = status[LQI];

           //MSB of LQI is the CRC_OK bit
            // LQI la mot thuoc do chat luong cua tin hieu thu duoc
            // CRC_OK la bit cuoi cung de so sanh neu bang 1 neu viec nhan data thanh cong va nguoc lai
            //return (status[LQI] & CRC_OK)
            if(status[LQI] & CRC_OK)
            {
                    return 1;
            }
            CC1101_FlushRX();
        }
        else
        {
            *length = packetLength;
            CC1101_FlushRX();
            return 0;
        }
    }
  return 0;
}
void CC1101_SendPacket(unsigned char *txBuffer)
{
    unsigned char size=1;
    unsigned char TempBuffer[64];
    while(*txBuffer)
    {
        TempBuffer[size++]=*(txBuffer++);
    };
    TempBuffer[0]=size-1;// Chi tinh data, khong tinh byte Size
    //TempBuffer[0]=0x01;//Dia chi cua ben nhan
    CC1101_WriteBurstReg(CC1101_TXFIFO, TempBuffer, size);
    CC1101_Strobe(CC1101_SIDLE);
    CC1101_Strobe(CC1101_STX);
    // Wait for GDO0 to be set -> sync transmitted
    while (!GDO0);
    // Wait for GDO0 to be cleared -> end of packet
    while (GDO0);
    CC1101_FlushTX();
}
void CC1101_SendPackets(unsigned char *txBuffer, unsigned char size)
{
    unsigned char i;
    for(i= size; i>0; i--)
        txBuffer[i] = txBuffer[i - 1];
        txBuffer[0] = size;
        CC1101_WriteBurstReg(CC1101_TXFIFO, txBuffer, size+1);
        CC1101_Strobe(CC1101_SIDLE);
        CC1101_Strobe(CC1101_STX);
         while (!GDO0);
    // Wait for GDO0 to be cleared -> end of packet
   while (GDO0);
  CC1101_FlushTX();
}