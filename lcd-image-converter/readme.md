LCD Image Converter
Tool to create bitmaps and fonts for embedded applications, v.2

Allows you to create bitmaps and fonts, and transform them to "C" source format for embedded applications.

## Features
- Supported display controllers
  - Monochrome, grayscale, color
  - With vertical and horizontal orientation of bytes
  - 8, 16, 24, 32-bit data
  - 1...32 bits per pixel
  - and other, not limited by some particular models
- Output format
  - Can be changed by templates
  - Text (source code) or binary
- Create a single image
  - With RLE compression
- Create fonts (set of images - characters)
  - Including unicode charset
  - Required characters only, not full range
- Command-line mode

## Web pages
- [Home web site](http://www.riuson.com/lcd-image-converter)
  - [Documentation](http://www.riuson.com/lcd-image-converter)
  - [Latest downloads](http://www.riuson.com/lcd-image-converter/download)
  - [Changelog](http://www.riuson.com/lcd-image-converter/changelog)
- [Source code repository on GitHub](https://github.com/riuson/lcd-image-converter)

## Contacts and support
 - Author: Vladimir
 - Mailto: riuson@gmail.com
 - [GitHub Issues](https://github.com/riuson/lcd-image-converter/issues)

## How to build on GNU/Linux
~~~
git clone https://github.com/riuson/lcd-image-converter.git ~/lcd-image-converter
cd ~/lcd-image-converter
qmake
make
~~~
Requires some additional packages.
Build logs available on [Travis-CI](https://travis-ci.org/riuson/lcd-image-converter).



## License

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/

## How to

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
