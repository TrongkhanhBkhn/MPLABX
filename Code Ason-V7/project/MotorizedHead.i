#line 1 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 1 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 1 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"

#line 33 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
 


#line 37 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"

extern volatile near unsigned char       SSPMSK;
extern volatile near struct {
  unsigned MSK0:1;
  unsigned MSK1:1;
  unsigned MSK2:1;
  unsigned MSK3:1;
  unsigned MSK4:1;
  unsigned MSK5:1;
  unsigned MSK6:1;
  unsigned MSK7:1;
} SSPMSKbits;
extern volatile near unsigned char       SLRCON;
extern volatile near struct {
  unsigned SLRA:1;
  unsigned SLRB:1;
  unsigned SLRC:1;
} SLRCONbits;
extern volatile near unsigned char       CM2CON1;
extern volatile near struct {
  unsigned :4;
  unsigned C2RSEL:1;
  unsigned C1RSEL:1;
  unsigned MC2OUT:1;
  unsigned MC1OUT:1;
} CM2CON1bits;
extern volatile near unsigned char       CM2CON0;
extern volatile near union {
  struct {
    unsigned C2CH:2;
    unsigned C2R:1;
    unsigned C2SP:1;
    unsigned C2POL:1;
    unsigned C2OE:1;
    unsigned C2OUT:1;
    unsigned C2ON:1;
  };
  struct {
    unsigned C2CH0:1;
    unsigned C2CH1:1;
  };
} CM2CON0bits;
extern volatile near unsigned char       CM1CON0;
extern volatile near union {
  struct {
    unsigned C1CH:2;
    unsigned C1R:1;
    unsigned C1SP:1;
    unsigned C1POL:1;
    unsigned C1OE:1;
    unsigned C1OUT:1;
    unsigned C1ON:1;
  };
  struct {
    unsigned C1CH0:1;
    unsigned C1CH1:1;
  };
} CM1CON0bits;
extern volatile near unsigned char       WPUB;
extern volatile near struct {
  unsigned WPUB0:1;
  unsigned WPUB1:1;
  unsigned WPUB2:1;
  unsigned WPUB3:1;
  unsigned WPUB4:1;
  unsigned WPUB5:1;
  unsigned WPUB6:1;
  unsigned WPUB7:1;
} WPUBbits;
extern volatile near unsigned char       IOCB;
extern volatile near struct {
  unsigned :4;
  unsigned IOCB4:1;
  unsigned IOCB5:1;
  unsigned IOCB6:1;
  unsigned IOCB7:1;
} IOCBbits;
extern volatile near unsigned char       ANSEL;
extern volatile near struct {
  unsigned ANS0:1;
  unsigned ANS1:1;
  unsigned ANS2:1;
  unsigned ANS3:1;
  unsigned ANS4:1;
} ANSELbits;
extern volatile near unsigned char       ANSELH;
extern volatile near struct {
  unsigned ANS8:1;
  unsigned ANS9:1;
  unsigned ANS10:1;
  unsigned ANS11:1;
  unsigned ANS12:1;
} ANSELHbits;
extern volatile near unsigned char       PORTA;
extern volatile near union {
  struct {
    unsigned RA0:1;
    unsigned RA1:1;
    unsigned RA2:1;
    unsigned RA3:1;
    unsigned RA4:1;
    unsigned RA5:1;
    unsigned RA6:1;
    unsigned RA7:1;
  };
  struct {
    unsigned AN0:1;
    unsigned AN1:1;
    unsigned AN2:1;
    unsigned AN3:1;
    unsigned :1;
    unsigned AN4:1;
  };
  struct {
    unsigned C12IN0M:1;
    unsigned C12IN1M:1;
    unsigned C2INP:1;
    unsigned C1INP:1;
    unsigned C1OUT:1;
    unsigned C2OUT:1;
  };
  struct {
    unsigned C12IN0N:1;
    unsigned C12IN1N:1;
    unsigned VREFM:1;
    unsigned VREFP:1;
    unsigned T0CKI:1;
    unsigned SS:1;
  };
  struct {
    unsigned :2;
    unsigned VREFN:1;
    unsigned :2;
    unsigned NOT_SS:1;
  };
  struct {
    unsigned :2;
    unsigned CVREF:1;
    unsigned :2;
    unsigned LVDIN:1;
  };
  struct {
    unsigned :5;
    unsigned HLVDIN:1;
  };
} PORTAbits;
extern volatile near unsigned char       PORTB;
extern volatile near union {
  struct {
    unsigned RB0:1;
    unsigned RB1:1;
    unsigned RB2:1;
    unsigned RB3:1;
    unsigned RB4:1;
    unsigned RB5:1;
    unsigned RB6:1;
    unsigned RB7:1;
  };
  struct {
    unsigned INT0:1;
    unsigned INT1:1;
    unsigned INT2:1;
    unsigned CCP2:1;
    unsigned KBI0:1;
    unsigned KBI1:1;
    unsigned KBI2:1;
    unsigned KBI3:1;
  };
  struct {
    unsigned AN12:1;
    unsigned AN10:1;
    unsigned AN8:1;
    unsigned AN9:1;
    unsigned AN11:1;
    unsigned PGM:1;
    unsigned PGC:1;
    unsigned PGD:1;
  };
  struct {
    unsigned FLT0:1;
    unsigned C12IN3M:1;
    unsigned :1;
    unsigned C12IN2M:1;
  };
  struct {
    unsigned :1;
    unsigned C12IN3N:1;
    unsigned :1;
    unsigned C12IN2N:1;
  };
  struct {
    unsigned :1;
    unsigned P1C:1;
    unsigned P1B:1;
    unsigned :1;
    unsigned P1D:1;
  };
} PORTBbits;
extern volatile near unsigned char       PORTC;
extern volatile near union {
  struct {
    unsigned RC0:1;
    unsigned RC1:1;
    unsigned RC2:1;
    unsigned RC3:1;
    unsigned RC4:1;
    unsigned RC5:1;
    unsigned RC6:1;
    unsigned RC7:1;
  };
  struct {
    unsigned T1OSO:1;
    unsigned T1OSI:1;
    unsigned CCP1:1;
    unsigned SCK:1;
    unsigned SDI:1;
    unsigned SDO:1;
    unsigned TX:1;
    unsigned RX:1;
  };
  struct {
    unsigned T13CKI:1;
    unsigned CCP2:1;
    unsigned P1A:1;
    unsigned SCL:1;
    unsigned SDA:1;
    unsigned :1;
    unsigned CK:1;
    unsigned DT:1;
  };
  struct {
    unsigned T1CKI:1;
  };
  struct {
    unsigned T3CKI:1;
  };
} PORTCbits;
extern volatile near unsigned char       PORTE;
extern volatile near union {
  struct {
    unsigned :3;
    unsigned RE3:1;
  };
  struct {
    unsigned :3;
    unsigned MCLR:1;
  };
  struct {
    unsigned :3;
    unsigned NOT_MCLR:1;
  };
  struct {
    unsigned :3;
    unsigned VPP:1;
  };
} PORTEbits;
extern volatile near unsigned char       LATA;
extern volatile near struct {
  unsigned LATA0:1;
  unsigned LATA1:1;
  unsigned LATA2:1;
  unsigned LATA3:1;
  unsigned LATA4:1;
  unsigned LATA5:1;
  unsigned LATA6:1;
  unsigned LATA7:1;
} LATAbits;
extern volatile near unsigned char       LATB;
extern volatile near struct {
  unsigned LATB0:1;
  unsigned LATB1:1;
  unsigned LATB2:1;
  unsigned LATB3:1;
  unsigned LATB4:1;
  unsigned LATB5:1;
  unsigned LATB6:1;
  unsigned LATB7:1;
} LATBbits;
extern volatile near unsigned char       LATC;
extern volatile near struct {
  unsigned LATC0:1;
  unsigned LATC1:1;
  unsigned LATC2:1;
  unsigned LATC3:1;
  unsigned LATC4:1;
  unsigned LATC5:1;
  unsigned LATC6:1;
  unsigned LATC7:1;
} LATCbits;
extern volatile near unsigned char       DDRA;
extern volatile near union {
  struct {
    unsigned TRISA0:1;
    unsigned TRISA1:1;
    unsigned TRISA2:1;
    unsigned TRISA3:1;
    unsigned TRISA4:1;
    unsigned TRISA5:1;
    unsigned TRISA6:1;
    unsigned TRISA7:1;
  };
  struct {
    unsigned RA0:1;
    unsigned RA1:1;
    unsigned RA2:1;
    unsigned RA3:1;
    unsigned RA4:1;
    unsigned RA5:1;
    unsigned RA6:1;
    unsigned RA7:1;
  };
} DDRAbits;
extern volatile near unsigned char       TRISA;
extern volatile near union {
  struct {
    unsigned TRISA0:1;
    unsigned TRISA1:1;
    unsigned TRISA2:1;
    unsigned TRISA3:1;
    unsigned TRISA4:1;
    unsigned TRISA5:1;
    unsigned TRISA6:1;
    unsigned TRISA7:1;
  };
  struct {
    unsigned RA0:1;
    unsigned RA1:1;
    unsigned RA2:1;
    unsigned RA3:1;
    unsigned RA4:1;
    unsigned RA5:1;
    unsigned RA6:1;
    unsigned RA7:1;
  };
} TRISAbits;
extern volatile near unsigned char       DDRB;
extern volatile near union {
  struct {
    unsigned TRISB0:1;
    unsigned TRISB1:1;
    unsigned TRISB2:1;
    unsigned TRISB3:1;
    unsigned TRISB4:1;
    unsigned TRISB5:1;
    unsigned TRISB6:1;
    unsigned TRISB7:1;
  };
  struct {
    unsigned RB0:1;
    unsigned RB1:1;
    unsigned RB2:1;
    unsigned RB3:1;
    unsigned RB4:1;
    unsigned RB5:1;
    unsigned RB6:1;
    unsigned RB7:1;
  };
} DDRBbits;
extern volatile near unsigned char       TRISB;
extern volatile near union {
  struct {
    unsigned TRISB0:1;
    unsigned TRISB1:1;
    unsigned TRISB2:1;
    unsigned TRISB3:1;
    unsigned TRISB4:1;
    unsigned TRISB5:1;
    unsigned TRISB6:1;
    unsigned TRISB7:1;
  };
  struct {
    unsigned RB0:1;
    unsigned RB1:1;
    unsigned RB2:1;
    unsigned RB3:1;
    unsigned RB4:1;
    unsigned RB5:1;
    unsigned RB6:1;
    unsigned RB7:1;
  };
} TRISBbits;
extern volatile near unsigned char       DDRC;
extern volatile near union {
  struct {
    unsigned TRISC0:1;
    unsigned TRISC1:1;
    unsigned TRISC2:1;
    unsigned TRISC3:1;
    unsigned TRISC4:1;
    unsigned TRISC5:1;
    unsigned TRISC6:1;
    unsigned TRISC7:1;
  };
  struct {
    unsigned RC0:1;
    unsigned RC1:1;
    unsigned RC2:1;
    unsigned RC3:1;
    unsigned RC4:1;
    unsigned RC5:1;
    unsigned RC6:1;
    unsigned RC7:1;
  };
} DDRCbits;
extern volatile near unsigned char       TRISC;
extern volatile near union {
  struct {
    unsigned TRISC0:1;
    unsigned TRISC1:1;
    unsigned TRISC2:1;
    unsigned TRISC3:1;
    unsigned TRISC4:1;
    unsigned TRISC5:1;
    unsigned TRISC6:1;
    unsigned TRISC7:1;
  };
  struct {
    unsigned RC0:1;
    unsigned RC1:1;
    unsigned RC2:1;
    unsigned RC3:1;
    unsigned RC4:1;
    unsigned RC5:1;
    unsigned RC6:1;
    unsigned RC7:1;
  };
} TRISCbits;
extern volatile near unsigned char       OSCTUNE;
extern volatile near union {
  struct {
    unsigned TUN:6;
    unsigned PLLEN:1;
    unsigned INTSRC:1;
  };
  struct {
    unsigned TUN0:1;
    unsigned TUN1:1;
    unsigned TUN2:1;
    unsigned TUN3:1;
    unsigned TUN4:1;
    unsigned TUN5:1;
  };
} OSCTUNEbits;
extern volatile near unsigned char       PIE1;
extern volatile near struct {
  unsigned TMR1IE:1;
  unsigned TMR2IE:1;
  unsigned CCP1IE:1;
  unsigned SSPIE:1;
  unsigned TXIE:1;
  unsigned RCIE:1;
  unsigned ADIE:1;
} PIE1bits;
extern volatile near unsigned char       PIR1;
extern volatile near struct {
  unsigned TMR1IF:1;
  unsigned TMR2IF:1;
  unsigned CCP1IF:1;
  unsigned SSPIF:1;
  unsigned TXIF:1;
  unsigned RCIF:1;
  unsigned ADIF:1;
} PIR1bits;
extern volatile near unsigned char       IPR1;
extern volatile near struct {
  unsigned TMR1IP:1;
  unsigned TMR2IP:1;
  unsigned CCP1IP:1;
  unsigned SSPIP:1;
  unsigned TXIP:1;
  unsigned RCIP:1;
  unsigned ADIP:1;
} IPR1bits;
extern volatile near unsigned char       PIE2;
extern volatile near union {
  struct {
    unsigned CCP2IE:1;
    unsigned TMR3IE:1;
    unsigned HLVDIE:1;
    unsigned BCLIE:1;
    unsigned EEIE:1;
    unsigned C2IE:1;
    unsigned C1IE:1;
    unsigned OSCFIE:1;
  };
  struct {
    unsigned :2;
    unsigned LVDIE:1;
  };
} PIE2bits;
extern volatile near unsigned char       PIR2;
extern volatile near union {
  struct {
    unsigned CCP2IF:1;
    unsigned TMR3IF:1;
    unsigned HLVDIF:1;
    unsigned BCLIF:1;
    unsigned EEIF:1;
    unsigned C2IF:1;
    unsigned C1IF:1;
    unsigned OSCFIF:1;
  };
  struct {
    unsigned :2;
    unsigned LVDIF:1;
  };
} PIR2bits;
extern volatile near unsigned char       IPR2;
extern volatile near union {
  struct {
    unsigned CCP2IP:1;
    unsigned TMR3IP:1;
    unsigned HLVDIP:1;
    unsigned BCLIP:1;
    unsigned EEIP:1;
    unsigned C2IP:1;
    unsigned C1IP:1;
    unsigned OSCFIP:1;
  };
  struct {
    unsigned :2;
    unsigned LVDIP:1;
  };
} IPR2bits;
extern volatile near unsigned char       EECON1;
extern volatile near struct {
  unsigned RD:1;
  unsigned WR:1;
  unsigned WREN:1;
  unsigned WRERR:1;
  unsigned FREE:1;
  unsigned :1;
  unsigned CFGS:1;
  unsigned EEPGD:1;
} EECON1bits;
extern volatile near unsigned char       EECON2;
extern volatile near unsigned char       EEDATA;
extern volatile near unsigned char       EEADR;
extern volatile near struct {
  unsigned EEADR0:1;
  unsigned EEADR1:1;
  unsigned EEADR2:1;
  unsigned EEADR3:1;
  unsigned EEADR4:1;
  unsigned EEADR5:1;
  unsigned EEADR6:1;
  unsigned EEADR7:1;
} EEADRbits;
extern volatile near unsigned char       EEADRH;
extern volatile near struct {
  unsigned EEADR8:1;
  unsigned EEADR9:1;
} EEADRHbits;
extern volatile near unsigned char       RCSTA;
extern volatile near union {
  struct {
    unsigned RX9D:1;
    unsigned OERR:1;
    unsigned FERR:1;
    unsigned ADDEN:1;
    unsigned CREN:1;
    unsigned SREN:1;
    unsigned RX9:1;
    unsigned SPEN:1;
  };
  struct {
    unsigned :3;
    unsigned ADEN:1;
  };
} RCSTAbits;
extern volatile near unsigned char       TXSTA;
extern volatile near struct {
  unsigned TX9D:1;
  unsigned TRMT:1;
  unsigned BRGH:1;
  unsigned SENDB:1;
  unsigned SYNC:1;
  unsigned TXEN:1;
  unsigned TX9:1;
  unsigned CSRC:1;
} TXSTAbits;
extern volatile near unsigned char       TXREG;
extern volatile near unsigned char       RCREG;
extern volatile near unsigned char       SPBRG;
extern volatile near unsigned char       SPBRGH;
extern volatile near unsigned char       T3CON;
extern volatile near union {
  struct {
    unsigned TMR3ON:1;
    unsigned TMR3CS:1;
    unsigned NOT_T3SYNC:1;
    unsigned T3CCP1:1;
    unsigned T3CKPS:2;
    unsigned T3CCP2:1;
    unsigned RD16:1;
  };
  struct {
    unsigned :2;
    unsigned T3SYNC:1;
    unsigned :1;
    unsigned T3CKPS0:1;
    unsigned T3CKPS1:1;
  };
} T3CONbits;
extern volatile near unsigned char       TMR3L;
extern volatile near unsigned char       TMR3H;
extern volatile near unsigned char       CVRCON2;
extern volatile near struct {
  unsigned :6;
  unsigned FVRST:1;
  unsigned FVREN:1;
} CVRCON2bits;
extern volatile near unsigned char       CVRCON;
extern volatile near union {
  struct {
    unsigned CVR:4;
    unsigned CVRSS:1;
    unsigned CVRR:1;
    unsigned CVROE:1;
    unsigned CVREN:1;
  };
  struct {
    unsigned CVR0:1;
    unsigned CVR1:1;
    unsigned CVR2:1;
    unsigned CVR3:1;
  };
} CVRCONbits;
extern volatile near unsigned char       ECCP1AS;
extern volatile near union {
  struct {
    unsigned PSSBD:2;
    unsigned PSSAC:2;
    unsigned ECCPAS:3;
    unsigned ECCPASE:1;
  };
  struct {
    unsigned PSSBD0:1;
    unsigned PSSBD1:1;
    unsigned PSSAC0:1;
    unsigned PSSAC1:1;
    unsigned ECCPAS0:1;
    unsigned ECCPAS1:1;
    unsigned ECCPAS2:1;
  };
} ECCP1ASbits;
extern volatile near unsigned char       PWM1CON;
extern volatile near union {
  struct {
    unsigned PDC:7;
    unsigned PRSEN:1;
  };
  struct {
    unsigned PDC0:1;
    unsigned PDC1:1;
    unsigned PDC2:1;
    unsigned PDC3:1;
    unsigned PDC4:1;
    unsigned PDC5:1;
    unsigned PDC6:1;
  };
} PWM1CONbits;
extern volatile near unsigned char       BAUDCON;
extern volatile near union {
  struct {
    unsigned ABDEN:1;
    unsigned WUE:1;
    unsigned :1;
    unsigned BRG16:1;
    unsigned CKTXP:1;
    unsigned DTRXP:1;
    unsigned RCIDL:1;
    unsigned ABDOVF:1;
  };
  struct {
    unsigned :4;
    unsigned SCKP:1;
  };
} BAUDCONbits;
extern volatile near unsigned char       BAUDCTL;
extern volatile near union {
  struct {
    unsigned ABDEN:1;
    unsigned WUE:1;
    unsigned :1;
    unsigned BRG16:1;
    unsigned CKTXP:1;
    unsigned DTRXP:1;
    unsigned RCIDL:1;
    unsigned ABDOVF:1;
  };
  struct {
    unsigned :4;
    unsigned SCKP:1;
  };
} BAUDCTLbits;
extern volatile near unsigned char       PSTRCON;
extern volatile near struct {
  unsigned STRA:1;
  unsigned STRB:1;
  unsigned STRC:1;
  unsigned STRD:1;
  unsigned STRSYNC:1;
} PSTRCONbits;
extern volatile near unsigned char       CCP2CON;
extern volatile near union {
  struct {
    unsigned CCP2M:4;
    unsigned DC2B:2;
  };
  struct {
    unsigned CCP2M0:1;
    unsigned CCP2M1:1;
    unsigned CCP2M2:1;
    unsigned CCP2M3:1;
    unsigned DC2B0:1;
    unsigned DC2B1:1;
  };
} CCP2CONbits;
extern volatile near unsigned            CCPR2;
extern volatile near unsigned char       CCPR2L;
extern volatile near unsigned char       CCPR2H;
extern volatile near unsigned char       CCP1CON;
extern volatile near union {
  struct {
    unsigned CCP1M:4;
    unsigned DC1B:2;
    unsigned P1M:2;
  };
  struct {
    unsigned CCP1M0:1;
    unsigned CCP1M1:1;
    unsigned CCP1M2:1;
    unsigned CCP1M3:1;
    unsigned DC1B0:1;
    unsigned DC1B1:1;
    unsigned P1M0:1;
    unsigned P1M1:1;
  };
} CCP1CONbits;
extern volatile near unsigned            CCPR1;
extern volatile near unsigned char       CCPR1L;
extern volatile near unsigned char       CCPR1H;
extern volatile near unsigned char       ADCON2;
extern volatile near union {
  struct {
    unsigned ADCS:3;
    unsigned ACQT:3;
    unsigned :1;
    unsigned ADFM:1;
  };
  struct {
    unsigned ADCS0:1;
    unsigned ADCS1:1;
    unsigned ADCS2:1;
    unsigned ACQT0:1;
    unsigned ACQT1:1;
    unsigned ACQT2:1;
  };
} ADCON2bits;
extern volatile near unsigned char       ADCON1;
extern volatile near union {
  struct {
    unsigned :4;
    unsigned VCFG:2;
  };
  struct {
    unsigned :4;
    unsigned VCFG0:1;
    unsigned VCFG1:1;
  };
} ADCON1bits;
extern volatile near unsigned char       ADCON0;
extern volatile near union {
  struct {
    unsigned ADON:1;
    unsigned GO_NOT_DONE:1;
    unsigned CHS:4;
  };
  struct {
    unsigned :1;
    unsigned DONE:1;
    unsigned CHS0:1;
    unsigned CHS1:1;
    unsigned CHS2:1;
    unsigned CHS3:1;
  };
  struct {
    unsigned :1;
    unsigned NOT_DONE:1;
  };
  struct {
    unsigned :1;
    unsigned GO_DONE:1;
  };
  struct {
    unsigned :1;
    unsigned GO:1;
  };
} ADCON0bits;
extern volatile near unsigned            ADRES;
extern volatile near unsigned char       ADRESL;
extern volatile near unsigned char       ADRESH;
extern volatile near unsigned char       SSPCON2;
extern volatile near struct {
  unsigned SEN:1;
  unsigned RSEN:1;
  unsigned PEN:1;
  unsigned RCEN:1;
  unsigned ACKEN:1;
  unsigned ACKDT:1;
  unsigned ACKSTAT:1;
  unsigned GCEN:1;
} SSPCON2bits;
extern volatile near unsigned char       SSPCON1;
extern volatile near union {
  struct {
    unsigned SSPM:4;
    unsigned CKP:1;
    unsigned SSPEN:1;
    unsigned SSPOV:1;
    unsigned WCOL:1;
  };
  struct {
    unsigned SSPM0:1;
    unsigned SSPM1:1;
    unsigned SSPM2:1;
    unsigned SSPM3:1;
  };
} SSPCON1bits;
extern volatile near unsigned char       SSPSTAT;
extern volatile near union {
  struct {
    unsigned BF:1;
    unsigned UA:1;
    unsigned R_NOT_W:1;
    unsigned S:1;
    unsigned P:1;
    unsigned D_NOT_A:1;
    unsigned CKE:1;
    unsigned SMP:1;
  };
  struct {
    unsigned :2;
    unsigned R:1;
    unsigned :2;
    unsigned D:1;
  };
  struct {
    unsigned :2;
    unsigned W:1;
    unsigned :2;
    unsigned A:1;
  };
  struct {
    unsigned :2;
    unsigned NOT_W:1;
    unsigned :2;
    unsigned NOT_A:1;
  };
  struct {
    unsigned :2;
    unsigned R_W:1;
    unsigned :2;
    unsigned D_A:1;
  };
  struct {
    unsigned :2;
    unsigned NOT_WRITE:1;
    unsigned :2;
    unsigned NOT_ADDRESS:1;
  };
  struct {
    unsigned :3;
    unsigned START:1;
    unsigned STOP:1;
  };
} SSPSTATbits;
extern volatile near unsigned char       SSPADD;
extern volatile near unsigned char       SSPBUF;
extern volatile near unsigned char       T2CON;
extern volatile near union {
  struct {
    unsigned T2CKPS:2;
    unsigned TMR2ON:1;
    unsigned T2OUTPS:4;
  };
  struct {
    unsigned T2CKPS0:1;
    unsigned T2CKPS1:1;
    unsigned :1;
    unsigned T2OUTPS0:1;
    unsigned T2OUTPS1:1;
    unsigned T2OUTPS2:1;
    unsigned T2OUTPS3:1;
  };
} T2CONbits;
extern volatile near unsigned char       PR2;
extern volatile near unsigned char       TMR2;
extern volatile near unsigned char       T1CON;
extern volatile near union {
  struct {
    unsigned TMR1ON:1;
    unsigned TMR1CS:1;
    unsigned NOT_T1SYNC:1;
    unsigned T1OSCEN:1;
    unsigned T1CKPS:2;
    unsigned T1RUN:1;
    unsigned RD16:1;
  };
  struct {
    unsigned :2;
    unsigned T1SYNC:1;
    unsigned :1;
    unsigned T1CKPS0:1;
    unsigned T1CKPS1:1;
  };
} T1CONbits;
extern volatile near unsigned char       TMR1L;
extern volatile near unsigned char       TMR1H;
extern volatile near unsigned char       RCON;
extern volatile near union {
  struct {
    unsigned NOT_BOR:1;
    unsigned NOT_POR:1;
    unsigned NOT_PD:1;
    unsigned NOT_TO:1;
    unsigned NOT_RI:1;
    unsigned :1;
    unsigned SBOREN:1;
    unsigned IPEN:1;
  };
  struct {
    unsigned BOR:1;
    unsigned POR:1;
    unsigned PD:1;
    unsigned TO:1;
    unsigned RI:1;
  };
} RCONbits;
extern volatile near unsigned char       WDTCON;
extern volatile near union {
  struct {
    unsigned SWDTEN:1;
  };
  struct {
    unsigned SWDTE:1;
  };
} WDTCONbits;
extern volatile near unsigned char       HLVDCON;
extern volatile near union {
  struct {
    unsigned HLVDL:4;
    unsigned HLVDEN:1;
    unsigned IRVST:1;
    unsigned :1;
    unsigned VDIRMAG:1;
  };
  struct {
    unsigned HLVDL0:1;
    unsigned HLVDL1:1;
    unsigned HLVDL2:1;
    unsigned HLVDL3:1;
  };
  struct {
    unsigned LVDL0:1;
    unsigned LVDL1:1;
    unsigned LVDL2:1;
    unsigned LVDL3:1;
    unsigned LVDEN:1;
    unsigned IVRST:1;
  };
  struct {
    unsigned LVV0:1;
    unsigned LVV1:1;
    unsigned LVV2:1;
    unsigned LVV3:1;
    unsigned :1;
    unsigned BGST:1;
  };
} HLVDCONbits;
extern volatile near unsigned char       LVDCON;
extern volatile near union {
  struct {
    unsigned HLVDL:4;
    unsigned HLVDEN:1;
    unsigned IRVST:1;
    unsigned :1;
    unsigned VDIRMAG:1;
  };
  struct {
    unsigned HLVDL0:1;
    unsigned HLVDL1:1;
    unsigned HLVDL2:1;
    unsigned HLVDL3:1;
  };
  struct {
    unsigned LVDL0:1;
    unsigned LVDL1:1;
    unsigned LVDL2:1;
    unsigned LVDL3:1;
    unsigned LVDEN:1;
    unsigned IVRST:1;
  };
  struct {
    unsigned LVV0:1;
    unsigned LVV1:1;
    unsigned LVV2:1;
    unsigned LVV3:1;
    unsigned :1;
    unsigned BGST:1;
  };
} LVDCONbits;
extern volatile near unsigned char       OSCCON;
extern volatile near union {
  struct {
    unsigned SCS:2;
    unsigned IOFS:1;
    unsigned OSTS:1;
    unsigned IRCF:3;
    unsigned IDLEN:1;
  };
  struct {
    unsigned SCS0:1;
    unsigned SCS1:1;
    unsigned :2;
    unsigned IRCF0:1;
    unsigned IRCF1:1;
    unsigned IRCF2:1;
  };
} OSCCONbits;
extern volatile near unsigned char       T0CON;
extern volatile near union {
  struct {
    unsigned T0PS:3;
    unsigned PSA:1;
    unsigned T0SE:1;
    unsigned T0CS:1;
    unsigned T08BIT:1;
    unsigned TMR0ON:1;
  };
  struct {
    unsigned T0PS0:1;
    unsigned T0PS1:1;
    unsigned T0PS2:1;
  };
} T0CONbits;
extern volatile near unsigned char       TMR0L;
extern volatile near unsigned char       TMR0H;
extern          near unsigned char       STATUS;
extern          near struct {
  unsigned C:1;
  unsigned DC:1;
  unsigned Z:1;
  unsigned OV:1;
  unsigned N:1;
} STATUSbits;
extern          near unsigned            FSR2;
extern          near unsigned char       FSR2L;
extern          near unsigned char       FSR2H;
extern volatile near unsigned char       PLUSW2;
extern volatile near unsigned char       PREINC2;
extern volatile near unsigned char       POSTDEC2;
extern volatile near unsigned char       POSTINC2;
extern          near unsigned char       INDF2;
extern          near unsigned char       BSR;
extern          near unsigned            FSR1;
extern          near unsigned char       FSR1L;
extern          near unsigned char       FSR1H;
extern volatile near unsigned char       PLUSW1;
extern volatile near unsigned char       PREINC1;
extern volatile near unsigned char       POSTDEC1;
extern volatile near unsigned char       POSTINC1;
extern          near unsigned char       INDF1;
extern          near unsigned char       W;
extern          near unsigned char       WREG;
extern          near unsigned            FSR0;
extern          near unsigned char       FSR0L;
extern          near unsigned char       FSR0H;
extern volatile near unsigned char       PLUSW0;
extern volatile near unsigned char       PREINC0;
extern volatile near unsigned char       POSTDEC0;
extern volatile near unsigned char       POSTINC0;
extern          near unsigned char       INDF0;
extern volatile near unsigned char       INTCON3;
extern volatile near union {
  struct {
    unsigned INT1IF:1;
    unsigned INT2IF:1;
    unsigned :1;
    unsigned INT1IE:1;
    unsigned INT2IE:1;
    unsigned :1;
    unsigned INT1IP:1;
    unsigned INT2IP:1;
  };
  struct {
    unsigned INT1F:1;
    unsigned INT2F:1;
    unsigned :1;
    unsigned INT1E:1;
    unsigned INT2E:1;
    unsigned :1;
    unsigned INT1P:1;
    unsigned INT2P:1;
  };
} INTCON3bits;
extern volatile near unsigned char       INTCON2;
extern volatile near union {
  struct {
    unsigned RBIP:1;
    unsigned :1;
    unsigned TMR0IP:1;
    unsigned :1;
    unsigned INTEDG2:1;
    unsigned INTEDG1:1;
    unsigned INTEDG0:1;
    unsigned NOT_RBPU:1;
  };
  struct {
    unsigned :7;
    unsigned RBPU:1;
  };
} INTCON2bits;
extern volatile near unsigned char       INTCON;
extern volatile near union {
  struct {
    unsigned RBIF:1;
    unsigned INT0IF:1;
    unsigned TMR0IF:1;
    unsigned RBIE:1;
    unsigned INT0IE:1;
    unsigned TMR0IE:1;
    unsigned PEIE_GIEL:1;
    unsigned GIE_GIEH:1;
  };
  struct {
    unsigned :1;
    unsigned INT0F:1;
    unsigned T0IF:1;
    unsigned :1;
    unsigned INT0E:1;
    unsigned T0IE:1;
    unsigned PEIE:1;
    unsigned GIE:1;
  };
  struct {
    unsigned :6;
    unsigned GIEL:1;
    unsigned GIEH:1;
  };
} INTCONbits;
extern          near unsigned            PROD;
extern          near unsigned char       PRODL;
extern          near unsigned char       PRODH;
extern volatile near unsigned char       TABLAT;
extern volatile near unsigned short long TBLPTR;
extern volatile near unsigned char       TBLPTRL;
extern volatile near unsigned char       TBLPTRH;
extern volatile near unsigned char       TBLPTRU;
extern volatile near unsigned short long PC;
extern volatile near unsigned char       PCL;
extern volatile near unsigned char       PCLATH;
extern volatile near unsigned char       PCLATU;
extern volatile near unsigned char       STKPTR;
extern volatile near union {
  struct {
    unsigned STKPTR:5;
    unsigned :1;
    unsigned STKUNF:1;
    unsigned STKFUL:1;
  };
  struct {
    unsigned SP0:1;
    unsigned SP1:1;
    unsigned SP2:1;
    unsigned SP3:1;
    unsigned SP4:1;
    unsigned :2;
    unsigned STKOVF:1;
  };
} STKPTRbits;
extern          near unsigned short long TOS;
extern          near unsigned char       TOSL;
extern          near unsigned char       TOSH;
extern          near unsigned char       TOSU;



