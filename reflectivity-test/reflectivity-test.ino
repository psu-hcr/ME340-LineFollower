
//this is a change to the code
int phototransD = 9; //the digital input pin
int phototransA = A0;//the analog input pin
//decrlaring variables to store the input values
int val=0;
int aval=0;

// the setup routine runs once when you press reset:
void setup() {
  //set input pins
  pinMode(phototransD, INPUT);
  pinMode(phototransA, INPUT);
  //initialize serial port
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  
  }

// the loop routine runs over and over again forever:
void loop() {
  //read the input values from the digital and analog pins
  val=digitalRead(phototransD);
  aval = analogRead(phototransA);
  digitalWrite(LED_BUILTIN, val);//Turn the LED on or off based on the digital input
  //publish the analog value to the serial port
  Serial.println(aval);
  delay(1000);                       // wait for a second
  }
