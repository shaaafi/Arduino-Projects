#include <Servo.h>

Servo myServo1;
Servo myServo2;
 void forwrd();
void bak();
void left();
void right();
void off();
void fullTurn();
void servo1_increase();
void servo1_decrease();

int M1A=2,M1B=3,M2A=4,M2B=5,MC1=6,MC2=7,S1=9,S2=10;
int i=0;
int s1=5;
int s2=5;
char inp;
void setup()
{
  Serial.begin(9600);
  pinMode(M1A,OUTPUT);
    pinMode(M1B,OUTPUT);
    pinMode(M2A,OUTPUT);
    pinMode(M2B,OUTPUT);
    pinMode(MC1,OUTPUT);
    pinMode(MC2,OUTPUT);
    myServo1.attach(S1);
    myServo2.attach(S2);
    analogWrite(MC1,255);
    analogWrite(MC2,255);
    myServo1.write(0);
    myServo2.write(0);
}

void loop()
{
  while(Serial.available()==0);
  inp=Serial.read();
  if(inp=='F'){
        forwrd();
  }else if(inp=='B'){
        bak();
  }else if(inp=='L'){
      left();
  }else if(inp=='R'){
        right();
  }else if(inp=='j'){
        fullTurn();
    }else if(inp=='W' || inp=='w'){
        servo1_increase();
    }else if(inp=='U' || inp=='u'){
        servo1_decrease();
    }else if(inp=='V' || inp=='v'){
        servo2_increase();
     }else if(inp=='X' || inp=='x'){
        servo2_decrease();
      }        
    else {
      off();
    }

}

void forwrd(){
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}


void bak(){
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,HIGH);
}


void left(){
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}
 

void right(){
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,LOW);
}


void off(){
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,LOW);
}

void fullTurn(){
    digitalWrite(M1A,LOW);
    digitalWrite(M1A,HIGH);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}

void servo1_increase(){
  s1++;
  myServo1.write(s1);
  }

void servo1_decrease(){
  s1--;
  myServo1.write(s1);
  }

void servo2_increase(){
  s2++;
  myServo2.write(s2);
  } 

void servo2_decrease(){
  s2--;
  myServo2.write(s2);
  }     
  
