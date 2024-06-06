#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


int main () {

    // Initialisation :
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

    while (!quit) {
        update(window, renderer, pos);



        SDL_WaitEvent(&event);

        if (event.type == SDL_KEYDOWN) {

            switch (event.key.keysym.scancode) {

                case 82: // UP
                    for (int i = 0; i < 5; i++) pos[i].y -= 0.02;
                    break;

                case 81: // DOWN
                    for (int i = 0; i < 5; i++) pos[i].y += 0.02;
                    break;

                case 80: // LEFT
                    for (int i = 0; i < 5; i++) pos[i].x -= 0.02;
                    break;

                case 79: // RIGHT
                    for (int i = 0; i < 5; i++) pos[i].x += 0.02;
                    break;


                case 68: // F11
                    if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
                        SDL_SetWindowFullscreen(window, 0);
                    } else {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    break;
                case 41: // ESCAPE
                    quit = SDL_TRUE;
                    break;
            }
                
        }
                
        if (event.type == SDL_QUIT)
            quit = SDL_TRUE;
    }




    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}