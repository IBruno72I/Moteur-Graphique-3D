#ifndef EVENTS_H

#define EVENTS_H

#include "window.h"
#include <SDL2/SDL.h>

void updateWindow(SDL_Window* window, SDL_Renderer* renderer, Coord* pos);
void updateEvents(SDL_Window* window, SDL_Event* event, Coord* pos, SDL_bool* quit, SDL_bool* UP,SDL_bool* DOWN,SDL_bool* LEFT,SDL_bool* RIGHT);
void destroyToQuit(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);
void updatePosition(Coord* pos, SDL_bool UP,SDL_bool DOWN,SDL_bool LEFT,SDL_bool RIGHT);

#endif