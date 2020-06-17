//  e88~-_  888                  888   _   888   |      e    e      ,d88~~\
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~  888___|     d8b  d8b     8888
// 8888     888 d888   i d888    888d8b    888   |    d888bdY88b    `Y88b
// 8888     888 8888   | 8888    888Y88b   888   |   / Y88Y Y888b    `Y88b,
// Y888   / 888 Y888   ' Y888    888 Y88b  888   |  /   YY   Y888b     8888
//  "88_-~  888  "88_-~   "88__/ 888  Y88b 888   | /          Y888b \__88P'
// 
// Hours, Minutes, and Seconds
#pragma once

#include <M5StickC.h>
#include <NixieStix.h>
#include "Clock.h"

#ifndef ClockHMS_h
#define ClockHMS_h

class ClockHMS : public Clock {
public:
  void draw();
private:
  static NixieStix   <BigNixie,2> Hours;
  static NixieStix   <BigNixie,2> Minutes;
  static NixieStix <SmallNixie,2> Seconds;
  void colon(unsigned int x, unsigned int y);
};

#endif
