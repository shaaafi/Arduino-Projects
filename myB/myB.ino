#include <SoftwareSerial.h>
String input;
String state = "1o2o\n";
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

    if(input == "first"){
        Serial.println("1st Switch Is On");
        state.setCharAt(1,'n');
      }
     if(input == "firstOff"){
        Serial.println("1st Switch Is Off");
        state.setCharAt(1,'o');
      }
      if(input == "second"){
        Serial.println("1nd Switch Is On");
        state.setCharAt(3,'n');
      }
     if(input == "secondOff"){
        Serial.println("2nd Switch Is Off");
        state.setCharAt(3,'o');
      }
    if(input=="read"){
      bt.print(state);
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
     // bt.print(state);
      Serial.println(state);
      
}
