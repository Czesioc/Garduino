#ifndef TestLibrary
#define TestLibrary
#include <Arduino.h>
#include <LiquidCrystal.h>

class Garduino{
  public:
    Garduino(int AnalogSensorPin1, int DigitalSensorPin1, int Digitaloutput1, int DesiredMoistureLvL1, int pDisplayConfig[6]);
    int CheckMoistureLvl(void);
    int AnalogSensorPin;
    int DigitalSensorPin;
    int DesiredMoistureLvL;
    int WarningPin;
    void DisplayMoistureLvl(int iValue);
  private:
    LiquidCrystal *pMyLcd;
    void SetWarningPin(void);
    void ShutDownWorningPin(void);
};

#endif
