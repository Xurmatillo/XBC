#include <AFMotor.h> // XURMATILLO OXUNOV XIKMATULLAYEVICH 15/06/2025 23:34:27
#include <SoftwareSerial.h>

// Motor obyektlari
AF_DCMotor motor1(1); // M1
AF_DCMotor motor2(2); // M2
AF_DCMotor motor3(3); // M3
AF_DCMotor motor4(4); // M4

// Bluetooth RX - pin 2, TX - pin 3
SoftwareSerial BT(2, 3); // RX, TX BLUETOOTH'NI 2 VA 3 RAQAMLI ARDUINO PINIGA ULANG.

char command;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  // Motor tezligini maksimalga sozlash
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop() {
  if (BT.available()) {
    command = BT.read();
    Serial.println(command); // Debug uchun

    switch (command) {
      case 'F': // Oldinga
        forward();
        break;
      case 'B': // Orqaga
        backward();
        break;
      case 'L': // Chapga burilish (tank-style)
        turnLeft();
        break;
      case 'R': // O‘ngga burilish (tank-style)
        turnRight();
        break;
      case 'S': // To‘xtash
        stopMotors();
        break;
      default:
        stopMotors();
        break;
    }
  }
}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
