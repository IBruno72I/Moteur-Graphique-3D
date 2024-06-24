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
void updateWindow(SDL_Window* window, SDL_Renderer* renderer, Coord* recF, Coord* recB, float focal) {
    clear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 25);
    drawScare(window, renderer, recF, recB, focal);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderPresent(renderer);
}

// Refresh Events
void updateEvents(SDL_Window* window, SDL_Event* event, Coord* recF, Coord* recB, SDL_bool* quit, SDL_bool* UP, SDL_bool* DOWN, SDL_bool* LEFT, SDL_bool* RIGHT, float* focal) {
    SDL_WaitEvent(event);
    if ((*event).type == SDL_KEYDOWN) {
        switch ((*event).key.keysym.scancode) {
            case 82: // UP
                *UP = SDL_TRUE;
                break;
            case 81: // DOWN
                *DOWN = SDL_TRUE;
                break;
            case 80: // LEFT
                *LEFT = SDL_TRUE;
                break;
            case 79: // RIGHT
                *RIGHT = SDL_TRUE;
                break;
            case 68: // F11
                if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
                    SDL_SetWindowFullscreen(window, 0);
                } else {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                }
                break;
            case 87: // +
                *focal += 0.1;
                break;
            case 86: // -
                *focal -= 0.1;
                break;
            case 41: // ESCAPE
                *quit = SDL_TRUE;
                break;
        }
    }
    if ((*event).type == SDL_KEYUP) {
        switch ((*event).key.keysym.scancode) {
            case 82: // UP
                *UP = SDL_FALSE;
                break;
            case 81: // DOWN
                *DOWN = SDL_FALSE;
                break;
            case 80: // LEFT
                *LEFT = SDL_FALSE;
                break;
            case 79: // RIGHT
                *RIGHT = SDL_FALSE;
                break;
        }
    }
    if ((*event).type == SDL_QUIT)
        *quit = SDL_TRUE;
}

// Refresh Position
void updatePosition(Coord* recF, Coord* recB, SDL_bool UP, SDL_bool DOWN, SDL_bool LEFT, SDL_bool RIGHT) {
    if (UP) for (int i = 0; i < 5; i++) {
        recF[i].y -= 0.02;
        recB[i].y -= 0.02;
    }
    if (DOWN) for (int i = 0; i < 5; i++) {
        recF[i].y += 0.02;
        recB[i].y += 0.02;
    }
    if (LEFT) for (int i = 0; i < 5; i++) {
        recF[i].x -= 0.02;
        recB[i].x -= 0.02;
    }
    if (RIGHT)  for (int i = 0; i < 5; i++) {
        recF[i].x += 0.02;
        recB[i].x += 0.02;
    }
}