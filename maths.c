#include "maths.h"
#include "events.h"
#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


// Convert Points x: [-1, 1] -> [0, 1920]  y: [-1, 1] -> [0, 1080]       P(x,y) = (0, 0) => middle of screen
SDL_Point convertCoord(SDL_Window* window, Proj pos) {
    SDL_Point point;
    int width = 0;
    int height = 0;
    SDL_GetWindowSize(window, &width, &height);
    point.x = (pos.x + 1) * (width/2);
    point.y = (pos.y + 1) * (height/2);
    return point;
}