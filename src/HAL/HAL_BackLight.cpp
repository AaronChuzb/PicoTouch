#include "DISP/DISP.h"
#include "HAL/HAL.h"

static uint32_t backlightValue = 0;

static void BL_AnimCallback(void *obj, int32_t brightness)
{
  HAL::BL_SetValue(brightness);
}

void HAL::BL_Init()
{
  ledcSetup(0, 5000, 10);
  ledcAttachPin(TFT_BL, 0);
  ledcWrite(0, 0);
}


/**
 * @description: 背光渐变
 * @param {uint32_t} target 目标亮度 (0~1000)
 * @param {uint16_t} time 时间 (ms)
 */
void HAL::BL_SetGradual(uint32_t target, uint16_t time)
{
  lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)BL_AnimCallback);
  lv_anim_set_values(&a, BL_GetValue(), target);
  lv_anim_set_time(&a, time);
  lv_anim_set_path_cb(&a, lv_anim_path_ease_out);

  lv_anim_start(&a);
}

uint32_t HAL::BL_GetValue()
{
  return backlightValue;
}

void HAL::BL_SetValue(int32_t val)
{
  val = constrain(val, 0, 1024);
  backlightValue = val;
  val = backlightValue;
  ledcWrite(0, val);
}

void HAL::BL_ForceLit(bool en)
{
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, en);
}
