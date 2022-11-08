/*
*****************************************************************************
@file         Deneyap_HareketIsikRenkAlgilayiciMesafeOlcer.h
@mainpage     Deneyap Gesture, Color, Proximity Sensor Arduino library header file
@version      v1.0.1
@date         November 08, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap Gesture, Color, Proximity Sensor Arduino library
*****************************************************************************
*/

#ifndef _DENEYAP_HAREKETISIKRENKALGILAYICIMESAFEOLCER_H_
#define _DENEYAP_HAREKETISIKRENKALGILAYICIMESAFEOLCER_H_

#include <Arduino.h>
#include <Wire.h>

#define APDS9960_ADDRESS (0x39) /**< I2C Address */
enum {
    APDS9960_RAM =           0x00,
    APDS9960_ENABLE =        0x80,
    APDS9960_ATIME =         0x81,
    APDS9960_WTIME =         0x83,
    APDS9960_AILTIL =        0x84,
    APDS9960_AILTH =         0x85,
    APDS9960_AIHTL =         0x86,
    APDS9960_AIHTH =         0x87,
    APDS9960_PILT =          0x89,
    APDS9960_PIHT =          0x8B,
    APDS9960_PERS =          0x8C,
    APDS9960_CONFIG1 =       0x8D,
    APDS9960_PPULSE =        0x8E,
    APDS9960_CONTROL =       0x8F,
    APDS9960_CONFIG2 =       0x90,
    APDS9960_ID =            0x92,
    APDS9960_STATUS =        0x93,
    APDS9960_CDATAL =        0x94,
    APDS9960_CDATAH =        0x95,
    APDS9960_RDATAL =        0x96,
    APDS9960_RDATAH =        0x97,
    APDS9960_GDATAL =        0x98,
    APDS9960_GDATAH =        0x99,
    APDS9960_BDATAL =        0x9A,
    APDS9960_BDATAH =        0x9B,
    APDS9960_PDATA =         0x9C,
    APDS9960_POFFSET_UR =    0x9D,
    APDS9960_POFFSET_DL =    0x9E,
    APDS9960_CONFIG3 =       0x9F,
    APDS9960_GPENTH =        0xA0,
    APDS9960_GEXTH =         0xA1,
    APDS9960_GCONF1 =        0xA2,
    APDS9960_GCONF2 =        0xA3,
    APDS9960_GOFFSET_U =     0xA4,
    APDS9960_GOFFSET_D =     0xA5,
    APDS9960_GOFFSET_L =     0xA7,
    APDS9960_GOFFSET_R =     0xA9,
    APDS9960_GPULSE =        0xA6,
    APDS9960_GCONF3 =        0xAA,
    APDS9960_GCONF4 =        0xAB,
    APDS9960_GFLVL =         0xAE,
    APDS9960_GSTATUS =       0xAF,
    APDS9960_IFORCE =        0xE4,
    APDS9960_PICLEAR =       0xE5,
    APDS9960_CICLEAR =       0xE6,
    APDS9960_AICLEAR =       0xE7,
    APDS9960_GFIFO_U =       0xFC,
    APDS9960_GFIFO_D =       0xFD,
    APDS9960_GFIFO_L =       0xFE,
    APDS9960_GFIFO_R =       0xFF,
};
#define APDS9960_UP         0x01    /**< Gesture Up */
#define APDS9960_DOWN       0x02    /**< Gesture Down */
#define APDS9960_LEFT       0x03    /**< Gesture Left */
#define APDS9960_RIGHT      0x04    /**< Gesture Right */
/** ADC gain settings */
typedef enum {
    APDS9960_AGAIN_1X =     0x00,  /**< No gain */
    APDS9960_AGAIN_4X =     0x01,  /**< 2x gain */
    APDS9960_AGAIN_16X =    0x02,  /**< 16x gain */
    APDS9960_AGAIN_64X =    0x03   /**< 64x gain */
} apds9960AGain_t;

/** Proxmity gain settings */
typedef enum {
    APDS9960_PGAIN_1X =     0x00, /**< 1x gain */
    APDS9960_PGAIN_2X =     0x04, /**< 2x gain */
    APDS9960_PGAIN_4X =     0x08, /**< 4x gain */
    APDS9960_PGAIN_8X =     0x0C  /**< 8x gain */
} apds9960PGain_t;

/** Dimensions */
enum {
    APDS9960_DIMENSIONS_ALL =        0x00,        // All dimensions
    APDS9960_DIMENSIONS_UP_DOWN =    0x01,    // Up/Down dimensions
    APGS9960_DIMENSIONS_LEFT_RIGHT = 0x02, // Left/Right dimensions
};

/** FIFO Interrupts */
enum {
    APDS9960_GFIFO_1 =      0x00,  // Generate interrupt after 1 dataset in FIFO
    APDS9960_GFIFO_4 =      0x01,  // Generate interrupt after 2 datasets in FIFO
    APDS9960_GFIFO_8 =      0x02,  // Generate interrupt after 3 datasets in FIFO
    APDS9960_GFIFO_16 =     0x03, // Generate interrupt after 4 datasets in FIFO
};
/** Gesture Gain */
enum {
    APDS9960_GGAIN_1 =      0x00, // Gain 1x
    APDS9960_GGAIN_2 =      0x01, // Gain 2x
    APDS9960_GGAIN_4 =      0x02, // Gain 4x
    APDS9960_GGAIN_8 =      0x03, // Gain 8x
};
class APDS9960 {
public:
    bool begin(uint8_t address, TwoWire &wirePort = Wire);
    void enable(boolean en);
    void setGesture(uint8_t dims, uint8_t Fthresh, uint8_t gain, uint8_t thresh);

