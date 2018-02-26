int buzzer=11;
int sec=0,minu=0,hour=0;

void setup() {
  // put your setup code here, to run once:
pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
sec++;
delay(1000);
if(sec==60)
{
  sec=0;
  minu++;
  if(minu==5 )
  {
    digitalWrite(buzzer,HIGH);
    delay(2000);
    //digitalWrite(buzzer,LOW);
    minu=0;
    }
  }

}
