#include "block.h"
#include <iostream>

Block::Block(SDL_Renderer* renderer) {
    cellSize = 30;
    rotationState = 0;
    columnOffset = 0;
    rowOffset = 0;
    colors = GetCellColors();
    this->renderer = renderer;
}

void Block::Draw() {
    std::vector<Position> tiles = GetCellPositions();
    for (Position item: tiles) {
        SDL_SetRenderDrawColor(renderer, colors[id].r, colors[id].g, colors[id].b, colors[id].a);
        SDL_FRect rect = 
        {
            (float) item.col * cellSize + 1,
            (float) item.row * cellSize + 1,
            (float) cellSize - 1,
            (float) cellSize - 1
        };
        SDL_RenderFillRect(renderer, &rect);
    }
}

void Block::Move(int rows_add, int cols_add) {
    rowOffset += rows_add;
    columnOffset += cols_add;
}

std::vector<Position> Block::GetCellPositions() {
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item: tiles) {
        Position newPos = Position(item.row + rowOffset, item.col +  columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState = (rotationState + 1) % 4;
}

void Block::UndoRotate()
{
    rotationState--;
    if (rotationState < 0) {
        rotationState = cells.size() - 1;
    }
}
