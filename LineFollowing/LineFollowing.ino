
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
  pinMode(phototransR, INPUT);
  pinMode(phototransL, INPUT);
  setupArdumoto(); // Set all pins as outputs
  
  }

// the loop routine runs over and over again forever:
void loop() {
  //read the input values from the digital and analog pins
  valR=digitalRead(phototransR);
  valL=digitalRead(phototransL);

 //both sensors straddle line (default)
  if(valR==LOW && valL==LOW){//both on white
    driveArdumoto(MOTOR_R, FORWARD, DEFAULTV); 
    driveArdumoto(MOTOR_L, FORWARD, DEFAULTV);  
  }
  else if (valR==HIGH && valL==LOW){//right on black left on white
    //turn right
    driveArdumoto(MOTOR_R, FORWARD, 0.5*DEFAULTV); 
    driveArdumoto(MOTOR_L, FORWARD, DEFAULTV);
    
  }
  else if (valR==LOW && valL==HIGH){//right on white black on left
    //turn left
    driveArdumoto(MOTOR_R, FORWARD, DEFAULTV); 
    driveArdumoto(MOTOR_L, FORWARD, 0.5*DEFAULTV);
  }
  else{//both on black
    //stop, spin in place, backwards, random input
    stopArdumoto(MOTOR_A);  // STOP motor A 
    stopArdumoto(MOTOR_B);  // STOP motor B 
    
  }
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
