// #ifndef __POV_lib_h__
// #define __POV_lib_h__

#include <Wire.h>
#include "RTClib.h"
#include <Energia.h>

RTC_DS1307 RTC;

#define TIME_DLY	50
#define OFF_TIME 40
#define STAY_TIME 942
#define STILL_TIME 3000 //background and clock number stay

// #define ST0	2
// #define SH0	3
// #define DI0	4

// #define ST1 5   //storage clock in
// #define SH1 6  //shift clock in 
// #define DI1 7 //data in 

// #define ST2 10
// #define SH2 9
// #define DI2 8

// #define ST3	 13
// #define SH3	 12
// #define DI3	 11

//*******************
//one cycle: delay(430);


#define RECV_PIN  19

#define CYCLE 321
#define SEC   5.3833333333  // (323/60)
#define QUAR  70

#define TEST_TIME  62
#define TIME_INDEX 300

#define COMM  19
//#define HI_LEV  1

//number go anticlockwise:delay longer; 
//          clockwise    :delay shorter;


#define TEST_DELAY  1


#define SCL 14
#define SDA 15

extern int ST[4] = {5,18,7,13};//0,1,2,3
extern int SH[4] = {4,14,8,12};
extern int DI[4] = {6,15,9,11};

//0:red 1:blue
extern int ST_TOP[4] = {8,8,8,8};//0,1,2,3
extern int SH_TOP[4] = {9,9,9,9};
extern int DI_TOP[4] = {10,10,10,10};



void Serial_Dis2(int Bar, int Pat_Ext, int Pat1, int Pat0);

void Serial_Dis4(int Bar, int Pat_ext0, int Pat3, int Pat2, int Pat1, int Pat0);

/************************************************************
Serial Display for dual 595 chips (TOP display)
/************************************************************/

void Serial_Dis2(int Bar, int Pat_Ext, int Pat1, int Pat0)//Pat is a hex number e.g. 0xfc
{
  int j;
  int bitstosend[3] = {Pat0,Pat1,Pat_Ext};
  digitalWrite(ST_TOP[Bar],LOW);
  
  //clear data
  digitalWrite(SH_TOP[Bar],LOW);
  digitalWrite(DI_TOP[Bar],LOW);
  digitalWrite(SH_TOP[Bar],HIGH);//test
  
  for(j=3;j>=0;j--)
  {
    shiftOut(DI_TOP[Bar],SH_TOP[Bar],MSBFIRST,bitstosend[j]);
    
  }
  //shiftOut(DI,SH,MSBFIRST,Pat1);//0
  digitalWrite(ST_TOP[Bar],HIGH);
  
  
}


/************************************************************
Serial Display for quad 595 chips (SIDE display)
/************************************************************/

void Serial_Dis4(int Bar, int Pat_ext0, int Pat3, int Pat2, int Pat1, int Pat0)//Pat is a hex number e.g. 0xfc
{//int Pat_ext1,
  int j;
  int bitstosend[5] = { Pat0,Pat1,Pat2,Pat3,Pat_ext0};
  digitalWrite(ST[Bar],LOW);
   //clear data
  digitalWrite(SH[Bar],LOW);
  digitalWrite(DI[Bar],LOW);
  digitalWrite(SH[Bar],HIGH);//test
  
  for(j=4;j>=0;j--)
  {
    shiftOut(DI[Bar],SH[Bar],MSBFIRST,bitstosend[j]);
    
  }
  
  digitalWrite(ST[Bar],HIGH);
  
  
}

void blank_Conway(void)
{
  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);

}

void blank_Clock_Stay(int time, int time_index)
{
  // Serial_Dis2(0,0,0,0);
  Serial_Dis2(1,0,0,0);
  // Serial_Dis4(2,0,0,0,0,0);
  // Serial_Dis4(3,0,0,0,0,0);
  delay(time);
  delayMicroseconds(time_index);

}

