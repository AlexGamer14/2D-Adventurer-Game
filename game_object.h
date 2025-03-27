#pragma once

#include <SDL3/SDL.h>

class game_object {
public:
    SDL_Texture* texture;
    SDL_FRect position_size;

    game_object();
    game_object(char texPath[]);
    int draw(SDL_FRect state, float offset_x, float offset_y);
};