#line 1227 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
 
#line 1229 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1230 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"


#line 1233 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
 
#line 1235 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1236 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1237 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1238 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"

#line 1240 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1241 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1242 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1243 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1244 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"


#line 1248 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
 
#line 1250 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"


#line 1253 "C:/Program Files (x86)/Microchip/mplabc18/v3.46/h/p18f26k20.h"
#line 1 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"

#line 1 "F:\MotorizedHeadP18F26K20.X/lcd.h"

#line 19 "F:\MotorizedHeadP18F26K20.X/lcd.h"
 




#line 25 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 1 "F:\MotorizedHeadP18F26K20.X/myutils.h"

#line 3 "F:\MotorizedHeadP18F26K20.X/myutils.h"

#line 5 "F:\MotorizedHeadP18F26K20.X/myutils.h"
#line 6 "F:\MotorizedHeadP18F26K20.X/myutils.h"
#line 7 "F:\MotorizedHeadP18F26K20.X/myutils.h"
#line 8 "F:\MotorizedHeadP18F26K20.X/myutils.h"

#line 10 "F:\MotorizedHeadP18F26K20.X/myutils.h"
#line 25 "F:\MotorizedHeadP18F26K20.X/lcd.h"




#line 30 "F:\MotorizedHeadP18F26K20.X/lcd.h"

