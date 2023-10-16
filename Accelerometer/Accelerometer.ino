#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup(void)
{
  Serial.begin(115200);
  if(!accel.begin())
  {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    while(1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
  accel.setDataRate(ADXL345_DATARATE_400_HZ);   
}


void loop(void)
{
  sensors_event_t event;
  accel.getEvent(&event);
  
  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  Serial.print(""); Serial.print(x); Serial.print(" ");
  Serial.print(""); Serial.print(y); Serial.print(" ");
  Serial.print(""); Serial.println(z);

  delay(100); 
}
