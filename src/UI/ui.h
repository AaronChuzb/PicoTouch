// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_BAT;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Hour;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Min;
extern lv_obj_t * ui_Bar1;
extern lv_obj_t * ui_Label4;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label5;
void ui_event_Slider1(lv_event_t * e);
extern lv_obj_t * ui_Slider1;






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
