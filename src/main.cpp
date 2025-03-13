#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "game.h"

int main() {
    // Defining window and render variables
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    int frameCount = 0;

    // Initalizing SDL, throw error if something is caught
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    // Creating Widow, throw error if something is caught
    if (!SDL_CreateWindowAndRenderer("SDL3 Tetris v1.1", 300, 600, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    Game game = Game(renderer, event);

    // Game Loop
    while (game.quit) {
        // calculate starting time for framerate
        Uint64 start = SDL_GetPerformanceCounter();

        //Set background color to dark blue
        game.HandleInput();
        if (frameCount % 20 == 0) {
            game.MoveBlockDown();
        }
        SDL_Color dark_blue = {44, 44, 127, 255};
        SDL_SetRenderDrawColor(renderer, dark_blue.r, dark_blue.g, dark_blue.b, dark_blue.a);
        SDL_RenderClear(renderer);
        // Draw the grid
        game.Draw();
        // Render the frame
        SDL_RenderPresent(renderer);

        // calculate ending time for framerate
        Uint64 end = SDL_GetPerformanceCounter();

        // Calculate total time passed for framerate and delay to achieve framerate
        float elapsed_time = (end - start) / (float) SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(floor(16.666f - elapsed_time));
        frameCount++;
        frameCount = frameCount % 60;
    }

    //Destroy and quit on quit
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}