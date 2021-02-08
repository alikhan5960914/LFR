#include <AFMotor.h>

AF_DCMotor motor_LU(1, MOTOR12_1KHZ); 
AF_DCMotor motor_LD(2, MOTOR12_1KHZ);
AF_DCMotor motor_RD(3, MOTOR34_1KHZ);
AF_DCMotor motor_RU(4, MOTOR34_1KHZ);

char command;

void forward();
void backward();
void left();
void right();
void Stop();

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    command=Serial.read();
    Stop();
  }

  switch(command){
    case 'F':
    forward();
    break;
    case 'B':
    backward();
    break;
    case 'L':
    left();
    break;
    case 'R':
    right();
    break;
  }
}

void forward(){
  motor_LU.setSpeed(200);
  motor_LD.setSpeed(200);
  motor_RU.setSpeed(200);
  motor_RD.setSpeed(200);

  motor_LU.run(FORWARD);
  motor_LD.run(FORWARD);
  motor_RU.run(FORWARD);
  motor_RD.run(FORWARD);
}

void backward(){
  motor_LU.setSpeed(100);
  motor_LD.setSpeed(100);
  motor_RU.setSpeed(100);
  motor_RD.setSpeed(100);

  motor_LU.run(BACKWARD);
  motor_LD.run(BACKWARD);
  motor_RU.run(BACKWARD);
  motor_RD.run(BACKWARD);
}

void left(){
  motor_LU.setSpeed(200);
  motor_LD.setSpeed(200);
  motor_RU.setSpeed(200);
  motor_RD.setSpeed(200);

  motor_LU.run(BACKWARD);
  motor_LD.run(BACKWARD);
  motor_RU.run(FORWARD);
  motor_RD.run(FORWARD);
}

void right(){
  motor_LU.setSpeed(200);
  motor_LD.setSpeed(200);
  motor_RU.setSpeed(200);
  motor_RD.setSpeed(200);

  motor_RU.run(BACKWARD);
  motor_RD.run(BACKWARD);
  motor_LU.run(FORWARD);
  motor_LD.run(FORWARD);
}

void Stop(){
  motor_RU.run(RELEASE);
  motor_RD.run(RELEASE);
  motor_LU.run(RELEASE);
  motor_LD.run(RELEASE);
}
