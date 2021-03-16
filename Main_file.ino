#define ANALOG_SENSOR_PIN A0
#define DIGITAL_SENSOR_PIN 9
#define DOCELOWE_NAWODNIENIE_GLEBY 500
#define WARNING_PIN 8
#define RS 7
#define ENABLE 6
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#include "Garduino.h"

int LcdCofig[] = {RS,ENABLE,D4,D5,D6,D7};

Garduino MYGarduino(ANALOG_SENSOR_PIN, DIGITAL_SENSOR_PIN, WARNING_PIN, DOCELOWE_NAWODNIENIE_GLEBY, &LcdCofig[0]);

void setup() {
}

void loop() {
  int iMoistureLvl;
  delay(2000);
  
  iMoistureLvl = MYGarduino.CheckMoistureLvl();
  MYGarduino.DisplayMoistureLvl(iMoistureLvl);
}
