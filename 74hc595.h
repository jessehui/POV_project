#ifndef __74hc5959__
#define __74hc5959__

#include "STC15Fxxxx.h"

sbit SDAA=P1^1;	//数据
sbit OEA =P4^7;  //595使能A
sbit STRA=P1^2;	 //锁存
sbit SCKA=P1^3;	//时钟

sbit SDAB=P1^4;	//数据
sbit OEB =P4^4;  //595使能B
sbit STRB=P1^6;	 //锁存
sbit SCKB=P1^7;	//时钟

sbit SDAC=P3^5;	//数据
sbit OEC =P4^0;  //侧面595使能
sbit STRC=P3^6;	 //锁存
sbit SCKC=P3^7;	//时钟

sbit OED =P4^6;  //侧面595使能

sbit LED0=P4^5;	  //平面外圈LED
sbit LED1=P5^5;	  //侧面左圈LED
sbit LED2=P5^4;	  //侧面右圈LED

extern void Send_data_A(uchar temp);
extern void Send_data_B(uchar temp);
extern void Send_data_C(uchar temp1,uchar temp2);
extern void dis_open(void);
extern void dis_close(void);

extern void delay(void);

#endif