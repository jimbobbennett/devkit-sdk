#include "lps25h_class.h"

#define RetVal_OK           0
#define LOOP_DELAY          100

DevI2C *i2c; 
LPS25H *lps25h;
float data;
PRESSURE_InitTypeDef *initType;
int counter = 1;

void setup(){
  Serial.println(">> Start");
    Serial.println(__FILE__);

    i2c = new DevI2C(D14, D15);
    lps25h = new LPS25H(*i2c);

    initType->OutputDataRate =1;
    initType->PressureResolution = 10;
    initType->TemperatureResolution = 10;
    initType->DiffEnable = 1;
    initType->BlockDataUpdate = 1;
    initType->SPIMode = 1;

    // init
    if(lps25h->init(initType) != RetVal_OK)
    {
        Serial.println("[LPS25H]: Error: Failed to init LPS25H");
        return;
    }
}

void loop() {
  while(counter <= 5)
  {
    Serial.printf(">> Start (%d)\r\n", counter);
    runCase();
    Serial.printf(">> End (%d)\r\n", counter); 

    if(counter == 5)
    {
        Serial.println(">> End");
    }
    
    counter++;
  }
}

void runCase()
{
  if(lps25h->reset() != RetVal_OK)
    {
      Serial.println("[LPS25H]: Error: Failed to reset LPS25H");
      return;
    }
    
    // get pressure
    if(lps25h->getPressure(&data) != RetVal_OK)
    {
        Serial.println("[LPS25H]: Error: Failed to get the pressure");
    }
    else
    {
        Serial.print("Pressure: ");
        Serial.println(data);
    }

    // get temperature
    if(lps25h->getTemperature(&data) != RetVal_OK)
    {
        Serial.println("[LPS25H]: Error: Failed to get the temperature");
    }
    else
    {
        Serial.print("Temperature: ");
        Serial.println(data);
    }

    delay(LOOP_DELAY);
}

