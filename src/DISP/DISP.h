/*
 * @Date: 2022-09-24 16:32:35
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-09-27 22:25:08
 */
#ifndef __DISP_H
#define __DISP_H

#include <stdint.h>
#include <Arduino.h>

#include <lvgl.h>
#include "TFT_eSPI.h"

#include "CST816T.h"
#include "config.h"


typedef TFT_eSPI SCREEN_CLASS;
  
void disp_init(SCREEN_CLASS*scr);
void lv_fs_if_init();
void Disp_Init();

extern TaskHandle_t handleTaskLvgl;


#endif