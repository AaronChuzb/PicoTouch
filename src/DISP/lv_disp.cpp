/*
 * @Date: 2022-09-24 16:23:28
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-11-11 23:33:02
 */
/* Display flushing */

#include "DISP.h"
#include "HAL/HAL.h"


lv_color_t* lv_disp_buf_p;


static lv_disp_draw_buf_t disp_buf;
static lv_disp_drv_t disp_drv;



void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{

  // TFT_eSPI tft = TFT_eSPI(SCR_WIDTH, SCR_HEIGHT); /* TFT instance */
  SCREEN_CLASS* tft = (SCREEN_CLASS*) disp->user_data;

  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft->startWrite();
  tft->setAddrWindow(area->x1, area->y1, w, h);
  tft->pushColors((uint16_t *)&color_p->full, w * h, true);
  tft->endWrite();

  lv_disp_flush_ready(disp);
}


void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  CST816T cst816t(I2C_SDA, I2C_SCL, TOUCH_RST, TOUCH_INT);
  TouchInfos tp;
  tp = cst816t.GetTouchInfo();
  bool touched = (tp.touching == 1 && tp.isValid == 1);

  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;
    /*Set the coordinates*/
    data->point.x = tp.x;
    data->point.y = tp.y;
  }
}

void disp_init(SCREEN_CLASS* scr){
  
  lv_disp_buf_p = static_cast<lv_color_t *>(malloc(SCR_WIDTH * SCR_HEIGHT/2 * sizeof(lv_color_t)));
  if (lv_disp_buf_p == nullptr)
    LV_LOG_WARN("lv_port_disp_init malloc failed!\n");
  // lv_color_t* lv_disp_buf_p = static_cast<lv_color_t*>(malloc(SCR_WIDTH * SCR_HEIGHT / 10 * sizeof(lv_color_t)));
  lv_disp_draw_buf_init(&disp_buf, lv_disp_buf_p, NULL, SCR_WIDTH * SCR_HEIGHT/2);
   /*Initialize the display*/
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = SCR_WIDTH;
  disp_drv.ver_res = SCR_HEIGHT;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &disp_buf;
  disp_drv.user_data = scr;
  lv_disp_drv_register(&disp_drv);

  
  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);
}
