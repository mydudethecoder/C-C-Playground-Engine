#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Renderer *renderer(SDL_Window *window) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return NULL;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    return renderer;
}
