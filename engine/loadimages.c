#include <SDL2/SDL_image.h>

SDL_Surface* load_image(const char* image_path) {
    SDL_Surface* imageSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return NULL;
    }

    // Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
    }

    // Load image
    imageSurface = IMG_Load(image_path);
    if (imageSurface == NULL) {
        printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
    }

    return imageSurface;
}
