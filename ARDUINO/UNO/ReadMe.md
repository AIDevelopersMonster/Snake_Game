# Snake Game Projects on Arduino Uno

## Overview
This repository contains implementations of the classic "Snake Game" built on the Arduino Uno platform. Each project demonstrates a unique configuration using different hardware components such as OLED displays, LED matrices, and button controls. The purpose is to provide a modular approach to building and customizing the Snake Game on Arduino Uno.

---

## Projects Structure

### **1. OLED_4Btn**
- **Description**: A simple implementation of Snake using an OLED display and four buttons for directional control.
- **Hardware Components**:
  - Arduino Uno
  - OLED display (SSD1306, I2C interface)
  - Four push buttons
  - Resistors (10kΩ)
  - Breadboard and jumper wires
- **Features**:
  - Smooth animation on the OLED display.
  - Four-button directional input.
  - Minimalist and portable design.

### **2. Uno_LED_Matrix** *(example)*
- **Description**: A variation of Snake using an 8x8 LED matrix for the display.
- **Hardware Components**:
  - Arduino Uno
  - 8x8 LED matrix with MAX7219 driver
  - Push buttons (4 for directional control)
- **Features**:
  - LED-based display for retro gaming feel.
  - Compact design with intuitive controls.

### **3. Uno_TFT_Touch** *(example)*
- **Description**: Snake Game using a TFT touchscreen for both display and input.
- **Hardware Components**:
  - Arduino Uno
  - TFT touchscreen (2.4-inch or 3.5-inch)
- **Features**:
  - Integrated display and touch controls.
  - Interactive gameplay with visual feedback.

---

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/Snake_Game
   ```
2. Navigate to the desired project folder (e.g., `Uno_OLED_4Btn`).
3. Open the `.ino` file in Arduino IDE.
4. Connect the required hardware components as per the wiring diagram provided in the folder.
5. Upload the sketch to your Arduino Uno.
6. Enjoy playing Snake!

---

## Common Features
- All projects are built using Arduino Uno for ease of accessibility.
- Detailed wiring diagrams and component lists are included in each project folder.
- Modular structure for easy adaptation and customization.

---

## Libraries Required
Ensure the following libraries are installed in Arduino IDE:
1. **Adafruit_GFX**
2. **Adafruit_SSD1306** (for OLED projects)
3. **LedControl** (for LED matrix projects)
4. **MCUFRIEND_kbv** (for TFT touchscreen projects)

To install:
1. Go to `Sketch -> Include Library -> Manage Libraries...`
2. Search for the library name and click `Install`.

---
## Demo Video

You can watch the demo of this project on YouTube:

<iframe width="560" height="315" src="https://www.youtube.com/shorts/WVFBBT0bwIA" frameborder="0" allowfullscreen></iframe>
## Future Additions
- Implementing Snake on other platforms such as ESP32 or Raspberry Pi Pico.
- Adding difficulty levels and score tracking.
- Integrating sound effects and RGB lighting for enhanced experience.

---

## Contribution
Feel free to contribute to the repository by:
- Suggesting new hardware configurations.
- Improving code efficiency.
- Adding new features to existing projects.

Fork the repository and submit a pull request with your updates.

---

## License
This repository is licensed under the MIT License. See `LICENSE` file for more details.