void pattern_1(void)
{
  Serial_Dis4(0,0,31,7,193,240);
  Serial_Dis4(1,0,31,7,193,240);
  Serial_Dis4(2,0,31,7,193,240);
  Serial_Dis4(3,0,31,7,193,240);
  delayMicroseconds(TIME_DLY);
  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);  
  Serial_Dis4(0,0,17,4,129,16);
  Serial_Dis4(0,0,17,4,129,16);
  Serial_Dis4(0,0,17,4,129,16);
  Serial_Dis4(0,0,17,4,129,16);  
  delayMicroseconds(TIME_DLY);
  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);
  Serial_Dis4(0,0,31,7,193,240); 
  Serial_Dis4(1,0,31,7,193,240); 
  Serial_Dis4(2,0,31,7,193,240); 
  Serial_Dis4(3,0,31,7,193,240);  
  delayMicroseconds(TIME_DLY);
  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);
}

void pattern_2(void)
{
  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,21,5,65,80);
  Serial_Dis4(1,0,21,5,65,80);
  Serial_Dis4(2,0,21,5,65,80);
  Serial_Dis4(3,0,21,5,65,80);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);  

  Serial_Dis4(0,0,21,5,65,80);
  Serial_Dis4(1,0,21,5,65,80);
  Serial_Dis4(2,0,21,5,65,80);
  Serial_Dis4(3,0,21,5,65,80);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);


}

void pattern_3(void)
{
  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY); 

  Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);
  
  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);


}


void pattern_4(void)
{
  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 


  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);

}

void pattern_5(void)
{

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 

  Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 

  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);
  
  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);

  
}

void pattern_6(void)
{
  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);


}



void pattern_7(void)
{
  Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY); 


    Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);

}


void pattern_8(void)
{
  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

  Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);


      Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,10,2,128,160);
  Serial_Dis4(1,0,10,2,128,160);
  Serial_Dis4(2,0,10,2,128,160);
  Serial_Dis4(3,0,10,2,128,160);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);




}

void pattern_9(void)
{

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

     Serial_Dis4(0,0,27,6,193,176);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);


      Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

     Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);


    Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

     Serial_Dis4(0,0,27,6,193,176);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);


      Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

     Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);



}

void pattern_10(void)
{
      Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

        Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

        Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

      Serial_Dis4(0,0,17,4,65,16);
  Serial_Dis4(1,0,17,4,65,16);
  Serial_Dis4(2,0,17,4,65,16);
  Serial_Dis4(3,0,17,4,65,16);
  delayMicroseconds(TIME_DLY);

        Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);

}



void pattern_11(void)
{

      Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);

          Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,21,5,65,80);
  Serial_Dis4(1,0,21,5,65,80);
  Serial_Dis4(2,0,21,5,65,80);
  Serial_Dis4(3,0,21,5,65,80);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,59,142,227,184);
  Serial_Dis4(1,0,59,142,227,184);
  Serial_Dis4(2,0,59,142,227,184);
  Serial_Dis4(3,0,59,142,227,184);
  delayMicroseconds(TIME_DLY);

     Serial_Dis4(0,0,21,5,65,80);
  Serial_Dis4(1,0,21,5,65,80);
  Serial_Dis4(2,0,21,5,65,80);
  Serial_Dis4(3,0,21,5,65,80);
  delayMicroseconds(TIME_DLY);


            Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

       Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);


            Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,21,5,65,80);
  Serial_Dis4(1,0,21,5,65,80);
  Serial_Dis4(2,0,21,5,65,80);
  Serial_Dis4(3,0,21,5,65,80);
  delayMicroseconds(TIME_DLY);

    Serial_Dis4(0,0,59,142,227,184);
  Serial_Dis4(1,0,59,142,227,184);
  Serial_Dis4(2,0,59,142,227,184);
  Serial_Dis4(3,0,59,142,227,184);
  delayMicroseconds(TIME_DLY);

     Serial_Dis4(0,0,21,5,65,80);
  Serial_Dis4(1,0,21,5,65,80);
  Serial_Dis4(2,0,21,5,65,80);
  Serial_Dis4(3,0,21,5,65,80);
  delayMicroseconds(TIME_DLY);


            Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);


        Serial_Dis4(0,0,4,1,0,64);
  Serial_Dis4(1,0,4,1,0,64);
  Serial_Dis4(2,0,4,1,0,64);
  Serial_Dis4(3,0,4,1,0,64);
  delayMicroseconds(TIME_DLY);





  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);

}





