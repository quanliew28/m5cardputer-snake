# M5Cardputer Snake Game

A classic Snake game implementation for the M5Stack Cardputer, built with PlatformIO and Arduino framework.

## Description

This is a traditional Snake game where you control a growing snake to eat apples while avoiding collisions with your own body. The game features:

- Grid-based movement system
- Wrapping boundaries (snake wraps around screen edges)
- Growing snake mechanics
- Self-collision detection with automatic game reset
- Simple keyboard controls using the M5Cardputer's built-in keyboard

## Hardware Requirements

- **M5Stack Cardputer** - A compact development board with built-in keyboard and display

## Controls

The game uses the following keys on the M5Cardputer keyboard:

- `;` - Move Up
- `/` - Move Right  
- `.` - Move Down
- `,` - Move Left

## Game Features

- **Grid Size**: 4x4 pixel cells
- **Display**: Full M5Cardputer screen (240x135 pixels)
- **Snake Speed**: Adjustable (currently set to move every 100 ticks)
- **Boundaries**: Wrapping edges - snake appears on opposite side when hitting screen boundary
- **Collision**: Game automatically resets when snake hits itself
- **Growth**: Snake grows by one segment each time it eats an apple
- **Maximum Length**: 255 segments

## Installation

### Prerequisites

- [PlatformIO](https://platformio.org/) installed in VS Code or as standalone
- M5Stack Cardputer device
- USB-C cable for programming

### Setup

1. Clone or download this project
2. Open in PlatformIO
3. Connect your M5Cardputer via USB-C
4. Build and upload:
   ```bash
   pio run -t upload
   ```

## Code Structure

- `setup()` - Initializes M5Cardputer, display canvas, and spawns first apple
- `loop()` - Main game loop calling tick() and render()
- `tick()` - Handles input, snake movement, collision detection, and game logic
- `render()` - Draws snake segments and apple on the display
- `spawnApple()` - Randomly places new apple avoiding snake body
- `checkApple()` - Verifies apple doesn't spawn on snake segments
- `resetGame()` - Resets all game variables to initial state

## Game Logic

1. **Movement**: Snake moves automatically in the current direction every 100 ticks
2. **Input**: Direction changes only if not opposite to current direction (prevents immediate self-collision)
3. **Boundaries**: Snake wraps around screen edges (60x34 grid cells)
4. **Growth**: Snake length increases when eating apples
5. **Collision**: Game resets when snake head touches any body segment

## Development

Built using:
- **Framework**: Arduino
- **Platform**: ESP32-S3 (M5Stack Cardputer)
- **IDE**: PlatformIO
- **Graphics**: M5Canvas for efficient sprite rendering

## License

This project is open source. Feel free to modify and distribute.

## Contributing

Pull requests welcome! Areas for improvement:
- Add score display
- Implement difficulty levels
- Add sound effects
- Create game over screen with statistics
- Add pause functionality