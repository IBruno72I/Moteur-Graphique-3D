#ifndef EVENTS_H

#define EVENTS_H

#include "maths.h"
#include <SDL2/SDL.h>

typedef struct{
    SDL_bool UP;
    SDL_bool DOWN;
    SDL_bool LEFT;
    SDL_bool RIGHT;
}Events;

void destroyToQuit(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);
void updateWindow(SDL_Window* window, SDL_Renderer* renderer, Coord* recF, Coord* recB, float focal);
void updateEvents(SDL_Window* window, SDL_Event* event, Coord* recF, Coord* recB, SDL_bool* quit, Events* key, float* focal);
void updatePosition(Coord* recF, Coord* recB, Events key);

#endif