//APSC200/293 Section_204 Team_7

#include <Adafruit_BMP280.h>
#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);  // (RX,TX)
#include <Wire.h>
#include <SPI.h>
#define SensorPin0 A0 
float sensorValue0 = 0; 
#include <Adafruit_BMP280.h> //Pressure & Temperature Sensor Library
#define BMP_SCK (13)  
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

  
void setup() { 
 bt.begin(9600); 
 
  if (!bmp.begin()) {
    bt.println(F("Could not find a valid BMP280 sensor."));
    while (1);
  }
  
   bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */          
}


void loop() { 
 for (int i = 0; i <= 100; i++) { 
   sensorValue0 = sensorValue0 + analogRead(SensorPin0); 
   delay(1); 
 } 
 sensorValue0=sensorValue0/100.0;
 bt.print("Soil Mositure: ");
 bt.println(sensorValue0);
 delay(1000);

bt.print("Temperature: ");
bt.print(bmp.readTemperature());
bt.println(" *C");

bt.print("Pressure: ");
bt.print(bmp.readPressure());
bt.println(" Pa");

delay(1000);
 
}
