#ifndef EVENTS_H

#define EVENTS_H

#include "window.h"
#include <SDL2/SDL.h>

void updateEvents(SDL_Window* window, SDL_Event* event, Coord* pos, SDL_bool* quit);

#endif