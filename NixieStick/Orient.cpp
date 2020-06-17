//   ,88~-_          ,e,                      d8
//  d888   \  888-~\  "   e88~~8e  888-~88e _d88__
// 88888    | 888    888 d888  88b 888  888  888
// 88888    | 888    888 8888__888 888  888  888
//  Y888   /  888    888 Y888    , 888  888  888
//   `88_-~   888    888  "88___/  888  888  "88_/
//
// persistent orientation for M5StickC

#include "Orient.h"
#include <M5StickC.h>

int Orient::Rotation;
float Orient::accX, Orient::accY, Orient::accZ;

void Orient::fetch() { M5.MPU6886.getAccelData(&accX,&accY,&accZ); }

void Orient::setRotation(int r) {
  if(r == Rotation) { return; }
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(r);
  Rotation = r;
}

int Orient::whatPortrait() {
  return accY > 0 ? 0 : 2;
}

int Orient::whatLandscape() {
  return accX > 0 ? 1 : 3;
}

int Orient::whatOrientation() {
  return fabs(accX) > fabs(accY) ? whatLandscape() : whatPortrait();
}

void Orient::portrait() {
  fetch();
  setRotation(whatPortrait());
}

void Orient::landscape() {
  fetch();
  setRotation(whatLandscape());
}

void Orient::orient() {
  fetch();
  setRotation(whatOrientation());
}
