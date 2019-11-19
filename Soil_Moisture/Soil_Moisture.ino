#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);  // (RX,TX)
#include <Wire.h>
#include <SPI.h>
#define SensorPin0 A0 
float sensorValue0 = 0; 


void setup() { 
 bt.begin(9600); 
} 

void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue0 = sensorValue0 + analogRead(SensorPin0); 
   delay(1); 
 } 
 sensorValue0=sensorValue0/800.0;
 bt.print("Soil Mositure: ");
 bt.println( sensorValue0);
 delay(30);

} 
