/***********************************
主函数文件
***********************************/
#include <string.h>
#include <stdio.h>
#include "config.h"  
#include "global.h"

uint32 photo_len = 0;   //图像的长度
uint8 photo_buf[photo_buf_size];    //声明图像缓冲区,

/*
*********************************************************************************************************
** 函数名称 ：main()
** 函数功能 ：下面是一个测试程序,把摄像头连接到串口1,把串口0连接到PC机,打开串口调试助手
**            从串口调试后手发送字符o,返回k则表示照相成功
** 调试说明 ：
*********************************************************************************************************
*/

int main (void)
{
	
	//串口初始化,这里初始化了串口0和串口1,串口1是摄像头的
	uart_init0 (38400);
	gpio_init();    //gpio初始化
  //摄像头初始化
	if (!photo_init()) 
	{
		photo_fatal_error();  //初始化失败，一直响，一个灯亮,可能没接上摄像头
	} 
	camera_power_off(); 	
	handle_success();  //响一声代表摄像头初始化成功 
	led_photo();
	delay(100);
	led_off();
		 	
   	//中断初始化,到这里还没有开中断的，因为只有超级用户才能开中断
	eint0_init();
	IRQEnable();
	   	
   	while(1)
   	{
     wait_led_on();

    }//end while
}

///////////////////////////////////////////以下为各功能函数定义///////////////////////////////////////
//复位命令
uint8 reset_cmd[] = 
{
	0x56,
	0x00,
	0x26,
	0x00
};

//复位返回命令
uint8 reset_rcv [] =
{ 
	0x76,
	0x00,
	0x26,
	0x00
};

//开始拍照命令
uint8 start_photo_cmd [] =
{
	0x56,
	0x00,
	0x36,
	0x01,
	0x00
};

//开始拍照返回命令
uint8 start_photo_rcv [] =
{
	0x76,
	0x00,
	0x36,
	0x00,
	0x00
};

//读长度命令
uint8 read_len_cmd [] = 
{
	0x56,
	0x00,
	0x34,
	0x01,
	0x00
};
//读长度返回命令的前七个字节,返回命令的后两个字节为图像长度
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

//取图像命令,也就是读数命令
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
	0xFF              //这个时间间隔要注意,应该设大一点,而不是设小一点,设小一点的话数据来得太快就容易出现接收错误

};
uint8 get_photo_rcv [] =
{
	0x76,
	0x00,
	0x32,
	0x00,
	0x00
};


//设置压缩率命令,这里设为0x80 : 1,尽量使图像小
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

//停止拍照命令,它的返回命令与开始拍照的相同
uint8 stop_photo_cmd [] =
{
	0x56,
	0x00,
	0x36,
	0x01,
	0x03
};
//停止拍照返回命令,跟开始拍照的一样
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



//设置图像大小命令

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
			if (count > 10000 * 100) return 0;      //这个count只是为了防止死循环
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
	
	//检验数据
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != zoom_size_rcv[i]) return 0;
	}

	return 1;


}

//发送设置图像大小命令,此函数可以不要
uint8 send_photo_size(void)
{
	uint32 i;//, count;
	uint8 tmp[5];
	
	//如果状态寄存器溢出标志不为1,则要把它清零,否则缓冲区会丢弃下一个到来的数据
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	
	uart0_sendbuf(photo_size_cmd, 10);
	
	
	if (!uart0_getbuf(tmp, 5)) return 0;
	
	//检验数据
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != photo_size_rcv[i]) return 0;
	}

	return 1;
}

//发送停止拍照函数
uint8 send_stop_photo(void)
{
	uint32 i;//, count;
	uint8 tmp[5];
	
	//清空一下溢出错误和接收缓冲区这两个标志,
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	
	//发送停止拍照命令,其实就是清空缓冲区,而不是什么停止拍照
	uart0_sendbuf(stop_photo_cmd, 5);
	if (!uart0_getbuf(tmp, 5)) return 0;
	
	//检验数据
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != stop_photo_rcv[i]) return 0;
	}
	return 1;
}


//发送复位命令函数
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
	
	delay(300);  //复位后延时,因为只检验了帧头,后面的数据要丢弃
	//清空一下溢出标志
	U0LSR = U0LSR & (~0x02); 
	data = U0RBR;
	
	return 1;
}

