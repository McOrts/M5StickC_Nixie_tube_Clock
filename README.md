# Nixie tube clock simulated on ESP32 using the device M5Stick-C
To build a Nixie tube clock is a perpetual project on my mind. But it requires high voltage, expensive and not easy to be wereable. So the feeling I wanted to see was made by software.

<img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/images/M5Stick-C.jpg" width="250" align="right" />

The perfect opportunity came up to me when I get the M5Stich-C. It is an amazing device based on ESP32 with a small LCD display of 80 × 160 pixel, but bright and clear. 

## Outcome

<img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/images/Nixie_Clock_M5StickC.gif" width="300"/>

The watch has three faces. You can switch betewen them using the M5 switch.
- <img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/images/Nixie_Clock_M5StickC_m1.gif" width="200"/>
- <img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/images/Nixie_Clock_M5StickC_m2.gif" width="200"/>
- <img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/images/Nixie_Clock_M5StickC_m3.gif" width="200"/>

## How to

<img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/images/M5Stick_Arduino_IDE.PNG" width="300" align="right" />

Previously, it is mandatory install the development environment. If you use the Arduino IDE, exists a perfect guide to start up the device : [M5StickC Quick Start - Arduino Win](https://docs.m5stack.com/#/en/quick_start/m5stickc/m5stickc_quick_start_with_arduino_Windows?id=_2-copy-the-following-esp32-boards-manager-url-to-additional-boards-manager-urls-hit-ok) 

finally this is the configuration that you need to compile the Arduino sketch of M5StickC_Nixie_tube_Clock that you have here in this repository.

Now only that you need is plug in the M5Stick whith the USB-C adaptor and load the program. 

### Update Nixie Tube images

<img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/lcd-image-converter/lcd_convert_s.jpg" align="right" />

Execute the lcd-image-converter.exe include in this repository.
1. Png or Jpg is read from File->Open Menu. The image will be displayed when loaded. 
2. Select: Option->Conversions Menu. The top Preset: selects "Color R5G6B5". 
3. Select: Image tap and select “8 bit” for Block size :. Press "OK". 
4. The example "vfd_35x67_8.c" is output by "Convert ..." in File-Convert Menu. 
Know in advance the destination path. 
Tick: Import All Images You can also output all the images with “Convert ... all”. 
5. Edit .c converted file. You will get an error as it is, so fix it with your editor. 
- Change: "Static const uint8_t image_data_vfd_35x67 [4690] = {" at the top of the file deleting "image_data_" as result of "static const uint8_t vfd_35x67_8 [4690] = {". 
- At the bottom of delete de entire line: "const tImage vfd_35x67 = {image_data_vfd_35x67, 35, 67, 8};
- Save the example "vfd_35x67_8".c

### Hardware components
The [M5Stick-C]() is a device with multiple components as processor, sensors, interrupters and LED. The processor features are:

|   |   |
|---|---|
|Microcontroler|ESP32 Pico|
|Frequency|240MHz|
|Flash|4MB|
|RAM|320KB|

- **I2C BM8563** : Realizes the RTC function. Address: 0x15. 
- **AXP192** :  power management IC. 
- **ST7735S** : LCD IPS Display 80 × 160 pixel, 0,96"
- **SH200Q** : IMU Movement and positioning 6 axis inertial sensor.
- **SPM1423** : PDM Micropohne
- **IR** : IR Transmitter

### Software components
- [Arduino IDE](https://www.hackster.io/arduino/products/arduino-ide?ref=project-8e87cc)
- ICONs files: [vfd_18x34.c](https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/vfd_18x34.c), [vfd_35x67.c](https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/vfd_35x67.c) <img src="https://github.com/McOrts/M5StickC_Nixie_tube_Clock/blob/master/images/vfd_35x67_5.png" align="left" />

