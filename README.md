# 🔧 STM32 Sensor Hub

I'm building a small sensor hub on an STM32 to practice real embedded firmware.  
Basically: read a couple sensors, push data through a buffer, and shoot it out over UART so I can plot/debug it.  
Practicing microcontroller fundamentals.

---

## 🎯 Goals

- Talk to sensors over **I2C** and **SPI** (IMU + temp/pressure)
- Use **interrupts** and eventually **DMA** to keep reads non-blocking
- Store samples in a **ring buffer**
- Stream everything out through a **UART debug interface**
- Keep the code clean + portable so I can reuse pieces in future projects

---

## 🔩 Hardware Setup

- **STM32F4** board (Nucleo/Discovery)
- **MPU6050** (IMU) → I²C  
- **BMP280** (pressure/temp) → SPI

