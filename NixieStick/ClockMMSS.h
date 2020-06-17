//  e88~-_  888                  888   _        e    e           e    e      ,d88~~\ ,d88~~\
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~      d8b  d8b         d8b  d8b     8888    8888
// 8888     888 d888   i d888    888d8b       d888bdY88b       d888bdY88b    `Y88b   `Y88b
// 8888     888 8888   | 8888    888Y88b     / Y88Y Y888b     / Y88Y Y888b    `Y88b,  `Y88b,
// Y888   / 888 Y888   ' Y888    888 Y88b   /   YY   Y888b   /   YY   Y888b     8888    8888
//  "88_-~  888  "88_-~   "88__/ 888  Y88b /          Y888b /          Y888b \__88P' \__88P'
// 
// Minutes and Seconds
#pragma once

#include <M5StickC.h>
#include <NixieStix.h>
#include "Clock.h"

#ifndef ClockMMSS_h
#define ClockMMSS_h

class ClockMMSS : public Clock {
public:
  void draw();
private:
  static NixieStix <BigNixie,2> Minutes;
  static NixieStix <BigNixie,2> Seconds;
  void colon(unsigned int x, unsigned int y);
};

#endif
