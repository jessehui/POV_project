#include "74hc595.h"

/********************
//延时函数
*********************/

void delay(void)   //误差 -0.46875us
{
    uchar a,b;
    for(b=20;b>0;b--)
        for(a=2;a>0;a--);
}


/****************
//发送数据A
****************/
void Send_data_A(uchar temp)	  
{
	uchar i; 
	for(i=0;i<8;i++)//一个字节8位 发送给595
   	{
	       	SCKA=0; //上升沿移位595 (在低电平时装填)	   
		SDAA=(bit)(temp&0x80);//通过IO口送一个位给595 (0x80 = 1000 0000)
	       	temp=temp<<1;  //字节移位 准备送下一位			   
	       	SCKA=1;
   	}
    	STRA=1;//锁存
	STRA=0;
   
}

/****************
//发送数据B
****************/
void Send_data_B(uchar temp)
{
	uchar i;
	for(i=0;<8;i++)
	{
		SCKB = 0;
		SDAB = (bit)(temp&0x80);
		temp = temp << 1;
		SCKB = 1;
	}
	STRB = 1;//锁存
	STRB = 0;
}

/****************
//发送数据C
*****************/
void Send_data_C(uchar temp1, uchar temp2)
{
	uchar i;
	for(i=0;i<8;i++)
	{
		SCKC = 0;
		SDAC = (bit)(temp1&0x01);
		temp1 = temp1 << 1;
		SCKC = 1;
	}

	for(i=0;i<8;i++)
	{
		SCKC = 0;
		//test: any difference with temp1
		SDAC = (bit)(temp2&0x08);
		temp2 = temp2 >> 1;
		SCKC = 1;
	}

	STRC = 1;
	STRC = 0;

}

/***************************
打开595显示
****************************/
void dis_open()
{
	OEA = OEB = OEC = 0;//低电平有效
}


/***************************
关闭595显示
****************************/
void dis_close()
{
	OEA = OEB = OEC = 1;//高电平对应高阻态
}







