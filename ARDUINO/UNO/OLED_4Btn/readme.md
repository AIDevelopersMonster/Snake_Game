# Snake Game for Arduino

## Overview
This project is a classic "Snake Game" implemented on Arduino Uno, using an OLED display and four buttons for control. The game is designed to demonstrate interactive programming with hardware components.

## Features
- **Hardware Compatibility:** Works with Arduino Uno and other compatible boards.
- **Display:** 128x64 OLED display (SSD1306).
- **Control:** Four-button setup for directional control.
- **Gameplay:**
  - Snake grows as it eats fruits.
  - Game ends on collision with walls or the snake's own body.

## Components
- **Arduino Uno** (or compatible microcontroller)
- **OLED Display** (128x64, SSD1306, I2C interface)
- **Four Push Buttons**
- **Resistors** (10kΩ for each button as pull-down resistors)
- **Breadboard and jumper wires**

## Wiring Diagram
### Connections:
| Component     | Arduino Pin      |
|---------------|------------------|
| OLED VCC      | 5V               |
| OLED GND      | GND              |
| OLED SDA      | A4 (I2C Data)    |
| OLED SCL      | A5 (I2C Clock)   |
| Button Up     | Digital Pin 2    |
| Button Down   | Digital Pin 3    |
| Button Left   | Digital Pin 4    |
| Button Right  | Digital Pin 5    |

## Libraries Used
1. [Adafruit_GFX](https://github.com/adafruit/Adafruit-GFX-Library)
2. [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

To install these libraries:
1. Open Arduino IDE.
2. Go to `Sketch -> Include Library -> Manage Libraries...`.
3. Search for the library and click `Install`.

## Setup and Installation
1. Clone this repository or download the code files.
2. Open the `.ino` file in Arduino IDE.
3. Connect the hardware components as described in the wiring diagram.
4. Upload the code to the Arduino board.

## How to Play
1. **Start the Game:** The game starts when the board is powered, and the `Up` button is pressed.
2. **Controls:** Use the buttons to change the direction of the snake:
   - **Up Button:** Move up.
   - **Down Button:** Move down.
   - **Left Button:** Move left.
   - **Right Button:** Move right.
3. **Objective:** Eat the fruits to grow the snake. Avoid collisions with walls and the snake's own body.
4. **Game Over:** A collision ends the game.

## Code Structure
### Key Functions:
- **`setup()`**: Initializes the display and sets up button inputs.
- **`loop()`**: Runs the game logic and updates the display.
- **`moveSnake()`**: Updates the snake's position.
- **`generateFruit()`**: Randomly places a fruit on the grid.
- **`drawMap()`**: Renders the game on the OLED display.

## Future Improvements
- Add difficulty levels with increasing snake speed.
- Implement obstacles to make the game more challenging.
- Add sound effects using a piezo buzzer.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

