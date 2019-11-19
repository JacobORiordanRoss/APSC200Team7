#include <Adafruit_BMP280.h>
#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);  // (RX,TX)
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h> //Pressure and temperature sensor libraries
#define SensorPin0 A0 
float sensorValue0 = 0; 
#define BMP_SCK (13)  
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)
//Adafruit_BMP280 bmp(BMP_CS); //software spi
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

  
void setup() { 
 Serial.begin(9600); 
 Serial.println("Arduino Test");

 // if (!bmp.begin()) {
   // Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    //while (1);
   }
  
  /* bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
    //              Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
      //            Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
        //          Adafruit_BMP280::FILTER_X16,      /* Filtering. */
          //        Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */          
//}


void loop() { 
 for (int i = 0; i <= 100; i++) { 
   sensorValue0 = sensorValue0 + analogRead(SensorPin0); 
   delay(1); 
 } 
 sensorValue0=sensorValue0/100.0;
 Serial.print("Soil Mositure: ");
 Serial.println(sensorValue0);
 delay(1000);
/*
Serial.print("Temperature: ");
Serial.print(bmp.readTemperature());
Serial.println(" *C");

Serial.print("Pressure: ");
Serial.print(bmp.readPressure());
Serial.println(" Pa");

delay(1000);
 */
}
