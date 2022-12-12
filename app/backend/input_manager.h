#pragma once

#include <SDL2/SDL.h>

typedef struct opened_controller_t {
    SDL_GameController *controller;
    SDL_JoystickID id;
} opened_controller_t;

typedef struct input_manager_t {
    opened_controller_t *controllers;
    size_t controllers_size, controllers_cap;
} input_manager_t;

input_manager_t *input_manager_create();

void input_manager_destroy(input_manager_t *manager);

void input_manager_sdl_gamepad_added(input_manager_t *manager, int which);

void input_manager_sdl_gamepad_removed(input_manager_t *manager, SDL_JoystickID which);