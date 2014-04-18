/*
  I2C_ADC_Suli.cpp

  This is a Suly compatible Library
  
  2014 Copyright (c) Seeed Technology Inc.  All right reserved.
  
  Loovee
  2014-4-15

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

#include "I2C_ADC_Suli.h"


void *__I2C_Device;


void i2c_adc_init(void *i2c_dev)
{ 
    __I2C_Device = i2c_dev;
    uint8 dta[2] = {REG_ADDR_CONFIG, 0x20};
    suli_i2c_write(__I2C_Device, ADDR_ADC121, dta, 2);
}


int i2c_adc_read()     //unsigned int *data
{
    uint8 dta[2] = {REG_ADDR_RESULT};
    
    suli_i2c_write(__I2C_Device, ADDR_ADC121, dta, 1);
    
    suli_i2c_read(__I2C_Device, ADDR_ADC121, dta, 2);
    
    int analog = (dta[0]&0x0f)<<8 | dta[1];
    return analog;
}