#include "ds1302.h"

uchar xdata disp_time[19];//xdata 外部存储器


void write_clock(uchar ord, uchar dd)

void clock_out(uchar dat)
{
	ACC = dat;
	
}
