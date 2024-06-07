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
    SDL_Texture* texture = NULL;
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
    SDL_bool UP = SDL_FALSE, DOWN = SDL_FALSE, LEFT = SDL_FALSE, RIGHT = SDL_FALSE;
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
    // Init Texture
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                                SDL_TEXTUREACCESS_TARGET, 200, 200);
    if (texture == NULL) {
        SDL_Log("Erreur : CreateTexture > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }


    // START..

    SDL_ShowWindow(window);
    while (!quit) {

        updateWindow(window, renderer, pos);
        updateEvents(window, &event, pos, &quit, &UP, &DOWN, &LEFT, &RIGHT);
        updatePosition(pos, UP, DOWN, LEFT, RIGHT);

    }

    destroyToQuit(window, renderer, texture);
    SDL_Quit();
    return EXIT_SUCCESS;
}