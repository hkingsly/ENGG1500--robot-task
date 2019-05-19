void setup() {
  pinMode(ECHO,INPUT); //Initialise pin 12 as an input
  pinMode(TRIG,OUTPUT); //Initialise pin 7 as an output
  Serial.begin(9600); //begin serial communication   
  pinMode(A1, INPUT); //Far right line sensor
  pinMode(A2, INPUT); //Inner right line sensor
  pinMode(A3, INPUT); //Inner left line sensor
  pinMode(A5, INPUT); //Far left line sensor
  pinMode(5,OUTPUT); //set ENA as an output
  pinMode(6,OUTPUT); //set ENB as an output
  pinMode(8,OUTPUT); //set IN1 as an output
  pinMode(9,OUTPUT); //set IN2 as an output
  pinMode(10,OUTPUT); //set IN3 as an output
  pinMode(11,OUTPUT); //set IN4 as an output
  servo.attach(13); 
   
}
