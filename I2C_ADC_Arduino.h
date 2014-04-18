/*
  Seeed_LED_Bar_Arduino.h
  For Arduino Only
  This is a Suly compatible Library
  
  2014 Copyright (c) Seeed Technology Inc.  All right reserved.
  
  Loovee
  2013-3-26

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include <Arduino.h>  
#include <Wire.h>
#include "I2C_ADC_Suli.h"


class I2C_ADC{

public:

    void begin()
    {
        Wire.begin();
        i2c_adc_init(&Wire);
    }
    
    int read()
    { 
        return i2c_adc_read();
    }    
    
    int read_u10()
    {
        return (i2c_adc_read()>>2);                 // return 10bit data
    }

};