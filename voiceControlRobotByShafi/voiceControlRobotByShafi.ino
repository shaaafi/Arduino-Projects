 void off();
 void forward();
 void back();
 void right();
 void left();
 void on();
  String input;
  int M1A=13,M1B =12,M2A=11,M2B=10,MC1=9,MC2=8;
  char c;
void setup() 
{
    pinMode(M1A,OUTPUT);  
    pinMode(M1B,OUTPUT);
    pinMode(M2A,OUTPUT);
    pinMode(M2B,OUTPUT);
    pinMode(MC1,OUTPUT);
    pinMode(MC2,OUTPUT);
    Serial.begin(9600);
    analogWrite(MC1,255);
    analogWrite(MC2,255);
}

void loop() 
{
    while(Serial.available()>0)
    {
          delay(10);
         c=Serial.read();
         if(c=='#')
         break;
         input+=c; 
    }    

    if(input=="*stop")
    off();
    else if(input=="*move")
    forward();
    else if(input=="*backward")
    back();
    else if(input=="*right")
    right();
    else if(input=="*left")
    left();
    else if(input=="*on")
    on();
    else
    off();
    input="";
}

void off()
{
   
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,LOW);
     
}

void forward()
{
    while(input!="*ok")
    {
      input="";
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
    while(Serial.available()>0)
    {
          delay(10);
         c=Serial.read();
         if(c=='#')
         break;
         input+=c; 
    }    
    
    }  
}

void back()
{
     while(input!="*ok")
    {
      input="";
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,HIGH);
    while(Serial.available()>0)
    {
          delay(10);
         c=Serial.read();
         if(c=='#')
         break;
         input+=c; 
    }    
    
    }  
}

void right()
{
    while(input!="*ok")
    {
      input="";
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,LOW);
    digitalWrite(M2A,LOW);
    digitalWrite(M2B,HIGH);
    while(Serial.available()>0)
    {
          delay(10);
         c=Serial.read();
         if(c=='#')
         break;
         input+=c; 
    }    
    
    }  
}

void left()
{
    while(input!="*ok")
    {
      input="";
    digitalWrite(M1A,LOW);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,LOW);
    while(Serial.available()>0)
    {
          delay(10);
         c=Serial.read();
         if(c=='#')
         break;
         input+=c; 
    }    
    
    }  
}

void on()
{
      while(input!="*ok")
    {
      input="";
    digitalWrite(M1A,HIGH);
    digitalWrite(M1B,HIGH);
    digitalWrite(M2A,HIGH);
    digitalWrite(M2B,HIGH);
    while(Serial.available()>0)
    {
          delay(10);
         c=Serial.read();
         if(c=='#')
         break;
         input+=c; 
    }    
    
    }  
}
