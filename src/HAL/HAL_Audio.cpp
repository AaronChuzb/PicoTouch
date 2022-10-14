/*
 * @Date: 2022-10-13 21:27:14
 * @LastEditors: AaronChu
 * @LastEditTime: 2022-10-13 23:58:38
 */
#include "HAL/HAL.h"
#include "TonePlayer.h"

static TonePlayer player;

#include "MusicCode.h"

static void Tone_Callback(uint32_t freq, uint16_t volume)
{
  HAL::Buzz_Tone(freq);
}

void HAL::Audio_Init()
{
  player.SetCallback(Tone_Callback);
  
}

void HAL::Audio_Update()
{
  player.Update(lv_tick_get());
}

bool HAL::Audio_PlayMusic(const char *name)
{
  bool retval = false;
  for (int i = 0; i < sizeof(MusicList) / sizeof(MusicList[0]); i++)
  {
    if (strcmp(name, MusicList[i].name) == 0)
    {
      player.Play(MusicList[i].mc, MusicList[i].length);
      retval = true;
      break;
    }
  }
  return retval;
}
