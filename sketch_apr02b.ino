#include <Servo.h>


// These #define statements make the code more readable.
// Instead of a pin number "7" or "12" we can write "ECHO" or "TRIG"
#define ECHO 12
#define TRIG 7

int servoPin = A4;
  Servo servo;  
  int angle = 0;   // servo position in degrees 

void setup() {
  pinMode(ECHO,INPUT); //Initialise pin 12 as an input
  pinMode(TRIG,OUTPUT); //Initialise pin 7 as an output
  Serial.begin(9600); //begin serial communication 
  pinMode(5,OUTPUT); //set ENA as an output
  pinMode(6,OUTPUT); //set ENB as an output
  pinMode(8,OUTPUT); //set IN1 as an output
  pinMode(9,OUTPUT); //set IN2 as an output
  pinMode(10,OUTPUT); //set IN3 as an output
  pinMode(11,OUTPUT); //set IN4 as an output
  servo.attach(A4); 
   
}
  
void loop() {
    for(angle = 30; angle < 150; angle=angle+10)  
  { 
      unsigned int distance_mm = 0; //This variable will hold the distance
      leftForwards();
      rightForwards();
      distance_mm = sonar_mm(); //call the function sonar_mm and store the result in distance_mm
      Serial.print("Distance="); //print the result to the serial monitor
      Serial.println(distance_mm);
      int sensorVal = digitalRead(A5);
      Serial.println(sensorVal);

      if(distance_mm <= 150 && distance_mm <=100 && sensorVal==0)
       {
             leftForwards();
             rightForwards();
             analogWrite(5,40);  
             analogWrite(6,20); 

        }
       else if (distance_mm>150 && distance_mm<=250 && sensorVal==0)
         {
              leftForwards();
              rightForwards();
              Serial.print("Distance=");
              Serial.println(distance_mm);
              analogWrite(5,70);  //set the left motor to half speed (ish)
              analogWrite(6,50); //set the right motor to half speed (ish)
         }
        else if (distance_mm > 250 && sensorVal==0)
  
        { 
               leftForwards();
               rightForwards();   
               analogWrite(5,90);  //set the left motor to full speed (ish)
               analogWrite(6,70); //set the right motor to full speed (ish)
          }
         else{
                leftBackwards();
                rightBackwards();
                analogWrite(5,0);
                analogWrite(6,0);
                delay(1000);
                leftBackwards();
                rightBackwards();
                analogWrite(5,80);
                analogWrite(6,0);
                delay(1000);
          }
                                
            servo.write(angle);               
            delay(15);                   
      } 
  // now scan back from 180 to 0 degrees
  for(angle = 150; angle > 30; angle=angle-10)    
        { 
          unsigned int distance_mm = 0; //This variable will hold the distance
        leftForwards();
        rightForwards();
        distance_mm = sonar_mm(); //call the function sonar_mm and store the result in distance_mm
        Serial.print("Distance="); //print the result to the serial monitor
        Serial.println(distance_mm);
        int sensorVal = digitalRead(A5);
        Serial.println(sensorVal);

        if(distance_mm <= 100 && sensorVal==0)
            {
              leftForwards();
              rightForwards();
              analogWrite(5,90);  
              analogWrite(6,70); 
          
            }
         else if (distance_mm>100 && distance_mm<=150 && sensorVal==0)
              {
                leftForwards();
                rightForwards();
                Serial.print("Distance=");
                Serial.println(distance_mm);
                analogWrite(5,90);  //set the left motor to half speed (ish)
                analogWrite(6,70); //set the right motor to half speed (ish)
              }
          else if (distance_mm > 150 && sensorVal==0)
  
                { 
                  leftForwards();
                  rightForwards();   
                  analogWrite(5,70);  //set the left motor to full speed (ish)
                  analogWrite(6,90); //set the right motor to full speed (ish)
                }
          else{
                  analogWrite(5,0);
                  analogWrite(6,0);
                }
                                               
              servo.write(angle);           
              delay(15);       
      } 
 
  unsigned int distance_mm = 0; //This variable will hold the distance
  leftForwards();
  rightForwards();
  distance_mm = sonar_mm(); //call the function sonar_mm and store the result in distance_mm
  Serial.print("Distance="); //print the result to the serial monitor
  Serial.println(distance_mm);
  int sensorVal = digitalRead(A5);
  Serial.println(sensorVal);

  if(distance_mm <= 100 && sensorVal==0)
  {
    leftForwards();
    rightForwards();
    analogWrite(5,90);  
    analogWrite(6,70); 

  }
  else if (distance_mm>100 && distance_mm<=150 && sensorVal==0)
  {
    leftForwards();
    rightForwards();
    Serial.print("Distance=");
    Serial.println(distance_mm);
    analogWrite(5,90);  //set the left motor to half speed (ish)
    analogWrite(6,70); //set the right motor to half speed (ish)
  }
  else if (distance_mm > 150 && sensorVal==0)
  
  { 
    leftForwards();
    rightForwards();   
    analogWrite(5,70);  //set the left motor to full speed (ish)
    analogWrite(6,90); //set the right motor to full speed (ish)
  }
  else{
    analogWrite(5,0);
    analogWrite(6,0);
  }
  delay(100);
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


  
unsigned int sonar_mm(void){
  long duration = 0;
  const float speed_sound = 340.29;// m/s, "const" makes the compiler able to optimise the program where this variable is used, cool!
  // Read in a distance from the ultrasonic distance sensor:
  // The ultrasonic burst is triggered by a HIGH pulse of 10 microseconds.
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  //read length of time pulse
  duration = pulseIn(ECHO, HIGH); //This function measures a pulsewidth and returns the width in microseconds
  // convert the time into a distance
  // the code "(unsigned int)" turns the result of the distance calculation
  // into an integer instead of a floating point (decimal or fractional) number.
  return (unsigned int)(0.5 * duration * 1e-6 * speed_sound * 1e3); 
  //"unsigned" ensures we are returning an unsigned number, remember that there is no such thing as negative distance.
  
}
