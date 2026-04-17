# 🔌 Smart Switchboard Guardian++


[Project GIF](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExMmw5cjQ1Y3ZyZHczOXo4cWV2OWIxeXZwMzBzMWtyaGwycnZpNmR4cSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/S93WQ0wrqd8AupBTuh/giphy.gif)
An IoT-based intelligent electrical switchboard designed to enhance safety and energy awareness using real-time monitoring and automated control.

---

## 🚀 Overview

Smart Switchboard Guardian++ transforms a traditional switchboard into a smart, safety-enabled system. It detects hazardous conditions like overheating and moisture presence, and automatically disconnects power to prevent accidents.

---

## 🎯 Features

- ⚡ Automatic power cut using relay
- 🌡️ Temperature monitoring (loose wiring detection)
- 💧 Moisture detection (shock prevention)
- 📟 Real-time OLED display
- 💡 LED-based alert system
- 🔄 Fully automated safety mechanism
- 🔌 Works without internet (offline system)

---

## 🧠 Architecture

     +-------------------+
     |   Temperature     |
     |    Sensor         |
     +--------+----------+
              |
              |
     +-------------------+
     |      ESP32        |
     |   (Controller)    |
     +----+----+----+----+
          |    |    |
          |    |    |
    +-----+  +---+  +--------+
    | Relay |  |LED|  |  OLED  |
    +---+---+  +---+  +--------+
        |
        |
    AC Power Supply
        |
       Load

---

## 🧩 Components Used

- ESP32 Development Board  
- DS18B20 Temperature Sensor  
- Capacitive Moisture Sensor  
- Relay Module  
- OLED Display (SSD1306)  
- LED Indicator  
- Breadboard & Wires  

---

## 🔧 Working Principle

1. ESP32 continuously reads temperature and moisture values  
2. If:
   - Temperature exceeds threshold OR  
   - Moisture detected  
3. Then:
   - Relay turns OFF (cuts power)  
   - LED turns ON  
   - OLED displays alert  

Otherwise:
- System remains active and safe  

---
## 🎬 Project Preview

![Demo](assets/IMG_3762%20(1).gif)

---

## 💻 Code

The ESP32 code handles:
- Sensor data reading  
- Threshold checking  
- Relay control  
- Display output  

---

## ⚙️ Installation

### 1. Install dependencies

Using Arduino CLI:
bash
arduino-cli lib install "OneWire"
arduino-cli lib install "DallasTemperature"
arduino-cli lib install "Adafruit GFX Library"
arduino-cli lib install "Adafruit SSD1306"

---

## 🌟 Novelty
	•	Combines multiple safety mechanisms into one system
	•	Works offline (no internet dependency)
	•	Low-cost and easy to implement
	•	Modular and scalable design
---

 ## 📈 Future Enhancements
	•	Mobile app notifications
	•	Energy consumption tracking
	•	Voice control integration
	•	Smart home ecosystem integration

---


## 📜 License

This project is open-source and available under the MIT License.
