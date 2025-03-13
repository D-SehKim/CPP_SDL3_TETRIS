#include "blocks.h"

// Defining color and rotational states.  
LBlock::LBlock(SDL_Renderer* renderer) : Block(renderer) {
    id = 1;
    cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
    cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
    Move(0, 3);
}

JBlock::JBlock(SDL_Renderer* renderer) : Block(renderer) {
    id = 2;
    cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
    cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
    Move(0, 3);
}

IBlock::IBlock(SDL_Renderer* renderer) : Block(renderer) {
    id = 3;
    cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
    cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
    cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
    cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
    Move(-1, 3);
}

OBlock::OBlock(SDL_Renderer* renderer) : Block(renderer) {
    id = 4;
    cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    cells[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    Move(0, 4);
}

SBlock::SBlock(SDL_Renderer* renderer) : Block(renderer) {
    id = 5;
    cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
    cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
    cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
    Move(0, 3);
}

TBlock::TBlock(SDL_Renderer* renderer) : Block(renderer) {
    id = 6;
    cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
    Move(0, 3);
}

ZBlock::ZBlock(SDL_Renderer* renderer) : Block(renderer) {
    id = 7;
    cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
    cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
    cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
    cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
    Move(0, 3);
}