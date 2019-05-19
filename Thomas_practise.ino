#define MID A2
#define LS A3
#define RS A1

void setup() {
  //pinMode(ECHO,INPUT); //Initialise pin 12 as an input
  //pinMode(TRIG,OUTPUT); //Initialise pin 7 as an output
  Serial.begin(9600); //begin serial communication   
  pinMode(A1, INPUT); //Far right line sensor
  pinMode(A2, INPUT); //Inner right line sensor
  pinMode(A3, INPUT); //Inner left line sensor
  //pinMode(A5, INPUT); //Far left line sensor
  pinMode(5,OUTPUT); //set ENA as an output
  pinMode(6,OUTPUT); //set ENB as an output
  pinMode(8,OUTPUT); //set IN1 as an output
  pinMode(9,OUTPUT); //set IN2 as an output
  pinMode(10,OUTPUT); //set IN3 as an output
  pinMode(11,OUTPUT); //set IN4 as an output
  //servo.attach(13); 
   
}
void leftForwards(void) //This function sets IN1 = LOW and IN2 = HIGH in order to set the direction to forwards for motor 1
{
  digitalWrite(8,HIGH); //IN1
  digitalWrite(9,LOW); //IN2
}

void rightForwards(void)  //This function sets IN3 = LOW and IN4 = HIGH in order to set the direction to forwards for motor 2
{
  digitalWrite(10,HIGH); //IN3
  digitalWrite(11,LOW); //IN4
}

void loop() { 
  if(digitalRead(MID))     // Move Forward
  {
    leftForwards();
    rightForwards();
    digitalWrite(5, 70);
    digitalWrite(6, 70);
  }
  
  if(digitalRead(LS))     // Turn right
  {
    leftForwards();
    rightForwards();
    digitalWrite(5, 30);
    digitalWrite(6, 70);

  }
  
  if(digitalRead(RS))     // turn left
  {
    leftForwards();
    rightForwards();
    digitalWrite(5, 70);
    digitalWrite(6, 30);
  }
  
  /*if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}*/
