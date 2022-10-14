/*
 * @Date: 2022-09-24 21:44:43
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-13 23:45:13
 */

#include "HAL.h"
#include "AXP173.h"

static AXP173 pmu;
static uint8_t BatPercent = 100;

void HAL::Init_Power()
{
  pmu.begin(I2C_SDA, I2C_SCL);
}

void HAL::Get_BatPercent(Power_Info_t *bat)
{
  if(pmu.isCharging() && !bat->chargeFlag){
    bat->chargeFlag = true;
  } else {
    bat->chargeFlag = false;
  }
  int readLevel = (int)pmu.getBatLevel();
  if(readLevel < BatPercent || bat->chargeFlag){ // 防止电量上下跳变
    BatPercent = readLevel;
  }
  bat->usage = String(BatPercent);
}

String HAL::Get_Bat()
{
  // int readLevel = (int)pmu.getBatLevel();
  // if(BatPercent < readLevel && !pmu.isCharging()){ // 防止电量上下跳变
  //   BatPercent = readLevel;
  // }
  return String(pmu.getBatLevel());
}

bool HAL::isCharging()
{
  return pmu.isCharging();
}

void HAL::Power_Shutdown()
{
  pmu.powerOFF();
}