//读图像数据函数，返回图像数据的大小(以字节为单位),若失败则返回0
uint32 send_get_photo(uint8 *buf) 
{
	uint32 i;//, count;
	if (photo_len > 8000) return 0;  //图像数据太大
	
	U0LSR = U0LSR & (~0x02); 
	buf[0] = U0RBR;
	
	//发送读数命令
	uart0_sendbuf(get_photo_cmd, 16);
	if (!uart0_getbuf(buf, 10 + photo_len)) return 0;
	//检验帧头
	for (i = 0; i < 5; i++)
	{
		if (buf[i] != get_photo_rcv[i]) return 0;
	}
	//检验帧尾
	for (i = 0; i < 5; i++)
	{
		if (buf[i + 5 + photo_len] != get_photo_rcv[i]) return 0;
	}
	//检验图像的合法性,以0xFF,0xD8开始,0xFF,0xD9结束
	if (buf[5] != 0xFF || buf[6] != 0xD8 ||
		buf[3 + photo_len] != 0xFF || buf[4 + photo_len] != 0xD9)
	{
		return 0;
	}
	//把图像数据移动到数组0开始处
	for (i = 0; i < photo_len; i++)
		buf[i] = buf[i + 5];
	return photo_len;	//返回图像长度
}

//短延时函数
void delay1(uint32 n)
{
	while (n--);
}
//读长度函数
uint8 send_read_len(void)
{
	uint32 i;//, count;
	uint8 tmp[9];
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	//发送读长度命令
	uart0_sendbuf(read_len_cmd, 5);
	if (!uart0_getbuf(tmp, 9)) return 0;
	//检验数据
	for (i = 0; i < 7; i++)
	{
		if (tmp[i] != read_len_rcv[i]) return 0;
	}
	
	set_photo_len(tmp[7], tmp[8]);  //设置读长度命令
	return 1;
}

void set_photo_len(uint8 length1, uint8 length2)
{

	get_photo_cmd[12] = length1;
	get_photo_cmd[13] = length2;
	photo_len = length1 * 0x100 + length2;
}
//发送压缩率函数
uint8 send_compress_rate(void)
{
	uint32 i;//, count;
	uint8 tmp[5];
	U0LSR = U0LSR & (~0x02); 
	tmp[0] = U0RBR;
	//设置压缩率为80:1
	uart0_sendbuf(set_compress_cmd, 9);
	if (!uart0_getbuf(tmp, 5)) return 0;
	//检验数据
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
	//向摄像头发送拍照命令
	uart0_sendbuf(start_photo_cmd, 5);
	if (!uart0_getbuf(tmp, 5)) return 0;
	//检验数据
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != start_photo_rcv[i]) return 0;
	}
	
	return 1;
}

//拍照初始化函数
uint8 photo_init(void)
{
	camera_power_on();
	delay(500);    //在上电复位后要等2.5秒摄像头才能接收命令
	if (!send_zoom_size()) goto error_exit;
	if (!send_photo_size()) goto error_exit;   //设置图像大小为320x240
	if (!send_stop_photo()) goto error_exit;  //清空摄像头缓冲区	
	if (!send_compress_rate()) goto error_exit;    //设置压缩率为0x80:1
	delay(10);   //这里要注意,设置压缩率后要延时
	return 1;
error_exit:
  
    return 0;
}

uint8 reset_photo(void)
{
	if (!send_reset()) goto error_exit;	       //设置图像大小后要重启
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
	
	//向摄像头发送退出省电命令
	uart0_sendbuf(save_power_cmd, 7);

	if (!uart0_getbuf(tmp, 5)) return 0;
	
	//检验数据
	for (i = 0; i < 5; i++)
	{
		if (tmp[i] != save_power_rcv[i]) return 0;
	}
	
	return 1;	
}

