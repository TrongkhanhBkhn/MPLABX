/***********************************
�������ļ�
***********************************/
#include <string.h>
#include <stdio.h>
#include "config.h"  
#include "global.h"

uint32 photo_len = 0;   //ͼ��ĳ���
uint8 photo_buf[photo_buf_size];    //����ͼ�񻺳���,

/*
*********************************************************************************************************
** �������� ��main()
** �������� ��������һ�����Գ���,������ͷ���ӵ�����1,�Ѵ���0���ӵ�PC��,�򿪴��ڵ�������
**            �Ӵ��ڵ��Ժ��ַ����ַ�o,����k���ʾ����ɹ�
** ����˵�� ��
*********************************************************************************************************
*/

int main (void)
{
	
	//���ڳ�ʼ��,�����ʼ���˴���0�ʹ���1,����1������ͷ��
	uart_init0 (38400);
	gpio_init();    //gpio��ʼ��
  //����ͷ��ʼ��
	if (!photo_init()) 
	{
		photo_fatal_error();  //��ʼ��ʧ�ܣ�һֱ�죬һ������,����û��������ͷ
	} 
	camera_power_off(); 	
	handle_success();  //��һ����������ͷ��ʼ���ɹ� 
	led_photo();
	delay(100);
	led_off();
		 	
   	//�жϳ�ʼ��,�����ﻹû�п��жϵģ���Ϊֻ�г����û����ܿ��ж�
	eint0_init();
	IRQEnable();
	   	
   	while(1)
   	{
     wait_led_on();

    }//end while
}

///////////////////////////////////////////����Ϊ�����ܺ�������///////////////////////////////////////
//��λ����
uint8 reset_cmd[] = 
{
	0x56,
	0x00,
	0x26,
	0x00
};

//��λ��������
uint8 reset_rcv [] =
{ 
	0x76,
	0x00,
	0x26,
	0x00
};

//��ʼ��������
uint8 start_photo_cmd [] =
{
	0x56,
	0x00,
	0x36,
	0x01,
	0x00
};

//��ʼ���շ�������
uint8 start_photo_rcv [] =
{
	0x76,
	0x00,
	0x36,
	0x00,
	0x00
};

//����������
uint8 read_len_cmd [] = 
{
	0x56,
	0x00,
	0x34,
	0x01,
	0x00
};
//�����ȷ��������ǰ�߸��ֽ�,��������ĺ������ֽ�Ϊͼ�񳤶�
uint8 read_len_rcv [] =
{
	0x76,
	0x00,
	0x34,
	0x00,
	0x04,
	0x00,
	0x00
};

//ȡͼ������,Ҳ���Ƕ�������
uint8 get_photo_cmd [] =
{
	0x56,
	0x00,
	0x32, 
	0x0C, 
	0x00, 
	0x0A,
	 
	0x00, 
	0x00, 
	0x00, 
	0x00,
	
	0x00, 
	0x00,
	0x00, 
	0x00,
	
	0x00,
	0xFF              //���ʱ����Ҫע��,Ӧ�����һ��,��������Сһ��,��Сһ��Ļ���������̫������׳��ֽ��մ���

};
uint8 get_photo_rcv [] =
{
	0x76,
	0x00,
	0x32,
	0x00,
	0x00
};


//����ѹ��������,������Ϊ0x80 : 1,����ʹͼ��С
uint8 set_compress_cmd [] =
{
	0x56,
	0x00, 
	0x31, 
	0x05,  
	0x01, 
	0x01, 
	0x12,
	0x04,  
	0x80
};

uint8 compress_rate_rcv [] = 
{
	0x76,
	0x00,
	0x31,
	0x00,
	0x00
};

//ֹͣ��������,���ķ��������뿪ʼ���յ���ͬ
uint8 stop_photo_cmd [] =
{
	0x56,
	0x00,
	0x36,
	0x01,
	0x03
};
//ֹͣ���շ�������,����ʼ���յ�һ��
uint8 stop_photo_rcv [] =
{
	0x76,
	0x00,
	0x36,
	0x00,
	0x00
};

uint8 zoom_size_cmd [] =
{
	0x56,
	0x00, 
	0x54, 
	0x01,  
	0x11, 
	0x00
};   

uint8 zoom_size_rcv [] =
{
	0x76,
	0x00, 
	0x54, 
	0x00,  
	0x00, 
};



//����ͼ���С����

uint8 photo_size_cmd [] =
{
	0x56,
	0x00, 
	0x31, 
	0x05,  
	0x04, 
	0x01, 
	0x00, 
	0x19,
	0x11,
	0x00
};

