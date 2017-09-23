/* 
 * File:   main.c
 * Author: BuiQuangMinh
 *
 * Created on Ngay 02 thang 8 nam 2012, 12:47
 */

#include "p18f14k50.h"
#include "USB/usb.h"
#include "USB/usb_function_hid.h"
#include "HID Device Driver/usb_function_hid.c"
#include "USB/usb_device.h"
#include "usb_device.c"

#pragma config CPUDIV = NOCLKDIV
#pragma config USBDIV = OFF
#pragma config FOSC   = HS
#pragma config PLLEN  = ON
#pragma config FCMEN  = OFF
#pragma config IESO   = OFF
#pragma config PWRTEN = OFF
#pragma config BOREN  = OFF
#pragma config BORV   = 30
#pragma config WDTEN  = OFF
#pragma config WDTPS  = 32768
#pragma config MCLRE  = ON
#pragma config HFOFST = OFF
#pragma config STVREN = ON
#pragma config LVP    = OFF
#pragma config XINST  = OFF
#pragma config BBSIZ  = OFF
#pragma config CP0    = OFF
#pragma config CP1    = OFF
#pragma config CPB    = OFF
#pragma config WRT0   = OFF
#pragma config WRT1   = OFF
#pragma config WRTB   = OFF
#pragma config WRTC   = OFF
#pragma config EBTR0  = OFF
#pragma config EBTR1  = OFF
#pragma config EBTRB  = OFF

unsigned char outbuffer[HID_OUT_SIZE];
unsigned char inbuffer[HID_IN_SIZE];

USB_HANDLE USBOutHandle = 0;
USB_HANDLE USBInHandle = 0;

void high_isr(void);
void low_isr(void); 

#pragma code low_vector=0x18
void interrupt_at_low_vector(void)
{
    _asm GOTO low_isr _endasm
}
#pragma code

#pragma code high_vector=0x8
void interrupt_at_high_vector(void)
{
    _asm GOTO high_isr _endasm
}
#pragma code

#pragma interrupt high_isr
void high_isr()
{
    
#if defined(USB_INTERRUPT)
        USBDeviceTasks();
#endif
}

#pragma interruptlow low_isr
void low_isr()
{

}

static void InitializeSystem(void) {
    ADCON1 |= 0x0F;
    TRISC = 0;
    LATC = 0;

    USBDeviceInit();
}

BOOL red, green;

void main() {
    InitializeSystem();

    red = FALSE;
    green = FALSE;

    #if defined(USB_INTERRUPT)
        USBDeviceAttach();
    #endif

    while (1) {
        if(!((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1))) {
            if(!HIDRxHandleBusy(USBOutHandle))
            {
                if (outbuffer[0] == 0) {
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        inbuffer[0] = green;
                        inbuffer[1] = red;
                        USBInHandle = HIDTxPacket(HID_EP,(BYTE*)&inbuffer[0], HID_IN_SIZE);
                    }
                }
                if (outbuffer[0] == 1) {
                    if (outbuffer[1] == 1) green = TRUE; else green = FALSE;
                    if (outbuffer[2] == 1) red = TRUE; else red = FALSE;
                    if (green) LATCbits.LATC6 = 1; else LATCbits.LATC6 = 0;
                    if (red) LATCbits.LATC7 = 1; else LATCbits.LATC7 = 0;
                }

                USBOutHandle = HIDRxPacket(HID_EP, (BYTE*)&outbuffer, HID_OUT_SIZE);
            }
        }
        
    }
}

BOOL USER_USB_CALLBACK_EVENT_HANDLER(int event, void *pdata, WORD size)
{
    switch(event)
    {
        case EVENT_CONFIGURED:
            USBEnableEndpoint(HID_EP,USB_IN_ENABLED|USB_OUT_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);
            USBOutHandle = HIDRxPacket(HID_EP,(BYTE*)&outbuffer, HID_OUT_SIZE);
            break;
        case EVENT_EP0_REQUEST:
            USBCheckHIDRequest();
            break;
        default:
            break;
    }
    return TRUE;
}