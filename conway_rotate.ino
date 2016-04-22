#include <POV_lib.h>

#define TIMES  30

void setup()
{
  char i;
  for(i=0;i<4;i++)  //Initialize pin
  {
    pinMode(ST[i],OUTPUT);
    pinMode(SH[i],OUTPUT);
    pinMode(DI[i],OUTPUT);
  }
  Serial.begin(9600); //test
  Serial.println("Start");
}

void loop()
{
  
    int i;
    
    
//  for(i=1;i<21;i++)
    for(i=0;i<TIMES;i++)
    pattern_1();
    //blank_Conway();
    for(i=0;i<TIMES;i++)
    pattern_2();
      for(i=0;i<TIMES;i++)
    pattern_3();
      for(i=0;i<TIMES;i++)
    pattern_4();
      for(i=0;i<TIMES;i++)
    pattern_5();
      for(i=0;i<TIMES;i++)
    pattern_6();
      for(i=0;i<TIMES;i++)
    pattern_7();
      for(i=0;i<TIMES;i++)
    pattern_8(); 
       for(i=0;i<TIMES;i++)
    pattern_9();
       for(i=0;i<TIMES;i++)
    pattern_10();
    
      for(i=0;i<TIMES;i++)
    pattern_11();
      for(i=0;i<TIMES;i++)
    pattern_12();
 //     for(i=0;i<TIMES;i++)
//    pattern_13();
 //     for(i=0;i<TIMES;i++)
//    pattern_14();
//     for(i=0;i<TIMES;i++)
//    pattern_15();
//     for(i=0;i<TIMES;i++)
//    pattern_16();
      
    
  
  
  
  
}