uint8 photo_size_rcv [] =
{
	0x76, 
	0x00, 
	0x31, 
	0x00, 
	0x00
};
uint8 save_power_cmd [] =
{
	0x56, 
	0x00, 
	0x3E, 
	0x03, 
	0x00, 
	0x01, 
	0x00
};
uint8 save_power_rcv [] =
{
	0x76, 
	0x00, 
	0x3E, 
	0x00, 
	0x00
};
uint8 set_bps_cmd [] = 
{
	0x56,
	0x00, 
	0x24, 
	0x03, 
	0x01, 
	0x0D,
	0xA6	
};
uint8 set_bps_rcv [] = 
{
	0x76, 
	0x00, 
	0x24, 
	0x00, 
	0x00
};

uint32 uart0_getbuf(uint8 *buf, uint32 n)
{
	uint32 count = 0, i = 0;
	for (i = 0; i < n; i++)
	{
		count = 0;
		while ((U0LSR & 0x01) == 0) 
		{
			count++;
			if (count > 10000 * 100) return 0;      //���countֻ��Ϊ�˷�ֹ��ѭ��
		}
		buf[i] = U0RBR;
	}	
	return n;
}

uint8 send_zoom_size(void)
{
uint32 i;//, count;
	uint8 tmp[5];
	
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	
	uart0_sendbuf(zoom_size_cmd, 6);
	
	
	if (!uart0_getbuf(tmp, 5)) return 0;
	
	//��������
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != zoom_size_rcv[i]) return 0;
	}

	return 1;


}

//��������ͼ���С����,�˺������Բ�Ҫ
uint8 send_photo_size(void)
{
	uint32 i;//, count;
	uint8 tmp[5];
	
	//���״̬�Ĵ��������־��Ϊ1,��Ҫ��������,���򻺳����ᶪ����һ������������
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	
	uart0_sendbuf(photo_size_cmd, 10);
	
	
	if (!uart0_getbuf(tmp, 5)) return 0;
	
	//��������
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != photo_size_rcv[i]) return 0;
	}

	return 1;
}

//����ֹͣ���պ���
uint8 send_stop_photo(void)
{
	uint32 i;//, count;
	uint8 tmp[5];
	
	//���һ���������ͽ��ջ�������������־,
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	
	//����ֹͣ��������,��ʵ������ջ�����,������ʲôֹͣ����
	uart0_sendbuf(stop_photo_cmd, 5);
	if (!uart0_getbuf(tmp, 5)) return 0;
	
	//��������
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != stop_photo_rcv[i]) return 0;
	}
	return 1;
}


//���͸�λ�����
uint8 send_reset(void)
{
	uint8 data, tmp[4];
	uint32 i;//, count;
	
	U0LSR = U0LSR & (~0x02); 
	data = U0RBR;
	uart0_sendbuf(reset_cmd, 4);
	if (!uart0_getbuf(tmp, 4)) return 0;
	
	for (i = 0; i < 4; i++)
		if (tmp[i] != reset_rcv[i]) return 0;
	
	delay(300);  //��λ����ʱ,��Ϊֻ������֡ͷ,���������Ҫ����
	//���һ�������־
	U0LSR = U0LSR & (~0x02); 
	data = U0RBR;
	
	return 1;
}

//��ͼ�����ݺ���������ͼ�����ݵĴ�С(���ֽ�Ϊ��λ),��ʧ���򷵻�0
uint32 send_get_photo(uint8 *buf) 
{
	uint32 i;//, count;
	if (photo_len > 8000) return 0;  //ͼ������̫��
	
	U0LSR = U0LSR & (~0x02); 
	buf[0] = U0RBR;
	
	//���Ͷ�������
	uart0_sendbuf(get_photo_cmd, 16);
	if (!uart0_getbuf(buf, 10 + photo_len)) return 0;
	//����֡ͷ
	for (i = 0; i < 5; i++)
	{
		if (buf[i] != get_photo_rcv[i]) return 0;
	}
	//����֡β
	for (i = 0; i < 5; i++)
	{
		if (buf[i + 5 + photo_len] != get_photo_rcv[i]) return 0;
	}
	//����ͼ��ĺϷ���,��0xFF,0xD8��ʼ,0xFF,0xD9����
	if (buf[5] != 0xFF || buf[6] != 0xD8 ||
		buf[3 + photo_len] != 0xFF || buf[4 + photo_len] != 0xD9)
	{
		return 0;
	}
	//��ͼ�������ƶ�������0��ʼ��
	for (i = 0; i < photo_len; i++)
		buf[i] = buf[i + 5];
	return photo_len;	//����ͼ�񳤶�
}

