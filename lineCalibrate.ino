//Distances from the centroid of the robot to the centre of each sensor in mm 
float x1 = -22.5;
float x2 = -7.5;
float x3 = 7.5;
float x4 = 22.5;

//Variables to store each data point in
float w1;
float w2;
float w3;
float w4;

//Variables for storing the numerator and denominator of Equation 1
float den = 0;   
float num = 0;

void setup() {
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  pinMode(5,OUTPUT); //set ENA as an output
  pinMode(6,OUTPUT); //set ENB as an output
  pinMode(8,OUTPUT); //set IN1 as an output
  pinMode(9,OUTPUT); //set IN2 as an output
  pinMode(10,OUTPUT); //set IN3 as an output
  pinMode(11,OUTPUT); //set IN4 as an output

  Serial.begin(115200);
}

void loop() {
  w1 = analogRead(A1);
  w2 = analogRead(A2);
  w3 = analogRead(A3);
  w4 = analogRead(A5);

  num = (w1 * x1) + (w2 * x2) + (w3 * x3) + (w4 * x4);
  den = w1 + w2 + w3 + w4;

  float lineDist = num/den;

  Serial.print("Distance from line = ");
  Serial.println(lineDist);
  delay(50);  //  50ms delay
  leftForwards;
  rightForwards;
  if(lineDist > -15){
    analogWrite(5, 90);
    analogWrite(6, 70);
  }
  else if(lineDist > 10){
    analogWrite(5, 70);
    analogWrite(6, 90);
  }
  else{
    analogWrite(5, 80);
    analogWrite(6, 80);
  }
}

void leftForwards(void) //This function sets IN1 = LOW and IN2 = HIGH in order to set the direction to forwards for motor 1
{
  digitalWrite(8,HIGH); //IN1
  digitalWrite(9,LOW); //IN2
}

void leftBackwards(void) //This function sets IN1 = HIGH and IN2 = LOW in order to set the direction to backwards for motor 1
{
  digitalWrite(8,LOW); //IN1
  digitalWrite(9,HIGH); //IN2
}

void rightForwards(void)  //This function sets IN3 = LOW and IN4 = HIGH in order to set the direction to forwards for motor 2
{
  digitalWrite(10,HIGH); //IN3
  digitalWrite(11,LOW); //IN4
}
void rightBackwards(void) //This function sets IN3 = HIGH and IN4 = LOW in order to set the direction to forwards for motor 2
{
  digitalWrite(10,LOW); //IN3
  digitalWrite(11,HIGH); //IN4
}
