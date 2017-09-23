#ifndef __OTHERS_H__
#define __OTHERS_H__

#include "config.h"


#define photo_buf_size 8000

extern uint8 photo_buf[photo_buf_size];    //����ͼ�񻺳���,�Ѿ��㹻����

void set_photo_len(uint8 length1, uint8 length2);
uint8 send_compress_rate(void);
uint8 send_start_photo(void);
uint8 send_read_len(void);
uint32 send_get_photo(uint8 *buf);
uint8 send_reset(void);
uint8 send_stop_photo(void);
uint8 send_zoom_size(void);
uint8 send_photo_size(void);
uint8 photo_init(void);
uint32 take_photo(uint8 *buf);
uint8 reset_photo(void);
uint8 send_save_power(void);


void uart_init0 (uint32 uart_bps);
uint32 uart0_getbuf(uint8 *buf, uint32 n);
void uart0_sendbuf(uint8 const *buf, uint32 n);






void gpio_init(void);
void eint0_init(void);
void beep_one(void);
void beep(uint32 times);
void camera_power_on(void);
void camera_power_off(void);
void led_on(void);
void led_off(void);
void led_photo(void);
void photo_fatal_error(void);
void handle_success(void);   //����ɹ�����


void delay(uint32 dly);

void int_led_on(void);
void wait_led_on(void);

void __irq IRQ_Eint0(void);	

/* for PTB203������ */

#define 	BEEP  	1 << 21			        /* P0.21���Ʒ����� */
#define     CAMERA_POWER_CONTROL  1 << 15               /*  P0.15��������ͷ��Դ���� */
#define     LED     1 << 17 | 1 << 18 | 1 << 19         /* P1.17��P1.18��P1.19 ��������ָʾ�� */
#define		LED_WAIT   1 << 18               /* P1.18���ƴ���״ָ̬ʾ�� */
#define     LED_PHOTO  1 << 19               /* P1.19��������ͷ״ָ̬ʾ�� */
#define		LED_INT   1 << 17 | 1 <<19       /* P1.17��P1.19 �����ж�״ָ̬ʾ�� */



#endif