void pattern_12(void)
{


            Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

         Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

         Serial_Dis4(0,0,32,136,34,8);
  Serial_Dis4(1,0,32,136,34,8);
  Serial_Dis4(2,0,32,136,34,8);
  Serial_Dis4(3,0,32,136,34,8);
  delayMicroseconds(TIME_DLY);

           Serial_Dis4(0,0,32,136,34,8);
  Serial_Dis4(1,0,32,136,34,8);
  Serial_Dis4(2,0,32,136,34,8);
  Serial_Dis4(3,0,32,136,34,8);
  delayMicroseconds(TIME_DLY);

           Serial_Dis4(0,0,32,136,34,8);
  Serial_Dis4(1,0,32,136,34,8);
  Serial_Dis4(2,0,32,136,34,8);
  Serial_Dis4(3,0,32,136,34,8);
  delayMicroseconds(TIME_DLY);

            Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

         Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

              Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);

           Serial_Dis4(0,0,32,136,34,8);
  Serial_Dis4(1,0,32,136,34,8);
  Serial_Dis4(2,0,32,136,34,8);
  Serial_Dis4(3,0,32,136,34,8);
  delayMicroseconds(TIME_DLY);

           Serial_Dis4(0,0,32,136,34,8);
  Serial_Dis4(1,0,32,136,34,8);
  Serial_Dis4(2,0,32,136,34,8);
  Serial_Dis4(3,0,32,136,34,8);
  delayMicroseconds(TIME_DLY);

           Serial_Dis4(0,0,32,136,34,8);
  Serial_Dis4(1,0,32,136,34,8);
  Serial_Dis4(2,0,32,136,34,8);
  Serial_Dis4(3,0,32,136,34,8);
  delayMicroseconds(TIME_DLY);

           Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delayMicroseconds(TIME_DLY);

              Serial_Dis4(0,0,14,3,128,224);
  Serial_Dis4(1,0,14,3,128,224);
  Serial_Dis4(2,0,14,3,128,224);
  Serial_Dis4(3,0,14,3,128,224);
  delayMicroseconds(TIME_DLY);


  Serial_Dis4(0,0,0,0,0,0);
  Serial_Dis4(1,0,0,0,0,0);
  Serial_Dis4(2,0,0,0,0,0);
  Serial_Dis4(3,0,0,0,0,0);
  delay(OFF_TIME);

}






// void pattern_13(void)
// {
//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);


//            Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);


//            Serial_Dis4(0,0,113,220,119,28);
//   Serial_Dis4(1,0,113,220,119,28);
//   Serial_Dis4(2,0,113,220,119,28);
//   Serial_Dis4(3,0,113,220,119,28);
//   delayMicroseconds(TIME_DLY);


//     Serial_Dis4(0,0,21,5,65,80);
//   Serial_Dis4(1,0,21,5,65,80);
//   Serial_Dis4(2,0,21,5,65,80);
//   Serial_Dis4(3,0,21,5,65,80);
//   delayMicroseconds(TIME_DLY);


//       Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);


//            Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);


//       Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);


//     Serial_Dis4(0,0,21,5,65,80);
//   Serial_Dis4(1,0,21,5,65,80);
//   Serial_Dis4(2,0,21,5,65,80);
//   Serial_Dis4(3,0,21,5,65,80);
//   delayMicroseconds(TIME_DLY);


//            Serial_Dis4(0,0,113,220,119,28);
//   Serial_Dis4(1,0,113,220,119,28);
//   Serial_Dis4(2,0,113,220,119,28);
//   Serial_Dis4(3,0,113,220,119,28);
//   delayMicroseconds(TIME_DLY);

