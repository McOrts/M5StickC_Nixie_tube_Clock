//   ,88~-_          ,e,                      d8
//  d888   \  888-~\  "   e88~~8e  888-~88e _d88__
// 88888    | 888    888 d888  88b 888  888  888
// 88888    | 888    888 8888__888 888  888  888
//  Y888   /  888    888 Y888    , 888  888  888
//   `88_-~   888    888  "88___/  888  888  "88_/
//
// persistent orientation for M5StickC

#pragma once

#include <M5StickC.h>

#ifndef Orient_h
#define Orient_h

class Orient {
public:
  static void portrait();
  static void landscape();
  static void orient();
private:
  static int Rotation;
  static float accX, accY, accZ;
  static void fetch();
  static void setRotation(int r);
  static int whatPortrait();
  static int whatLandscape();
  static int whatOrientation();
};

#endif Orient_h
