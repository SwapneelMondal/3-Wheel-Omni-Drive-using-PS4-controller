
int ledPin=13;

void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
  digitalWrite(ledPin,HIGH);
  delay(10000);
  digitalWrite(ledPin,LOW);
  delay(10000);

}
