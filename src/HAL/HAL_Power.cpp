/*
 * @Date: 2022-09-24 21:44:43
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-09-24 22:29:28
 */

#include "HAL.h"

static AXP173 pmu;
static uint8_t BatPercent = 0;

void HAL::Init_Power()
{
  pmu.begin(I2C_SDA, I2C_SCL);
}

String HAL::Get_BatPercent()
{
  int readLevel = (int)pmu.getBatLevel();
  if(BatPercent < readLevel && !pmu.isCharging()){ // 防止电量上下跳变
    BatPercent = readLevel;
  }
  return String(BatPercent);
}

bool HAL::isCharging()
{
  return pmu.isCharging();
}

void HAL::powerOFF()
{
  pmu.powerOFF();
}



