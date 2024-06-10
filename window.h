#ifndef WINDOW_H

#define WINDOW_H

#include "maths.h"
#include <SDL2/SDL.h>

void clear(SDL_Renderer* renderer);
void drawLines(SDL_Window* window, SDL_Renderer* renderer, Proj* pos);


#endif