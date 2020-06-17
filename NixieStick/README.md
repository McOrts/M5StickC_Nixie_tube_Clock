```
888b    | ,e,          ,e,           ,d88~~\   d8   ,e,         888   _
|Y88b   |  "  Y88b  /   "   e88~~8e  8888    _d88__  "   e88~~\ 888 e~ ~
| Y88b  | 888  Y88b/   888 d888  88b `Y88b    888   888 d888    888d8b
|  Y88b | 888   Y88b   888 8888__888  `Y88b,  888   888 8888    888Y88b
|   Y88b| 888   /Y88b  888 Y888    ,    8888  888   888 Y888    888 Y88b
|    Y888 888  /  Y88b 888  "88___/  \__88P'  "88_/ 888  "88__/ 888  Y88b
```

# NixieStick

A simulated Nixie tube clock for the M5Stick-C
by [stephan.com](https://stephan.com/)

based on [McOrts/M5StickC_Nixie_tube_Clock](https://github.com/McOrts/M5StickC_Nixie_tube_Clock)

## Enhancements to McOrts/M5StickC_Nixie_tube_Clock

* Sets time automatically via NTP server
* WiFi configuration
* Orientation sensing
* Four clock faces
* Clean object-oriented design
* Hold button down for millisecond counter

## Requires libraries:

* [M5StickC](https://github.com/m5stack/M5StickC)
* [NixieStix](https://github.com/stephancom/NixieStix)
* [WiFiManager](https://github.com/tzapu/WiFiManager)

## TODO

* Time zone configuration via web UI
* enable/disable watch faces in web UI
* Select vertical/horizontal configuration via orientation
* More devices (M5StickC-Plus, M5Stack, LilyGo T-Watch)
* UDP time server/hub for other projects?
