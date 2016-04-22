//MCU2
// second hand 
//GREEN BAR
//ST[1]


#include "POV_lib.h"
//
//#define RECV_PIN  19
//
//#define CYCLE 321
//#define SEC   5.3833333333  // (323/60)
//#define QUAR  70
//
//#define TEST_TIME  65
//#define TIME_INDEX 400


int count_sec = 1;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("START");
  Wire.begin();
  int i;
  for(i=0;i<4;i++)//display pin
  {
    pinMode(ST_TOP[i],OUTPUT);
    pinMode(SH_TOP[i],OUTPUT);
    pinMode(DI_TOP[i],OUTPUT);
  }
  
  //initialize RTC
  RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  
  //communication pin
  pinMode(RECV_PIN,INPUT);
  
  
  
}

void loop()
{

  char state = 0;
  int min_,hour_,sec_;
  int dis_hour;
//  DateTime now = RTC.now();
//  min_ = now.minute();
//  sec_ = now.second();
//  Serial.print("sec = ");
//  Serial.println(sec_,DEC);
//  hour_ = now.hour();
//  if(hour_>=13)
//  hour_ = hour_-12;
  
  state = digitalRead(RECV_PIN);
  Serial.print("state = ");
  Serial.println(state,DEC);
  Serial_Dis2(1,0,0,0);
  while(digitalRead(RECV_PIN) == 0);//wait until get the signal from MCU1
  //LOW: wait; HIGH: go
  Serial.println("Signal received");
  
  
  //second hand
  //0000 0111, 0000 0000
  //one second : 430/60 
  //display second hand
//  Serial_Dis2(1,0,7,255);
//  delay(1000);
//  Serial_Dis2(1,0,0,0);
//  delay(1000);
//  //count_sec++;
  
  //0000 0111; 1000 0000
  //wait for the blue hand
  display: 
  //RTC.adjust(DateTime(__DATE__, __TIME__));
  DateTime now = RTC.now();
//  min_ = now.minute();
  sec_ = now.second();
  Serial.print("sec = ");
  Serial.println(sec_,DEC);
//  hour_ = now.hour();
//  if(hour_>=13)
//  hour_ = hour_-12;
  
  if(sec_>=60)
  goto display;
  
  delay(QUAR);//green
  //0000 1111; 0000 0000
  Serial_Dis2(1,0,15,0);
  delay(SEC*sec_);
  Serial_Dis2(1,0,0,0);
  Serial.println("IN goto");
  while(digitalRead(RECV_PIN) == 0)//wait for high(low: delay)
  {delay(TEST_DELAY);
   Serial.println("Signal Received in goto");
  }
  goto display;
  
  //count_sec++;
  
//  if(count_sec == 59)
//  count_sec = 0;

//  //0000 0000; 0111 1000
//  blank_Clock_Stay(TEST_TIME,TIME_INDEX);//wait for next color bar
//  Serial_Dis2(2,0,0,120);
//  delay(min_*SEC);
//  Serial_Dis2(2,0,0,0);
//  delay(CYCLE-SEC*min_);
//  
//  //0000 0000; 0000 0111
//  blank_Clock_Stay(TEST_TIME,TIME_INDEX);
//  Serial_Dis2(3,0,0,7);
//  dis_hour = hour_*(CYCLE/12)+(CYCLE/12)*(min_/60);//add minute index 
//  delay(dis_hour);
//  Serial_Dis2(3,0,0,0);
//  delay(CYCLE-dis_hour);
  
  
  
  
  Serial.println("Loop End");
  
}
