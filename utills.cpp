#include <SDL3/SDL.h>

#include "utills.h"

Uint64 lastTime = 0;
float deltaTime = 0.0f;

void updateDeltaTime() {
    Uint64 currentTime = SDL_GetPerformanceCounter();
    Uint64 frequency = SDL_GetPerformanceFrequency();  // Get the CPU tick rate

    deltaTime = (float)(currentTime - lastTime) / frequency;  // Convert to seconds
    lastTime = currentTime;
}

bool checkCollision(SDL_FRect* a, SDL_FRect* b) {
	return SDL_HasRectIntersectionFloat(a, b);
}