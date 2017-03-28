
int  val; // variable to receive data from the serial port

void setup() {
   Serial.begin(9600);       // start serial communication at 9600bps
}
void loop() {
  if( Serial.available() )       // if data is available to read
  {
    val = Serial.parseInt();    // read it and store it in 'val'
  }
  
  
  switch (val) {
  case 22:    // your hand is on the sensor
    prindw();
    break;
  case 11:    // your hand is close to the sensor
    prinup();
    break;
  }
  
  Serial.println(val);
  
  // Serial.println (val);

  delay(500);   // wait 100ms for next reading
}

void prinup(){
  Serial.println("up");
}

void prindw(){
  Serial.println("down");
}
