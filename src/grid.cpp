#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid(SDL_Renderer *renderer)
{
    /*
    * Constructor
    */
    this->renderer = renderer;
    numRows = 20;
    numCols = 10;
    cellSize = 30;

    Initalize();
    colors = GetCellColors();
}

void Grid::Initalize() {
    for (int row = 0; row < numRows; row ++)
    {
        for (int col = 0; col < numCols; col++) 
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() {
    /*
    * Print's the current state of the grid (each number representing said 
    * color on from GetCellColors())
    */
    for (int row = 0; row < numRows; row ++)
    {
        for (int col = 0; col < numCols; col++) 
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }    
}

void Grid::Draw() {
    /*
    * draws the grid of the window using cellSize and numRows/numCols
    */
    for (int row = 0; row < numRows; row ++)
    {
        for (int col = 0; col < numCols; col++) 
        {
            int cell_value = grid[row][col];
            SDL_SetRenderDrawColor(renderer, colors[cell_value].r, colors[cell_value].g, colors[cell_value].b, colors[cell_value].a);
            SDL_FRect rect = 
            {
                (float) col * cellSize + 1,
                (float) row * cellSize + 1,
                (float) cellSize - 1,
                (float) cellSize - 1
            };
            SDL_RenderFillRect(renderer, &rect);
        }
    } 
}

bool Grid::IsCellOutside(int row, int col) {
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        return false;
    } else {
        return true;
    }
}

bool Grid::IsCellEmpty(int row, int col)
{
    if (grid[row][col] == 0) {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = numRows-1; row >= 0; row--) {
        if(IsRowFull(row)) {
            ClearRow(row);
            completed++;
        } else if (completed > 0) {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int col = 0; col < numCols; col++) {
        if (grid[row][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) {
    for(int col = 0; col < numCols; col++) {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows) {
    for(int col = 0; col < numCols; col++) {
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
