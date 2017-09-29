int Data = 0;
void setup()
{
  Serial.begin(9600);  //開啟通訊
}
void loop()
{
  if (Serial.available() > 0)
  {
    Data = Serial.read();    //讀取通訊訊息
  }
  switch (Data)
  {
    case 'f':  //前進
      MotorControl(0, 200);
      MotorControl(1, 200);
      break;
    case 'l':  //左轉
      MotorControl(0, 100);
      MotorControl(1, 200);
      break;
    case 'r':  //右轉
      MotorControl(0, 200);
      MotorControl(1, 100);
      break;
    case 'b':  //後退
      MotorControl(0, -200);
      MotorControl(1, -200);
      break;
    case 's':  //停止
      MotorControl(0, 0);
      MotorControl(1, 0);
      break;
  }
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