//拍照函数,包括四个步骤
uint32 take_photo(uint8 *buf)
{
	uint32 len;
   
	if(!photo_init()) goto error_exit;
	if (!send_start_photo()) goto error_exit;  //送开始拍照命令
	if (!send_read_len()) goto error_exit;   //读长度
		
	len = send_get_photo(buf);		//读数
	if (len == 0)  goto error_exit;

	if (!send_stop_photo()) goto error_exit;  //停止拍照,清空缓冲区
	
	camera_power_off();
	return len;
	
error_exit:

    camera_power_off();
  	return 0;
}


//gpio初始化函数
void gpio_init(void)
{
		
	IO0DIR = IO0DIR |BEEP|CAMERA_POWER_CONTROL;		// 设置控制口为输出，其余输入。					
	IO0CLR = IO0CLR |BEEP;                              //输出低电平	
	IO0CLR = IO0CLR |CAMERA_POWER_CONTROL;              //输出低电平	
	 led_on();
	  beep(1000);
	 led_off();
	
}

//中断初始化函数
void eint0_init()
{
	PINSEL1 = PINSEL1 | 0x01;			// 设置管脚连接，P0.16为EINT0	
	EXTMODE = 0x01;					//设置EINT0为下降沿触发。	
						
	// 打开EINT0中断(使用向量中断)
	VICIntSelect   = 0x00000000;	// 设置所有中断分配为IRQ中断		
	VICVectCntl0   = 0x20 | 0x0e;	// 分配外部中断0到向量中断0		
	VICVectAddr0   = (uint32)IRQ_Eint0;//* 设置中断服务程序地址					
	EXTINT         = 0x01;			// 清除EINT0中断标志					
	VICIntEnable   = 1 << 0x0e;		// 使能EINT0中断,写入0是无效的		
}


//蜂鸣器响铃一次函数
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


//蜂鸣器响铃函数,次数由参数times控制,如果times为0,就一直响铃,直到复位为止
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

//摄像头电源打开
void camera_power_on()
{
	IO0SET = IO0SET |CAMERA_POWER_CONTROL;              //输出高电平	
}

//摄像头电源关闭
void camera_power_off()
{
	IO0CLR = IO0CLR |CAMERA_POWER_CONTROL;              //输出低电平
}

//三个led灯点亮函数
void led_on()
{
	IO1CLR = IO1CLR | LED;
}

//熄灭函数
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


//致命错误函数
void photo_fatal_error(void)
{
	led_photo();
	beep(0);
}

//处理成功函数，主要是响一次短鸣
void handle_success(void)
{
	beep(1000);
	delay(50);
}

//这是中断函数
void __irq IRQ_Eint0(void)
{
  uint8  fail_count = 0;
  uint32  len=0;	//图片长度
  
  	
    IRQDisable();   //先关闭中断，防止自身嵌套和其它中断影响
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
  	
	EXTINT = 0x01;      		//清除中断标志
	VICVectAddr = 0;			// 向量中断向量地址寄存器	
		
	wait_led_on();	
	IRQEnable();   //重新开启中断
		
}

/*
*********************************************************************************************************
** 函数名称 ：uart0_sendbuf()
** 函数功能 ：向串口发送一字符串
** 入口参数 ：str	要发送的字符串的指针
** 出口参数 ：无
*********************************************************************************************************/

void uart0_sendbuf(uint8 const *buf, uint32 n)
{
	int i;
	for (i = 0; i < n; i++)  
	  {
	   U0THR = buf[i];
	   while ((U0LSR & 0x40) == 0);		/* 等待数据发送完毕			*/
	  }
}

/*
*********************************************************************************************************
** 函数名称 ：delay()
** 函数功能 ：长软件延时。
** 入口参数 ：dly	延时参数，值越大，延时越久
** 出口参数 ：无
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
** 函数名称 ：uart_init()
** 函数功能 ：串口初始化，设置为8位数据位，1位停止位，无奇偶校验
** 入口参数 ：无
** 出口参数 ：无
*********************************************************************************************************
*/
void uart_init0 (uint32 uart_bps)
{
	uint16 Fdiv;
    
    	
	//串口0波特率设为38400
	U0LCR = 0x83;						// DLAB=1,允许设置波特率
	Fdiv  = (Fpclk / 16) / uart_bps;	// 设置波特率
	U0DLM = Fdiv / 256;
	U0DLL = Fdiv % 256;
	U0LCR = 0x03;      //3表示发送字符长度为8
	
}






