#include <Servo.h>
// no reverse 
// need to implement relay method to make reverse 


Servo FL;
Servo FR;
Servo RL;
Servo RR;

int val;

int throttleValue;

int FL_throttle;
int FR_throttle;
int RL_throttle;
int RR_throttle;

void setup()
{
FL.attach(11);
FR.attach(10);
RL.attach(6);
RR.attach(9);
Serial.begin(9600);


}
 
void loop()
{
  appController();
  
sped(FL_throttle, FR_throttle, RL_throttle, RR_throttle);

Serial.print(FL_throttle);
Serial.print(FR_throttle);
Serial.print(RL_throttle);
Serial.print(RR_throttle);
Serial.println(' ' );
Serial.println(throttleValue);
delay(200);
}

int appController(){
if( Serial.available() )       // if data is available to read
  {
   val = Serial.parseInt();    // read it and store it in 'val'
  }
  switch (val) {
   case 11:  //Move Forward
   return moveForward();
    break;
    
   case 22:  //Move Backward
   return moveBackward();
    break;
    
   case 33:  //Move Left
    return moveLeft();
    break;
    
   case 44:  //Move Right  
    return moveRight();
    break;
    
  case 55:  //Start
    throttleValue =69;
    return allSpeed(throttleValue);
    break;
    
  case 66:  //Stop
    throttleValue =0;
    return allSpeed(throttleValue);
    break;
    
  case 77:    // Up
    
    if (throttleValue < 160){
      throttleValue = throttleValue + 5;
    return allSpeed(throttleValue), val = 99;
    }
    break;
    
  case 88:    // Down
    //throttleValue =throttleValue-50;
    if (throttleValue > 0){
    return allSpeed(throttleValue-5),val = 99;}
    break;
    
  case 99:
    return allSpeed(throttleValue);
    break;
    
  case 101:  //Arm
    throttleValue = 20;
    return allSpeed(throttleValue);
    break;
  } 
}

void sped(int FL_throttle,int FR_throttle, int RL_throttle,int RR_throttle){
FL.write(FL_throttle);
FR.write(FR_throttle);
RL.write(RL_throttle);
RR.write(RR_throttle);
}

int allSpeed(int throttle){
if (throttle > 68){ FR_throttle = throttle - 40;
RL_throttle= throttle - 40;}
if(throttle < 65){
FR_throttle = 20 ;
RL_throttle= 20 ;
}
FL_throttle= throttle;
RR_throttle= throttle;

throttleValue = throttle;
check(FL_throttle, FR_throttle, RL_throttle, RR_throttle );
return FL_throttle, FR_throttle, RL_throttle, RR_throttle, throttleValue;

}

int check(int FL_throttle, int FR_throttle, int RL_throttle, int RR_throttle){
  if (FL_throttle < 50|| FR_throttle < 50 || RL_throttle<50 || RR_throttle<50){
      FL_throttle=0;
      FR_throttle=0;
      RL_throttle=0;
      RR_throttle=0;
      return FL_throttle,FR_throttle, RL_throttle, RR_throttle;   
  }
}
int moveForward(){
  return 0;
}

int moveBackward(){
  return 0;
}

int moveRight(){
  return 0;
}

int moveLeft(){
  return 0;
}  
