#include "DHT.h"
#include <ESP32Servo.h>
#define DHTPIN 27 
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
Servo myservo; 
int pos = 0;
int servoPin = 5;

void setup() {
  Serial.begin(9600);
  dht.begin();
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 1000, 2000); // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
}

void loop() {
  
  //demo code
  float h = dht.readHumidity();
  Serial.println(h);
  myservo.write(180);
  delay(1000);
  myservo.write(-180);
  delay(1000);

  //for realistic applications
  //use an if statement to check whether humidity is above a certain threshold
  //if true then move servo/motor to open grate
  //use an if statement to check whether humidity is below a certain threshold and if the grate is open
  //if true then move servo/motor to close gate

  
}
