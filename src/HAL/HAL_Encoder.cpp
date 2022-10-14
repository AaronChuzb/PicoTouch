/*
 * @Date: 2022-09-25 00:28:52
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-14 00:07:04
 */
#include "HAL/HAL.h"
#include "ButtonEvent.h"

static ButtonEvent EncoderPush(5000);

static bool EncoderEnable = true;
static volatile int16_t EncoderDiff = 0;
static bool EncoderDiffDisable = false;

// Account* actEncoder;

static void Encoder_IrqHandler()
{
  if (!EncoderEnable || EncoderDiffDisable)
  {
    return;
  }

  static volatile int count, countLast;
  static volatile uint8_t a0, b0;
  static volatile uint8_t ab0;
  uint8_t a = digitalRead(EC_A);
  uint8_t b = digitalRead(EC_B);
  if (a != a0)
  {
    a0 = a;
    if (b != b0)
    {
      b0 = b;
      count += ((a == b) ? 1 : -1);
      if ((a == b) != ab0)
      {
        count += ((a == b) ? 1 : -1);
      }
      ab0 = (a == b);
    }
  }

  if (count != countLast)
  {
    EncoderDiff += (count - countLast) > 0 ? 1 : -1;
    countLast = count;
  }
  HAL::Encoder_GetDiff();
}

static void Encoder_PushHandler(ButtonEvent *btn, int event)
{
  if (event == ButtonEvent::EVENT_PRESSED)
  {
    HAL::Buzz_Tone(500, 20);
    // HAL::Audio_PlayMusic("Startup");
    Serial.println("按下");
    EncoderDiffDisable = true;
  }
  else if (event == ButtonEvent::EVENT_RELEASED)
  {
    HAL::Buzz_Tone(700, 20);
    Serial.println("松开");
    EncoderDiffDisable = false;
    if(HAL::BL_GetValue() == 0){
      HAL::BL_SetGradual(HAL::BL_GetBacklightValue(),100);
    } else {
      HAL::BL_SetGradual(0,100);
    }
  }
  else if (event == ButtonEvent::EVENT_LONG_PRESSED)
  {
    Serial.println("长按");
    // HAL::Audio_PlayMusic("Shutdown");
    // HAL::Power_Shutdown();
  }
}

static void Encoder_RotateHandler(int16_t diff)
{
  Serial.println(diff);
  int32_t light = HAL::BL_GetValue() + -diff * 100;
  light <= 128?light = 100:light = light;
  HAL::BL_SetBacklightValue(light);
  HAL::BL_SetGradual(light, 100);
  HAL::Buzz_Tone(400, 15);

  // actEncoder->Commit((const void*) &diff, sizeof(int16_t));
  // actEncoder->Publish();
}

void HAL::Encoder_Init()
{
  pinMode(EC_A, INPUT_PULLUP);
  pinMode(EC_B, INPUT_PULLUP);
  pinMode(EC_KEY, INPUT_PULLUP);

  attachInterrupt(EC_A, Encoder_IrqHandler, CHANGE);

  EncoderPush.EventAttach(Encoder_PushHandler);

  // actEncoder = new Account("Encoder", AccountSystem::Broker(), sizeof(int16_t), nullptr);
}

void HAL::Encoder_Update()
{
  EncoderPush.EventMonitor(Encoder_GetIsPush());
  
}

int16_t HAL::Encoder_GetDiff()
{
  int16_t diff = -EncoderDiff / 2;
  if (diff != 0)
  {
    // EncoderDiff是实际的脉冲数；把本次变量用掉了，需要重新置0
    EncoderDiff = 0;
    Encoder_RotateHandler(diff);
  }

  return diff;
}

bool HAL::Encoder_GetIsPush()
{
  if (!EncoderEnable)
  {
    return false;
  }

  return (digitalRead(EC_KEY) == LOW);
}

void HAL::Encoder_SetEnable(bool en)
{
  EncoderEnable = en;
}
