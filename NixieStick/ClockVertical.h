//  e88~-_  888                  888   _   Y88b      /                    d8   ,e,                   888
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~   Y88b    /   e88~~8e  888-~\ _d88__  "   e88~~\   /~~~8e  888
// 8888     888 d888   i d888    888d8b      Y88b  /   d888  88b 888     888   888 d888          88b 888
// 8888     888 8888   | 8888    888Y88b      Y888/    8888__888 888     888   888 8888     e88~-888 888
// Y888   / 888 Y888   ' Y888    888 Y88b      Y8/     Y888    , 888     888   888 Y888    C888  888 888
//  "88_-~  888  "88_-~   "88__/ 888  Y88b      Y       "88___/  888     "88_/ 888  "88__/  "88_-888 888

#pragma once

#include <M5StickC.h>
#include <NixieStix.h>
#include "Clock.h"

#ifndef ClockVertical_h
#define ClockVertical_h

class ClockVertical : public Clock {
public:
  void draw();
private:
  static NixieStix <SmallNixie,4>    Year;
  static NixieStix <SmallNixie,2>   Month;
  static NixieStix <SmallNixie,2>    Date;
  static NixieStix <SmallNixie,2>   Hours;
  static NixieStix <SmallNixie,2> Minutes;
  // static NixieStix <SmallNixie,2> Seconds;
  void colon(unsigned int x, unsigned int y);
};

#endif
