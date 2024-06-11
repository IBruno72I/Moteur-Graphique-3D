#include "window.h"
#include "events.h"
#include "maths.h"
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

    // Rec Front
    Coord recF[5];
    // Rec Front : Point 1
    recF[0].x = -0.2;
    recF[0].y = 0.2;
    recF[0].z = -0.2;
    recF[4].x = -0.2;
    recF[4].y = 0.2;
    recF[4].z = -0.2;
    // Rec Front : Point 2
    recF[1].x = 0.2;
    recF[1].y = 0.2;
    recF[1].z = -0.2;
    // Rec Front : Point 3
    recF[2].x = 0.2;
    recF[2].y = -0.2;
    recF[2].z = -0.2;
    // Rec Front : Point 4
    recF[3].x = -0.2;
    recF[3].y = -0.2;
    recF[3].z = -0.2;

    // Rec Back
    Coord recB[5];
    // Rec Back : Point 1
    recB[0].x = -0.2;
    recB[0].y = 0.2;
    recB[0].z = 0.2;
    recB[4].x = -0.2;
    recB[4].y = 0.2;
    recB[4].z = 0.2;
    // Rec Back : Point 2
    recB[1].x = 0.2;
    recB[1].y = 0.2;
    recB[1].z = 0.2;
    // Rec Back : Point 3
    recB[2].x = 0.2;
    recB[2].y = -0.2;
    recB[2].z = 0.2;
    // Rec Back : Point 4
    recB[3].x = -0.2;
    recB[3].y = -0.2;
    recB[3].z = 0.2;
    

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
         
        updateWindow(window, renderer, recF, recB);
        updateEvents(window, &event, recF, recB, &quit, &UP, &DOWN, &LEFT, &RIGHT);
        updatePosition(recF, recB, UP, DOWN, LEFT, RIGHT);

    }

    destroyToQuit(window, renderer, texture);
    SDL_Quit();
    return EXIT_SUCCESS;
}