#define CURRENT_SENSOR A0

// Define measurement variables
float amplitude_current;
float effective_value;
float effective_voltage = 110; // Set voltage to 230V (Europe) or 110V (US)
float effective_power;
float zero_sensor;

void setup(void)
{
  Serial.begin(115200);

  // Calibrate sensor with null current
  zero_sensor = readCurrent();
  Serial.print("Zero point sensor: ");
  Serial.println(zero_sensor);
  Serial.println("");
}

void loop(void)
{
  // Perform power measurement
  float sensor_value = readCurrent();  //呼叫自定義的感測器讀取函式
  Serial.print("Sensor value: ");
  Serial.println(sensor_value);

  //轉換為電流
  amplitude_current = (float)(sensor_value - zero_sensor) / 1024 * 5 / 185 * 1000000;
  effective_value = amplitude_current / 1.414;

  //顯示計算後資料
  Serial.println("Current amplitude (in mA): ");
  Serial.println(amplitude_current, 1);
  Serial.println("Current effective value (in mA)");
  Serial.println(effective_value, 1);
  Serial.println("Effective power (in W): ");
  Serial.println(abs(effective_value * effective_voltage / 1000), 1);

  delay(50);
}

//讀取感測器數值
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
