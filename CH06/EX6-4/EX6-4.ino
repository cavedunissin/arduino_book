#define motorIn1  5
//右邊馬達，L293D 的 input 1 接到Arduino的#5腳位
#define motorIn2  6
//右邊馬達，L293D 的 input 2 接到Arduino的#6腳位
#define motorIn3  9
//左邊馬達，L293D 的 input 3 接到Arduino的#9腳位
#define motorIn4  10
//左邊馬達，L293D 的 input 4 接到Arduino的#10腳位

//ultrasonic
int trig = 3;   // Trig腳位接到digital 3
int echo = 4;   // Echo腳位接到digital 4
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);
  //設定馬達控制晶片連接之腳位模式
  pinMode(trig, OUTPUT);  //設定超音波模組連接之腳位模式
  pinMode(echo, INPUT);
}

void loop()
{
  ultrasonic();      //呼叫超音波測量距離的副函式
  if (distance < 20) //距離低於20cm，後退後往右轉
  {
    backward();
    delay(2000);
    right();
    delay(500);
  }
  else                //距離大於20cm，前進
  {
    forward();
    delay(1000);
  }
}//loop

void ultrasonic()
{
  digitalWrite(trig, LOW);    //送出低電位2us
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);   //送出高電位10us
  delayMicroseconds(10);    //等待10us讓模組準備好發出超音波
  digitalWrite(trig, LOW);   //時間到立刻設定為LOW
  distance = pulseIn(echo, HIGH);
  //等待超音波回波讀取，並量取所經過的時間長短
  distance = distance / 58;        // 轉換為CM

  Serial.print(distance);
  Serial.println(" cm.");
  delay(100);
}

void forward()         //前進之副程式
{
  Serial.println("Forward");
  digitalWrite(motorIn1, HIGH);  //右輪正轉
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn3, HIGH);  //左輪正轉
  digitalWrite(motorIn4, LOW);
}

void backward()         //後退之副程式
{
  Serial.println("Backward");
  digitalWrite(motorIn1, LOW);  //右輪反轉
  digitalWrite(motorIn2, HIGH);
  digitalWrite(motorIn3, LOW);  //左輪反轉
  digitalWrite(motorIn4, HIGH);
}

void right()         //右轉之副程式
{
  Serial.println("Right");
  digitalWrite(motorIn1, LOW);  //右輪反轉
  digitalWrite(motorIn2, HIGH);
  digitalWrite(motorIn3, HIGH);  //左輪正轉
  digitalWrite(motorIn4, LOW);
}

