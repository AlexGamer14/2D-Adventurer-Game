#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#pragma once

class game_object {
public:
    SDL_Texture* texture;
    SDL_FRect position_size;

    game_object();
    game_object(char texPath[]);
    int draw(SDL_FRect state);
};
