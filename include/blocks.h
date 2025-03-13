#pragma once
#include "block.h"

class LBlock : public Block {
public:
    LBlock(SDL_Renderer* renderer);
};

class JBlock : public Block {
public:
    JBlock(SDL_Renderer* renderer);
};

class IBlock : public Block {
public:
    IBlock(SDL_Renderer* renderer);
};

class OBlock : public Block {
public:
    OBlock(SDL_Renderer* renderer);
};

class SBlock : public Block {
public:
    SBlock(SDL_Renderer* renderer);
};

class TBlock : public Block {
public:
    TBlock(SDL_Renderer* renderer);
};

class ZBlock : public Block {
public:
    ZBlock(SDL_Renderer* renderer);
};