#include <Arduino.h>

void straight();
void bak();
void left();
void right();
void off();
void fullTurn();
void slightRight();
void slightLeft();

int sensor[7]={0};
thr=550;
int reading[]={A0,A1,A2,A3,A4,A5,A6,A7};
int M1A=2,M1B=3,M2A=5,M2B=6,MC1=8,MC2=9;
int i;
byte junc[20]={0};
byte j=0;


void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);
  pinMode(M1A,OUTPUT);
    pinMode(M1B,OUTPUT);
    pinMode(M2A,OUTPUT);
    pinMode(M2B,OUTPUT);
    pinMode(MC1,OUTPUT);
    pinMode(MC2,OUTPUT);
}

void loop() {
  sensorRead();
  if(){
    
    }else if((sensor[5]>thr && sensor[6]<thr && sensor[7]>thr) || (sensor[0]>thr && sensor[1]>thr && sensor[2]<thr && sensor[3]>thr && sensor[4]>thr && sensor[5]>thr && sensor[6]>thr && sensor[7]>thr)){
     straight();
    }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]>thr && sensor[3]>thr && sensor[4]>thr && sensor[5]>thr && sensor[6]<thr && sensor[7]<thr){
      right();
      }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]>thr && sensor[3]>thr && sensor[4]>thr && sensor[5]<thr && sensor[6]<thr && sensor[7]>thr){
      left();
      }else if(sensor[0]>thr && sensor[1]<thr && sensor[2]>thr && sensor[3]>thr && sensor[4]>thr){
      slightLeft();
      }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]>thr && sensor[3]<thr && sensor[4]>thr){
      slightRight();
      }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]>thr && sensor[3]>thr && sensor[4]>thr && sensor[5]>thr && sensor[6]<thr && sensor[7]>thr){
        while(sensor[2]>thr){
          fullTurn();
          }
          j--;
      }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]<thr && sensor[3]>thr && sensor[4]>thr && sensor[5]<thr && sensor[6]<thr && sensor[7]<thr){
        left();
        j++;
        junc[j]+=1;
        }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]>thr && sensor[3]>thr && sensor[4]>thr && sensor[5]<thr && sensor[6]<thr && sensor[7]<thr){
          j++;
          left();
          junc[j]+=1;
          }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]<thr && sensor[3]>thr && sensor[4]>thr && sensor[5]<thr && sensor[6]<thr && sensor[7]>thr){
          j++;
          left();
          junc[j]+=1;
          }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]<thr && sensor[3]>thr && sensor[4]>thr && sensor[5]>thr && sensor[6]<thr && sensor[7]<thr){
          j++;
          straight();
          junc[j]+=2;
          }else if(sensor[0]<thr && sensor[1]>thr && sensor[2]>thr && sensor[3]>thr && sensor[4]>thr && sensor[5]>thr && sensor[6]<thr && sensor[7]>thr){
      left();
      }else if(sensor[0]>thr && sensor[1]>thr && sensor[2]>thr && sensor[3]>thr && sensor[4]<thr && sensor[5]>thr && sensor[6]<thr && sensor[7]>thr){
      right();
      }                              
          
        
      

}

void straight(){
  analogWrite(MC1,255);
    analogWrite(MC2,255);
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}


void bak(){
  analogWrite(MC1,255);
    analogWrite(MC2,255);
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,HIGH);
}


void left(){
  analogWrite(MC1,255);
    analogWrite(MC2,255);
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}

 void slightLeft(){
    analogWrite(MC1,140);
    analogWrite(MC2,220);
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}


void right(){
  analogWrite(MC1,255);
    analogWrite(MC2,255);
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,LOW);
}

 void slightRight(){
    analogWrite(MC1,220);
    analogWrite(MC2,130);
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}


void off(){
   digitalWrite(M1A,LOW);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,LOW);
}

void fullTurn(){
   analogWrite(MC1,255);
    analogWrite(MC2,255);
    digitalWrite(M1A,LOW);
    digitalWrite(M1A,HIGH);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
}

void sensorRead(){
  for(i=0 ; i<8 ; i++){
    sensor[i]=analogRead(reading[i]);
    }
  }
