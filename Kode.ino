#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 7
#define BUZZER_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);

Servo doorServo;

LiquidCrystal_I2C lcd(0x27, 16, 2);

String authorizedUID = "11 22 33 44";

void setup() {

  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  doorServo.attach(SERVO_PIN);
  doorServo.write(0);

  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SMART DOOR LOCK");

  lcd.setCursor(0, 1);
  lcd.print("Tempel Kartu");

  Serial.println("=== RFID READY ===");
  Serial.println("Scan your card...");
}

void loop() {

  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  String scannedUID = "";

  for (byte i = 0; i < rfid.uid.size; i++) {

    if (rfid.uid.uidByte[i] < 0x10) {
      scannedUID += "0";
    }

    scannedUID += String(rfid.uid.uidByte[i], HEX);

    if (i < rfid.uid.size - 1) {
      scannedUID += " ";
    }
  }

  scannedUID.toUpperCase();

  Serial.print("UID : ");
  Serial.println(scannedUID);

  if (scannedUID == authorizedUID) {

    Serial.println("AKSES DITERIMA");

    tone(BUZZER_PIN, 1000, 200);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Akses Diterima");

    lcd.setCursor(0, 1);
    lcd.print("Selamat Datang");

    doorServo.write(90);

    delay(5000);

    doorServo.write(0);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Pintu Tertutup");

    delay(1500);
  }

  else {

    Serial.println("AKSES DITOLAK");

    tone(BUZZER_PIN, 500, 500);

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Akses Ditolak");

    lcd.setCursor(0, 1);
    lcd.print("Kartu Salah");

    doorServo.write(0);

    delay(2000);
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Tempel Kartu");

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(1000);
}