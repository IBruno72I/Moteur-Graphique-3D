#include "window.h"
#include "events.h"
#include "maths.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


// Clear Renderer
void clear(SDL_Renderer* renderer) {
        if(0 != SDL_RenderClear(renderer))
        {
            SDL_Log("Erreur : RenderClear : %s", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }

// Draw the lines between points
void drawScare(SDL_Window* window, SDL_Renderer* renderer, Coord* recF, Coord* recB) {
    SDL_Point pointsF[5];
    SDL_Point pointsB[5];
    for (int i = 0; i < 5; i++) {
        pointsF[i] = convertCoord(window, recF[i]);
        pointsB[i] = convertCoord(window, recB[i]);
    }
    SDL_RenderDrawLines(renderer, pointsF, 5);
    SDL_RenderDrawLines(renderer, pointsB, 5);

    for (int i = 0; i < 4; i++) SDL_RenderDrawLine(renderer, pointsF[i].x, pointsF[i].y, pointsB[i].x, pointsB[i].y);
}