//����ʱ����
void delay1(uint32 n)
{
	while (n--);
}
//�����Ⱥ���
uint8 send_read_len(void)
{
	uint32 i;//, count;
	uint8 tmp[9];
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	//���Ͷ���������
	uart0_sendbuf(read_len_cmd, 5);
	if (!uart0_getbuf(tmp, 9)) return 0;
	//��������
	for (i = 0; i < 7; i++)
	{
		if (tmp[i] != read_len_rcv[i]) return 0;
	}
	
	set_photo_len(tmp[7], tmp[8]);  //���ö���������
	return 1;
}

void set_photo_len(uint8 length1, uint8 length2)
{

	get_photo_cmd[12] = length1;
	get_photo_cmd[13] = length2;
	photo_len = length1 * 0x100 + length2;
}
//����ѹ���ʺ���
uint8 send_compress_rate(void)
{
	uint32 i;//, count;
	uint8 tmp[5];
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	//����ѹ����Ϊ80:1
	uart0_sendbuf(set_compress_cmd, 9);
	if (!uart0_getbuf(tmp, 5)) return 0;
	//��������
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != compress_rate_rcv[i]) return 0;
	}
	return 1;
}

uint8 send_start_photo(void)
{	
	uint32 i;//, count;
	uint8 tmp[5];
	
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR; 
	//������ͷ������������
	uart0_sendbuf(start_photo_cmd, 5);
	if (!uart0_getbuf(tmp, 5)) return 0;
	//��������
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != start_photo_rcv[i]) return 0;
	}
	
	return 1;
}

//���ճ�ʼ������
uint8 photo_init(void)
{
	camera_power_on();
	delay(500);    //���ϵ縴λ��Ҫ��2.5������ͷ���ܽ�������
	if (!send_zoom_size()) goto error_exit;
	if (!send_photo_size()) goto error_exit;   //����ͼ���СΪ320x240
	if (!send_stop_photo()) goto error_exit;  //�������ͷ������	
	if (!send_compress_rate()) goto error_exit;    //����ѹ����Ϊ0x80:1
	delay(10);   //����Ҫע��,����ѹ���ʺ�Ҫ��ʱ
	return 1;
error_exit:
  
    return 0;
}

uint8 reset_photo(void)
{
	if (!send_reset()) goto error_exit;	       //����ͼ���С��Ҫ����
	return 1;
error_exit:
	return 0;
}

uint8 send_save_power(void)
{
	uint32 i;//, count;
	uint8 tmp[5];
	
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR; 
	
	//������ͷ�����˳�ʡ������
	uart0_sendbuf(save_power_cmd, 7);

	if (!uart0_getbuf(tmp, 5)) return 0;
	
	//��������
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != save_power_rcv[i]) return 0;
	}
	
	return 1;	
}

//���պ���,�����ĸ�����
uint32 take_photo(uint8 *buf)
{
	uint32 len;
   
	if(!photo_init()) goto error_exit;
	if (!send_start_photo()) goto error_exit;  //�Ϳ�ʼ��������
	if (!send_read_len()) goto error_exit;   //������
		
	len = send_get_photo(buf);		//����
	if (len == 0)  goto error_exit;

	if (!send_stop_photo()) goto error_exit;  //ֹͣ����,��ջ�����
	
	camera_power_off();
	return len;
	
error_exit:

    camera_power_off();
  	return 0;
}


//gpio��ʼ������
void gpio_init(void)
{
		
	IO0DIR = IO0DIR |BEEP|CAMERA_POWER_CONTROL;		// ���ÿ��ƿ�Ϊ������������롣					
	IO0CLR = IO0CLR |BEEP;                              //����͵�ƽ	
	IO0CLR = IO0CLR |CAMERA_POWER_CONTROL;              //����͵�ƽ	
	 led_on();
	  beep(1000);
	 led_off();
	
}

//�жϳ�ʼ������
void eint0_init()
{
	PINSEL1 = PINSEL1 | 0x01;			// ���ùܽ����ӣ�P0.16ΪEINT0	
	EXTMODE = 0x01;					//����EINT0Ϊ�½��ش�����	
						
	// ��EINT0�ж�(ʹ�������ж�)
	VICIntSelect   = 0x00000000;	// ���������жϷ���ΪIRQ�ж�		
	VICVectCntl0   = 0x20 | 0x0e;	// �����ⲿ�ж�0�������ж�0		
	VICVectAddr0   = (uint32)IRQ_Eint0;//* �����жϷ�������ַ					
	EXTINT         = 0x01;			// ���EINT0�жϱ�־					
	VICIntEnable   = 1 << 0x0e;		// ʹ��EINT0�ж�,д��0����Ч��		
}


