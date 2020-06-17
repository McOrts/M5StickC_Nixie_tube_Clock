//  e88~-_  888                  888   _   888   |      e    e      ,d88~~\
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~  888___|     d8b  d8b     8888
// 8888     888 d888   i d888    888d8b    888   |    d888bdY88b    `Y88b
// 8888     888 8888   | 8888    888Y88b   888   |   / Y88Y Y888b    `Y88b,
// Y888   / 888 Y888   ' Y888    888 Y88b  888   |  /   YY   Y888b     8888
//  "88_-~  888  "88_-~   "88__/ 888  Y88b 888   | /          Y888b \__88P'
// 
// Hours, Minutes, and Seconds

#include "ClockDateTime.h"
#include "Orient.h"
  NixieStix <SmallNixie,4>    ClockDateTime::Year(  0, 0, 1);
  NixieStix <SmallNixie,2>   ClockDateTime::Month( 80, 0, 1);
  NixieStix <SmallNixie,2>    ClockDateTime::Date(120, 0, 2);
  NixieStix <SmallNixie,2>   ClockDateTime::Hours(  0,40, 2);
  NixieStix <SmallNixie,2> ClockDateTime::Minutes( 60,40, 2);
  NixieStix <SmallNixie,2> ClockDateTime::Seconds(120,40, 2);

void ClockDateTime::colon(unsigned int x, unsigned int y) {
  dot(x, y); dot(x, y+10);
}

void ClockDateTime::draw() {
  Orient::landscape();
  getDate();

   Year.draw(RTC_DateStruct.Year);
        colon( 77,13);
  Month.draw(RTC_DateStruct.Month);
        colon(118,13);
   Date.draw(RTC_DateStruct.Date);
  
  getTime();
    Hours.draw(RTC_TimeStruct.Hours);
         colon( 48,54);
  Minutes.draw(RTC_TimeStruct.Minutes);
         colon(108,54);
  Seconds.draw(RTC_TimeStruct.Seconds);
  
  if(RTC_TimeStruct.Seconds == 0) { fade(); }
}
