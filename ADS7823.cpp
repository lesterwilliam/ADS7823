#include "ADS7823.h"

ADS7823::ADS7823(byte address, float ref_voltage){
  _address = address;
  _ref_voltage = ref_voltage;
  init();
}

void ADS7823::init(){
  
}

int ADS7823::readADC(){
  Wire.beginTransmission(_address);
  Wire.write(command_byte);
  Wire.endTransmission();
  
  Wire.requestFrom(_address, 2);
  
  if(Wire.available() <= 2){
    return ((Wire.read()) << 8) | (Wire.read());
  }
}

float ADS7823::readADCvoltage(){
  float value;
  Wire.beginTransmission(_address);
  Wire.write(command_byte);
  Wire.endTransmission();
  
  Wire.requestFrom(_address, 2);
  
  if(Wire.available() <= 2){
    value = ((Wire.read()) << 8) | (Wire.read());
  }
  value = 2.5 * value / 4096.0;
  return value;
}

