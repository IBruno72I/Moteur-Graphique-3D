#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>




int main () {

    printf("START\n");

    SDL_Window *window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Erreur : Initialisation SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Initialisation de la fenêtre..

    window = SDL_CreateWindow(
                "WINDOW", 
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                640, 480, SDL_WINDOW_SHOWN
            );
    if (window == NULL) {
        SDL_Log("Erreur : Initialisation Window > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }




    SDL_Quit();

    return 0;
}