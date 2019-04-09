//Distances from the centroid of the robot to the centre of each sensor in mm 
float x1 = -22;
float x2 = -7;
float x3 = 7;
float x4 = 22;

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

  Serial.begin(115200);
}

void loop() {
  w1 = analogRead(A1);
  w2 = analogRead(A2);
  w3 = analogRead(A3);
  w4 = analogRead(A4);

  num = w1*x1 + w2*x2 + w3*x3 + w4*x4;
  den = w1 + w2 + w3 + w4;

  float lineDist = num/den;

  Serial.print("Distance from line = ");
  Serial.println(lineDist);
  delay(50);  //  50ms delay

  if()
}
