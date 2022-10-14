/*
 * @Date: 2022-10-15 00:08:13
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-15 00:09:27
 */
#include "HAL.h"

const char* ssid       = "WYX";
const char* password   = "05210122";

void HAL::WiFi_Init()
{
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");
}