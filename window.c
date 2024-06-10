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
void drawLines(SDL_Window* window, SDL_Renderer* renderer, Proj* pos) {
    SDL_Point points[5];

    for (int i = 0; i < 5; i++) {
        points[i] = convertCoord(window, pos[i]);
    }
    SDL_RenderDrawLines(renderer, points, 5);
}