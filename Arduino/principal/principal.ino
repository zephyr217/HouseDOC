#include <Wire.h> // Used to establied serial communication on the I2C bus
#include "SparkFunTMP102.h" // Used to send and recieve specific information from our sensor

// Connections
// VCC = 3.3V
// GND = GND
// SDA = A4
// SCL = A5
const int ALERT_PIN = A3;
int buf1[10], buf2[10];
TMP102 sensor0(0x48); // Initialize sensor at I2C address 0x48

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  pinMode(4, INPUT); // Setup for leads off detection LO +
  pinMode(5, INPUT); // Setup for leads off detection LO -
  pinMode(ALERT_PIN,INPUT);  // Declare alertPin as an input
  sensor0.begin();  // Join I2C bus

  sensor0.setFault(0);  // Trigger alarm immediately

  // set the polarity of the Alarm. (0:Active LOW, 1:Active HIGH).
  sensor0.setAlertPolarity(1); // Active HIGH

  // set the sensor in Comparator Mode (0) or Interrupt Mode (1).
  sensor0.setAlertMode(0); // Comparator Mode.

  // set the Conversion Rate (how quickly the sensor gets a new reading)
  //0-3: 0:0.25Hz, 1:1Hz, 2:4Hz, 3:8Hz
  sensor0.setConversionRate(2);

  //set Extended Mode.
  //0:12-bit Temperature(-55C to +128C) 1:13-bit Temperature(-55C to +150C)
  sensor0.setExtendedMode(0);

  //set T_HIGH, the upper limit to trigger the alert on
 
  sensor0.setHighTempC(29.4); // set T_HIGH in C

  //set T_LOW, the lower limit to shut turn off the alert
  
  sensor0.setLowTempC(26.67); // set T_LOW in C
}

void loop()
{
  float temperature;
  boolean alertPinState, alertRegisterState;
  int i;
  sensor0.wakeup();

  // read temperature data
 
  temperature = sensor0.readTempC();
  delay(250);

  // Check for Alert
  alertPinState = digitalRead(ALERT_PIN); // read the Alert from pin
  alertRegisterState = sensor0.alert();   // read the Alert from register

  sensor0.sleep();

  // Print temperature and alarm state
  Serial.print("Temperature: ");
  Serial.println(temperature);
  delay(250);
  Serial.print("Puls: ");
  Serial.println(analogRead(A0));
  delay(250);s
  Serial.print("EKG: ");
  Serial.println(analogRead(A1));
  for ( i = 0; i < 10; i++){
    buf1[i] = A1;
    buf2[i] = 0;
      Serial.print(buf1[i]);
  }
  Serial.println("");
  for ( i = 0; i < 10; i++){
    buf2[i] = A1;
    buf1[i] = 0;
      Serial.print(buf2[i]);
  }
  
  
  delay(250);  // Wait 1000ms
}