//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);

//       Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);


//   Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delay(OFF_TIME);

// }







// void pattern_14(void)
// {

//                Serial_Dis4(0,0,14,3,128,224);
//   Serial_Dis4(1,0,14,3,128,224);
//   Serial_Dis4(2,0,14,3,128,224);
//   Serial_Dis4(3,0,14,3,128,224);
//   delayMicroseconds(TIME_DLY);

//            Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);

//          Serial_Dis4(0,0,32,136,34,8);
//   Serial_Dis4(1,0,32,136,34,8);
//   Serial_Dis4(2,0,32,136,34,8);
//   Serial_Dis4(3,0,32,136,34,8);
//   delayMicroseconds(TIME_DLY);

//       Serial_Dis4(0,0,59,142,227,184);
//   Serial_Dis4(1,0,59,142,227,184);
//   Serial_Dis4(2,0,59,142,227,184);
//   Serial_Dis4(3,0,59,142,227,184);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,17,4,65,16);
//   Serial_Dis4(1,0,17,4,65,16);
//   Serial_Dis4(2,0,17,4,65,16);
//   Serial_Dis4(3,0,17,4,65,16);
//   delayMicroseconds(TIME_DLY);


//     Serial_Dis4(0,0,10,2,128,160);
//   Serial_Dis4(1,0,10,2,128,160);
//   Serial_Dis4(2,0,10,2,128,160);
//   Serial_Dis4(3,0,10,2,128,160);
//   delayMicroseconds(TIME_DLY);

//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);

//       Serial_Dis4(0,0,10,2,128,160);
//   Serial_Dis4(1,0,10,2,128,160);
//   Serial_Dis4(2,0,10,2,128,160);
//   Serial_Dis4(3,0,10,2,128,160);
//   delayMicroseconds(TIME_DLY);

//       Serial_Dis4(0,0,17,4,65,16);
//   Serial_Dis4(1,0,17,4,65,16);
//   Serial_Dis4(2,0,17,4,65,16);
//   Serial_Dis4(3,0,17,4,65,16);
//   delayMicroseconds(TIME_DLY);


//       Serial_Dis4(0,0,59,142,227,184);
//   Serial_Dis4(1,0,59,142,227,184);
//   Serial_Dis4(2,0,59,142,227,184);
//   Serial_Dis4(3,0,59,142,227,184);
//   delayMicroseconds(TIME_DLY);


//            Serial_Dis4(0,0,32,136,34,8);
//   Serial_Dis4(1,0,32,136,34,8);
//   Serial_Dis4(2,0,32,136,34,8);
//   Serial_Dis4(3,0,32,136,34,8);
//   delayMicroseconds(TIME_DLY);

//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);

//                  Serial_Dis4(0,0,14,3,128,224);
//   Serial_Dis4(1,0,14,3,128,224);
//   Serial_Dis4(2,0,14,3,128,224);
//   Serial_Dis4(3,0,14,3,128,224);
//   delayMicroseconds(TIME_DLY);



//   Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delay(OFF_TIME);

// }



// void pattern_15(void)
// {

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);


//          Serial_Dis4(0,0,32,136,34,8);
//   Serial_Dis4(1,0,32,136,34,8);
//   Serial_Dis4(2,0,32,136,34,8);
//   Serial_Dis4(3,0,32,136,34,8);
//   delayMicroseconds(TIME_DLY);

//            Serial_Dis4(0,0,42,138,162,168);
//   Serial_Dis4(1,0,42,138,162,168);
//   Serial_Dis4(2,0,42,138,162,168);
//   Serial_Dis4(3,0,42,138,162,168);
//   delayMicroseconds(TIME_DLY);

//            Serial_Dis4(0,0,32,136,34,8);
//   Serial_Dis4(1,0,32,136,34,8);
//   Serial_Dis4(2,0,32,136,34,8);
//   Serial_Dis4(3,0,32,136,34,8);
//   delayMicroseconds(TIME_DLY);


