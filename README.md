# Green Heart Monitor 💚

🏆 **Awarded Winner, GMU HackOverflow 2025 Beginner’s Track**

A portable, low-power IoT device built on the Arduino Nano ESP32 for real-time monitoring of environmental conditions and animal/people health metrics.

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

![image](https://github.com/user-attachments/assets/01938320-d6e8-44cd-a420-b53ce298b5ed)

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
| Arduino Nano ESP32  | —       | Main controller with built-in Wi‑Fi  |

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

![image](https://github.com/user-attachments/assets/c7763c35-83a0-4dfb-b9c9-77c2d5169af3)

---

## 🚀 Usage

1. Power on the device.  
2. Look for the OLED splash screen confirming system boot.  
3. Connect your device to the Wi‑Fi network:  
   - **SSID**: `ESP32Test`  
   - **Password**: `test1234`  
4. Open a web browser and go to:  
   `http://192.168.4.1/`  

   Or use the QR Code:

   ![image](https://github.com/user-attachments/assets/a537dea3-5fe8-46d6-80a7-6897e31cb49d)

5. View live sensor data. Click **Refresh Data** or wait for auto‑updates every 10 seconds.

---

## 🎥 Demo Video

Watch our quick demo on YouTube Shorts:

[![Watch the Demo](https://img.youtube.com/vi/0sqBJr7fCgs/hqdefault.jpg)](https://youtube.com/shorts/0sqBJr7fCgs)

---

## 🔮 Future Work

- 🔌 **Cloud Integration**  
  Push collected data to cloud platforms like **Firebase** or **AWS** for historical logging, remote access, and analytics.

- ☀️ **Power Optimization**  
  Integrate **solar charging** systems and optimize code for low-power consumption, enabling continuous field operation.

- 📦 **Miniaturization**  
  Redesign the hardware into a **compact, wearable tag** suitable for smaller wildlife species without disturbing behavior.

- 📊 **Advanced UI**  
  Improve the web dashboard with **interactive charts**, mobile responsiveness, and visual insights for researchers.

- 🤖 **Machine Learning**  
  Implement lightweight models for **anomaly detection**, behavior classification, and real-time alerts directly on the ESP32.

![image](https://github.com/user-attachments/assets/c8872a9b-cdeb-4cd4-b00d-cc5988a4be28)
