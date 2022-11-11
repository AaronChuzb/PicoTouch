/*
 * @Date: 2022-09-24 21:43:07
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-11-11 23:23:46
 */
#include <stdint.h>
#include <Arduino.h>
#include "DISP/DISP.h"
#include "UI/ui.h"
#include <Wire.h>
#include "config.h"
#include "FreeRTOS.h"
#include <WiFi.h>
#include "time.h"



typedef struct
{
  String usage;
  bool isCharging;
  bool chargeFlag;
} Power_Info_t;

namespace HAL
{
  void Init();
  void Update();
  // 电源相关
  void Init_Power();
  void Get_BatPercent(Power_Info_t *bat);
  String Get_Bat();
  bool isCharging();
  void Power_Shutdown();

  // 背光
  void BL_Init();
  void BL_SetGradual(uint32_t target, uint16_t time);
  uint32_t BL_GetValue();
  void BL_SetValue(int32_t val);
  void BL_ForceLit(bool en);
  void BL_SetBacklightValue(int32_t val);
  uint32_t BL_GetBacklightValue();

  // 编码器
  void Encoder_Init();
  void Encoder_Update();
  bool Encoder_GetIsPush();
  int16_t Encoder_GetDiff();
  void Encoder_SetEnable(bool en);
  // SD卡
  bool SD_Init();
  bool SD_GetReady();
  float SD_GetCardSizeMB();
  // 陀螺仪
  void IMU_Init();
  void IMU_Update(int interval);
  // 蜂鸣器
  void Buzz_init();
  void Buzz_SetEnable(bool en);
  void Buzz_Tone(uint32_t _freq, int32_t _duration = 0);
  // 音乐
  void Audio_Init();
  void Audio_Update();
  bool Audio_PlayMusic(const char *name);
  // iic扫描
  void I2C_Init(bool startScan);
  // WIFI
  void WiFi_Init();
  // 时间
  void Time_Init();
  void Time_Event();

}