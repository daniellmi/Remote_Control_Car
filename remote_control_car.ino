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

  void Motor::go(int speed) {

    analogWrite(ENA, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  void Motor::left(int speed) {

    analogWrite(ENA, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
  }

  void Motor::right(int speed) {

    analogWrite(ENA, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    analogWrite(ENB, speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  void Motor::back() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
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

  Sensor(): ultra(trigger, echo) {
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
  }

  int readtSensor() {
    distance = ultra.read(CM);
    return distance;
  }
};


class Bluetooth {

private:
  char c = ' ';
  Motor motor;
  Sensor sensor;

public:

  Bluetooth() {
  }

  void Bluetooth::CarControl() {
    if (Serial.available()){      
      c = Serial.read();
    }

    sensor.readtSensor();

    switch (c) {

      case 'f':
        if (sensor.readtSensor() <= 15)
          motor.stop();
        else
          motor.go(200);
        break;

      case 'b':
        motor.back();
        break;

      case 'l':
        motor.left(100);
        break;

      case 'r':
        motor.right(100);
        break;

      default:
        motor.stop();
    }
  }

  char Bluetooth::getC() {
    return c;
  }
};

Motor motor;
Sensor sensor;

void setup() {
  Serial.begin(9600);
}


Bluetooth bluetooth;

void loop() {

   bluetooth.CarControl() ;
  Serial.print("distance:");
  Serial.println(sensor.getDistance());
  delay(200);
}
