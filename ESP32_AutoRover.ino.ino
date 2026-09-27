/*
 * Project: ESP32 Smart Obstacle Avoiding Car
 * Description: An autonomous robot car using ESP32, L298N Motor Driver, and HC-SR04 Ultrasonic Sensor.
 */

// ===== MOTOR DRIVER PINS (L298N) =====
const int IN1 = 5;   // Right Motor Forward
const int IN2 = 26;  // Right Motor Backward
const int IN3 = 25;  // Left Motor Forward
const int IN4 = 19;  // Left Motor Backward
const int ENA = 23;  // Right Motor Speed (PWM)
const int ENB = 18;  // Left Motor Speed (PWM)

// ===== ULTRASONIC SENSOR PINS =====
const int TRIG_PIN = 13; // Sensor's TRIG pin
const int ECHO_PIN = 14; // Sensor's ECHO pin

// ===== CAR SETTINGS =====
const int SPEED_LEFT = 130;     // PWM Speed (0-255)
const int SPEED_RIGHT = 130;    // PWM Speed (0-255)
const int SAFE_DISTANCE = 25;   // Obstacle detection threshold (cm)

void setup() {
  Serial.begin(115200);

  // Initialize Motor Pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize Sensor Pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Ensure car is stationary at startup
  stopCar();
  delay(2000); 
}

void loop() {
  int distance = getDistance();
  
  Serial.print("Obstacle Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < SAFE_DISTANCE) {
    // Obstacle detected
    stopCar();
    delay(300);

    backward();  // Move back slightly
    delay(400); 
    stopCar();
    delay(200);

    turnRight(); // Change direction
    delay(500);  
  } else {
    // Path is clear
    forward();
  }

  delay(60); // Small delay for sensor stability
}

// ===== ULTRASONIC SENSOR FUNCTION =====
int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int dist = duration * 0.034 / 2; // Convert time to cm
  return dist;
}

// ===== MOTOR MOVEMENT FUNCTIONS =====
void forward() {
  analogWrite(ENA, SPEED_RIGHT);
  analogWrite(ENB, SPEED_LEFT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, SPEED_RIGHT);
  analogWrite(ENB, SPEED_LEFT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  analogWrite(ENA, SPEED_RIGHT);
  analogWrite(ENB, SPEED_LEFT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, SPEED_RIGHT);
  analogWrite(ENB, SPEED_LEFT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}