typedef unsigned char uint8_t;

 


#line 37 "F:\MotorizedHeadP18F26K20.X/lcd.h"
 

#line 40 "F:\MotorizedHeadP18F26K20.X/lcd.h"

#line 42 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 43 "F:\MotorizedHeadP18F26K20.X/lcd.h"

#line 45 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 46 "F:\MotorizedHeadP18F26K20.X/lcd.h"

#line 48 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 49 "F:\MotorizedHeadP18F26K20.X/lcd.h"




#line 54 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 55 "F:\MotorizedHeadP18F26K20.X/lcd.h"




#line 60 "F:\MotorizedHeadP18F26K20.X/lcd.h"
 



void LCDInit(uint8_t style);
void LCDWriteString(const char *msg);
void LCDWriteInt(int val,unsigned int field_length);
void LCDGotoXY(uint8_t x,uint8_t y);


void LCDByte(uint8_t,uint8_t);
#line 72 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 73 "F:\MotorizedHeadP18F26K20.X/lcd.h"

void LCDBusyLoop();




#line 80 "F:\MotorizedHeadP18F26K20.X/lcd.h"
 



#line 85 "F:\MotorizedHeadP18F26K20.X/lcd.h"
 
#line 87 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 88 "F:\MotorizedHeadP18F26K20.X/lcd.h"


