/*
 * @Date: 2022-09-24 21:43:00
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-05 23:24:27
 */


#include "HAL.h"
#include "UI/ui.h"


void HAL::Init()
{
  Serial.begin(115200);
  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  
  Serial.println(LVGL_Arduino);
  Serial.println("I am LVGL_Arduino");
  HAL::Init_Power();
  Serial.println("I am LVGL_Arduino2");
  HAL::BL_Init();
  
  HAL::BL_SetGradual(500, 1000);
  // HAL::Encoder_Init();

  HAL::SD_Init();

  HAL::IMU_Init();
}

void HAL::Update()
{
  HAL::Encoder_Update();
  // HAL::IMU_Update(200);
  
  // lv_label_set_text(ui_Label1, HAL::Get_BatPercent().c_str());
}