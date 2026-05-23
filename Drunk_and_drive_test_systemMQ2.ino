#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // Most common address = 0x27
Servo gate;

int irSensor = 8;
int mq3 = A0;
int fan = 9;
int buzzer = 10;
int servoPin = 11;

int alcoholLevel = 0;
int threshold = 300;  // Adjust if needed

void setup() {

  lcd.init();
  lcd.backlight();

  pinMode(irSensor, INPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);

  gate.attach(servoPin);
  gate.write(0);   // Gate closed

  lcd.setCursor(0, 0);
  lcd.print(" Alcohol Test ");
  lcd.setCursor(0, 1);
  lcd.print("  System Ready ");
  delay(2000);
  lcd.clear();
}

void loop() {

  int carDetected = digitalRead(irSensor);

  if (carDetected == LOW) {    // Car present (IR triggered)
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Car Detected");

    digitalWrite(fan, HIGH);   // Fan ON
    delay(1500);               // Send fumes to MQ3

    alcoholLevel = analogRead(mq3);

    lcd.setCursor(0, 1);
    lcd.print("Checking....");
    delay(1500);

    lcd.clear();

    if (alcoholLevel > threshold) {    // Alcohol Present

      lcd.setCursor(0, 0);
      lcd.print("Alcohol Found!");
      lcd.setCursor(0, 1);
      lcd.print("Entry Blocked");

      digitalWrite(buzzer, HIGH);
      gate.write(0);   // Keep gate closed
      delay(3000);
      digitalWrite(buzzer, LOW);
    }

    else {   // No alcohol detected

      lcd.setCursor(0, 0);
      lcd.print("No Alcohol");
      lcd.setCursor(0, 1);
      lcd.print("Entry Allowed");

      gate.write(90);    // Gate opens
      delay(3000);

      gate.write(0);     // Gate closes
      lcd.clear();
    }

    digitalWrite(fan, LOW);
  }

  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Waiting for Car");
    delay(500);
  }
}