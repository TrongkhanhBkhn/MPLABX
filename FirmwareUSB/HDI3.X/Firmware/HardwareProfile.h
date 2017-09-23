/* 
 * File:   HardwareProfile.h
 * Author: BuiQuangMinh
 *
 * Created on Ngày 02 tháng 8 n?m 2012, 14:35
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

//#define USE_SELF_POWER_SENSE_IO
#define tris_self_power     TRISAbits.TRISA2    // Input
#if defined(USE_SELF_POWER_SENSE_IO)
#define self_power          PORTAbits.RA2
#else
#define self_power          1
#endif

//#define USE_USB_BUS_SENSE_IO
#define tris_usb_bus_sense  TRISAbits.TRISA1    // Input
#if defined(USE_USB_BUS_SENSE_IO)
#define USB_BUS_SENSE       PORTAbits.RA1
#else
#define USB_BUS_SENSE       1
#endif

#define CLOCK_FREQ 48000000

#endif	/* HARDWAREPROFILE_H */

