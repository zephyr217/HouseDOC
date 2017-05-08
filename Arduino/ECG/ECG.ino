void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(4, INPUT); // Setup for leads off detection LO +
  pinMode(5, INPUT); // Setup for leads off detection LO -

}

void loop() {
  
  if((digitalRead(4) == 1)||(digitalRead(5) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      Serial.println(analogRead(A1));
  }
  //Wait for a bit to keep serial data from saturating
  delay(1000);
}
