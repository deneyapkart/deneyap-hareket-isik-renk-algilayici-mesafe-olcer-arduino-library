# Deneyap Gesture, Color, Proximity Sensor Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap Gesture, Color, Proximity Sensor APDS9960

## :mag_right:Specifications 
- `Product ID` **M25** , **mpv1.0**
- `MCU` APDS-9960
- `Weight` 
- `Module Dimension` 25,4 mm x 25,4 mm
- `I2C address` 0x39

| Address |  | 
| :---    | :---     |
| 0x39 | default address |

## :closed_book:Documentation
[Deneyap Gesture, Color, Proximity Sensor](https://docs.deneyapkart.org/en/content/contentDetail/deneyap-modul-deneyap-hareket-isk-renk-alglayc-ve)

[Deneyap Gesture, Color, Proximity Sensor Shematic](https://cdn.deneyapkart.org/media/upload/userFormUpload/siVrurpuG9sb9DMKQPnCD6H5vYXWXsD0.pdf)

[Deneyap Gesture, Color, Proximity Sensor Mechanical Drawing](https://cdn.deneyapkart.org/media/upload/userFormUpload/Zi33d127Omdb0DTZ2rR3EvV1uwp4Ul5j.pdf)

[APDS-9960_datasheet](https://docs.broadcom.com/doc/AV02-4191EN)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap Gesture, Color, Proximity Sensor APDS9960
This Arduino library allows you to use Deneyap Gesture, Color, Proximity Sensor APDS9960 with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.1 - updated funtion(enableGesture) and comment line in examples

1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap Gesture, Color, Proximity Sensor and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|APDS9960| Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|SDA  | I2C Data  | SDA pin |
|SCL  | I2C Clock | SCL pin |
|INT  | Interrput  |   | 

## License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-hareket-isik-renk-algilayici-mesafe-olcer-arduino-library/blob/master/LICENSE) file for license information.

This code is partly based on the Adafruit APDS9960 Proximity, Light, RGB, and Gesture sensor Arduino Library.
Changed to work with Deneyap Gesture, Color, Proximity Sensor APDS9960 Arduino Library.
Following their requirements, here is the Adafruit README file:

 Adafruit_APDS9960 Build Status

This is the Adafruit APDS9960 Proximity, Light, RGB, and Gesture sensor Library

Tested and works great with the Adafruit APDS9960 Board

http://www.adafruit.com/products/3595
This chip uses I2C to communicate, 2 pins are required to interface

Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

Written by Dean Miller, Limor Fried for Adafruit Industries.
BSD license, check license.txt for more information All text above must be included in any redistribution

To install, use the Arduino Library Manager and search for "Adafruit APDS9960 Library" and install the library.