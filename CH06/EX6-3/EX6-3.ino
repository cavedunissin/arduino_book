#define motorIn1  3     //L293D 的 input 1 接到Arduino的#3腳位
#define motorIn2  5     //L293D 的 input 2 接到Arduino的#5腳位
#define motorIn3  6     //L293D 的 input 3 接到Arduino的#6腳位
#define motorIn4  9     //L293D 的 input 4 接到Arduino的#9腳位
int data = 0;            //KY-033感測器讀數

void setup()
{
  Serial.begin(9600);   //USB
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);
  pinMode(10, OUTPUT);  //PWM
  pinMode(11, OUTPUT);  //PWM
}

void loop()
{
  data = analogRead(A2);  //更新感測器讀數
  if (data > 600) { //偵測到黑線, 左轉
    left();
  }
  else {
    right();
  }
  delay(200);
}//loop

void left()      //左轉之副程式
{
  Serial.println("left");
  analogWrite(10, 255);  //設定左輪轉速為 100%
  analogWrite(11, 154);  //設定右輪轉速為 60%
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, HIGH);
  digitalWrite(motorIn4, LOW);
}

void right()         //右轉之副程式
{
  Serial.println("right");
  analogWrite(10, 154);  //設定左輪轉速為 60%
  analogWrite(11, 255);  //設定右輪轉速為 100%
  digitalWrite(motorIn1, HIGH);
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, HIGH);
  digitalWrite(motorIn4, LOW);
}

