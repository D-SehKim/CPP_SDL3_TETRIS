#include "colors.h"

std::vector<SDL_Color> GetCellColors() {
    /*
    * Declaring colors, NOTE: ORDER OF THE COLORS MATTERS
    */
    SDL_Color dark_grey = {26, 31, 40, 255};
    SDL_Color green = {47, 230, 23, 255};
    SDL_Color red = {232, 18, 18, 255};
    SDL_Color orange = {226, 116, 17, 255};
    SDL_Color yellow = {237, 234, 4, 255};
    SDL_Color purple = {166, 0, 247, 255};
    SDL_Color cyan = {21, 204, 209, 255};
    SDL_Color blue = {13, 64, 216, 255};

    return {dark_grey, green, red, orange, yellow, purple, cyan, blue};
}