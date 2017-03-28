#include <Servo.h>
// no reverse 
// need to implement relay method to make reverse 


Servo esc;
int throttlePin = 0;
int throttleValue;
String receiv;

void setup()
{
esc.attach(9);
Serial.begin(9600);
}
 
void loop()
{
  if (Serial.available()){
   // throttleValue = Serial.parseInt(); 
   // assign received serial in reciev
   receiv = Serial.readString();
   if (receiv == "up"){  
     Serial.println(receiv); 
     delay(300);
     throttleValue = + 50;
     speed_motor(throttleValue);
     receiv ="";
   if (receiv != "up"){
   Serial.println("Not up");
   }
}
//int throttle = analogRead(throttlePin); 
}
}
void speed_motor(int n_throttle){
  int throttle= map(n_throttle, 0, 1023, 
               0, 179);
  esc.write(throttle);
  Serial.println(throttle);
  delay(300);
}

