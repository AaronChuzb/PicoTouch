#include "HAL/HAL.h"
#include "DISP/DISP.h"
#include "UI/ui.h"

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

  lv_obj_t *label_zh = lv_label_create(ui_Screen1);
  lv_obj_align(label_zh, LV_ALIGN_BOTTOM_MID, 0, 0);
  lv_obj_add_style(ui_Label1, &font_style, 0);
  lv_obj_add_style(ui_Label2, &font_style, 0);
  // lv_obj_add_style(label_zh, &font_style, 0);
  // lv_label_set_text(label_zh, "你好8");
  lv_label_set_text(ui_Label1, "233");
  lv_label_set_text(ui_Label2, "你是大傻逼");
  
}

void loop()
{
  HAL::Update();
  delay(20);
}
