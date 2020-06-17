//  e88~-_  888                  888   _
// d888   \ 888  e88~-_   e88~~\ 888 e~ ~
// 8888     888 d888   i d888    888d8b
// 8888     888 8888   | 8888    888Y88b
// Y888   / 888 Y888   ' Y888    888 Y88b
//  "88_-~  888  "88_-~   "88__/ 888  Y88b
// 
// a series of tubes, telling the time.
#pragma once

#include <M5StickC.h>

#ifndef Clock_h
#define Clock_h

class Clock {
public:
  static void clear();
  virtual void draw() = 0;
protected:
  Clock() {};
  static void getTime();
  static void getDate();
  static void dot(unsigned int x, unsigned int y);
  static void fade();
  static RTC_TimeTypeDef RTC_TimeStruct;
  static RTC_DateTypeDef RTC_DateStruct;
  virtual void colon(unsigned int x, unsigned int y) = 0;
};

#endif
