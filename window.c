#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Point convertCoord(SDL_Window* window, Coord p) {
    SDL_Point point;
    int width = 0;
    int height = 0;
    SDL_GetWindowSize(window, &width, &height);
    point.x = (p.x + 1) * (width/2);
    point.y = (p.y + 1) * (height/2);
    return point;
}

void clear(SDL_Renderer* renderer) {
        if(0 != SDL_RenderClear(renderer))
        {
            SDL_Log("Erreur : RenderClear : %s", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }


void drawLines(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_Point points[5];
    Coord p[5];

    p[0].x = -0.25;
    p[0].y = 0.25;
    p[1].x = 0.25;
    p[1].y = 0.25;
    p[2].x = 0.25;
    p[2].y = -0.25;
    p[3].x = -0.25;
    p[3].y = -0.25;
    p[4].x = -0.25;
    p[4].y = 0.25;

    for (int i = 0; i < 5; i++) {
        points[i] = convertCoord(window, p[i]);
    }
    SDL_RenderDrawLines(renderer, points, 5);
}