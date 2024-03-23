#include <SDL2/SDL.h>
#include <stdio.h>

void draw_images(SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *image) {
    if (!window || !renderer || !image) {
        // Error handling: Clean up resources and quit
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
        if (image) SDL_FreeSurface(image);
        SDL_Quit();
        return;
    }

    // Create texture from surface
    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, image);
    if (!imageTexture) {
        printf("Failed to create texture from surface: %s\n", SDL_GetError());
        // Clean up resources and quit
        SDL_FreeSurface(image);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Get the dimensions of the image
    int imageWidth = image->w;
    int imageHeight = image->h;

    // Define the destination rectangle for rendering the image (make it smaller)
    SDL_Rect destinationRect = { 0, 0, imageWidth / 2, imageHeight / 2 }; // Halves the image size

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = 1;
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 225, 255, 255);
        SDL_RenderClear(renderer);

        // Render the texture onto the renderer with the smaller destination rectangle
        SDL_RenderCopy(renderer, imageTexture, NULL, &destinationRect);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Clean up resources
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
