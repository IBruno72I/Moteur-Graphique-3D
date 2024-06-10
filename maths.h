#ifndef MATHS_H

#define MATHS_H

#include <SDL2/SDL.h>

typedef struct{
    float x;
    float y;
    float z;
}Coord;

typedef struct{
    // [-1,1]
    float x;
    float y;
}Proj;

SDL_Point convertCoord(SDL_Window* window, Proj pos);

#endif