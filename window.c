#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


void update(SDL_Window* window, SDL_Renderer* renderer, Coord* pos) {
    clear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 25);
    drawLines(window, renderer, pos);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderPresent(renderer);
}


SDL_Point convertCoord(SDL_Window* window, Coord pos) {
    SDL_Point point;
    int width = 0;
    int height = 0;
    SDL_GetWindowSize(window, &width, &height);
    point.x = (pos.x + 1) * (width/2);
    point.y = (pos.y + 1) * (height/2);
    return point;
}


void clear(SDL_Renderer* renderer) {
        if(0 != SDL_RenderClear(renderer))
        {
            SDL_Log("Erreur : RenderClear : %s", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }


void drawLines(SDL_Window* window, SDL_Renderer* renderer, Coord* pos) {
    SDL_Point points[5];

    for (int i = 0; i < 5; i++) {
        points[i] = convertCoord(window, pos[i]);
    }
    SDL_RenderDrawLines(renderer, points, 5);
}