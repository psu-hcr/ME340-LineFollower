// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define FORWARD  0
#define REVERSE 1

// Motor definitions to make life easier:
#define MOTOR_R 0
#define MOTOR_L 1

// Pin Assignments //
//Default pins:
#define DIRA 2 // Direction control for motor R
#define PWMA 3  // PWM control (speed) for motor R
#define DIRB 4 // Direction control for motor L
#define PWMB 11 // PWM control (speed) for motor L

int DEFAULTV = 200;

int phototransR = 9; //the right sensor
int phototransL = 10;//the left sensor
//decrlaring variables to store the input values
int valR=0;
int valL=0;

// the setup routine runs once when you press reset:
void setup() {
  //set input pins
  setupArdumoto(); // Set all pins as outputs
  
  }

// the loop routine runs over and over again forever:
void loop() {
   
    driveArdumoto(MOTOR_R, FORWARD, DEFAULTV); //travel forward 30cm
    driveArdumoto(MOTOR_L, FORWARD, DEFAULTV);  
    delay(2000);
    
    stopArdumoto(MOTOR_R);  // STOP motor A 
    stopArdumoto(MOTOR_L);  // STOP motor B 
    delay(1000);

    driveArdumoto(MOTOR_L, FORWARD, DEFAULTV);//Make a 90deg turn right
    delay(1000);

    stopArdumoto(MOTOR_R);  // STOP motor A 
    stopArdumoto(MOTOR_L);  // STOP motor B 
    delay(1000);
    
    driveArdumoto(MOTOR_R, FORWARD, DEFAULTV);//Make a 90deg turn left
    delay(1000);
    
    stopArdumoto(MOTOR_R);  // STOP motor A 
    stopArdumoto(MOTOR_L);  // STOP motor B 
    delay(1000);
      
    driveArdumoto(MOTOR_R, REVERSE, DEFAULTV); //travel reverse 30cm
    driveArdumoto(MOTOR_L, REVERSE, DEFAULTV);
    delay(2000);

    stopArdumoto(MOTOR_R);  // STOP motor A 
    stopArdumoto(MOTOR_L);  // STOP motor B 
    delay(1000);

    driveArdumoto(MOTOR_R, REVERSE, DEFAULTV); //rotate clockwise 360deg
    driveArdumoto(MOTOR_L, FORWARD, DEFAULTV);
    delay(4000);
    
    
    stopArdumoto(MOTOR_R);  // STOP motor A 
    stopArdumoto(MOTOR_L);  // STOP motor B 
    delay(10000);
    
  
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
  if (motor == MOTOR_R)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_L)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}
