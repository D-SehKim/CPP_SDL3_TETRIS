# CPP_SDL3_TETRIS
 
# Tetris in C++ using SDL3

This is a basic implementation of the classic Tetris game using C++ and the SDL3 (Simple DirectMedia Layer 3) library.

## Features

- Standard Tetris gameplay
- Scoring system
- Line clearing
- Collision detection
- Piece rotation
- Game over detection

## Prerequisites

- C++17 or higher
- CMake 3.15 or higher
- SDL3 installed (either manually or via a package manager like vcpkg)

## Install SDL3

If you want to compile the game on a local machine, you must download SDL3 on your local machine (https://www.libsdl.org/languages.php)

## Build Instructions

```
git clone https://github.com/your-username/tetris-sdl3.git
cd tetris-sdl3
mkdir build
cd build
cmake ..
make
./Tetris
```


## Controls

| Key        | Action         |
|------------|----------------|
| A       | Move left      |
| D      | Move right     |
| W         | Rotate piece   |
| S       | Soft drop      |
| X in the corner     | Quit game      |

## Project Structure

```
tetris-sdl3/
├── .vscode/
│ └── settings.json
├── src/
│ ├── block.cpp
│ ├── blocks.cpp
│ ├── colors.cpp
│ ├── game.cpp
│ ├── grid.cpp
│ ├── main.cpp
│ └── game.cpp
├── include/
│ ├── block.h
│ ├── blocks.h
│ ├── colors.h
│ ├── game.h
│ ├── grid.h
│ ├── main.h
│ └── game.h
├── build/
│ ├── block.o
│ ├── blocks.o
│ ├── colors.o
│ ├── game.o
│ ├── grid.o
│ ├── main.o
│ └── game.o
└── Makefile
└── tetris (executable)
└── .gitattributes
└── README.md
```


## Future Improvements

- Add background music and sound effects
- Add Hard-drop
- Save and display high scores
- UI overlays for pause and restart
- Theming and improved visuals

## License

This project is open source and licensed under the MIT License.

