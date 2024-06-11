#ifndef EVENTS_H

#define EVENTS_H

#include "maths.h"
#include <SDL2/SDL.h>

void destroyToQuit(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);
void updateWindow(SDL_Window* window, SDL_Renderer* renderer, Coord* recF, Coord* recB);
void updateEvents(SDL_Window* window, SDL_Event* event, Coord* recF, Coord* recB, SDL_bool* quit, SDL_bool* UP,SDL_bool* DOWN,SDL_bool* LEFT,SDL_bool* RIGHT);
void updatePosition(Coord* recF, Coord* recB, SDL_bool UP,SDL_bool DOWN,SDL_bool LEFT,SDL_bool RIGHT);

#endif