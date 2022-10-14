/*
 * @Date: 2022-10-13 21:31:20
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-13 21:34:40
 */
#include "HAL/HAL.h"

static bool IsEnable = true;
static int32_t duration = 0;
static uint32_t freq = 0;

static void BuzzerThread(void* argument)
{
    for (;;)
    {
        if (duration > 0)
        {
            ledcWriteTone(2, freq);
            delay(duration);
            ledcWriteTone(2, 0);

            duration = 0;
        }

        delay(50);
    }
}

void HAL::Buzz_init()
{
    pinMode(BUZZ, OUTPUT);
    ledcAttachPin(BUZZ, 2);
    ledcSetup(2, 0, 8);
    ledcWriteTone(2, 0);

    // Create Buzzer thread
    TaskHandle_t handleBuzzerThread;
    xTaskCreate(
        BuzzerThread,
        "BuzzerThread",
        800,
        nullptr,
        1,
        &handleBuzzerThread);
}

void HAL::Buzz_SetEnable(bool en)
{
    IsEnable = en;
}

void HAL::Buzz_Tone(uint32_t _freq, int32_t _duration)
{
    if (!IsEnable)
        return;

    if (_duration == 0)
    {
        ledcWriteTone(2, _freq);
    } else
    {
        freq = _freq;
        duration = _duration;
    }
}
