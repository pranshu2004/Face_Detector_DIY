#include <cvzone.h>
#include <Servo.h>

SerialData serialData(1,1);
int valsRec[1];

Servo sm;

void setup() {
  sm.attach(9);
  serialData.begin();
  pinMode(6,OUTPUT);
	pinMode(7,OUTPUT);
}

void loop() {
  serialData.Get(valsRec);
  if (valsRec[0]==1){
    sm.write(180);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else{
    delay(1000);
    serialData.Get(valsRec);
    if (valsRec[0]==0){
      sm.write(80);
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
  }
  }
}