    void setADCIntegrationTime(uint16_t iTimeMS);
    void setADCGain(apds9960AGain_t gain);

    void disableProximityInterrupt();
    void enableProximity(boolean en = true);
    void enableProximityInterrupt();
    void clearInterrupt();
    uint8_t readProximity();
    void setProximityInterruptThreshold(uint8_t low, uint8_t high,
                                        uint8_t persistance = 4);

    void enableGesture(boolean en = true);
    uint8_t readGesture();
    bool gestureValid();
    void resetCounts();

    void enableColor(boolean en = true);
    bool colorDataReady();
    void getColorData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);

private:
    uint8_t _address;
    uint8_t read8(byte reg);
    uint8_t readRegisters(uint8_t i2caddress, uint8_t *data, size_t length);
    uint16_t read16R(uint8_t reg);

    void write8(byte reg, byte value);
    void write(uint8_t reg, uint8_t *buf, uint8_t num);

    uint8_t gestCnt;

    uint8_t UCount;
    uint8_t DCount;

    uint8_t LCount;
    uint8_t RCount;

    struct enable {
        uint8_t PON : 1;
        uint8_t AEN : 1;
        uint8_t PEN : 1;
        uint8_t WEN : 1;
        uint8_t AIEN : 1;
        uint8_t PIEN : 1;
        uint8_t GEN : 1;

        uint8_t get() {
            return (GEN << 6) | (PIEN << 5) | (AIEN << 4) | (WEN << 3) | (PEN << 2) |
                   (AEN << 1) | PON;
        };
    };
    struct enable _enable;

    struct pers {
        uint8_t APERS : 4;
        uint8_t PPERS : 4;
        uint8_t get() { return (PPERS << 4) | APERS; };
    };
    pers _pers;

    struct config1 {
        uint8_t WLONG : 1;
        uint8_t get() { return WLONG << 1; };
    };
    config1 _config1;

    struct ppulse {
        uint8_t PPULSE : 6;
        uint8_t PPLEN : 2;
        uint8_t get() { return (PPLEN << 6) | PPULSE; }
    };
    ppulse _ppulse;

    struct control {
        uint8_t AGAIN : 2;
        uint8_t PGAIN : 2;
        uint8_t LDRIVE : 2;
        uint8_t get() { return (LDRIVE << 6) | (PGAIN << 2) | AGAIN; }
    };
    control _control;

    struct gstatus {
        uint8_t GVALID : 1;
        uint8_t GFOV : 1;
        void set(uint8_t data)
        {
            GFOV = (data >> 1) & 0x01;
            GVALID = data & 0x01;
        }
    };
    gstatus _gstatus;

    struct status {
        uint8_t AVALID : 1;
        uint8_t PVALID : 1;
        uint8_t GINT : 1;
        uint8_t AINT : 1;
        uint8_t PINT : 1;
        uint8_t PGSAT : 1;
        uint8_t CPSAT : 1;

        void set(uint8_t data) {
            AVALID = data & 0x01;
            PVALID = (data >> 1) & 0x01;
            GINT = (data >> 2) & 0x01;
            AINT = (data >> 4) & 0x01;
            PINT = (data >> 5) & 0x01;
            PGSAT = (data >> 6) & 0x01;
            CPSAT = (data >> 7) & 0x01;
        }
    };
    status _status;

    struct gconf4 {
        uint8_t GMODE : 1;
        uint8_t GIEN : 2;

        uint8_t get() { return (GIEN << 1) | GMODE; }
        void set(uint8_t data)
        {
            GIEN = (data >> 1) & 0x01;
            GMODE = data & 0x01;
        }
    };
    gconf4 _gconf4;

    struct gconf1 {

        uint8_t GEXPERS : 2;
        uint8_t GEXMSK : 4;
        uint8_t GFIFOTH : 2; // Interrupt is generated after 8 datasets are added to FIFO.

        uint8_t get() { return (GFIFOTH << 6) | (GEXMSK << 2) | GEXPERS; }
    };
    gconf1 _gconf1;

    struct gconf2 {

        uint8_t GWTIME : 3;
        uint8_t GLDRIVE : 2;
        uint8_t GGAIN : 2; // 4x

        uint8_t get() { return (GGAIN << 5) | (GLDRIVE << 3) | GWTIME; }
    };
    gconf2 _gconf2;

    struct gconf3 {
        uint8_t GDIMS : 3; // Both pairs are active. UP-DOWN and LEFT-RIGHT FIFO data is valid.

        uint8_t get() { return GDIMS; }
    };
    gconf3 _gconf3;
};
#endif /* __DENEYAP_HAREKETISIKRENKALGILAYICIMESAFEOLCER__H */
