/*
 * @Date: 2022-09-24 21:43:07
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-05 23:23:01
 */
#include <stdint.h>
#include <Arduino.h>
#include "DISP/DISP.h"
#include <Wire.h>
#include "config.h"
#include "FreeRTOS.h"

typedef struct
{
  String usage;
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
  void powerOFF();

  // 背光
  void BL_Init();
  void BL_SetGradual(uint32_t target, uint16_t time);
  uint32_t BL_GetValue();
  void BL_SetValue(int32_t val);
  void BL_ForceLit(bool en);
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


}