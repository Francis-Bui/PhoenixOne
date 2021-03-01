// Made by Francis Bui

#include <Stepper.h>

char t;

// Sets steps per revolution and actuation
const int stepsPerRevolution = 2048;
const int actuate = 600;

// Stepper flag
int stepflag = 0;

// H-BRIDGE MOTOR, DRIVE
#define IN1 5
#define IN2 4
#define IN3 3
#define IN4 2

//  RELAY, INGITION
#define RPIN 6

// STEPPER MOTOR, GAS TANK ACTUATION
#define STEP1 7
#define STEP2 8
#define STEP3 9
#define STEP4 10

// Creates stepper object
Stepper myStepper = Stepper(stepsPerRevolution, 7, 9, 8, 10);

void setup() 
{
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(RPIN,OUTPUT);   // Relay
pinMode(STEP1, OUTPUT);
pinMode(STEP2, OUTPUT);
pinMode(STEP3, OUTPUT);
pinMode(STEP4, OUTPUT);

// Set stepper speed
myStepper.setSpeed(15);

Serial.begin(9600);
 
}

// Reads bluetooth serial input 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'w'){            // Move forward (all motors rotate in forward direction)
  forward();
}
 
else if(t == 's'){      //Move reverse (all motors rotate in reverse direction)
  reverse();
}
 
else if(t == 'a'){      //Turn right (left side motors rotate in forward direction, right side motors reverse)
  left();
}
 
else if(t == 'd'){      //Turn left (right side motors rotate in forward direction, left side motors reverse)
  right();
}

else if(t == 'r'){    // Turn relay on
  relayon();
}

else if(t == 'f'){    // Turn relay off
  relayoff();
}

else if(t == 't' and stepflag == 0){    // Turn stepper forward
  steppergo();
  relayon();
  stepflag += 1;
}

else if(t == 'y' and stepflag == 1){    // Turn stepper reverse
  stepperstop();
  relayoff();
  stepflag -= 1;
}

else if (t == 'z'){      // Stops robot (all motors stop)
  stoprobot();
}

else if (t == '1') {   // Autonomous 
simpleautopath();
}
delay(50);
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stoprobot()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void relayon()
{
  digitalWrite(RPIN, HIGH);
}

void relayoff()
{
  digitalWrite(RPIN, LOW);
}

void steppergo()
{
  myStepper.step(actuate);
}

void stepperstop()
{
  myStepper.step(-actuate);
}

void simpleautopath()
{
  stoprobot();
  forward();
  delay(2000);
  left();
  delay(50);
  right();
  delay(50);
  forward();
  delay(200);
  relayon();
  steppergo();
  delay(150);
  stepperstop();
  relayoff();
}
