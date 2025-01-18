#include <Wire.h>
#include "SensirionI2CSen5x.h"

#define SEL_PIN 7 // SEL pin connected to digital pin 7 of Arduino

SensirionI2CSen5x sen55;

void setup() {
  // Start serial communication 
  Serial.begin(9600);
  
  // Set SEL pin as output
  pinMode(SEL_PIN, OUTPUT);

  // Set SEL pin HIGH for I2C communication
  digitalWrite(SEL_PIN, HIGH);

  // Start I2C communication
  Wire.begin();

  // Initialize sensor
  sen55.begin(Wire);  // No need to capture return value

  // Optionally, you can check if the sensor is responsive after initialization
  uint16_t error = sen55.deviceReset();
  if (error) {
    Serial.print("Error during device reset: ");
    Serial.println(error);  // Print the error code
  } else {
    Serial.println("Sensor successfully reset.");
  }
}

void loop() {
  float massConcentrationPm1p0, massConcentrationPm2p5, massConcentrationPm4p0, massConcentrationPm10p0;
  float ambientHumidity, ambientTemperature;
  float rawTemperature, rawHumidity;  // Additional parameters for readMeasuredValues

  // Start measurement
  uint16_t error = sen55.startMeasurement();
  if (error) {
    Serial.println("Measurement failed. Check the connections.");
    delay(5000);
    return;
  }

  delay(1000);  // Wait for measurement to complete

  // Read measured values
  error = sen55.readMeasuredValues(
    massConcentrationPm1p0, massConcentrationPm2p5, massConcentrationPm4p0, massConcentrationPm10p0,
    ambientHumidity, ambientTemperature, rawTemperature, rawHumidity
  );
  if (error) {
    Serial.println("Failed to read values. Check error code.");
  } else {
    // Print measured values
    Serial.print("PM1.0: "); Serial.print(massConcentrationPm1p0); Serial.println(" µg/m³");
    Serial.print("PM2.5: "); Serial.print(massConcentrationPm2p5); Serial.println(" µg/m³");
    Serial.print("PM4.0: "); Serial.print(massConcentrationPm4p0); Serial.println(" µg/m³");
    Serial.print("PM10.0: "); Serial.print(massConcentrationPm10p0); Serial.println(" µg/m³");
    Serial.print("Humidity: "); Serial.print(ambientHumidity); Serial.println(" %");
    Serial.print("Temperature: "); Serial.print(ambientTemperature); Serial.println(" °C");
    Serial.print("Raw Temperature: "); Serial.print(rawTemperature); Serial.println(" °C");
    Serial.print("Raw Humidity: "); Serial.print(rawHumidity); Serial.println(" %");
  }

  delay(5000);  // Wait for the next measurement
}