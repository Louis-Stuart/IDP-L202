#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *left = AFMS.getMotor(1);
Adafruit_DCMotor *right = AFMS.getMotor(2);

//define constant

bool run_once = false;
int low_speed = 0;
int high_speed = 255;
char backward = FORWARD;
char forward = BACKWARD;

//predefine function
void read()
void stop(int t=0)
void straight(int speed=high_speed, int t=0);
void reverse(int speed=high_speed, int t=0);
void turn(int high=high_speed, int low=low_speed, bool left);
void turn_r();
void turn_l();

void setup() {
  Serial.begin(9600);           
  if (!AFMS.begin()) {        
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
}

//main
void loop() {
  if (!run_once) { // run the start code only once
      //test any function by adding it in
      straight();
      run_once = true;
  }
}

void stop(int t=0) {
  left->setSpeed(0);
  right->setSpeed(0);
  delay(t);
}

void straight(int speed=high_speed, int t=0) {
  left->setSpeed(speed);
  right->setSpeed(speed);
  left->run(forward);
  right->run(forward);
  delay(t);
}

void reverse(int speed=high_speed, int t=0) {
  left->setSpeed(speed);
  right->setSpeed(speed);
  left->run(backward);
  right->run(backward);
  delay(t); 
}

void turn(int high=high_speed, int low=low_speed, bool left) {
  if(left){
    left->setSpeed(high);
    right->setSpeed(low);
  }else{
    left->setSpeed(low);
    right->setSpeed(high);
  }
  left->run(forward);
  right->run(forward);
}

void turn_left() {
  turn(high_speed,low_speed,true);
}

void turn_right() {
  turn(high_speed,low_speed,false);
}
