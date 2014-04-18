/*
 * demo code of Grove - I2C ADC
 *
 * void begin() - initialize
 * read() - read 12 bit data
 * read_u10 - read 10 bit data
 */
 
#include <Wire.h>
#include <SoftwareSerial.h>
#include "Suli.h"
#include "I2C_ADC_Arduino.h"

#include "Streaming.h"


I2C_ADC adc;

void setup()
{
    Serial.begin(115200);
    
    adc.begin();
}

void loop()
{
    cout << adc.read() << endl;
    delay(100);
}