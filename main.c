#include "SoftwareSerial.h"

SoftwareSerial pm25(4,5);
int green = 2;
int yellow = 8;
int red = 13; 
char buf[31];

void setup()  {
  pm25.begin(9600);
  Serial.begin(9600);
}

void loop()  {
 
  
   if( pm25.find("B")) {     // 0X42
    pm25.readBytes(buf,31);
    

    if (buf[0] == 0x4d){
      int n1 = buf[4] + (buf[5] <<8);
      int n2 = buf[6] + (buf[7] <<8);
      int n3 = buf[8] + (buf[9] <<8);
      Serial.print("         pm1.0 :");
      Serial.print(n1);
      if (n2 < 100){
       digitalWrite(green, HIGH);
       delay(520);
       digitalWrite(green, LOW);
      }
      Serial.print("         pm2.5: ");
      Serial.print(n2);
       if (n2 < 200 && n2 > ){
       digitalWrite(yellow, HIGH);
       delay(520);
       digitalWrite(yellow, LOW);
      }
      Serial.print("         pm10: ");
      Serial.print(n3);
       if(n2 > 300){
       digitalWrite(red, HIGH);
       delay(520);
       digitalWrite(red, LOW);
      }
      Serial.println();
      delay(1000);
      }
   
     //digitalWrite(led, HIGH); 
     
   }
}
