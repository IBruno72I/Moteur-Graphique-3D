#include "events.h"
#include "window.h"
#include "maths.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


// Destroy To Quit
void destroyToQuit(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture) {
    if(NULL != texture)
        SDL_DestroyTexture(texture);
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
}

// Refresh Window
void updateWindow(SDL_Window* window, SDL_Renderer* renderer, Vec3 cam, Vec3* recF, Vec3* recB, float fov) {
    clear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 25);
    drawScare(window, renderer, cam, recF, recB, fov);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderPresent(renderer);
}

// Refresh Events
void updateEvents(SDL_Window* window, SDL_Event* event, Events* key, float* fov) {
    SDL_WaitEvent(event);
    if ((*event).type == SDL_KEYDOWN) {
        switch ((*event).key.keysym.scancode) {
            case 26: // FORWARD (Z)
                key->FORWARD = SDL_TRUE;
                break;
            case 22: // DOWN (S)
                key->REAR = SDL_TRUE;
                break;
            case 4: // LEFT (Q)
                key->LEFT = SDL_TRUE;
                break;
            case 7: // RIGHT (D)
                key->RIGHT = SDL_TRUE;
                break;
            case 44: // SPACE
                key->SPACE = SDL_TRUE;
                break;
            case 224: // CTRL
                key->CTRL = SDL_TRUE;
                break;
            case 225: // SHIFT
                key->SHIFT = SDL_TRUE;
                break;
            case 112: // P
                *fov += 0.1;
                break;
            case 109: // M
                *fov -= 0.1;
                break;
            case 68: // F11
                if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
                    SDL_SetWindowFullscreen(window, 0);
                } else {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                }
                break;
            case 41: // ESCAPE
                key->QUIT = SDL_TRUE;
                break;
        }
    }
    if ((*event).type == SDL_KEYUP) {
        switch ((*event).key.keysym.scancode) {
            case 26: // FORWARD (Z)
                key->FORWARD = SDL_FALSE;
                break;
            case 22: // DOWN (S)
                key->REAR = SDL_FALSE;
                break;
            case 4: // LEFT (Q)
                key->LEFT = SDL_FALSE;
                break;
            case 7: // RIGHT (D)
                key->RIGHT = SDL_FALSE;
                break;
            case 44: // SPACE
                key->SPACE = SDL_FALSE;
                break;
            case 224: // CTRL
                key->CTRL = SDL_FALSE;
                break;
            case 225: // SHIFT
                key->SHIFT = SDL_FALSE;
                break;
        }
    }
    if ((*event).type == SDL_QUIT)
        key->QUIT = SDL_TRUE;
}

// Refresh Position
void updatePosition(Vec3* cam, float* speed, Events key) {
    if (key.FORWARD) cam->z += (*speed);
    if (key.REAR) cam->z -= (*speed);
    if (key.LEFT) cam->x -= (*speed);
    if (key.RIGHT) cam->x += (*speed);
    if (key.SPACE) cam->y += (*speed);
    if (key.CTRL) cam->y -= (*speed);
}