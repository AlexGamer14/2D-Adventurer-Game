#include <SDL3/SDL.h>

#include "main.h"
#include "graphics.h"


void SetScreenColor(Uint8 rColor, Uint8 gColor, Uint8 bColor, Uint8 alpha) {
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, rColor, gColor, bColor, alpha);
}
