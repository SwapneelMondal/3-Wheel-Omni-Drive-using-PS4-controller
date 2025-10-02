```cpp
int en1 = 6; 
int in1 = 4; 
int in2 = 5; 
int en2 = 3; 
int in3 = 9; 
int in4 = 10; 
int en3 = 11; 
int in5 = 13; 
int in6 = 12; 

float L = 0.1; 
float r = 0.05; 
float Vx = 0.2; 
float Vy = 0.0; 
float W = 0.0; 

void setup() {
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en3, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float w1 = (-0.866 * Vx - 0.5 * Vy + L * W)/r;  
  float w2 = ( 0.866 * Vx - 0.5 * Vy + L * W)/r;  
  float w3 = ( 0.0 * Vx + 1.0 * Vy + L * W)/r;    

  setMotor(en1, in1, in2, w1);
  setMotor(en2, in3, in4, w2);
  setMotor(en3, in5, in6, w3);

  delay(100);
}

void setMotor(int pwmPin, int dir1, int dir2, float speed) {
  int pwmVal = constrain(abs(speed)/0.2*255, 0, 255);
  if (speed > 0) {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  } else if (speed < 0) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  } else {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
  }
  analogWrite(pwmPin, pwmVal);
}
```
