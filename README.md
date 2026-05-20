# Smart Door Lock RFID System

An Arduino-based smart door lock system utilizing RFID authentication for secure access control. This project integrates the MFRC522 RFID module, servo motor locking mechanism, I2C LCD display, and buzzer notification system to provide a reliable and user-friendly security solution.

The system verifies RFID card UID data before granting access. Authorized cards trigger automatic door unlocking through the servo motor, while unauthorized attempts generate warning notifications via the LCD and buzzer.

---

# Features

* RFID-based authentication
* Automatic door locking and unlocking
* LCD status display
* Audio notification using buzzer
* Real-time UID monitoring via Serial Monitor
* Simple and expandable hardware design

---

# Hardware Components

| Component           | Quantity |
| ------------------- | -------- |
| Arduino UNO / Nano  | 1        |
| MFRC522 RFID Reader | 1        |
| Servo Motor         | 1        |
| I2C LCD 16x2        | 1        |
| Buzzer              | 1        |
| Jumper Wires        | Several  |

---

# Pin Configuration

| Module        | Arduino Pin |
| ------------- | ----------- |
| RFID SDA (SS) | D10         |
| RFID RST      | D9          |
| Servo Signal  | D7          |
| Buzzer        | D8          |
| LCD SDA       | A4          |
| LCD SCL       | A5          |

---

# Required Libraries

Install the following libraries through Arduino IDE Library Manager:

* SPI
* MFRC522
* Servo
* Wire
* LiquidCrystal_I2C

---

# System Workflow

1. User scans RFID card/tag.
2. System reads UID from RFID card.
3. UID is compared with authorized UID.
4. If authorized:

   * LCD displays access granted
   * Buzzer notification activates
   * Servo unlocks the door
5. If unauthorized:

   * LCD displays access denied
   * Warning buzzer activates
   * Door remains locked

---

# Circuit Overview

* MFRC522 communicates using SPI protocol.
* LCD uses I2C communication.
* Servo controls door lock mechanism.
* Buzzer provides audio feedback.

---

# How to Use

## 1. Upload the Code

Upload the Arduino sketch using Arduino IDE.

## 2. Find Your RFID UID

Open Serial Monitor and scan your RFID card to get the UID.

Example:

```txt
UID : 11 22 33 44
```

## 3. Replace Authorized UID

Edit this line in the code:

```cpp
String authorizedUID = "11 22 33 44";
```

Replace it with your RFID card UID.

## 4. Scan the RFID Card

* Authorized card → Door opens
* Unauthorized card → Access denied

---

# Project Structure

```txt
Smart-Door-Lock-RFID/
│
├── SmartDoorLock.ino
├── README.md
└── images/
```

---

# Applications

* Smart home security
* Office access control
* Laboratory security systems
* Embedded systems projects
* IoT learning and prototyping

---

# Future Improvements

* Multiple RFID card support
* Password keypad integration
* IoT monitoring using ESP32
* Mobile application control
* Database logging system

---

# Author

Developed for embedded systems and IoT learning purposes using Arduino and RFID technology.
