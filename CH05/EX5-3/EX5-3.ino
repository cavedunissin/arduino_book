#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial I2CBT(10, 11);
byte serialA;

void setup() {
  //define pin modes for tx,rx pin
  Serial.begin(9600);
  I2CBT.begin(9600);
}

void loop () {
  byte Data[2];
  byte cmmd[20];
  int insize;
  int i = analogRead(A0); //讀取A0腳位狀態，也就是電位計
  serialA = I2CBT.read();
  Data[0] = 'a';
  Data[1] = i / 256;
  Data[2] = i % 256;
  Serial.println(i);
  if (serialA == 49) {
    for (int j = 0; j < 3; j++)
      I2CBT.write(Data[j]);
    serialA = 0;
  }
  delay(100);
}

