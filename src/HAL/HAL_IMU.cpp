/*
 * @Date: 2022-10-05 20:56:49
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-05 22:45:17
 */
#include "HAL.h"
#include "MPU6050.h"

static MPU6050 imu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t roll, yaw, pitch;
long  last_update_time;
int flag;

void HAL::IMU_Init()
{
  Wire1.begin(IMU_SDA, IMU_SCL);
  Wire1.setClock(400000);
  if (imu.testConnection())
  {
    Serial.println("MPU6050 connection failed.");
  }
  imu.initialize();
}

void HAL::IMU_Update(int interval)
{
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  imu.getRotation(&roll, &yaw, &pitch);
  
 
  if (millis() - last_update_time > interval)
  {
    if (ay > 3000 && flag)
    {
      // encoder_diff--;
      flag = 0;
      Serial.println("ay > 3000 && flag");
    }
    else if (ay < -3000 && flag)
    {
      // encoder_diff++;
      flag = 0;
      Serial.println("ay < 3000 && flag");

    }
    else
    {
      flag = 1;
      Serial.println("else");
    }

    if (ax > 10000)
    {
      // encoder_state = LV_INDEV_STATE_PR;
      Serial.println("ax > 10000");
    }
    else
    {
      // encoder_state = LV_INDEV_STATE_REL;
      Serial.println("ax =< 10000");
    }

    last_update_time = millis();
  }
}
