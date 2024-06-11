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

SDL_Point convertCoord(SDL_Window* window, Coord pos);
//void rotationX(double a, Coord* pos);
//void rotationY(double a, Coord* pos);
//void rotationZ(double a, Coord* pos);

#endif