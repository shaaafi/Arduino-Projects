int a[]={A0,A1,A2,A3,A4,A5,A6,A7};
int reading[8]={0};
int i;
void setup() { 
  analogReference(DEFAULT);
  Serial.begin(9600);
}

void loop() {
  for(i=0 ; i<8 ; i++) {
    reading[i]=analogRead(a[i]);}
 for(i=0;i<8;i++) {
  Serial.print(reading[i]);
  Serial.print("   ");
  
}
Serial.println("");
delay(500);
}