#line 92 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 93 "F:\MotorizedHeadP18F26K20.X/lcd.h"


#line 97 "F:\MotorizedHeadP18F26K20.X/lcd.h"
#line 98 "F:\MotorizedHeadP18F26K20.X/lcd.h"
 




 
#line 105 "F:\MotorizedHeadP18F26K20.X/lcd.h"




#line 2 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"













#pragma config FOSC = INTIO67   
#pragma config FCMEN = OFF      
#pragma config IESO = OFF       


#pragma config PWRT = OFF       
#pragma config BOREN = SBORDIS  
#pragma config BORV = 18        


#pragma config WDTEN = OFF      
#pragma config WDTPS = 32768    


#pragma config CCP2MX = PORTC   
#pragma config PBADEN = OFF     
#pragma config LPT1OSC = OFF    
#pragma config HFOFST = OFF     
#pragma config MCLRE = OFF      


#pragma config STVREN = ON      
#pragma config LVP = OFF        
#pragma config XINST = OFF      


#pragma config CP0 = OFF        
#pragma config CP1 = OFF        
#pragma config CP2 = OFF        
#pragma config CP3 = OFF        


#pragma config CPB = OFF        
#pragma config CPD = OFF        


#pragma config WRT0 = OFF       
#pragma config WRT1 = OFF       
#pragma config WRT2 = OFF       
#pragma config WRT3 = OFF       