//����������һ�κ���
void beep_one()
{
	uint32 time = 0;
	IO0SET =IO0SET|BEEP;  
	time = 2000;
	while(time--);
	IO0CLR =IO0CLR|BEEP; 			
	time = 2000;
	while(time--);
}


//���������庯��,�����ɲ���times����,���timesΪ0,��һֱ����,ֱ����λΪֹ
void beep(uint32 times)
{
	if (times == 0) 
	{
		while (1) beep_one();
	}
	else
	{
		while (times--) beep_one();
	}
}

//����ͷ��Դ��
void camera_power_on()
{
	IO0SET = IO0SET |CAMERA_POWER_CONTROL;              //����ߵ�ƽ	
}

//����ͷ��Դ�ر�
void camera_power_off()
{
	IO0CLR = IO0CLR |CAMERA_POWER_CONTROL;              //����͵�ƽ
}

//����led�Ƶ�������
void led_on()
{
	IO1CLR = IO1CLR | LED;
}

//Ϩ����
void led_off()
{
	IO1SET = IO1SET | LED;
}

void int_led_on(void)
{
	IO1SET = IO1SET|LED;
	IO1CLR = IO1CLR|LED_INT;
}
void wait_led_on(void)
{
	IO1SET = IO1SET|LED;
	IO1CLR = IO1CLR|LED_WAIT;
}


void led_photo(void)
{
	IO1SET = IO1SET|LED;
	IO1CLR = IO1CLR|LED_PHOTO;
}


//����������
void photo_fatal_error(void)
{
	led_photo();
	beep(0);
}

//����ɹ���������Ҫ����һ�ζ���
void handle_success(void)
{
	beep(1000);
	delay(50);
}

//�����жϺ���
void __irq IRQ_Eint0(void)
{
  uint8  fail_count = 0;
  uint32  len=0;	//ͼƬ����
  
  	
    IRQDisable();   //�ȹر��жϣ���ֹ����Ƕ�׺������ж�Ӱ��
	int_led_on();
    photo_buf[0] = 0;
    
     
    while ((len = take_photo(photo_buf)) == 0)
    {         
    	fail_count++;
   		if (fail_count == 3)
		 {
		   photo_fatal_error();
		 }
	}//while	
  
   handle_success();
  	
	EXTINT = 0x01;      		//����жϱ�־
	VICVectAddr = 0;			// �����ж�������ַ�Ĵ���	
		
	wait_led_on();	
	IRQEnable();   //���¿����ж�
		
}

/*
*********************************************************************************************************
** �������� ��uart0_sendbuf()
** �������� ���򴮿ڷ���һ�ַ���
** ��ڲ��� ��str	Ҫ���͵��ַ�����ָ��
** ���ڲ��� ����
*********************************************************************************************************/

void uart0_sendbuf(uint8 const *buf, uint32 n)
{
	int i;
	for (i = 0; i < n; i++)  
	  {
	   U0THR = buf[i];
	   while ((U0LSR & 0x40) == 0);		/* �ȴ����ݷ������			*/
	  }
}

/*
*********************************************************************************************************
** �������� ��delay()
** �������� ���������ʱ��
** ��ڲ��� ��dly	��ʱ������ֵԽ����ʱԽ��
** ���ڲ��� ����
*********************************************************************************************************
*/
void delay(uint32 dly)
{
	uint32 i, j;
	
	for (i = 0; i < dly; i++)
		for (j=0; j<50000; j++);
}

/*
*********************************************************************************************************
** �������� ��uart_init()
** �������� �����ڳ�ʼ��������Ϊ8λ����λ��1λֹͣλ������żУ��
** ��ڲ��� ����
** ���ڲ��� ����
*********************************************************************************************************
*/
void uart_init0 (uint32 uart_bps)
{
	uint16 Fdiv;
    
    	
	//����0��������Ϊ38400
	U0LCR = 0x83;						// DLAB=1,�������ò�����
	Fdiv  = (Fpclk / 16) / uart_bps;	// ���ò�����
	U0DLM = Fdiv / 256;
	U0DLL = Fdiv % 256;
	U0LCR = 0x03;      //3��ʾ�����ַ�����Ϊ8
	
}