//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);


//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);


//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);
  

//            Serial_Dis4(0,0,32,136,34,8);
//   Serial_Dis4(1,0,32,136,34,8);
//   Serial_Dis4(2,0,32,136,34,8);
//   Serial_Dis4(3,0,32,136,34,8);
//   delayMicroseconds(TIME_DLY);

//            Serial_Dis4(0,0,42,138,162,168);
//   Serial_Dis4(1,0,42,138,162,168);
//   Serial_Dis4(2,0,42,138,162,168);
//   Serial_Dis4(3,0,42,138,162,168);
//   delayMicroseconds(TIME_DLY);

//            Serial_Dis4(0,0,32,136,34,8);
//   Serial_Dis4(1,0,32,136,34,8);
//   Serial_Dis4(2,0,32,136,34,8);
//   Serial_Dis4(3,0,32,136,34,8);
//   delayMicroseconds(TIME_DLY);


//       Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,4,1,0,64);
//   Serial_Dis4(1,0,4,1,0,64);
//   Serial_Dis4(2,0,4,1,0,64);
//   Serial_Dis4(3,0,4,1,0,64);
//   delayMicroseconds(TIME_DLY);





//   Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delay(OFF_TIME);

// }



// void pattern_16(void)
// {

//   Serial_Dis4(0,0,14,3,128,224);
//   Serial_Dis4(1,0,14,3,128,224);
//   Serial_Dis4(2,0,14,3,128,224);
//   Serial_Dis4(3,0,14,3,128,224);
//   delayMicroseconds(TIME_DLY);

//                Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,21,5,65,80);
//   Serial_Dis4(1,0,21,5,65,80);
//   Serial_Dis4(2,0,21,5,65,80);
//   Serial_Dis4(3,0,21,5,65,80);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,96,216,54,12);
//   Serial_Dis4(1,0,96,216,54,12);
//   Serial_Dis4(2,0,96,216,54,12);
//   Serial_Dis4(3,0,96,216,54,12);
//   delayMicroseconds(TIME_DLY);

//     Serial_Dis4(0,0,17,4,65,16);
//   Serial_Dis4(1,0,17,4,65,16);
//   Serial_Dis4(2,0,17,4,65,16);
//   Serial_Dis4(3,0,17,4,65,16);
//   delayMicroseconds(TIME_DLY);


//                Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);


//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);


//              Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);

//       Serial_Dis4(0,0,17,4,65,16);
//   Serial_Dis4(1,0,17,4,65,16);
//   Serial_Dis4(2,0,17,4,65,16);
//   Serial_Dis4(3,0,17,4,65,16);
//   delayMicroseconds(TIME_DLY);

//       Serial_Dis4(0,0,96,216,54,12);
//   Serial_Dis4(1,0,96,216,54,12);
//   Serial_Dis4(2,0,96,216,54,12);
//   Serial_Dis4(3,0,96,216,54,12);
//   delayMicroseconds(TIME_DLY);

//       Serial_Dis4(0,0,21,5,65,80);
//   Serial_Dis4(1,0,21,5,65,80);
//   Serial_Dis4(2,0,21,5,65,80);
//   Serial_Dis4(3,0,21,5,65,80);
//   delayMicroseconds(TIME_DLY);


//                Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delayMicroseconds(TIME_DLY);

//   Serial_Dis4(0,0,14,3,128,224);
//   Serial_Dis4(1,0,14,3,128,224);
//   Serial_Dis4(2,0,14,3,128,224);
//   Serial_Dis4(3,0,14,3,128,224);
//   delayMicroseconds(TIME_DLY);



//   Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delay(OFF_TIME);

// }






// void pattern_(void)
// {







//   Serial_Dis4(0,0,0,0,0,0);
//   Serial_Dis4(1,0,0,0,0,0);
//   Serial_Dis4(2,0,0,0,0,0);
//   Serial_Dis4(3,0,0,0,0,0);
//   delay(OFF_TIME);

// }















//#endif