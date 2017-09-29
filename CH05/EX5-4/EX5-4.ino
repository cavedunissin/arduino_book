#include <IRremote.h>   //使用IRRemote 函式庫
IRsend irsend;           // 定義 IRsend 物件來發射紅外線訊號

void setup()
{
  Serial.begin(9600);    // 設定通訊速率為 9600 bps
}

void loop()
{
  if (Serial.available() > 0)
  {
    char c = Serial.read();
    if (c == '1')
    {
      irsend.sendNEC(0x511DBB, 32);    //傳送紅外線NEC協定資料
    }
    else if (c == '0')
    {
      irsend.sendNEC(0xA3C8EDDB, 32);  //傳送紅外線NEC協定資料
    }
  }
}

