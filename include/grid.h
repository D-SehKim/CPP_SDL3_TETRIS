#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class  Grid {
private:
    int numRows;
    int numCols;
    int cellSize;
    SDL_Renderer* renderer;
    std::vector<SDL_Color> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);

public:
    Grid(SDL_Renderer* renderer);
    void Initalize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    int ClearFullRows();
    int grid[20][10];
};
