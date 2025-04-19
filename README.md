# Green Heart Monitor 🚀

A portable, low-power IoT device built on the Arduino Nano ESP32 for real-time monitoring of environmental conditions and animal health metrics.

---

## 📚 Table of Contents

- [Overview](#overview)
- [Key Features](#key-features)
- [Hardware Components](#hardware-components)
- [Software Setup](#software-setup)
- [Usage](#usage)
- [Project Architecture](#project-architecture)
- [Future Work](#future-work)
- [License](#license)

---

## 🧭 Overview

**Green Heart Monitor** is a portable, battery-friendly device based on the **Arduino Nano ESP32**. It provides:

- 🌱 Real-time tracking of environmental and animal health metrics  
- 🌐 Web-based dashboard accessible via Wi‑Fi  
- 📟 On-board OLED display for local monitoring  

Perfect for ecological research, wildlife conservation, and field data collection.

---

## 🛠️ Key Features

- ⚙️ **Multi-Sensor Integration**: Water level, ambient light, humidity, temperature, GPS, and heartbeat.
- 🌐 **Live Dashboard**: HTTP server delivers live data to any Wi‑Fi–connected browser.
- 📶 **SoftAP Mode**: No router needed — ESP32 hosts its own network.
- 🖥️ **OLED Display**: Real-time visual feedback on the device.
- 🔋 **Field-Ready**: Optimized for battery-powered and remote environments.

---

## 🔩 Hardware Components

| Sensor              | Pin     | Description                          |
|---------------------|---------|--------------------------------------|
| Water Level Sensor  | A1      | Detects water presence or flooding   |
| Light Sensor        | A0      | Measures ambient light intensity     |
| DHT11 (Temp & Humid)| D2      | Captures temperature and humidity    |
| GPS Module          | RX/TX   | Retrieves GPS location               |
| Pulse Sensor        | A3      | Monitors animal heart rate           |
| OLED Display        | I²C     | SSD1306 128x64 for local display     |
| Arduino Nano ESP32  | —       | Main controller with built-in Wi‑Fi |

---

## 💻 Software Setup

1. Install **Arduino IDE** v1.8.13 or later.
2. Add ESP32 board support:  
   - Go to **File → Preferences**  
   - Under *Additional Boards Manager URLs*, add:  
     `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Install required libraries via **Sketch → Include Library → Manage Libraries**:
   - `Adafruit GFX`
   - `Adafruit SSD1306`
   - `Adafruit Unified Sensor`
   - `DHT sensor library by Adafruit`
   - `TinyGPS++`
   - `PulseSensor Playground`
   - `SoftwareSerial`
4. Open `GreenHeartMonitor.ino` in Arduino IDE.
5. Select **Arduino Nano ESP32** board and appropriate COM port.
6. Upload the sketch.
7. Open **Serial Monitor** at `115200` baud to confirm device startup.

---

## 🚀 Usage

1. Power on the device.
2. Look for the OLED splash screen confirming system boot.
3. Connect your device to the Wi‑Fi network:
   - **SSID**: `ESP32Test`
   - **Password**: `test1234`
4. Open a web browser and go to:  
   `http://192.168.4.1/`
5. View live sensor data. Click **Refresh Data** or wait for auto-updates every 10 seconds.

---

## 🧱 Project Architecture

```mermaid
flowchart LR
  Sensors --> ESP32
  ESP32 --> OLED[OLED Display]
  ESP32 --> SoftAP[Wi-Fi SoftAP]
  SoftAP --> Browser[Web Browser]
  ESP32 --> API[/json API]
  Browser --> API
