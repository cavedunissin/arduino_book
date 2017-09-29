#include <Bridge.h>
#include <BridgeSSLClient.h>
#include <ArduinoCloud.h>

//電流感測器相關設定
#define CURRENT_SENSOR A0  //電流感測器連接腳位
float amplitude_current;
float effective_value;
float effective_voltage = 110; //如果是歐洲地區請改為220
float effective_power;
float zero_sensor;


// Arduino Cloud 相關設定
const char userName[]   = "***"; //填入您的Arduino.cc使用者名稱
const char thingName[] = "%%%"; //填入您的thing名稱
const char thingId[]   = "XXX";  //填入您的 thingId
const char thingPsw[]  = "OOO";  //填入您的 thingPsw

BridgeSSLClient sslClient;

//建立一個 ArduinoCloudThing物件
ArduinoCloudThing  sensorTower;

void setup() {
  Serial.begin(115200);
  //於空電流時校正感測器
  zero_sensor = readCurrent();
  Serial.print("Zero point sensor: ");
  Serial.println(zero_sensor);
  Serial.println("");

  Serial.println("Starting Bridge");
  Bridge.begin();
  Serial.println("Done");

  sensorTower.begin(thingName, userName, thingId, thingPsw, sslClient);
  sensorTower.enableDebug();
  //定義property內容
  sensorTower.addProperty("light", INT, R);
}

void loop() {
  float sensor_value = readCurrent();  //呼叫自定義的感測器讀取函式
  Serial.print("Sensor value: ");
  Serial.println(sensor_value);

  //轉換為電流
  amplitude_current = (float)(sensor_value - zero_sensor) / 1024 * 5 / 185 * 1000000;
  effective_value = amplitude_current / 1.414;  //

  //顯示計算後資料
  Serial.println("Current amplitude (in mA): ");
  Serial.println(amplitude_current, 1);
  Serial.println("Current effective value (in mA)");
  Serial.println(effective_value, 1);
  Serial.println("Effective power (in W): ");
  Serial.println(abs(effective_value * effective_voltage / 1000), 1);

  delay(50);

  sensorTower.poll();
  sensorTower.writeProperty("light", sensor);
  //將資料發送到Arduino Cloud 的指定property: light
  delay(1000);
}

//讀取電流感測器數值
float readCurrent()
{
  int sensorValue;
  float avg = 0;
  int nb_measurements = 20;
  for (int i = 0; i < nb_measurements; i++) {
    sensorValue = analogRead(CURRENT_SENSOR);
    avg = avg + float(sensorValue);
  }
  avg = avg / float(nb_measurements);
  return avg;
}

