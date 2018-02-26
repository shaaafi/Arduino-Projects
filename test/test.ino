#include <SoftwareSerial.h>
#include <IRremote.h>
IRsend irsend;
String input;

SoftwareSerial bt(10,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(5,OUTPUT);
   pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   while(bt.available()>0)
    {
          delay(10);
        char c=bt.read();
         if(c=='#')
         {break;}
         input+=c; 
    } 

    if(input == "on"){
        Serial.println("Data sent");
        for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0xE1A2E817, 32);
    delay(40);
  }
      }

      digitalWrite(5,HIGH);
     

         if(input== "b"){
        digitalWrite(6,HIGH);
        }

      if(input == "bb"){
        digitalWrite(6,LOW);
        }
     
     
     
/*
      if(input.length()>0)
      {
        Serial.println(input);
        bt.println(input);
      }
      delay(1000);
*/

       delay(1000);
       digitalWrite(5,LOW);
       delay(1000);
      input="";
}
