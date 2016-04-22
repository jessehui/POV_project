#define ST 13   //storage clock in
#define SH 12  //shift clock in 
#define DI 11 //data in 


void setup()
{
  // put your setup code here, to run once:
  pinMode(ST,OUTPUT);
  pinMode(SH,OUTPUT);
  pinMode(DI,OUTPUT);
  Serial.begin(9600);
  Serial.println("start");
  Serial_Dis(134,188,196,212);   //10000110
  delay(5000);
  //Serial_Dis(188);  //10111100
  delay(10000000);
}


void loop()
{
  //delay(50);
  // put your main code here, to run repeatedly:
  Serial.println(Serial.available());
  if(Serial.available() > 1)
  {
    int light_num = Serial.read() - 48;//ASCII
    registerWrite(light_num, HIGH);
  }
}

void registerWrite(int Num, int State)
{
  byte bitstosend = 0;
  
  ///turn off the storage line and wait for data
  digitalWrite(ST,LOW);
  Serial.print("bitstosend (before)= ");
  Serial.print(bitstosend,DEC);
  Serial.println(".");
  
  bitWrite(bitstosend,Num,State);//write State to the Num of bit of bitstosend 
  Serial.print("bitstosend = ");
  Serial.print(bitstosend,DEC);
  Serial.println(".");
  
  shiftOut(DI,SH,MSBFIRST,bitstosend);
  
  digitalWrite(ST,HIGH);
  //delay(5000);
}


void Serial_Dis(int Pat3, int Pat2, int Pat1, int Pat0)//Pat is a hex number e.g. 0xfc
{
  int Pat[4] = {Pat0,Pat1,Pat2,Pat3};
  int bits[4][7] = {0};
  byte bitstosend[4] = {0};
  char i,j;
  
  for(j=0;j<4;i++)
  {    
    bits[j][7] = Pat[j]/128;
    bits[j][6] = (Pat[j]%128)/64;
    bits[j][5] = (Pat[j]%64)/32;
    bits[j][4] = (Pat[j]%32)/16;
    bits[j][3] = (Pat[j]%16)/8;
    bits[j][2] = (Pat[j]%8)/4;
    bits[j][1] = (Pat[j]%4)/2;
    bits[j][0] = Pat[j]%2;
  }

  Serial.println(Pat[3]);
  Serial.println(Pat[2]);
  Serial.println(Pat[1]);
  Serial.println(Pat[0]);

  digitalWrite(ST,LOW);
  for(j=0;j<4;j++)
  {
    for(i=0;i<8;i++)
    {
      bitWrite(bitstosend[j],i,bits[j][i]);
    }
     Serial.print("bitstosend");
     Serial.print(j);
     Serial.print(" = ");
     Serial.print(bitstosend[j],DEC);
     Serial.println("");
  }


  // Serial.print("bitstosend = ");
  // Serial.print(bitstosend,DEC);
  // Serial.println("");
  //delay(3000);
  for(j=3;j>=0;j--)
  {
    shiftOut(DI,SH,MSBFIRST,bitstosend[j]);

  }
  Serial.println("Shift Complete");
  digitalWrite(ST,HIGH);
  
}
