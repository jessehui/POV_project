#ifndef __DS1320_H__
#define __DS1320_H__

#include "STC15Fxxxx.h"
#include "Time.h"

/******************************************************************************/
//寄存器宏定义
/***************************************************************************/
#define WRITE_PROTECT 	0x8e
#define YEAR 		0x8c	//1000 1100 (最后一位:RD/W',0表示写,1表示读)
#define MONTH		0x88	//1000 1000
#define DAY		0x86
#define HOUR		0x84
#define	MINUTE		0x82
#define SECOND		0x80
#define WEEK		0x8a
#define WriteFlag	0x00	//RD/W'
#define ReadFlag	0x01

sbit clock_clk = P4^2; //时钟线
sbit clock_Rst = P4^1; //复位线
sbit clock_dat = P4^3; //数据线


/**************************************
子函数声明
***************************************/
extern void clock_out(uchar dat);
extern void write_clock(uchar ord, uchar dd); //
extern uchar clock_in(void);
extern uchar read_clock(uchar ord);
extern void Init_1302(void);
extern void time_first_read(void);
extern void time_refurbish();
extern void WriteProtect(uchar ProtectFlag);
extern uchar xdata disp_time[19];//
#endif

