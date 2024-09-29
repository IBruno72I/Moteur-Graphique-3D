#ifndef WINDOW_H

#define WINDOW_H

#include "maths.h"
#include <SDL2/SDL.h>

void clear(SDL_Renderer* renderer);
void drawScare(SDL_Window* window, SDL_Renderer* renderer, Vec3 cam, Vec3* recF, Vec3* recB, float fov);

#endif