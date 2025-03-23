#pragma once

#include <SDL3/SDL.h>

// Subsystems that will be used for SDL
#define SDL_INIT_ALL_SUBSYSTEMS SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS

// Function fails or passes
#define FAIL 1
#define PASS 0

#define MOVEMENT_SPEED 30

#define FORWARDKEY SDL_SCANCODE_W
#define BACKWARDKEY SDL_SCANCODE_S
#define LEFTKEY SDL_SCANCODE_A
#define RIGHTKEY SDL_SCANCODE_D

#define MAX_ENTITIES 100
#define MAX_GAMEOBJECTS 1000