# 🌫️ Arduino + Sensirion SEN55 Air Quality Sensor Interface

This Arduino project interfaces with the **Sensirion SEN55** air quality sensor using I2C communication to continuously read and display:

- Particulate Matter concentrations (PM1.0, PM2.5, PM4.0, PM10.0)
- Ambient humidity and temperature
- Raw temperature and humidity

---

## 🧰 Hardware Requirements

- Arduino board (Uno, Mega, etc.)
- Sensirion SEN55 Sensor
- SEL pin of SEN55 connected to **digital pin 7** on Arduino
- I2C pins:
  - **SDA** → A4 (Uno)  
  - **SCL** → A5 (Uno)  
- Power: Connect VCC and GND as per sensor specs

---

## 📦 Library Dependencies

Install the following library via Arduino Library Manager:

- **Sensirion I2C SEN5x**
  - Go to **Tools > Manage Libraries...**
  - Search for **"Sensirion I2C SEN5x"**
  - Install the latest version

---

## 🧾 Code Overview

- Sets up I2C communication with the sensor
- Toggles the **SEL pin high** to enable I2C mode
- Resets the sensor on startup
- Starts periodic measurements
- Reads and prints values every 5 seconds over the Serial Monitor

### Example Output

Sensor successfully reset.

PM1.0: 3.45 µg/m³

PM2.5: 6.78 µg/m³

PM4.0: 8.22 µg/m³

PM10.0: 9.10 µg/m³

Humidity: 45.67 %

Temperature: 24.3 °C

Raw Temperature: 24.7 °C

Raw Humidity: 44.9 %

---

## ▶️ How to Run

1. Connect the SEN55 sensor to your Arduino as described.
2. Open the Arduino IDE and upload the sketch.
3. Open the **Serial Monitor** at 9600 baud.
4. Observe the live environmental data.

---

## ⚠️ Notes

- Ensure **SEL pin is HIGH** for I2C communication (some breakout boards require manual bridging).
- Check sensor orientation and airflow for accurate readings.
- The first few readings may be unstable — let the sensor stabilize for a few minutes.

  
