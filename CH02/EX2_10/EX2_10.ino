#include <dht.h>
dht DHT;           //定義dht物件

#define DHT11_PIN 4 //定義DHT之訊號腳位接在Arduino D4
int threshold = 28; //觸發繼電器之邊界值

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);  //繼電器之訊號腳位
}

void loop()
{
  //顯示溫度與濕度
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);
  //根據溫度觸發繼電器
  if (DHT.temperature > threshold) {
    digitalWrite(13, HIGH);
    Serial.println("fan on");
  }
  else {
    digitalWrite(13, LOW);
    Serial.println("fan off");
  }
  delay(4000);
}

