/*
*****************************************************************************
@file         Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.cpp
@mainpage     Deneyap Gesture, Color, Proximity Sensor Arduino 
              library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.1
@date         November 08, 2022
@brief        Includes functions to control Deneyap Gesture, Color, Proximity 
              Sensor Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*****************************************************************************
*/

#include <math.h>
#include <stdlib.h>

#include "Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h"

/**
 * @brief  I2C initialization and read check
 * @param  addr: Device adress
 * @retval  Return true(1)
 **/
bool APDS9960::begin(uint8_t address, TwoWire &wirePort) {
    _address = address;
    Wire.begin();

    uint8_t x = read8(APDS9960_ID);
    if (x != 0xAB)
        return false;
    setADCIntegrationTime(10);

    setADCGain(APDS9960_AGAIN_4X);
    enable(false);
    delay(10);
    enable(true);
    delay(10);

    enableProximity(false);
    enableGesture(false);

    setGesture(APDS9960_DIMENSIONS_ALL, APDS9960_GFIFO_4, APDS9960_GGAIN_4, 50);
    resetCounts();
    return true;
}

/**
 * @brief enable
 * @param en: enable
 * @retval  None
 **/
void APDS9960::enable(boolean en) {
    _enable.PON = en;
    write8(APDS9960_ENABLE, _enable.get());
}

/**
 * @brief  enable gesture
 * @param  en: enable gesture
 * @retval  None
 **/
void APDS9960::enableGesture(boolean en) {
    enableProximity(true);
    _enable.GEN = en;
    write8(APDS9960_ENABLE, _enable.get());
    resetCounts();
}

/**
 * @brief  enable proximity
 * @param  en: enable proximity
 * @retval  None
 **/
void APDS9960::enableProximity(boolean en) {
    _enable.PEN = en;
    write8(APDS9960_ENABLE, _enable.get());
}

/**
 * @brief  enable color detection
 * @param  en: enable color
 * @retval None
 **/
void APDS9960::enableColor(boolean en) {
    _enable.AEN = en;
    write8(APDS9960_ENABLE, _enable.get());
}

/**
 * @brief
 * @param
 * @retval  None
 **/
void APDS9960::setGesture(uint8_t dims, uint8_t Fthresh, uint8_t gain, uint8_t thresh) {
    _gconf3.GDIMS = dims;
    write8(APDS9960_GCONF3, _gconf3.get());
    _gconf1.GFIFOTH = Fthresh;
    write8(APDS9960_GCONF1, _gconf1.get());
    _gconf1.GFIFOTH = thresh;
    write8(APDS9960_GCONF1, _gconf1.get());
    _gconf2.GGAIN = gain;
    write8(APDS9960_GCONF2, _gconf2.get());
}

/**
 * @brief
 * @param reg:
 * @retval
 **/
uint8_t APDS9960::read8(uint8_t reg) {
    uint8_t ret;
    readRegisters(reg, &ret, 1);
    return ret;
}

/**
 * @brief
 * @param
 * @retval
 **/
uint16_t APDS9960::read16R(uint8_t reg) {
    uint8_t ret[2];
    readRegisters(reg, ret, 2);
    return (ret[1] << 8) | ret[0];
}

/**
 * @brief
 * @param
 * @retval
 **/
uint8_t APDS9960::readRegisters(uint8_t i2caddress, uint8_t *data, size_t length) {
    Wire.beginTransmission(_address);
    Wire.write(i2caddress);

    if (Wire.endTransmission(false) != 0) {
        return 0;
    }

    if (Wire.requestFrom(_address, length) != length) {
        return 0;
    }

    for (size_t i = 0; i < length; i++) {
        *data++ = Wire.read();
    }

    return true;
}

/**
 * @brief
 * @param
 * @retval  None
 **/
void APDS9960::write(uint8_t reg, uint8_t *buf, uint8_t num) {
    Wire.beginTransmission((uint8_t)_address);
    Wire.write((uint8_t)reg);
    Wire.write((uint8_t *)buf, num);
    Wire.endTransmission();
}

/**
 * @brief
 * @param
 * @retval  None
 **/
void APDS9960::write8(byte reg, byte value) {
    write(reg, &value, 1);
}

/**
 * @brief
 * @param
 * @retval
 **/
bool APDS9960::gestureValid() {
    _gstatus.set(read8(APDS9960_GSTATUS));
    return _gstatus.GVALID;
}

/**
 * @brief
 * @param
 * @retval  None
 **/
void APDS9960::resetCounts() {
    gestCnt = 0;
    UCount = 0;
    DCount = 0;
    LCount = 0;
    RCount = 0;
}

/**
 * @brief
 * @param
 * @retval
 **/
uint8_t APDS9960::readGesture() {
    uint8_t buf[256];
    unsigned long time = 0;
    uint8_t Received;
    while (1) {
        int up_down = 0;
        int left_right = 0;
        Received = 0;
        if (!gestureValid())
            return 0;

        delay(30);
        readRegisters(APDS9960_GFIFO_U, buf, 32);
        if (abs((int)buf[0] - (int)buf[1]) > 13)
            up_down += (int)buf[0] - (int)buf[1];

        if (abs((int)buf[2] - (int)buf[3]) > 13)
            left_right += (int)buf[2] - (int)buf[3];

        if (up_down != 0) {
            if (up_down < 0) {
                if (DCount > 0) {
                    Received = APDS9960_UP;
                }
                else
                    UCount++;
            }
            else if (up_down > 0) {
                if (UCount > 0) {
                    Received = APDS9960_DOWN;
                }
                else
                    DCount++;
            }
        }

        if (left_right != 0) {
            if (left_right < 0) {
                if (RCount > 0) {
                    Received = APDS9960_LEFT;
                }
                else
                    LCount++;
            }
            else if (left_right > 0) {
                if (LCount > 0) {
                    Received = APDS9960_RIGHT;
                }
                else
                    RCount++;
            }
        }

        if (up_down != 0 || left_right != 0)
            time = millis();

        if (Received || millis() - time > 300) {
            resetCounts();
            return Received;
        }
    }
}

/**
 * @brief
 * @param
 * @retval  None
 **/
uint8_t APDS9960::readProximity() {
    return read8(APDS9960_PDATA);
}

/**
 * @brief  command for specified data length
 * @param  *r: red register address ,*g: green register address ,*b: blue register address ,*c: color register address
 * @retval  None
 **/
void APDS9960::getColorData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c) {
    *c = read16R(APDS9960_CDATAL);
    *r = read16R(APDS9960_RDATAL);
    *g = read16R(APDS9960_GDATAL);
    *b = read16R(APDS9960_BDATAL);
}

/**
 * @brief
 * @param
 * @retval
 **/
bool APDS9960::colorDataReady() {
    _status.set(this->read8(APDS9960_STATUS));
    return _status.AVALID;
}

/**
 * @brief set ADC integration time
 * @param  iTimeMS:
 * @retval  
 **/
void APDS9960::setADCIntegrationTime(uint16_t iTimeMS) {
    float temp;

    // convert ms into 2.78ms increments
    temp = iTimeMS;
    temp /= 2.78;
    temp = 256 - temp;
    if (temp > 255)
        temp = 255;
    if (temp < 0)
        temp = 0;

    write8(APDS9960_ATIME, (uint8_t)temp);
}

/**
 * @brief  set ADC gain
 * @param  
 * @retval  
 **/
void APDS9960::setADCGain(apds9960AGain_t aGain) {
    _control.AGAIN = aGain;
    write8(APDS9960_CONTROL, _control.get());
}
