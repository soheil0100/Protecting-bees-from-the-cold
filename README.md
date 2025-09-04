# Protecting-bees-from-the-cold
---

## 🐝 Bee Hive Temperature and Humidity Protector with Arduino UNO

This project is designed to **protect a bee hive** from extreme temperatures by monitoring and controlling the internal environment using an **Arduino UNO**. It uses a **DHT11 sensor** to measure temperature and humidity inside the hive. Depending on the readings, it automatically controls a **fan** and a **heater** via relay modules to maintain optimal conditions. Users can set minimum and maximum temperature thresholds with two potentiometers. The system provides real-time feedback via a display and status LEDs.

---

### 📌 Features

* Temperature and humidity monitoring inside the hive using **DHT11 sensor**
* Automatic control of **fan** (for cooling) and **heater** (for warming) via relay modules
* User-adjustable minimum and maximum temperature thresholds with two potentiometers
* Real-time status display of temperature, humidity, and set thresholds on an LCD or similar display
* Status indication using **3 LEDs**:

  * Green LED for normal condition
  * Red LED for overheating (fan ON)
  * Blue LED for cold condition (heater ON)

---

### ⚙️ Hardware Components

* Arduino UNO
* DHT11 Temperature & Humidity Sensor
* 2x Potentiometers (for min & max temperature settings)
* Fan (12V or compatible)
* Heater (appropriate heating element)
* 2x Relay Modules (to control fan and heater)
* Display module (LCD or OLED)
* 3x LEDs (Green, Red, Blue)
* Resistors, jumper wires, breadboard or PCB

---

### 🧠 How It Works

1. The **DHT11 sensor** continuously measures temperature and humidity inside the hive.
2. The user sets desired **minimum** and **maximum** temperature limits using two potentiometers.
3. If the temperature exceeds the maximum limit, the **fan relay** is activated to cool down the hive.
4. If the temperature drops below the minimum limit, the **heater relay** turns on to warm the hive.
5. The current temperature, humidity, and threshold settings are shown on the display.
6. LEDs indicate the current status: normal, overheating, or too cold.

---

### 🛠️ Software Details

* Programmed in **Arduino C++**
* Uses libraries for DHT11 sensor and display (e.g., `DHT.h` and `LiquidCrystal.h`)
* Reads analog values from potentiometers for thresholds
* Controls relays via digital output pins
* Updates display and LEDs based on sensor readings and thresholds

---

### 📁 Project Structure

```
BeeHive-Protector/
│
├── code/
│   └── bee_hive_protector.ino      ← Arduino code  
│
├── README.md  
└── ...
```

---

### ✅ How to Run

1. Open `bee_hive_protector.ino` in Arduino IDE.
2. Connect all hardware components as per the wiring diagram.
3. Upload the code to your **Arduino UNO**.
4. Adjust the potentiometers to set your desired min and max temperature limits.
5. Monitor the hive environment and let the system automatically manage fan and heater.

---

### 📜 License

This project is licensed under the **MIT License** — feel free to use, adapt, and share with attribution.

---

### 🤝 Contributions

Contributions, bug reports, or feature requests (such as adding remote monitoring, data logging, or mobile alerts) are highly welcome!

---
