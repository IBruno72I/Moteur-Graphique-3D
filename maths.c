#include "maths.h"
#include "events.h"
#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#define FOV 180


// Convert Points x: [-1, 1] -> [0, 1920]  y: [-1, 1] -> [0, 1080]       P(x,y) = (0, 0) => middle of screen
SDL_Point convertCoord(SDL_Window* window, Coord pos) {
    Proj projPos;
    SDL_Point point;
    int width = 0;
    int height = 0;
    projPos.x = pos.x / (pos.z * (tan(FOV/2)));
    projPos.y = pos.y / (pos.z * (tan(FOV/2)));
    SDL_GetWindowSize(window, &width, &height);
    point.x = (projPos.x + 1) * (width/2);
    point.y = (projPos.y + 1) * (height/2);
    return point;
}

/*  Rotation X
void rotationX(double a, Coord* pos) {
    double Rx [3][3] = {{1,0,0},{0,cos(a),sin(a)},{0,-sin(a),cos(a)}};
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < 3; i++) {
        x += (*pos).x * Rx[0][i];
        y += (*pos).y * Rx[1][i];
        z += (*pos).z * Rx[2][i];
    }
    (*pos).x = x;
    (*pos).y = y;
    (*pos).z = z;
}

// Rotation Y
void rotationY(double a, Coord* pos) {
    double Ry [3][3] = {{cos(a),0,sin(a)},{0,1,0},{-sin(a),0,cos(a)}};
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < 3; i++) {
        x += (*pos).x * Ry[0][i];
        y += (*pos).y * Ry[1][i];
        z += (*pos).z * Ry[2][i];
    }
    (*pos).x = x;
    (*pos).y = y;
    (*pos).z = z;
}

// Rotation Z
void rotationZ(double a, Coord* pos) {
    double Rz [3][3] = {{cos(a),-sin(a),0},{sin(a),cos(a),0},{0,0,1}};
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < 3; i++) {
        x += (*pos).x * Rz[0][i];
        y += (*pos).y * Rz[1][i];
        z += (*pos).z * Rz[2][i];
    }
    (*pos).x = x;
    (*pos).y = y;
    (*pos).z = z;
}
*/