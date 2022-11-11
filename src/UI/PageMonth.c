#include "Page.h"
#include "PageManager.h"

static lv_style_t font_style;

void InitMonthPages(lv_obj_t* page) {
  LV_FONT_DECLARE(chinese);
  lv_style_init(&font_style);
  lv_style_set_text_font(&font_style, &chinese);
  
  lv_obj_t* label = lv_label_create(page);
  lv_obj_add_style(label, &font_style, 0);
  lv_label_set_text(label, "第二页");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  // lv_obj_set_style_text_font(label, &lv_font_montserrat_48, 0);
}

void DeinitMonthPages(lv_obj_t* page) {
    lv_style_reset(&font_style);
    lv_obj_clean(page);
}


