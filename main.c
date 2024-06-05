#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>




int main () {

    SDL_Window *window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Erreur : Initialisation SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Initialisation de la fenêtre..

    window = SDL_CreateWindow(
                "WINDOW", 
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                960, 540, 
                SDL_WINDOW_BORDERLESS
            );
    if (window == NULL) {
        SDL_Log("Erreur : Initialisation Window > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_ShowWindow(window);

    
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

    while (!quit) {
        SDL_WaitEvent(&event);

        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.scancode == SDL_SCANCODE_F11) {
                if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
                    SDL_SetWindowFullscreen(window, 0);
                } else {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                }
            }

            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                quit = SDL_TRUE;
        }
                
        if (event.type == SDL_QUIT)
            quit = SDL_TRUE;
    }




    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}