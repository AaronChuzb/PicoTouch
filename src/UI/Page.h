#ifndef PAGE_H
#define PAGE_H

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

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

//页面初始化
void PageManagerInit(void);

//页面函数
void InitMainPages(lv_obj_t* page);
void DeinitMainPages(lv_obj_t* page);

void InitMonthPages(lv_obj_t* page);
void DeinitMonthPages(lv_obj_t* page);

void InitPopPages(lv_obj_t* page);
void DeinitPopPages(lv_obj_t* page);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
