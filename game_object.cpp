#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game_object.h"
#include "main.h"

#include <iostream>
using namespace std;

game_object::game_object(char texPath[]) {
	game_object::texture = nullptr;
	game_object::texture = IMG_LoadTexture(renderer, texPath);

	if (texture == nullptr) {
		fprintf(stderr, "Error loading texture\n");
	}
	game_object::x = 0;
	game_object::y = 0;
}

int game_object::draw() {
	SDL_RenderTexture(renderer, game_object::texture, NULL, NULL);
	return 0;
}
