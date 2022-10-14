/*
 * @Date: 2022-10-15 00:11:15
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-15 00:22:09
 */
#include "HAL.h"

const char *ntpServer = "asia.pool.ntp.org";
const long gmtOffset_sec = 8 * 60 * 60;
const int daylightOffset_sec = 0;

struct tm timeinfo;

void HAL::Time_Init()
{
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  getLocalTime(&timeinfo);
}

void HAL::Time_Event(){
  time_t now = time(nullptr);
  struct tm *timeInfo = localtime(&now);
  String hour = timeInfo->tm_hour < 10? "0" + String(timeInfo->tm_hour):String(timeInfo->tm_hour);
  String min = timeInfo->tm_min < 10? "0" + String(timeInfo->tm_min):String(timeInfo->tm_min);
  lv_label_set_text(ui_Hour, hour.c_str());
  lv_label_set_text(ui_Min, min.c_str());
}

// PAINT_TIME getNowTime()
// {
//     time_t now = time(nullptr);
//     struct tm *timeInfo = localtime(&now);
//     PAINT_TIME sPaint_time;
//     sPaint_time.Hour = timeInfo->tm_hour;
//     sPaint_time.Min = timeInfo->tm_min;
//     return sPaint_time;
// }