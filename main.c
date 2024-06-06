#include "window.h"
#include "events.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


int main () {

    // INIT..

    // Init Values
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event event;
    SDL_bool quit = SDL_FALSE;
    Coord pos[5];
    pos[0].x = -0.25;
    pos[0].y = 0.25;
    pos[1].x = 0.25;
    pos[1].y = 0.25;
    pos[2].x = 0.25;
    pos[2].y = -0.25;
    pos[3].x = -0.25;
    pos[3].y = -0.25;
    pos[4].x = -0.25;
    pos[4].y = 0.25;
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Erreur : Initialisation SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    // Init Window
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
    // Init Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_Log("Erreur : CreateRenderer > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }


    // START..

    SDL_ShowWindow(window);
    while (!quit) {

        updateWindow(window, renderer, pos);
        updateEvents(window, &event, pos, &quit);

    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}