//  e88~-_  888                  888   _   Y88b      /                    d8   ,e,                   888
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~   Y88b    /   e88~~8e  888-~\ _d88__  "   e88~~\   /~~~8e  888
// 8888     888 d888   i d888    888d8b      Y88b  /   d888  88b 888     888   888 d888          88b 888
// 8888     888 8888   | 8888    888Y88b      Y888/    8888__888 888     888   888 8888     e88~-888 888
// Y888   / 888 Y888   ' Y888    888 Y88b      Y8/     Y888    , 888     888   888 Y888    C888  888 888
//  "88_-~  888  "88_-~   "88__/ 888  Y88b      Y       "88___/  888     "88_/ 888  "88__/  "88_-888 888

#include "ClockVertical.h"
#include "Orient.h"
  NixieStix <SmallNixie,2>   ClockVertical::Hours(  0, 10, 1);
  NixieStix <SmallNixie,2> ClockVertical::Minutes( 41, 10, 1);
  // NixieStix <SmallNixie,2> ClockVertical::Seconds(120, 40, 2);

  NixieStix <SmallNixie,2>   ClockVertical::Month(  0, 80, 1);
  NixieStix <SmallNixie,2>    ClockVertical::Date( 41, 80, 1);
  NixieStix <SmallNixie,4>    ClockVertical::Year(  1,120, 1);

void ClockVertical::colon(unsigned int x, unsigned int y) {
  dot(x, y); dot(x, y+10);
}

void ClockVertical::draw() {
  Orient::portrait();
  getTime();

    Hours.draw(RTC_TimeStruct.Hours);
         colon(39,25);
  Minutes.draw(RTC_TimeStruct.Minutes);
  // Seconds.draw(RTC_TimeStruct.Seconds);
  
  getDate();
  Month.draw(RTC_DateStruct.Month);
        colon(39,95);
   Date.draw(RTC_DateStruct.Date);
   Year.draw(RTC_DateStruct.Year);
  
  if(RTC_TimeStruct.Seconds == 0) { fade(); }
}
