#include <SoftwareSerial.h>
#include <IRremote.h>
IRsend irsend;
String input;

SoftwareSerial bt(10,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
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
        for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0xE1A2E817, 32);
    delay(40);
  }
      }

     if(input == "test1"){
        for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0xF20A40BF, 32);
    delay(40);
  }
      }

      if(input == "test2"){
        for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0x10C8E11E, 32);
    delay(40);
  }
      }

      if(input == "test3"){
        for (int i = 0; i < 3; i++) {
    irsend.sendNEC(0xCF300FF, 32);
    delay(40);
  }
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
   
      input="";
}
