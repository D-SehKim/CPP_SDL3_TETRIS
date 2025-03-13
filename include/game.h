#pragma once
#include "grid.h"
#include <tuple>
#include "blocks.h"

class Game
{
private:
    SDL_Renderer* renderer;
    SDL_Event event_log;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    void RotateBlock();
    std::tuple<bool, int, int> IsBlockOutside();
    void Reset();
public:
    Game(SDL_Renderer* renderer, SDL_Event event);
    Block GetRandomBlock();
    std::vector<Block> GetAllBlock(SDL_Renderer *renderer);
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    void LockBlock();
    bool BlockFits();
    Grid grid;
    bool quit;
    bool gameOver;
};

