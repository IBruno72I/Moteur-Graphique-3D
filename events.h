#ifndef EVENTS_H

#define EVENTS_H

#include "maths.h"
#include <SDL2/SDL.h>

typedef struct{
    SDL_bool FORWARD;
    SDL_bool REAR;
    SDL_bool LEFT;
    SDL_bool RIGHT;
    SDL_bool SPACE;
    SDL_bool CTRL;
    SDL_bool SHIFT;
    SDL_bool QUIT;
}Events;

void destroyToQuit(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);
void updateWindow(SDL_Window* window, SDL_Renderer* renderer, Vec3 cam, Vec3* recF, Vec3* recB, float fov);
void updateEvents(SDL_Window* window, SDL_Event* event, Events* key, float* fov);
void updatePosition(Vec3* cam, float* speed, Events key);

#endif