#pragma once

#include <vector>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "player.h"
#include "game_object.h"
#include "const.h"

//#include "text_obj.h"

extern bool is_game_running;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern player* Player;
extern TTF_Font* baseFont;

extern std::vector<game_object> all_game_objects;
//extern std::vector<Text> all_text_objects;

extern TTF_Font* baseFont;