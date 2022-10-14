#include "HAL/HAL.h"
#include "DISP/DISP.h"
#include "UI/ui.h"





Power_Info_t bat;
void Bat_Update(lv_timer_t *timer)
{
  HAL::Get_BatPercent(&bat);
  HAL::Time_Event();
  // Serial.println(HAL::isCharging());
  // Serial.println(HAL::Get_Bat());
  lv_label_set_text(ui_BAT, bat.usage.c_str());
  lv_label_set_text(ui_Label3, String(HAL::isCharging()).c_str());
}

void setup()
{
  // 顺序不能调换，需要先申请足够的内存，如果先对HAL库进行初始化就会没有足够连续的内存给lvgl申请
  Disp_Init();
  HAL::Init();
  ui_init();
  LV_FONT_DECLARE(chinese);
  static lv_style_t font_style;
  lv_style_init(&font_style);
  lv_style_set_text_font(&font_style, &chinese);
  lv_obj_add_style(ui_BAT, &font_style, 0);
  lv_obj_add_style(ui_Label3, &font_style, 0);
  // lv_label_set_text(ui_BAT, "Pico-Touch");
  lv_timer_t *timer = lv_timer_create(Bat_Update, 1000, nullptr);
  lv_timer_ready(timer);
  
  // setCpuFrequencyMhz(160);
}

void loop()
{
  HAL::Update();

  delay(20);
}
