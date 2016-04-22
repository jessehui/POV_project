//MCU2

#include "POV_lib.h"

#define RECV_PIN  8
#define SEC   7.1666666666666667  // (430/60)
#define CYCLE 430
#define QUAR  70

int count_sec = 1;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("START");
  int i;
  for(i=0;i<4;i++)//display pin
  {
    pinMode(ST_TOP[i],OUTPUT);
    pinMode(SH_TOP[i],OUTPUT);
    pinMode(DI_TOP[i],OUTPUT);
  }
  
  //communication pin
  pinMode(RECV_PIN,INPUT);
  
  
  
}

void loop()
{
  int min_,hour_;
  int dis_hour;
  DateTime now = RTC.now();
  min_ = now.minute();
 
  hour_ = now.hour();
  if(hour_>=13)
  hour_ = hour_-12;
  
  
  //!!test while(digitalRead(RECV_PIN) == LOW);//wait until get the signal from MCU1
  //second hand
  //0000 0111, 1111 1111
  //one second : 430/60 
  //display second hand
  Serial_Dis2(1,0,7,255);
  delay(SEC*count_sec);
  Serial_Dis2(1,0,0,0);
  delay(CYCLE-SEC*count_sec);
  count_sec++;
  
  //display minute hand
  //0000 0000,0111 1111
  delay(QUAR);//wait for next color bar
  Serial_Dis2(2,0,0,127);
  delay(min_*SEC);
  Serial_Dis2(2,0,0,0);
  delay(CYCLE-SEC*count_sec);
  
  //display hour hand
  //0000 0000, 0000 0111
  delay(QUAR);
  Serial_Dis2(3,0,0,7);
  dis_hour = hour_*(430/12)+(430/12)*(min_/60);//add minute index 
  delay(dis_hour);
  Serial_Dis2(3,0,0,0);
  delay(CYCLE-dis_hour);
  
  
  Serial.println("Loop End");
  
}
