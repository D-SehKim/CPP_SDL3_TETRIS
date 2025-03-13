#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
private:
    int cellSize;
    int rotationState;
    int columnOffset;
    int rowOffset;
    std::vector<SDL_Color> colors;
    
public:
    Block(SDL_Renderer* renderer);
    SDL_Renderer* renderer;
    std::map<int, std::vector<Position>> cells;
    void Draw();
    void Move(int row, int col);
    void Rotate();
    void UndoRotate();
    std::vector<Position> GetCellPositions();
    int id;
};