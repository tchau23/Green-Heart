# Environmental and Wildlife Monitoring System  
**Hackathon Project | Arduino Nano ESP32**

## Introduction

Our goal was to design a compact, real-time monitoring system that tracks both environmental changes and animal health metrics. The data collected would be made available to scientists to support research and inform conservation strategies.

## Our Plan

We set out to create a multi-sensor device that could:

- Monitor environmental conditions and animal health indicators  
- Allow Real time access to data  
- Identify environmental changes and behavioral patterns in animals 

The system would be deployed in natural habitats and provide valuable data for long-term ecological studies.

## Our Execution

We used the **Arduino Nano ESP32** as the foundation of our device due to its small size, low power usage, and built-in Wi-Fi. The following sensors were incorporated into the system:

- **Water Sensor** – Detects water presence and flooding conditions  
- **Light Sensor** – Measures light levels and exposure trends  
- **Heartbeat Sensor** – Monitors animal heart rate  
- **Temperature Sensor** – Measures ambient temperature  
- **GPS Sensor** – Records geographic location of data collection  
- **Accelerometer** – Tracks motion and activity levels  
- **Humidity Sensor** – Detects atmospheric moisture  

To make the data accessible in real time, we hosted a lightweight web server directly on the ESP32. This allowed users to connect to the device over a local Wi-Fi network and view sensor readings through a live dashboard.

## Conclusion

This project demonstrates the potential of embedded IoT solutions in environmental and wildlife monitoring. By integrating multiple sensors with a real-time data interface, our system offers a reliable and scalable tool for scientists studying ecosystems and animal behavior. The ability to remotely access live environmental data can lead to more responsive and effective conservation strategies.

## Future Plans

- Integrate with cloud storage platforms (e.g., Firebase, AWS) for remote data logging and historical analysis  
- Improve power efficiency and battery life for long-term deployment in remote areas  
- Develop a wearable version for tracking smaller wildlife species  
- Build a more advanced web interface for data visualization and analysis  
- Explore the use of machine learning for anomaly detection and predictive modeling  
