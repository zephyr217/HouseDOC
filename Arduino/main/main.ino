#include <Wire.h> // Used to establied serial communication on the I2C bus
#include "SparkFunTMP102.h" // Used to send and recieve specific information from our sensor
#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3); // RX | TX
TMP102 sensor0(0x48); // Initialize sensor at I2C address 0x48
String sir = "\0";
//int counter = 0, k = 0;
//int sum_temp = 0;
//int sum_puls = 0;
//char inbyte = 0;
unsigned long previousMillisEcg = 0;
unsigned long previousMillisTrEcg = 0;
unsigned long previousMillisTrSir = 0;
const long intervalEcg = 10;
const long intervalTrimiteEcg = 2000;
const long intervalFinal = 30000;

void setup() {
 Serial.begin(9600);
 BTserial.begin(9600);
 sensor0.begin(); 

  // set the Conversion Rate (how quickly the sensor gets a new reading)
  //0-3: 0:0.25Hz, 1:1Hz, 2:4Hz, 3:8Hz
  sensor0.setConversionRate(2); 

  //set Extended Mode.
  //0:12-bit Temperature(-55C to +128C) 1:13-bit Temperature(-55C to +150C)
  sensor0.setExtendedMode(0);
}
void sendto_android(){
  
  //trimit doar sirul taiat de la E incolo
  //daca au trecut 30 de secunde, trimit tot sirul
  BTserial.print("abc");
  }
void read_sensors(){
 float temperatura;
 sensor0.wakeup();
 temperatura = sensor0.readTempC();
 sensor0.sleep();
  sir += "S";
  sir += "T";
  sir += temperatura;
  sir += "P";
  sir += analogRead(A0);
  sir += "E";
  for (int i = 0; i < 100; i++){
    sir += analogRead(A1);
    sir += "-";
    }
 sir += "F\n";
  }

  
void loop()
{   
unsigned long currentMillis = millis();

sendto_android();
read_sensors();



if(currentMillis - previousMillisEcg >= intervalEcg){
  previousMillisEcg = currentMillis;
  sir += analogRead(A1);
  sir += "-";
  if(curentMillis - previousMillisTrEcg >= intervalTrimiteEcg){
    sendto_android();
    previousMillisTrEcg = currentMillis;
    if(currentMillis - previousMillisTrSir >= intervalFinal){
      sir += 
      previousMillisTrSir = currentMillis;
    }
  }
}

/*
// Serial.println("cnt "+counter);
 i{f (counter == 10) 
 // Serial.println("Trimit ecg "+ecg);
  ecg = "\0";
  counter = 0;

  //temperatura
  sum_temp = sum_temp + citire_temperatura();
  delay(250);
//   Serial.println("temp "+sum_temp);
  sum_puls = sum_puls + citire_puls();
  delay(250);
//Serial.println("puls "+sum_puls);
  k++;
 //  Serial.println("k "+k);
 }

 if (k == 3){
  //trimit sum_temp/3
   Serial.println("Am trimis temperatura "+sum_temp/3);
  //trimit sum_puls/3
   Serial.println("Am trimis pulsul "+sum_puls/3);
   k = 0;
  }*/
  
 
 //delay(1000); 
 
}
