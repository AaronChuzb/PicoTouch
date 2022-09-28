#ifndef _AXP173_H_
#define _AXP173_H_

#include "I2C.h"

/* AXP173 device address */
#define AXP173_ADDR 0x34
#define AXP173_ADDR_READ 0x69
#define AXP173_ADDR_WRITE 0x68

class AXP173 : public I2C_PORT
{
private:
  uint16_t _getMin(uint16_t a, uint16_t b);
  uint16_t _getMax(uint16_t a, uint16_t b);
  uint16_t _getMid(uint16_t input, uint16_t min, uint16_t max);

public:
  enum OUTPUT_CHANNEL
  {
    OP_DCDC1 = 0,
    OP_LDO4,
    OP_LDO2,
    OP_LDO3,
    OP_DCDC2,
  };
  enum ADC_CHANNEL
  {
    ADC_TS = 0,
    ADC_APS_V,
    ADC_VBUS_C,
    ADC_VBUS_V,
    ADC_ACIN_C,
    ADC_ACIN_V,
    ADC_BAT_C,
    ADC_BAT_V,
  };
  enum CHARGE_CURRENT
  {
    CHG_100mA = 0,
    CHG_190mA,
    CHG_280mA,
    CHG_360mA,
    CHG_450mA,
    CHG_550mA,
    CHG_630mA,
    CHG_700mA,
    CHG_780mA,
    CHG_880mA,
    CHG_960mA,
    CHG_1000mA,
    CHG_1080mA,
    CHG_1160mA,
    CHG_1240mA,
    CHG_1320mA,
  };
  enum COULOMETER_CTRL
  {
    COULOMETER_RESET = 5,
    COULOMETER_PAUSE,
    COULOMETER_ENABLE,
  };
/* Init */
#ifdef ARDUINO
  bool begin(uint8_t sda, uint8_t scl);
#else
  void begin();
#endif
  /* Power input state */
  bool isACINExist();
  bool isACINAvl();
  bool isVBUSExist();
  bool isVBUSAvl();
  bool getBatCurrentDir();
  bool isAXP173OverTemp();
  bool isCharging();
  bool isBatExist();
  bool isChargeCsmaller();
  /* Power output control */
  void setOutputEnable(OUTPUT_CHANNEL channel, bool state);
  void setOutputVoltage(OUTPUT_CHANNEL channel, uint16_t voltage);
  /* Basic control */
  void powerOFF();
  /* Charge control */
  void setChargeEnable(bool state);
  void setChargeCurrent(CHARGE_CURRENT current);
  /* ADC control */
  void setADCEnable(ADC_CHANNEL channel, bool state);
  /* Coulometer control */
  void setCoulometer(COULOMETER_CTRL option, bool state);
  /* Coulometer data */
  uint32_t getCoulometerChargeData();
  uint32_t getCoulometerDischargeData();
  float getCoulometerData();
  /* BAT data */
  float getBatVoltage();
  float getBatCurrent();
  float getBatLevel();
  float getBatPower();
  /* VBUS data */
  float getVBUSVoltage();
  float getVBUSCurrent();
  /* Temperature data */
  float getAXP173Temp();
  float getTSTemp();
};

#endif