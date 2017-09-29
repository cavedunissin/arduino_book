#include <Servo.h>
Servo myservo1; // 底盤旋轉馬達
Servo myservo2; // 後臂升降馬達
Servo myservo3; // 前臂馬達
Servo myservo4; // 夾爪馬達

void setup()
{
  Serial.begin(9600);
  myservo1.attach(3); // 底盤旋轉馬達設定為Pin3
  myservo2.attach(6); // 後臂升降馬達設定為Pin6
  myservo3.attach(9); // 前臂馬達設定為Pin9
  myservo4.attach(10);// 夾爪馬達設定為Pin10
}
void loop()
{
  int s1, s2, s3, s4;
  // 將搖桿的數值儲存於s1,s2,s3,s4
  //每一個搖桿中點的數值會由些微的不同
  s1 = analogRead(A0); // Pin A0:搖桿1，由左至右為0~1023 , 中點約在510
  s2 = analogRead(A1); // Pin A1:搖桿1，由前往後為0~1023, 中點約在499
  s3 = analogRead(A2); // Pin A2:搖桿2 由前往後為0~1023 ,中點約在490
  s3 = analogRead(A3); // Pin A3:搖桿2 由左至右為0~1023，中點約511
  Serial.print("analogRead: ");
  Serial.print(s1); // 將搖桿的四個可變電阻值顯示於監視窗
  Serial.print(",");
  Serial.print(s2);
  Serial.print(",");
  Serial.print(s3);
  Serial.print(",");
  Serial.println(s4);
  //底座控制，運動角度為50~180度
  s1 = map(s1, 0, 1023, 50, 180);
  //直接把轉換過的角度寫入servo1，控制底座旋轉
  Serial.print("motor angle : ");
  myservo1.write(s1);
  Serial.print(" Servo1:");
  Serial.print(s1);
  Serial.print(",");

  // 後臂控制，運動角度為50~150 度
  s2 = map(s2, 0, 1023, 50, 150);
  myservo1.write(s2);
  Serial.print(" Servo2:");
  Serial.print(s2);
  Serial.print(",");

  // 前臂控制，運動角度對應到70~180 度
  s3 = map(s3, 0, 1023, 40, 140);
  myservo2.write(s3);
  Serial.print(" Servo3:");
  Serial.print(s3);
  Serial.print(",");

  // 夾爪控制，打開和閉合的運動角度對應到60~120
  s4 = map(s4, 0, 1023, 60, 120);
  myservo4.write(s4);
  Serial.print(" Servo4:");
  Serial.println(s4);
  delay(50);
}


