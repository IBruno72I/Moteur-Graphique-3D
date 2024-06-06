#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


int main () {

    // Initialisation :
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Erreur : Initialisation SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Window:
    window = SDL_CreateWindow(
                "WINDOW", 
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                960, 540, 
                SDL_WINDOW_BORDERLESS
            );
    if (window == NULL) {
        SDL_Log("Erreur : CreateWindow > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Rendu:
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_Log("Erreur : CreateRenderer > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Affichage :
    SDL_ShowWindow(window);



    // Évènements :
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

    while (!quit) {

        // Refresh:
        clear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 25);
        drawLines(window, renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderPresent(renderer);



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

    return EXIT_SUCCESS;
}