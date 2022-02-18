
// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define FORWARD  0
#define REVERSE 1

// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
//Default pins:
#define DIRA 2 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B

int phototransD = 9; //the digital input pin
//int phototransA = A0;//the analog input pin
//decrlaring variables to store the input values
int val=0;
//int aval=0;

// the setup routine runs once when you press reset:
void setup() {
  //set input pins
  pinMode(phototransD, INPUT);
//  pinMode(phototransA, INPUT);
  setupArdumoto(); // Set all pins as outputs
  
  }

// the loop routine runs over and over again forever:
void loop() {
  //read the input values from the digital and analog pins
  val=digitalRead(phototransD);
  //aval = analogRead(phototransA);
   
  // Drive motor A and B at medium speed in the direction indicated by the 
  //phototransistor
  if(val==LOW){
  driveArdumoto(MOTOR_A, FORWARD, 255); // Set motor A to run at half
  driveArdumoto(MOTOR_B, FORWARD, 255);  // Set motor B to FORWARD at half
  }
  else{
    driveArdumoto(MOTOR_A, REVERSE, 255); // Set motor A to run at half
  driveArdumoto(MOTOR_B, REVERSE, 255);  // Set motor B to FORWARD at half
  }
  delay(1000);  // Motor A will keep trucking for 1 second 
  stopArdumoto(MOTOR_A);  // STOP motor A 
  stopArdumoto(MOTOR_B);  // STOP motor B 
 }


void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}
// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}
