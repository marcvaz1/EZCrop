#include <SoftwareSerial.h>
#include <Servo.h>
Servo servo1;
SoftwareSerial BTserial(3,2); //(Rx, Tx)

int WaterButtonPin = A1;
int WaterButtonState = 0;
int thermPin = A0;
int moistPin1 = A3;
int moistPin2 = A4;
int moistPin3 = A5;
int flag = 0;
int servoPin = 9;
int thermValue = 0;
int moistVal1 = 0;
int moistVal2 = 0;
int moistVal3 = 0;
int normTemp = 0;
int realTemp = 0;
int motor1pin1 = 10;
int motor1pin2 = 11;
int manualPin = A2;
int t1 = 7;
int manualButton = 0;
int s1 = 0;
int manState = 0;
int servoState = 0;

String outstr = "";


void setup() {
  BTserial.begin(9600); // open the bluetooth serial port
  Serial.begin(9600);
  servo1.attach(servoPin);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(t1, INPUT);
}



void loop() {
  //initialize

WaterButtonState = digitalRead(WaterButtonPin);
manualButton = digitalRead(manualPin);
s1 = digitalRead(t1);
thermValue = analogRead(thermPin);
moistVal1 = analogRead(moistPin1);
moistVal2 = analogRead(moistPin2);
moistVal3 = analogRead(moistPin3);
if(flag == 0)
{
  normTemp = thermValue;
  flag = 1;
}

realTemp = thermValue - normTemp;
outstr = "Temperature Variance: ";
outstr += realTemp;
outstr += ", ";
outstr += "Moisture 1: ";
outstr += moistVal1;
outstr += ", ";
outstr += "Moisture 2: ";
outstr = outstr + moistVal2;
outstr += ", ";
outstr += "Moisture 3: ";
outstr = outstr + moistVal3;
//BTserial.println(outstr);
Serial.println(outstr);


if(manualButton == HIGH)
{
 if(s1 == HIGH)
 {
    if(servoState == 0)
    {
      servo1.write(100);
      servoState = 1;
    }
    else if (servoState == 1)
    {
      servo1.write(120);
      servoState = 2;
    }
    else
    {
      servo1.write(40);
      servoState = 0;
    }
 }
}
else
{

  //AUTOMATED TEMP
  if(thermValue > normTemp + 50)
  {
     servo1.write(40);
     servoState = 0;
  }
  else if (thermValue < normTemp - 50)
  {
     servo1.write(120);
     servoState = 2;
  }
  else
  {
     servo1.write(100);
     servoState = 1;
  } 
}


    //AUTOMATED WATER
if((moistVal1 + moistVal2 + moistVal3)/3 < 600 || WaterButtonState == HIGH){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  delay(5000);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
}
delay(1000);
}
