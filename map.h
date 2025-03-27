#pragma once

#include <SDL3_image/SDL_image.h>
#include "cute_tiled.h"
#include "main.h"

#include <string>
#include <iostream>

int load_map();
void render_map(float offset_x, float offset_y);
void cleanup();

struct Texture {
	SDL_Texture* texture;
	// Used for identifying the correct Texture
	int firstgid;
	int tilecount;
	Texture* next;
};