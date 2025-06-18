# Clock

---
# 🕒 P10 LED Display Clock with Arduino Nano + DS1307 RTC

This project displays the **real-time clock** on a **P10 single-color LED matrix** using an **Arduino Nano** and **DS1307 RTC module**. It can be used as a digital wall clock or message board with time display.

![P10 Clock Demo](images/demo.jpg) <!-- Replace with your actual image path -->

---

## 🛠️ Features

- Displays **Hour:Minute:Second** on P10 display
- Uses **DS1307 RTC** for accurate real-time keeping
- Built with **Arduino Nano**
- Easy to modify for custom messages or alarms
- Clean, compact design for mounting

---

## 🔌 Components Used

| Component           | Quantity |
|---------------------|----------|
| Arduino Nano        | 1        |
| P10 LED Display     | 1        |
| DS1307 RTC Module   | 1        |
| 10K Pull-up Resistors (for SDA/SCL) | 2 (optional) |
| Jumper Wires        | As needed |
| Power Supply (5V 2A recommended) | 1 |

---

## 📷 Images

### Front View
![Front View](images/front.jpg)

### Wiring Preview
![Wiring Diagram](images/wiring.jpg)

---

## ⚙️ Wiring Instructions

| Arduino Nano | P10 Display | DS1307 RTC |
|--------------|-------------|------------|
| D6           | A           |            |
| D7           | B           |            |
| D8           | CLK         |            |
| D9           | STB         |            |
| D10          | DIN         |            |
| GND          | GND         | GND        |
| 5V           | VCC         | VCC        |
| A4 (SDA)     |             | SDA        |
| A5 (SCL)     |             | SCL        |

---

## 💾 Required Libraries

Install these libraries via Arduino Library Manager:

- [DMD2](https://github.com/freetronics/DMD2)
- [RTClib](https://github.com/adafruit/RTClib)
- SPI (built-in with Arduino IDE)

---

## 🔧 Customization Ideas

* Add temperature display with **DHT11/22**
* Add scrolling text features
* Use multiple P10 displays for longer messages
* Sync time via Bluetooth or Wi-Fi (ESP8266/ESP32)

---

## 🧠 License

This project is open-source under the [MIT License](LICENSE).

---

## 🙌 Acknowledgements

* Inspired by open-source Arduino + LED matrix clock projects.
* Based on [Freetronics DMD2 library](https://github.com/freetronics/DMD2)

---

## 📩 Connect

If you like this project or have questions:

* Create an Issue
* Submit a Pull Request
* Share your build!
