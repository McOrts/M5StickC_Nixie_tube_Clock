//  e88~-_  888                  888   _
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~
// 8888     888 d888   i d888    888d8b
// 8888     888 8888   | 8888    888Y88b
// Y888   / 888 Y888   ' Y888    888 Y88b
//  "88_-~  888  "88_-~   "88__/ 888  Y88b
// 
// a series of tubes, telling the time.

#include "Clock.h"

RTC_TimeTypeDef Clock::RTC_TimeStruct;
RTC_DateTypeDef Clock::RTC_DateStruct;

void Clock::getTime() {
  M5.Rtc.GetTime(&RTC_TimeStruct);  
}

void Clock::getDate() {
  M5.Rtc.GetData(&RTC_DateStruct);
}

void Clock::clear() {
  M5.Lcd.fillScreen(BLACK);
}

void Clock::dot(unsigned int x, unsigned int y) {
  M5.Lcd.drawPixel( x, y,  ORANGE);
  M5.Lcd.drawPixel( x, y-1,YELLOW);
}

void Clock::fade() {
  for (int i=7;i<16;i++){M5.Axp.ScreenBreath(i);delay(25);}
  for (int i=15;i>7;i--){M5.Axp.ScreenBreath(i);delay(25);}
  M5.Axp.ScreenBreath(12);
}
