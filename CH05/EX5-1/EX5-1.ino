#include <SoftwareSerial.h>
#include <Wire.h>

int LED = 13;
SoftwareSerial I2CBT(10, 11);

void setup() {
  Serial.begin(9600);
  I2CBT.begin(9600);//bluetooth baud rate
  pinMode(LED, OUTPUT);
}

void loop() {
  byte cmmd[20];
  int insize;
  while (1) {
    //讀取藍牙訊息
    if ((insize = (I2CBT.available())) > 0) {
      Serial.print("input size = ");
      Serial.println(insize);
      for (int i = 0; i < insize; i++) {
        Serial.print(cmmd[i] = char(I2CBT.read()));
        Serial.print("\n");
      }//for
    }//if
    switch (cmmd[0]) {
      case 97: //"a"
        digitalWrite(LED, HIGH);
        break;
      case 98://"b"
        digitalWrite(LED, LOW);
        break;
    } //switch
  } //while
}
