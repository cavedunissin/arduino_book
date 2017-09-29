#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial I2CBT(10, 11); // RX,  TX
void setup() {
  Serial.begin(9600);
  I2CBT.begin(9600);    //藍牙鮑率
  pinMode(9, OUTPUT);
}

void loop() {
  byte cmmd[20];
  int insize;
  int a = 0;
  while (1) {
    if ((insize = (I2CBT.available())) > 0) {
      Serial.print("input size = ");
      Serial.println(insize);
      for (int i = 0; i < insize; i++) {
        Serial.print(cmmd[i] = char(I2CBT.read()));
      }
      Serial.println("\n");
    }//if
  }//while
}//loop

