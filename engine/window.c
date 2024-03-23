#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Window *window() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) { // Check for error in SDL_Init
    printf("Failed to initialize SDL: %s\n", SDL_GetError());
  }
  SDL_Window *gameWindow =
      SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  if (gameWindow == NULL) { // Check if window creation failed
    printf("Failed to create window: %s\n", SDL_GetError());
    SDL_Quit();
  }
  return gameWindow;
}
