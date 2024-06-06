#ifndef WINDOW_H

#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct{
    // [-1,1]
    float x;
    float y;
}Coord;

SDL_Point convertCoord(SDL_Window* window, Coord p);
void clear(SDL_Renderer* renderer);
void drawLines(SDL_Window* window, SDL_Renderer* renderer);


#endif