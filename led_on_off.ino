char blueToothVal;           //value sent over via bluetooth
char lastValue;              //stores last state of device (on/off)
int sig;
 
void setup()
{
 Serial.begin(9600); 
 pinMode(13,OUTPUT);
 sig = HIGH;
}


void loop1()
{
  if (sig==LOW) 
  {
    sig = HIGH;
  }
  else
  {
    sig = LOW;
  }
  digitalWrite(13,sig);
  delay(1000);
 /* 
  else if (blueToothVal=='f')
  {//if value from bluetooth serial is n
    digitalWrite(13,LOW);             //turn off LED
    if (lastValue!='f')
      Serial.println(F("LED is off")); //print LED is on
    lastValue=blueToothVal;
  }
  delay(1000);
  */
} 
 
void loop()
{
  Serial.print(F("Checking input\n"));
  if(Serial.available()>0)
  {//if there is data being recieved
    blueToothVal=Serial.read(); //read it
  }
 if (blueToothVal=='n')
  {//if value from bluetooth serial is n
    digitalWrite(13,HIGH);            //switch on LED
    if (lastValue!='n')
      Serial.println(F("LED is on")); //print LED is on
    lastValue=blueToothVal;
    delay(500);
    digitalWrite(13,LOW);   
    blueToothVal='\0';
    Serial.println(F("LED is off")); //print LED is off
  }
  delay(1000);
 /* 
  else if (blueToothVal=='f')
  {//if value from bluetooth serial is n
    digitalWrite(13,LOW);             //turn off LED
    if (lastValue!='f')
      Serial.println(F("LED is off")); //print LED is on
    lastValue=blueToothVal;
  }
  delay(1000);
  */
}
