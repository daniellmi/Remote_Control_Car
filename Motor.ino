#include <Ultrasonic.h>


#define echo 8
#define trigger 9 

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

#define ENA 2
#define ENB 7

class Motor {

  public:

  Motor() {
    
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

  }

void Motor::go(int speed1, int speed2) {

  analogWrite(ENA, speed1);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speed2);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void Motor::stop() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
};


class Sensor {

  private:
  Ultrasonic ultra;
  int distance;

  public:

  Sensor(): ultra(trigger,echo) {
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
  }

  void initSensor() {
    distance = ultra.read(CM);
  }
  int getDistance() {
    return distance;
  }
};


 Motor motor;
Sensor sensor;
void setup() {
  Serial.begin(9600);

}

void loop() {
   sensor.initSensor();

 if(sensor.getDistance() <= 10) 
   motor.stop();
  // else
      motor.go(200,200);

  Serial.print("distance:");
  Serial.println(sensor.getDistance());
  delay(200);

}