#pragma config WRTC = OFF       
#pragma config WRTB = OFF       
#pragma config WRTD = OFF       


#pragma config EBTR0 = OFF      
#pragma config EBTR1 = OFF      
#pragma config EBTR2 = OFF      
#pragma config EBTR3 = OFF      


#pragma config EBTRB = OFF      

#line 71 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 72 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 73 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 74 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"

#line 76 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 77 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 78 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"

#line 80 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 81 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"

 
void Wait(unsigned int delay)
{
	for(;delay;delay--)
		__delay_us(100);
}


#line 91 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 92 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
#line 93 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"

char key, is_key_pressed = 0;
unsigned int roll_param = 0;
unsigned int spin_times = 0;
unsigned int VITRI = 68 ;


void PWM_config(void);
void config(void);
unsigned int CharToNumber(char param_char);
char NumberToChar(unsigned int param);
void playing(void);
void SetDCPWM2(unsigned int dutycycle);

void main()
{

    OSCCONbits.IRCF2=0;
    OSCCONbits.IRCF1=1;
    OSCCONbits.IRCF0=1;
    
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;
    LATAbits.LATA4 = 1;
    LATAbits.LATA5 = 1;

    
    TRISB  = 0x0f;
    LATB   = 0x00;

    INTCON2bits.RBPU = 0;
    WPUB = 0x0f;

   
    
	Wait(100);

	
	LCDInit(0B00000001 );

	
	(LCDByte(0b00000001,0))  ;
	
	
	LCDWriteString("Motorized ready!");
        LCDGotoXY(0,1);
        LCDWriteString("Setup");
        

        while(1)
        {
            
                 config();
        };


}

