#include "ADS7823.h"
#include <Wire.h>

#define ADDRESS_ADC     0x48 //  1001 000

ADS7823 analogDigitalConverter(ADDRESS_ADC, 2.5); // I2C address and reference voltage in [V]

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.print("\nByte value:\t");
  Serial.println(analogDigitalConverter.readADC());
  Serial.print("Voltage:\t");
  Serial.print(analogDigitalConverter.readADCvoltage());
  Serial.println("V");
  delay(1000);
}
