/*
  ESP32 + 2 x L298N + 3 x HC-SR04
  Fully automatic obstacle avoidance

  Front obstacle < 30 cm:
  Stop -> Check left and right
  Prefer left if clear; otherwise right if clear.
  If both sides blocked, remain stopped.
*/

// ===== Driver 1: LEFT SIDE =====
#define ENA 26
#define IN1 27
#define IN2 14
#define ENB 32
#define IN3 25
#define IN4 33

// ===== Driver 2: RIGHT SIDE =====
#define ENA2 18
#define IN1_2 19
#define IN2_2 21
#define ENB2 13
#define IN3_2 22
#define IN4_2 23

// ===== Ultrasonic sensors =====
#define FRONT_TRIG 4
#define FRONT_ECHO 34

#define LEFT_TRIG 16
#define LEFT_ECHO 35

#define RIGHT_TRIG 17
#define RIGHT_ECHO 36

const float SAFE_DISTANCE = 30.0;
const unsigned long ECHO_TIMEOUT = 25000UL;

const int TURN_TIME_MS = 400;
const int REVERSE_TIME_MS = 250;

float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration =
      pulseIn(echoPin, HIGH, ECHO_TIMEOUT);

  // No echo: treat as unknown/unsafe, not clear.
  if (duration == 0) {
    return -1.0;
  }

  return duration * 0.0343 / 2.0;
}

bool isClear(float distance) {
  return distance >= SAFE_DISTANCE;
}

// Stop every motor
void stopAll() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(ENA2, LOW);
  digitalWrite(ENB2, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW);
  digitalWrite(IN4_2, LOW);
}

// Driver 1 left side, Driver 2 right side
void moveForward() {
  // Left side forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Right side forward
  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, HIGH);
  digitalWrite(IN4_2, LOW);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(ENA2, HIGH);
  digitalWrite(ENB2, HIGH);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN3_2, LOW);
  digitalWrite(IN4_2, HIGH);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(ENA2, HIGH);
  digitalWrite(ENB2, HIGH);
}

// Left side backward, right side forward
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN1_2, HIGH);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, HIGH);
  digitalWrite(IN4_2, LOW);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(ENA2, HIGH);
  digitalWrite(ENB2, HIGH);
}

// Left side forward, right side backward
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN1_2, LOW);
  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN3_2, LOW);
  digitalWrite(IN4_2, HIGH);

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(ENA2, HIGH);
  digitalWrite(ENB2, HIGH);
}

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA2, OUTPUT);
  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(ENB2, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN4_2, OUTPUT);

  pinMode(FRONT_TRIG, OUTPUT);
  pinMode(FRONT_ECHO, INPUT);

  pinMode(LEFT_TRIG, OUTPUT);
  pinMode(LEFT_ECHO, INPUT);

  pinMode(RIGHT_TRIG, OUTPUT);
  pinMode(RIGHT_ECHO, INPUT);

  stopAll();
  Serial.println("Automatic obstacle avoidance started");
}

void loop() {
  float front = readDistance(FRONT_TRIG, FRONT_ECHO);

  Serial.print("Front: ");
  Serial.println(front);

  if (isClear(front)) {
    moveForward();
    delay(60);
    return;
  }

  // Front blocked or reading invalid
  stopAll();
  delay(150);

  // Read sensors one by one to reduce cross-talk
  float leftDistance = readDistance(LEFT_TRIG, LEFT_ECHO);
  delay(60);
  float rightDistance = readDistance(RIGHT_TRIG, RIGHT_ECHO);
  delay(60);

  Serial.print("Left: ");
  Serial.print(leftDistance);
  Serial.print(" cm | Right: ");
  Serial.println(rightDistance);

  if (isClear(leftDistance)) {
    turnLeft();
    delay(TURN_TIME_MS);
    stopAll();
    delay(100);
  }
  else if (isClear(rightDistance)) {
    turnRight();
    delay(TURN_TIME_MS);
    stopAll();
    delay(100);
  }
  else {
    // Both directions blocked or sensor readings invalid
    stopAll();
    delay(250);

    // Reverse briefly only if the rear path is known to be clear.
    // No rear sensor is installed, so do not reverse automatically.
  }
}
