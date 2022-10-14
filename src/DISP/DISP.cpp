/*
 * @Date: 2022-09-24 16:32:13
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-10 16:46:20
 */
#include "DISP.h"
#include "HAL/HAL.h"



TaskHandle_t handleTaskLvgl;
void TaskLvglUpdate(void *parameter)
{
  // ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

  for (;;)
  {
    lv_task_handler();

    delay(5);
  }
  vTaskDelete(NULL);
}

void Disp_Init()
{
  
  
  static SCREEN_CLASS tft;
  tft.begin();
  tft.startWrite();
  CST816T cst816t(I2C_SDA, I2C_SCL, TOUCH_RST, TOUCH_INT);
  cst816t.begin();
  lv_init();
  disp_init(&tft);
  lv_fs_if_init();
  xTaskCreate(
      TaskLvglUpdate,
      "LvglThread",
      20000,
      nullptr,
      configMAX_PRIORITIES - 1,
      &handleTaskLvgl);
}