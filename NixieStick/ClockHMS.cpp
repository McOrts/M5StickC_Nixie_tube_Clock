//  e88~-_  888                  888   _   888   |      e    e      ,d88~~\
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~  888___|     d8b  d8b     8888
// 8888     888 d888   i d888    888d8b    888   |    d888bdY88b    `Y88b
// 8888     888 8888   | 8888    888Y88b   888   |   / Y88Y Y888b    `Y88b,
// Y888   / 888 Y888   ' Y888    888 Y88b  888   |  /   YY   Y888b     8888
//  "88_-~  888  "88_-~   "88__/ 888  Y88b 888   | /          Y888b \__88P'
// 
// Hours, Minutes, and Seconds

#include "ClockHMS.h"
#include "Orient.h"
  NixieStix   <BigNixie,2>   ClockHMS::Hours(  2, 6, 4);
  NixieStix   <BigNixie,2> ClockHMS::Minutes( 83, 6, 4);
  NixieStix <SmallNixie,2> ClockHMS::Seconds(120,45, 2);

void ClockHMS::colon(unsigned int x, unsigned int y) {
  dot(x, y); dot(x, y+26);
}

void ClockHMS::draw() {
  Orient::landscape();
  getTime();

    Hours.draw(RTC_TimeStruct.Hours);
          colon(79,22);
  Minutes.draw(RTC_TimeStruct.Minutes);
  Seconds.draw(RTC_TimeStruct.Seconds);
  
  if(RTC_TimeStruct.Seconds == 0) { fade(); }    
}
