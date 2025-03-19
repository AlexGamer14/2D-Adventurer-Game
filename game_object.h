#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#pragma once

class game_object {
public:
    SDL_Texture* texture;
    int x;
    int y;

    game_object(char texPath[]);
    int draw();
};
