#include <Servo.h>
// no reverse 
// need to implement relay method to make reverse 


Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;

int throttlePin = 0;
int throttleValue;
void setup()
{
esc1.attach(11);
esc2.attach(10);
esc3.attach(6);
esc4.attach(9);
Serial.begin(9600);
}
 
void loop()
{
  if (Serial.available()){
    throttleValue = Serial.parseInt(); 
  }
 

  
int throttle= map(throttleValue, 0, 1023, 
 0, 179);

sped(throttle);
Serial.println(throttle);
}

void sped(int throttle){
esc1.write(throttle);
esc2.write(throttle);
esc3.write(throttle);
esc4.write(throttle);
}




