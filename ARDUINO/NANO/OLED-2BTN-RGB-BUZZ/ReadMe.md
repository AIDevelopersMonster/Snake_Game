# Snake Game on Arduino Nano

## Overview
This is a classic "Snake Game" implemented for Arduino Nano. The game utilizes external devices such as an OLED display, NeoPixel RGB LEDs, and buttons for control. The objective is to eat as much food as possible without colliding with walls or the snake's own body. The game includes sound and lighting effects for enhanced interactivity.

---

## Features
- **Hardware Integration**:
  - 128x64 OLED display for game visuals.
  - NeoPixel RGB LED for colorful feedback.
  - Two-button control (left and right).
  - Piezo buzzer for sound effects.
- **Game Mechanics**:
  - Randomly placed food.
  - Snake grows in length after eating food.
  - Game ends on collision with walls or snake's body.
- **Customization**:
  - Adjustable game speed.
  - Configurable winning points.

---

## Hardware Requirements

### Components
| Component            | Quantity | Notes                              |
|----------------------|----------|------------------------------------|
| Arduino Nano         | 1        | Microcontroller board              |
| OLED Display (SSD1306) | 1      | 128x64 pixels, I2C interface       |
| NeoPixel RGB LED     | 1        | For visual effects                 |
| Push Buttons         | 2        | For directional control            |
| Resistors (10kΩ)     | 2        | For pull-down configuration        |
| Piezo Buzzer         | 1        | For sound feedback                 |
| Breadboard           | 1        | For wiring connections             |
| Jumper Wires         | 15+      | Male-to-male connectors            |

### Wiring Diagram
- **OLED Display**:
  - VCC → 5V
  - GND → GND
  - SDA → A4
  - SCL → A5
- **Buttons**:
  - Left Button: A0 (connected with 10kΩ pull-down resistor)
  - Right Button: A1 (connected with 10kΩ pull-down resistor)
- **NeoPixel**:
  - DIN → Pin 13
  - VCC → 5V
  - GND → GND
- **Buzzer**:
  - Positive → Pin 2
  - Negative → GND

---

## Software Requirements
### Libraries Used
1. **Adafruit_GFX**: For graphics rendering.
2. **Adafruit_SSD1306**: For OLED display control.
3. **Adafruit_NeoPixel**: For RGB LED control.

### Installation
1. Open Arduino IDE.
2. Go to `Sketch -> Include Library -> Manage Libraries...`.
3. Search for the required libraries and install them.

---

## Code Structure

### Key Sections
1. **Display Initialization**:
   - Initializes the SSD1306 OLED display.
2. **Snake Movement**:
   - Calculates the new position of the snake based on the direction.
3. **Food Placement**:
   - Randomly generates coordinates for food.
4. **Collision Detection**:
   - Checks for collisions with walls or the snake's own body.
5. **Game Effects**:
   - Uses NeoPixel LEDs and buzzer for interactive feedback.

### Adjustable Parameters
- `WIN_POINTS`: Number of points required to win.
- `CYCLE_INTERVAL`: Speed of the game loop.
- `BUTTON_INTERVAL`: Debounce delay for button presses.

---

## How to Play
1. **Start the Game**:
   - Turn on the Arduino Nano.
   - Press the left button to start.
2. **Control the Snake**:
   - Use the left button to turn left and the right button to turn right.
3. **Objective**:
   - Eat the food to grow the snake.
   - Avoid collisions with walls and your own body.
4. **Win/Lose Conditions**:
   - Win by reaching the `WIN_POINTS` threshold.
   - Lose by colliding with walls or the snake's own body.

---

## Future Improvements
- Add more buttons for four-directional control.
- Implement levels with increasing difficulty.
- Add sound and visual effects for different events (e.g., collisions, winning).

---

## License
This project is licensed under the MIT License. See `LICENSE` for details.

---

Feel free to modify or expand this project to suit your needs. Enjoy building and playing Snake on Arduino Nano!

