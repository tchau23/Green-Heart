#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// === SoftAP credentials ===
const char* apSSID = "ESP32Test";
const char* apPASS = "test1234";

// === Web server on port 80 ===
WebServer server(80);

// === OLED setup ===
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET   -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// === DHT11 setup ===
#define DHTPIN   2
#define DHTTYPE  DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);

// === Other sensor pins ===
const int waterSensorPin = A1;  // water level sensor
const int lightSensorPin = A0;  // light sensor

// === HTML page ===
const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <title>Green Heart Monitor</title>
  <style>
    body { margin:0; font-family:sans-serif; background:#e0f7fa; color:#004d40; }
    header { background:#00796b; color:#fff; text-align:center; padding:1em; }
    .container { display:flex; flex-wrap:wrap; justify-content:center; max-width:1000px; margin:1em auto; }
    .card { background:#fff; border-radius:8px; box-shadow:0 2px 5px rgba(0,0,0,0.1);
            flex:1 1 300px; margin:0.5em; padding:1em; }
    .card h2 { margin-top:0; color:#00695c; border-bottom:2px solid #00695c; padding-bottom:0.3em; }
    .reading { display:flex; justify-content:space-between; margin:0.5em 0; }
    button { display:block; margin:1em auto; padding:0.5em 1em; background:#00796b; 
             color:#fff; border:none; border-radius:4px; cursor:pointer; }
    button:hover { background:#004d40; }
    @media(max-width:600px){ .container { flex-direction:column; } }
  </style>
</head>
<body>
  <header><h1>Green Heart Monitor</h1></header>
  <div class="container">
    <div class="card">
      <h2>Environment Monitor</h2>
      <div class="reading"><span>Humidity:</span><span id="humidity">—</span>%</div>
      <div class="reading"><span>Temperature:</span><span id="temperature">—</span>°C</div>
      <div class="reading"><span>GPS:</span><span id="latitude">—</span>,<span id="longitude">—</span></div>
      <div class="reading"><span>Light Brightness:</span><span id="light">—</span>lx</div>
      <div class="reading"><span>Water Level:</span><span id="waterLevel">—</span>cm</div>
    </div>
    <div class="card">
      <h2>Health Monitor</h2>
      <div class="reading"><span>Body Temp:</span><span id="bodyTemp">—</span>°C</div>
      <div class="reading"><span>Movement:</span><span id="movement">—</span></div>
      <div class="reading"><span>Heartbeat:</span><span id="heartbeat">—</span>bpm</div>
      <div class="reading"><span>GPS:</span><span id="healthLat">—</span>,<span id="healthLng">—</span></div>
    </div>
  </div>
  <button onclick="fetchData()">Refresh Data</button>
  <script>
    async function fetchData() {
      try {
        const resp = await fetch('/json');
        const d = await resp.json();
        document.getElementById('humidity'   ).textContent = d.humidity;
        document.getElementById('temperature').textContent = d.temperature;
        document.getElementById('latitude'   ).textContent = d.latitude;
        document.getElementById('longitude'  ).textContent = d.longitude;
        document.getElementById('light'      ).textContent = d.light;
        document.getElementById('waterLevel' ).textContent = d.waterLevel;
        document.getElementById('bodyTemp'   ).textContent = d.bodyTemp;
        document.getElementById('movement'   ).textContent = d.movement;
        document.getElementById('heartbeat'  ).textContent = d.heartbeat;
        document.getElementById('healthLat'  ).textContent = d.latitude;
        document.getElementById('healthLng'  ).textContent = d.longitude;
      } catch(e) {
        console.error(e);
      }
    }
    window.onload = fetchData;
    setInterval(fetchData, 10000);
  </script>
</body>
</html>
)=====";

// === Serve main page ===
void handleRoot() {
  server.send_P(200, "text/html", PAGE_MAIN);
}

// === Serve JSON ===
void handleJson() {
  // Read DHT11
  sensors_event_t evt;
  float hum = NAN, temp = NAN;
  dht.temperature().getEvent(&evt);
  if (!isnan(evt.temperature)) temp = evt.temperature;
  dht.humidity().getEvent(&evt);
  if (!isnan(evt.relative_humidity)) hum = evt.relative_humidity;

  // Read water & light
  int w = analogRead(waterSensorPin);
  int l = analogRead(lightSensorPin);

  // Dummy health fields
  float bodyTemp = temp;           // just reuse DHT temp
  const char* movement = "Active";
  int heartbeat = 75;

  // Build JSON
  String js = "{";
  js += "\"humidity\":"    + String(hum,1)     + ",";
  js += "\"temperature\":" + String(temp,1)    + ",";
  js += "\"latitude\":"    + String(38.8317)   + ",";
  js += "\"longitude\":"   + String(-77.3120)  + ",";
  js += "\"light\":"       + String(l)         + ",";
  js += "\"waterLevel\":"  + String(w<600?0:100)+ ",";
  js += "\"bodyTemp\":"    + String(bodyTemp,1)+ ",";
  js += "\"movement\":\""   + String(movement)  + "\",";
  js += "\"heartbeat\":"   + String(heartbeat);
  js += "}";

  server.sendHeader("Access-Control-Allow-Origin","*");
  server.send(200,"application/json", js);
}

void setup() {
  Serial.begin(115200);
  while(!Serial);

  // OLED init & splash
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)) {
    Serial.println("SSD1306 failed");
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Green");
  display.println("Heart");
  display.println("Monitor");
  display.display();
  delay(2000);
  display.clearDisplay();

  // DHT init
  dht.begin();

  // Start SoftAP & server
  WiFi.softAP(apSSID, apPASS);
  Serial.printf("AP '%s' @ %s\n", apSSID, WiFi.softAPIP().toString().c_str());

  server.on("/",     handleRoot);
  server.on("/json", handleJson);
  server.begin();
}

void loop() {
  server.handleClient();

  // Also update OLED in parallel
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,  0); display.print("T:");
  display.setCursor(16, 0);
  // reuse last JSON values (could cache), but here read again:
  sensors_event_t evt;
  float tempVal = NAN, humVal = NAN;
  dht.temperature().getEvent(&evt);
  if(!isnan(evt.temperature)) tempVal = evt.temperature;
  dht.humidity().getEvent(&evt);
  if(!isnan(evt.relative_humidity)) humVal = evt.relative_humidity;
  if(!isnan(tempVal)) display.print(tempVal,1); else display.print("Err");
  display.setCursor(0, 10); display.print("H:");
  display.setCursor(16,10);
  if(!isnan(humVal)) display.print(humVal,1); else display.print("Err");
  int w = analogRead(waterSensorPin);
  display.setCursor(0, 20); display.print("Wl:");
  display.setCursor(24,20); display.print(w<600?"LOW":"HIGH");
  int lVal = analogRead(lightSensorPin);
  display.setCursor(0, 30); display.print("Lt:");
  display.setCursor(24,30); display.print(lVal);
  display.setCursor(0,40); display.print("GPS:");
  display.setCursor(28,40); display.print("XX,YY");
  display.display();

  delay(2000);
}
