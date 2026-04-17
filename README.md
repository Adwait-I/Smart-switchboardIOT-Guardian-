# 🔌 Smart Switchboard Guardian++

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
     +--------v----------+
     |     ESP32         |
     |  (Controller)     |
     +---+-----+----+----+
         |     |    |
         |     |    |
  +------v+  +-v-+  v
  | Relay |  |LED| OLED
  +---+---+  +---+ Display
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

## 🎥 Demo

![Demo](IMG_3762 (1).gif)

---

## 🎬 Project Preview

![Project GIF](https://media.giphy.com/media/3o7TKMt1VVNkHV2PaE/giphy.gif)

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


## 🌟 Novelty
	•	Combines multiple safety mechanisms into one system
	•	Works offline (no internet dependency)
	•	Low-cost and easy to implement
	•	Modular and scalable design
  ____

 ## 📈 Future Enhancements
	•	Mobile app notifications
	•	Energy consumption tracking
	•	Voice control integration
	•	Smart home ecosystem integration

⸻
## 📜 License

This project is open-source and available under the MIT License.
