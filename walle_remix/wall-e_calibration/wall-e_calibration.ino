/**
 * WALL-E CALIBRATION CODE (MODIFIED TO REPRINT COMMANDS)
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Define the pin-mapping
#define SR_OE 7          // Servo shield output enable pin

// Define other constants
#define SERVOS 7         // Number of servo motors

// Instantiate objects
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo Positions:  Low,High
int preset[][2] =  {{398, 112},  // head rotation
                    {565, 188},  // neck top
                    {470, 100},  // neck bottom
                    {475, 230},  // eye right
                    {270, 440},  // eye left
                    {350, 185},  // arm left
                    {188, 360}}; // arm right

// Rest position
float restpos[7] = {50, 50, 40, 0, 0, 100, 100};

// Messages
String messages1[7] = {"Head Rotation - ","Neck Top Joint - ","Neck Bottom Joint - ","Eye Right - ","Eye Left - ","Arm Left - ","Arm Right - "};
String messages2[][2] = {{"LOW (head facing left)", "HIGH (head facing right)"},
                         {"LOW (head looking up)", "HIGH (head looking down)"},
                         {"LOW (head looking down)", "HIGH (head looking up)"},
                         {"LOW (eye rotated down)", "HIGH (eye rotated up)"},
                         {"LOW (eye rotated down)", "HIGH (eye rotated up)"},
                         {"LOW (arm rotated down)", "HIGH (arm rotated up)"},
                         {"LOW (arm rotated down)", "HIGH (arm rotated up)"}};

// Runtime Variables
int currentServo = 0;
int currentPosition = -1;
int position = preset[0][0] - 1;

// ----- MODIFIED -----
// A new helper function to print the current status.
void printStatus() {
  Serial.print("Current Pulse: ");
  Serial.print(position);
  Serial.println("  |  Commands: 'a'=-10, 'd'=+10, 'z'=-1, 'c'=+1, 'n'=confirm");
}

// ------------------------------------------------------------------
/// INITIAL SETUP
// ------------------------------------------------------------------
void setup() {
  pinMode(SR_OE, OUTPUT);
  digitalWrite(SR_OE, HIGH);

  pwm.begin();
  pwm.setPWMFreq(60);

  for (int i = 0; i < SERVOS; i++) pwm.setPin(i, 0);

  Serial.begin(115200);
  while(!Serial);

  Serial.println(F("////////// Starting Wall-E Calibration Program //////////"));

  digitalWrite(SR_OE, LOW);
  softStart();
  moveToNextPosition();
}

// -------------------------------------------------------------------
/// MOVE TO NEXT POSITION OR SERVO (MODIFIED)
// -------------------------------------------------------------------
void moveToNextPosition() {
  if (currentPosition != -1) {
    preset[currentServo][currentPosition] = position;
    Serial.print(F("\n[Confirmed Position: ")); Serial.print(position); Serial.println("]\n");
  }

  if (currentPosition < 1) {
    currentPosition++;
  } else {
    changeServoPosition(int(restpos[currentServo] / 100.0 * (preset[currentServo][1] - preset[currentServo][0]) + preset[currentServo][0]));
    pwm.setPin(currentServo, 0);
    currentServo++;
    currentPosition = 0;
    position = preset[currentServo][currentPosition] - 1;

    if (currentServo == SERVOS) {
      digitalWrite(SR_OE, HIGH);
      outputResults();
    }
    softStart();
  }

  Serial.print(messages1[currentServo]);
  Serial.println(messages2[currentServo][currentPosition]);
  Serial.println(F("-----------------------------------"));
  
  changeServoPosition(preset[currentServo][currentPosition]);
  
  // ----- MODIFIED -----
  // Call the new status printing function.
  printStatus();
}

// -------------------------------------------------------------------
/// CHANGE SERVO POSITION
// -------------------------------------------------------------------
void changeServoPosition(int newPosition) {
  while (position != newPosition) {
    if (position < newPosition) position++;
    else position--;
    pwm.setPWM(currentServo, 0, position);
    delay(5);
  }
}

// -------------------------------------------------------------------
/// SOFT START
// -------------------------------------------------------------------
void softStart() {
  unsigned long endTime = millis() + 1000;
  while (endTime > millis()) {
    pwm.setPWM(currentServo, 0, position);
    delay(10);
    pwm.setPin(currentServo, 0);
    delay(50);
  }
  pwm.setPWM(currentServo, 0, position);
}

// -------------------------------------------------------------------
/// OUTPUT THE RESULTS
// -------------------------------------------------------------------
void outputResults() {
  Serial.println("\n\nCalibrated values - please copy and paste these into the 'wall-e.ino' sketch:\n");
  Serial.print("int preset[][2] =  {{"); Serial.print(preset[0][0]); Serial.print(","); Serial.print(preset[0][1]); Serial.println("},  // head rotation");
  Serial.print("                    {"); Serial.print(preset[1][0]); Serial.print(","); Serial.print(preset[1][1]); Serial.println("},  // neck top");
  Serial.print("                    {"); Serial.print(preset[2][0]); Serial.print(","); Serial.print(preset[2][1]); Serial.println("},  // neck bottom");
  Serial.print("                    {"); Serial.print(preset[3][0]); Serial.print(","); Serial.print(preset[3][1]); Serial.println("},  // eye right");
  Serial.print("                    {"); Serial.print(preset[4][0]); Serial.print(","); Serial.print(preset[4][1]); Serial.println("},  // eye left");
  Serial.print("                    {"); Serial.print(preset[5][0]); Serial.print(","); Serial.print(preset[5][1]); Serial.println("},  // arm left");
  Serial.print("                    {"); Serial.print(preset[6][0]); Serial.print(","); Serial.print(preset[6][1]); Serial.println("}}; // arm right");

  while(1){}
}

// -------------------------------------------------------------------
/// READ INPUT FROM SERIAL (MODIFIED)
// -------------------------------------------------------------------
void readSerial() {
  char inchar = Serial.read();
  bool moved = false; 

  if (inchar == 'n') {
    moveToNextPosition();
  } else if (inchar == 'a') {
    changeServoPosition(position - 10);
    moved = true;
  } else if (inchar == 'd') {
    changeServoPosition(position + 10);
    moved = true;
  } else if (inchar == 'z') {
    changeServoPosition(position - 1);
    moved = true;
  } else if (inchar == 'c') {
    changeServoPosition(position + 1);
    moved = true;
  }

  // ----- MODIFIED -----
  // If the servo moved, call the new status printing function.
  if (moved) {
    printStatus();
  }
}

// -------------------------------------------------------------------
/// MAIN PROGRAM LOOP
// -------------------------------------------------------------------
void loop() {
  if (Serial.available() > 0){
    readSerial();
  }
}