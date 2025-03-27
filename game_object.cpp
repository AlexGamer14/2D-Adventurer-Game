#include "game_object.h"
#include "main.h"
#include <SDL3_image/SDL_image.h>

#include <iostream>
#include <vector>
using namespace std;


game_object::game_object() {
	fprintf(stderr, "USING WRONG GAMEOBJECT CONSTRUCTOR");
}

game_object::game_object(char texPath[]) {
	game_object::texture = nullptr;
	game_object::texture = IMG_LoadTexture(renderer, texPath);
	SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

	if (texture == nullptr) {
		fprintf(stderr, "Error loading texture\n");
	}
	game_object::position_size = {0,0,0,0};

	all_game_objects.push_back(*this);
}

int game_object::draw(SDL_FRect state, float offset_x, float offset_y) {
	SDL_FRect final_pos = { position_size.x - offset_x, position_size.y - offset_y, position_size.w, position_size.h };
	SDL_RenderTexture(renderer, game_object::texture,&state, &final_pos);
	return 0;
}
