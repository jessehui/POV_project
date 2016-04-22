#include <POV_lib.h>
//number display on the top
//RED
//MCU1
//
//#define TEST_TIME  65
//#define TIME_INDEX 1000
//
//////delay(65-66)
//////delaymicroseconds(65700)
////#define TEST_TIME  657000
//
//#define COMM  19
//#define HI_LEV  1

char state;
int flag = 1;//loop times

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");
  int i;
  // put your setup code here, to run once:
  for(i=0;i<2;i++)
  {
    pinMode(ST_TOP[i],OUTPUT);
    pinMode(SH_TOP[i],OUTPUT);
    pinMode(DI_TOP[i],OUTPUT);
  }
  
  //communication pin
  pinMode(COMM,OUTPUT);
  digitalWrite(COMM,LOW);//low
 
  
  
  
}

void loop()
{
  //*****************************
  //display "1" test
  // 0100 1000, 1111 1000, 0000 1000
  Serial_Dis2(1,0,72,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,248,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,8,0);
  delayMicroseconds(STILL_TIME);
  
  //after display "1", send a signal to MCU2
  if(flag >= 60)
  {
    digitalWrite(COMM,HIGH);//high
    Serial.println("if 1");
    //delay(100);
    
  }
  
  //delay(1000);
  //Serial.println(state);
  
  //*****************************
  //display "2" test
  // 1011 1000, 1010 1000, 1110 1000
  Serial_Dis2(1,0,184,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,168,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,232,0);
  delayMicroseconds(STILL_TIME);
  blank_Clock_Stay(TEST_TIME,TIME_INDEX);//wait for the "3" position
  
  //*****************************
  //display "3" test
  // 1010 1000, 1010 1000, 1111 1000
  Serial_Dis2(1,0,168,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,168,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,248,0);
  delayMicroseconds(STILL_TIME);
  blank_Clock_Stay(TEST_TIME,TIME_INDEX);
  digitalWrite(COMM,LOW);
  //*****************************
  //display "6" test
  // 1111 1000, 1010 1000, 0011 1000
  Serial_Dis2(1,0,248,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,168,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,56,0);
  delayMicroseconds(STILL_TIME);
  blank_Clock_Stay(TEST_TIME,TIME_INDEX);
  
  //*****************************
  //display "9" test
  // 1110 0000, 1010 1000, 1111 1000
  Serial_Dis2(1,0,224,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,168,0);
  delayMicroseconds(STILL_TIME);
  Serial_Dis2(1,0,248,0);
  delayMicroseconds(STILL_TIME);
  blank_Clock_Stay(TEST_TIME,TIME_INDEX);
  //digitalWrite(COMM,HIGH);
  //delay(1000);
  //delay(3000);//test
  
  //Serial.println(state);
  //number go anticlockwise:delay longer; 
  //          clockwise    :delay shorter;
  
  //test
  //blank_Clock_Stay(430);
  Serial.print("flag = ");
  Serial.println(flag,DEC);
  flag++;
  
  
 //*****************************
 //Time Display
 
 //*****************************
 
 // second hand
 //sec = now.second();
 
 
 
 //background added
 // Serial_Dis2(0,0,)

 //test
//  Serial_Dis2(1,0,85,85); 
//  delay(500);
//  Serial_Dis2(1,0,170,170);
//  delay(500);

  
}

