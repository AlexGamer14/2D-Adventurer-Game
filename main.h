#pragma once

#include <vector>

#include <SDL3/SDL.h>
#include "player.h"
#include "game_object.h"
#include "const.h"

extern bool is_game_running;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern player* Player;

extern std::vector<game_object> all_game_objects;