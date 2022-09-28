/**************************************************************************/
/*!
  @file     CST816T.cpp
  Author: Atsushi Sasaki (https://github.com/aselectroworks)
  License: MIT (see LICENSE)
*/
/**************************************************************************/

#include "CST816T.h"
#include "Arduino.h"
#include <Wire.h>

CST816T::CST816T()
{
}

CST816T::CST816T(uint8_t rst_n_pin, uint8_t int_n_pin)
{
    rst_n = rst_n_pin;
    int_n = int_n_pin;
}

CST816T::CST816T(uint8_t sda_pin, uint8_t scl_pin, uint8_t rst_n_pin, uint8_t int_n_pin)
{
    sda = sda_pin;
    scl = scl_pin;
    rst_n = rst_n_pin;
    int_n = int_n_pin;
}

CST816T::~CST816T() {
}

void CST816T::begin(void) {
    // Initialize I2C
    if(sda != -1 && scl != -1) {
        Wire.begin(sda, scl); 
    }
    else {
        Wire.begin(); 
    }
    // Int Pin Configuration
    if(int_n != -1) {
        pinMode(int_n, INPUT); 
    }
    // Reset Pin Configuration
    if(rst_n != -1) {
        pinMode(rst_n, OUTPUT); 
        digitalWrite(rst_n, LOW); 
        delay(10); 
        digitalWrite(rst_n, HIGH); 
        delay(500); 
    }
    // Initialize Touch
    readByte(0x15);
    delay(1);
    readByte(0xa7);
    delay(1);
    writeByte(0xEC,  0x05);
    delay(1);
    writeByte(0xFA, 0b01110000);
    delay(1);
}

/**
 * @设置旋转方向,默认为Rotation_0
 * @Rotation：方向 0~3
*/
void CST816T::setRotation(TouchRotation Rotation)
{
    switch (Rotation) {
    case Rotation_0:
      touch_rotation = Rotation_0;
      break;
    case Rotation_1:
      touch_rotation = Rotation_1;
      break;
    case Rotation_2:
      touch_rotation = Rotation_2;
      break;
    case Rotation_3:
      touch_rotation = Rotation_3;
      break;
    }
}

//coordinate diagram（FPC downwards）
TouchInfos CST816T::GetTouchInfo(void){
    // Serial.println("GetTouchInfo");
    byte error;
    TouchInfos info;
    uint8_t touchData[7];
    uint8_t rdDataCount;
    // 唤醒
    // readByte(0x15);
    // readByte(0xa7);
    uint8_t i = 0;
    long startTime = millis();
    do {
        Wire.beginTransmission(I2C_ADDR_CST816T); 
        Wire.write(0); 
        error = Wire.endTransmission(false); // Restart
        if (error != 0) {
            info.isValid = false;
            return info;
        }
        rdDataCount = Wire.requestFrom(I2C_ADDR_CST816T, sizeof(touchData)); 
        // Serial.printf("读取中%d  %d\n", i, rdDataCount);
        if(millis() - startTime > 15) {
            info.isValid = false;
            return info;
        }
    } while(rdDataCount == 0); 
    i = 0;
    while(Wire.available()) {
        touchData[i] = Wire.read();
        // Serial.printf("%d %02X \n", i, touchData[i]);
        i++;
        if(i >= sizeof(touchData)) {
            break;
        }
    }
    // Serial.println("GetTouchInfo end");

    // This can only be 0 or 1
    uint8_t nbTouchPoints = touchData[touchPointNumIndex] & 0x0f;
    uint8_t xHigh = touchData[touchXHighIndex] & 0x0f;
    uint8_t xLow = touchData[touchXLowIndex];
    uint16_t x = (xHigh << 8) | xLow;
    uint8_t yHigh = touchData[touchYHighIndex] & 0x0f;
    uint8_t yLow = touchData[touchYLowIndex];
    uint16_t y = (yHigh << 8) | yLow;
    Gestures gesture = static_cast<Gestures>(touchData[gestureIndex]);

    // Validity check
    if(x >= TouchWidth || y >= TouchHeight ||
        (gesture != Gestures::None &&
        gesture != Gestures::SlideDown &&
        gesture != Gestures::SlideUp &&
        gesture != Gestures::SlideLeft &&
        gesture != Gestures::SlideRight &&
        gesture != Gestures::SingleTap &&
        gesture != Gestures::DoubleTap &&
        gesture != Gestures::LongPress)) {
        info.isValid = false;
        return info;
    }

    info.x = x;
    info.y = y;
    info.touching = (nbTouchPoints > 0);
    info.gesture = gesture;
    info.isValid = true;
    return info;

    // touchPoint.touch_count = read_td_status(); 

    // touchPoint.tp[id1].status = (touchPoint.tp[id1].status == release) ? touch : stream;
    // switch (touch_rotation) {
    //     case Rotation_0://不变
    //         touchPoint.tp[id1].x = read_touch1_x(); 
    //         touchPoint.tp[id1].y = read_touch1_y();
    //     break;
    //     case Rotation_1:
    //         touchPoint.tp[id1].x = read_touch1_y(); 
    //         touchPoint.tp[id1].y = TouchWidth - read_touch1_x();
    //     break;
    //     case Rotation_2:
    //         touchPoint.tp[id1].x = TouchWidth - read_touch1_x(); 
    //         touchPoint.tp[id1].y = TouchHeight - read_touch1_y();
    //     break;
    //     case Rotation_3:
    //         touchPoint.tp[id1].x = TouchHeight - read_touch1_y(); 
    //         touchPoint.tp[id1].y = read_touch1_x();
    //     break;
    // }  
    // touchPoint.tp[~id1 & 0x01].status = release; 

    // return touchPoint; 
}

// Private Function
uint8_t CST816T::readByte(uint8_t addr) {
    uint8_t rdData; 
    uint8_t rdDataCount; 
    do {
        Wire.beginTransmission(I2C_ADDR_CST816T); 
        Wire.write(addr); 
        Wire.endTransmission(false); // Restart
        rdDataCount = Wire.requestFrom(I2C_ADDR_CST816T, 1); 
    } while(rdDataCount == 0); 
    while(Wire.available()) {
        rdData = Wire.read(); 
    }
    return rdData; 
}

void CST816T::writeByte(uint8_t addr, uint8_t data) {
	Wire.beginTransmission(I2C_ADDR_CST816T); 
    Wire.write(addr); 
    Wire.write(data); 
    Wire.endTransmission(); 
}
