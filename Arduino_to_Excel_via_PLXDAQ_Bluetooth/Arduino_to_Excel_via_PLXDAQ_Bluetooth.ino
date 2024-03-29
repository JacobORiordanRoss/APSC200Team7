//APSC200/293 Section_204 Team_7

#include <Adafruit_BMP280.h>
#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);  // (RX,TX)
#include <Wire.h>
#include <SPI.h>
#define SensorPin0 A0 
float sensorValue0 = 0; 
float pressureValue;
float maxSaturation;
float memFactor;
int count = 0;
#include <Adafruit_BMP280.h> //Pressure & Temperature Sensor Library
#define BMP_SCK (13)  
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

  
void setup() { 
 bt.begin(9600); 
 bt.println("LABEL,Time,Soil Moisture,Pressure,Soil Saturation Capacity");
 
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
 
if (bmp.readTemperature() < -5) {
  bt.println("Temperature is sufficiently low. Flooding potential is undeterminable based on soil water holding capacity data.");
}
else {
 sensorValue0 = sensorValue0/800.0;
 pressureValue = (bmp.readPressure());
 maxSaturation = 24.799*pow(pressureValue/100000, -0.141);
 memFactor = sensorValue0/maxSaturation*100;
}
//insert code here to describe the change from below to above freezing, indicates melting snow or ice
 
bt.print("DATA,TIME,");
bt.print(sensorValue0);
bt.print(",");
bt.print(pressureValue);
bt.print(",");
bt.println(memFactor);
delay(1000);

if (memFactor < 100) {
  count = 0;
}
else{
  count++;  //add code here to add to a count if Mem is greater than 100 for 5 consecutive hours
}

if (count >= 5*3600) {  //CHANGE THIS TO 20 FOR THE DEMO  
  bt.println("WARNING: SOIL SATURATION CAPACITY AT MAXIMUM. POTENTIAL FOR INCOMING FLOOD.");
}
}
