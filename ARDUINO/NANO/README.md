# Snake Game Projects on Arduino Nano

## Overview
This repository contains implementations of the classic "Snake Game" developed for the Arduino Nano platform. These projects demonstrate various hardware configurations, such as OLED displays, LED matrices, and button controls, optimized for the compact and versatile Arduino Nano board.

---

## Projects Structure

### **1. OLED_4Btn**
- **Description**: A compact Snake Game using an OLED display and four buttons for control.
- **Hardware Components**:
  - Arduino Nano
  - OLED display (SSD1306, I2C interface)
  - Four push buttons
  - Resistors (10kΩ)
  - Breadboard and jumper wires
- **Features**:
  - Smooth OLED animations.
  - Compact design suitable for small projects.

### **2.LED_Matrix** *(example)*
- **Description**: A variation of Snake using an 8x8 LED matrix for display.
- **Hardware Components**:
  - Arduino Nano
  - 8x8 LED matrix with MAX7219 driver
  - Push buttons (4 for directional control)
- **Features**:
  - Retro gaming style with LED matrix display.
  - Highly portable setup.

### **3. TFT_Touch** *(example)*
- **Description**: Snake Game with a TFT touchscreen for both display and input.
- **Hardware Components**:
  - Arduino Nano
  - TFT touchscreen (2.4-inch or 3.5-inch)
- **Features**:
  - Touchscreen-based controls.
  - High-quality visual display.

---

## How to Use
1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/Snake_Game
   ```
2. Navigate to the desired project folder (e.g., `Nano_OLED_4Btn`).
3. Open the `.ino` file in Arduino IDE.
4. Connect the required hardware components as per the wiring diagram provided in the folder.
5. Upload the sketch to your Arduino Nano.
6. Enjoy playing Snake!

---

## Common Features
- Optimized for Arduino Nano's compact size.
- Projects include detailed wiring diagrams and component lists.
- Easy to modify and expand for custom configurations.

---

## Libraries Required
Ensure the following libraries are installed in Arduino IDE:
1. **Adafruit_GFX**
2. **Adafruit_SSD1306** (for OLED projects)
3. **LedControl** (for LED matrix projects)
4. **MCUFRIEND_kbv** (for TFT touchscreen projects)

To install:
1. Open Arduino IDE.
2. Go to `Sketch -> Include Library -> Manage Libraries...`
3. Search for the library name and click `Install`.

---

## Future Additions
- Adding support for additional displays and input methods.
- Implementing multiplayer functionality over serial communication.
- Creating difficulty settings and score tracking.

---

## Contribution
Contributions are welcome! You can:
- Suggest new hardware configurations.
- Improve the code.
- Add new features to the existing projects.

Fork the repository, make your changes, and submit a pull request.

---

## License
This repository is licensed under the MIT License. See the `LICENSE` file for details.

