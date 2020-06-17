// 888b    | ,e,          ,e,           ,d88~~\   d8   ,e,         888   _
// |Y88b   |  "  Y88b  /   "   e88~~8e  8888    _d88__  "   e88~~\ 888 e~ ~
// | Y88b  | 888  Y88b/   888 d888  88b `Y88b    888   888 d888    888d8b
// |  Y88b | 888   Y88b   888 8888__888  `Y88b,  888   888 8888    888Y88b
// |   Y88b| 888   /Y88b  888 Y888    ,    8888  888   888 Y888    888 Y88b
// |    Y888 888  /  Y88b 888  "88___/  \__88P'  "88_/ 888  "88__/ 888  Y88b
// 
// by stephan.com 2020
// based on McOrts/M5StickC_Nixie_tube_Clock

// M5StickC Nixie tube Clock: 2019.06.06
// NixieStick refactored: 2020.06.20
#include <M5StickC.h>
#include <NixieStix.h>
#include <WiFi.h>
#include <strings_en.h>
#include <WiFiManager.h>
#include "ClockHMS.h"
#include "ClockMMSS.h"
#include "ClockDateTime.h"
#include "ClockVertical.h"

WiFiManager wifiManager;
const char* ntpServer = "time.google.com";

int mode = 0;

ClockMMSS vfd1;
ClockDateTime vfd2;
ClockHMS vfd3;
ClockVertical Vertical;

NixieStix <SmallNixie, 8> Counter(1,23,2);

void setup(void){ 
  M5.begin();
  pinMode(M5_BUTTON_HOME, INPUT);
  Clock::clear();
  M5.MPU6886.Init();
  M5.Lcd.setRotation(0);

  // wifiManager.resetSettings();
  wifiManager.autoConnect("NixieStick");

  // Set ntp time to local
  configTime(-5 * 3600L, 3600, ntpServer);

  // Get local time
  struct tm timeInfo;
  Serial.printf("Contacting ntp: %s\n", ntpServer);
  if (getLocalTime(&timeInfo)) {
    Serial.printf("received");
    // Set RTC time
    RTC_TimeTypeDef TimeStruct;
    TimeStruct.Hours   = timeInfo.tm_hour;
    TimeStruct.Minutes = timeInfo.tm_min;
    TimeStruct.Seconds = timeInfo.tm_sec;
    M5.Rtc.SetTime(&TimeStruct);

    RTC_DateTypeDef DateStruct;
    DateStruct.WeekDay = timeInfo.tm_wday;
    DateStruct.Month = timeInfo.tm_mon + 1;
    DateStruct.Date = timeInfo.tm_mday;
    DateStruct.Year = timeInfo.tm_year + 1900;
    M5.Rtc.SetData(&DateStruct);
  }

  //disconnect WiFi
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop(void){
  if(digitalRead(M5_BUTTON_HOME) == LOW){
    int startButton = millis();
    Clock::clear();
    M5.Lcd.setRotation(1);
    while(digitalRead(M5_BUTTON_HOME) == LOW) Counter.draw(millis() - startButton);
    mode++;
    Clock::clear();
  }

       if(mode == 0) { Vertical.draw(); }
  else if(mode == 1) { vfd3.draw(); }
  else if(mode == 2) { vfd2.draw(); }
  else if(mode == 4) { vfd1.draw(); } 
  else               { mode = 0; return; }

  delay(500);
}
