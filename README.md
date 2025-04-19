Green Heart Monitor 

 

Table of Contents

Overview

Key Features

Hardware Components

Software Setup

Usage

Project Architecture

Future Work

License

Overview

Green Heart Monitor is a portable, low-power IoT device built on the Arduino Nano ESP32. It provides:

Real-time tracking of environmental and animal health metrics

Web-based dashboard accessible over Wi‑Fi

On-board OLED display for local monitoring

Use this system for ecological research, wildlife conservation, and field data collection.

Key Features

⚙️ Multi-Sensor Integration: water level, ambient light, humidity, temperature, GPS location, and heartbeat.

🌐 Live Dashboard: Embedded HTTP server serves JSON & HTML to any Wi‑Fi–connected device.

📶 SoftAP Mode: ESP32 hosts its own Wi‑Fi network—no router needed.

🖥️ OLED Display: Instant local readout of critical data.

🔋 Field-Ready: Optimized for battery operation and remote deployment.

Hardware Components

Sensor

Pin

Description

Water Level Sensor

A1

Detects flooding or water presence

Light Sensor

A0

Measures ambient light intensity

DHT11 (Temp & Humid)

D2

Records temperature & humidity

GPS Module

RX/TX

Captures latitude & longitude

Pulse Sensor

A3

Monitors animal heart rate

OLED Display

I²C

Local visual feedback (SSD1306 128x64)

Arduino Nano ESP32

—

Main controller with built-in Wi-Fi

Software Setup

Install Arduino IDE v1.8.13 or later.

Add ESP32 board support:

Go to File → Preferences

Under Additional Boards Manager URLs, add:

https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

Install Libraries via Sketch → Include Library → Manage Libraries:

Adafruit GFX

Adafruit SSD1306

Adafruit Unified Sensor

DHT sensor library by Adafruit

TinyGPS++

PulseSensor Playground

SoftwareSerial

Open the GreenHeartMonitor.ino sketch in Arduino IDE.

Select Arduino Nano ESP32 board and correct COM port.

Upload the sketch.

Monitor the Serial output at 115200 baud for startup messages.

Usage

Power on the device. The OLED splash screen will confirm initialization.

Connect your PC or smartphone to the ESP32 network:

SSID: ESP32Test

Password: test1234

Open a browser to:  http://192.168.4.1/

View live readings in the web dashboard. Click Refresh Data or wait for auto‑updates every 10 seconds.

Project Architecture

flowchart LR
  Sensors --> ESP32
  ESP32 --> OLED[OLED Display]
  ESP32 --> SoftAP[Wi-Fi SoftAP]
  SoftAP --> Browser[Web Browser]
  ESP32 --> API[/json API]
  Browser --> API

Future Work

🔌 Cloud Integration: Push data to Firebase or AWS for historical logging.

☀️ Power Optimization: Solar/battery enhancements for long-term field use.

📦 Miniaturization: Wearable tag for small wildlife.

📊 Advanced UI: Enhanced charts and analytics.

🤖 Machine Learning: On-device anomaly detection and alerts.

License

This project is released under the MIT License. See LICENSE for details.