#line 157 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
 
unsigned int CharToNumber(char param_char)
{
    unsigned int number;
    if (param_char == '0') number = 0;
    if (param_char == '1') number = 1;
    if (param_char == '2') number = 2;
    if (param_char == '3') number = 3;
    if (param_char == '4') number = 4;
    if (param_char == '5') number = 5;
    if (param_char == '6') number = 6;
    if (param_char == '7') number = 7;
    if (param_char == '8') number = 8;
    if (param_char == '9') number = 9;
    return number;
}

#line 180 "F:\MotorizedHeadP18F26K20.X\MotorizedHead.c"
 
char NumberToChar(unsigned int param)
{
    char character;
    if (param == 0) character = '0';
    if (param == 1) character = '1';
    if (param == 2) character = '2';
    if (param == 3) character = '3';
    if (param == 4) character = '4';
    if (param == 5) character = '5';
    if (param == 6) character = '6';
    if (param == 7) character = '7';
    if (param == 8) character = '8';
    if (param == 9) character = '9';
    return character;
}
void config(void)
{
    if (PORTBbits.RB1 == 0)
            {
                __delay_us(10000);
                if (PORTBbits.RB1 == 0)
                {
                    (LCDByte(0b00000001,0))  ;
                    LCDWriteString("Setting");
                    LCDGotoXY(0,1);
                    LCDWriteString("Spin times N:");
                    while (PORTBbits.RB2 == 1)
                        {
                            if (PORTBbits.RB0 == 0)
                            {
                                __delay_us(10000);
                                if (PORTBbits.RB0 == 0)
                                {
                                    LCDGotoXY(13,1);
                                    spin_times++;
                                    (LCDByte(NumberToChar(spin_times),1)) ;
                                }
                            }
                            if (PORTBbits.RB3 == 0)
                            {
                                __delay_us(10000);
                                if (PORTBbits.RB3 == 0)
                                {
                                    LCDGotoXY(13,1);
                                    spin_times--;
                                    (LCDByte(NumberToChar(spin_times),1)) ;
                                }
                            }

                        }
                    (LCDByte(0b00000001,0))  ;
                    LCDWriteString("Setting done!");
                    LCDGotoXY(0,1);
                    LCDWriteString("N=");
                    (LCDByte(NumberToChar(spin_times),1)) ;
                    LCDGotoXY(11,1);
                    LCDWriteString("Start");
               }
            }
}
void playing(void)
{
    
}
void PWM_config(void)
{
    CCP2CONbits.CCP2M = 0b1100;
    RCONbits.IPEN = 1; 
    IPR1bits.RCIP = 1;
    INTCONbits.GIEH = 1;
    T2CON = 0x7e;
    PR2 = 0xff;
}
void SetDCPWM2(unsigned int dutycycle)
{
  union PWMDC DCycle;

  
  DCycle.lpwm = dutycycle << 6;

  
  CCPR2L = DCycle.bpwm[1];

  
  CCP2CON = (CCP2CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
}
