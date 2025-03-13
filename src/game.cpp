#include "game.h"
#include <iostream>

Game::Game(SDL_Renderer *renderer, SDL_Event event) : currentBlock(renderer), nextBlock(renderer), grid(renderer)
{
    blocks = GetAllBlock(renderer);
    this->renderer = renderer;
    event_log = event;

    quit = true;

    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlock(renderer);
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlock(SDL_Renderer* renderer) {
    return {IBlock(renderer), ZBlock(renderer), SBlock(renderer), TBlock(renderer), LBlock(renderer), JBlock(renderer), OBlock(renderer)};
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput() {
    SDL_PollEvent(&event_log);
    if (event_log.type == SDL_EVENT_KEY_DOWN) {
        if (event_log.key.key == SDLK_W) {
            RotateBlock();
        }
        if (event_log.key.key == SDLK_A) {
            MoveBlockLeft();
        }
        if (event_log.key.key == SDLK_S) {
            MoveBlockDown();    
        }
        if (event_log.key.key == SDLK_D) {
            MoveBlockRight();
        }
    }
    if (gameOver && event_log.type == SDL_EVENT_KEY_DOWN) {
        gameOver = false;
        Reset();
    }
    if (event_log.type == SDL_EVENT_QUIT) {
        quit = false;
    }
}

void Game::MoveBlockLeft() {
    if (!gameOver) {
        currentBlock.Move(0, -1);
        if (std::get<0>(IsBlockOutside()) || !BlockFits()) {
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight() {
    if (!gameOver) {
        currentBlock.Move(0, 1);
        if (std::get<0>(IsBlockOutside()) || !BlockFits()) {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown() {
    if (!gameOver) {
        currentBlock.Move(1, 0);
        if (std::get<0>(IsBlockOutside()) || !BlockFits()) {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::RotateBlock()
{
    if (!gameOver) {
        currentBlock.Rotate();
        if (!BlockFits()) {
            currentBlock.UndoRotate();
        }
        if(std::get<0>(IsBlockOutside())) {
            currentBlock.Move(0, std::get<2>(IsBlockOutside()));
        }
    }
}

void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles) {
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(!BlockFits()) {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) {
        if (!grid.IsCellEmpty(item.row, item.col)) {
            return false;
        }
    }
    return true;
}

std::tuple<bool, int, int> Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item: tiles) {
        if (grid.IsCellOutside(item.row, item.col)) {
            int move;
            if (currentBlock.id == 3) {
                if (item.col < 0) {
                    move = 2;
                } else {
                    move = -2;
                }
            } else {
                if (item.col < 0) {
                    move = 1;
                } else {
                    move = -1;
                }
            }
            return std::make_tuple(true, move, move);
        }
    }
    return std::make_tuple(false, 0, 0);
}

void Game::Reset()
{
    grid.Initalize();
    blocks = GetAllBlock(renderer);
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
