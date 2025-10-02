#include <USBHost_t36.h>

USBHost myusb;
USBHub hub1(myusb);
USBHub hub2(myusb);
BluetoothController bluet(myusb);
JoystickController joystick(myusb);


void setup() {
  Serial.begin(9600);
  while (!Serial && millis() < 10000);
  Serial.println("Waiting for controller...");
}

void loop() {
  myusb.Task(); 

  if (joystick.available()) {
    int lx = joystick.getAxis(0);
    int ly = joystick.getAxis(1); 

    Serial.print("LX: "); 
    Serial.print(lx);
    Serial.print("  LY: "); 
    Serial.println(ly);

    delay(50);
  }
}
