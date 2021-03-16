#define DOCELOWE_NAWODNIENIE_GLEBY 500
#include "Garduino.h"

Garduino::Garduino(int AnalogSensorPin1, int DigitalSensorPin1, int WarningPin1, int DesiredMoistureLvL1, int pDisplayConfig[6]){
  AnalogSensorPin = AnalogSensorPin1;
  DigitalSensorPin = DigitalSensorPin1;
  DesiredMoistureLvL = DesiredMoistureLvL1;
  WarningPin = WarningPin1;
  pinMode(AnalogSensorPin, INPUT);
  pinMode(DigitalSensorPin, OUTPUT);
  pinMode(WarningPin, OUTPUT);
  LiquidCrystal Mylcd(pDisplayConfig[0],pDisplayConfig[1],pDisplayConfig[2],pDisplayConfig[3],pDisplayConfig[4],pDisplayConfig[5]);
  pMyLcd = &Mylcd;
  Mylcd.begin(16,2);
  }

int Garduino::CheckMoistureLvl(){
  digitalWrite(DigitalSensorPin, HIGH);  
  delay(10);              
  int val = analogRead(AnalogSensorPin);  
  digitalWrite(DigitalSensorPin, LOW);   
  return val;
  }

void Garduino::DisplayMoistureLvl(int iValue){
  int iMoistureLvLProcentage = (iValue*100)/DOCELOWE_NAWODNIENIE_GLEBY;
 
  pMyLcd -> clear();
  pMyLcd -> print("Nawodnienie ");
  pMyLcd -> setCursor(12,0);
  pMyLcd -> print(iMoistureLvLProcentage);
  pMyLcd -> setCursor(15,0);
  pMyLcd -> print("%");
  pMyLcd -> setCursor(0,1);
  if(iValue >= DOCELOWE_NAWODNIENIE_GLEBY*1.1){
    pMyLcd -> print("wysokie nawod.");
    SetWarningPin();
    }
  else if(iValue <= DOCELOWE_NAWODNIENIE_GLEBY*0.9){
    pMyLcd -> print("niskie nawod.");
    SetWarningPin();
    }
  else{
    pMyLcd -> print("nawod. w normie");
    ShutDownWorningPin();
    }
  }

void Garduino::SetWarningPin(void){
    digitalWrite(WarningPin, HIGH);
  }

void Garduino::ShutDownWorningPin(void){
    digitalWrite(WarningPin, LOW);
  }
