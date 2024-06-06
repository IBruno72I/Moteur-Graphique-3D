#include "events.h"
#include "window.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


void updateEvents(SDL_Window* window, SDL_Event* event, Coord* pos, SDL_bool* quit) {
    SDL_WaitEvent(event);
    if ((*event).type == SDL_KEYDOWN) {
        switch ((*event).key.keysym.scancode) {
            case 82: // UP
                for (int i = 0; i < 5; i++) pos[i].y -= 0.02;
                break;
            case 81: // DOWN
                for (int i = 0; i < 5; i++) pos[i].y += 0.02;
                break;
            case 80: // LEFT
                for (int i = 0; i < 5; i++) pos[i].x -= 0.02;
                break;
            case 79: // RIGHT
                for (int i = 0; i < 5; i++) pos[i].x += 0.02;
                break;
            case 68: // F11
                if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
                    SDL_SetWindowFullscreen(window, 0);
                } else {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                }
                break;
            case 41: // ESCAPE
                *quit = SDL_TRUE;
                break;
        }
    }
    if ((*event).type == SDL_QUIT)
        *quit = SDL_TRUE;
}