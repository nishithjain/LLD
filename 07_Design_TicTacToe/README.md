# TicTacToe - C++ Implementation

## Overview
This is a C++ implementation of the classic TicTacToe game. The project is organized into modules such as `core`, `exceptions`, `factory`, and `strategy`, following best practices in design and architecture. The game allows multiple players and includes custom exception handling for game-related errors like invalid board dimensions or duplicate player symbols.

## Project Structure
The project is organized as follows:

```plaintext
├───Notes                  # MS Word Notes about the design.
├───TicTacToe
│   ├───headers
│   │   ├───core           # Core game logic and classes
│   │   ├───exceptions     # Custom exceptions for game-related errors
│   │   ├───factory        # Factory classes for object creation
│   │   └───strategy       # Strategy pattern implementation for game rules
└───└───source
        ├───core           # Source files for core logic
        ├───exceptions     # Source files for exception handling
        ├───factory        # Source files for factory pattern
        └───strategy       # Source files for strategy pattern
```

## Features
- **Core Game Logic**: Manages the rules and flow of the TicTacToe game.
- **Custom Exceptions**: Handles invalid input such as incorrect board dimensions and duplicate player symbols.
- **Design Patterns**:
  - **Factory Pattern**: For creating game components.
  - **Strategy Pattern**: Allows flexible implementation of game rules.
- **Multiple Player Support**: Easily extendable for more players.

## Build and Run

### Prerequisites:
- C++17 or higher
- CMake (optional but recommended for cross-platform builds)
- A C++ compiler such as GCC, Clang, or MSVC.

### Contributing
Feel free to contribute to this project by opening an issue or submitting a pull request.
