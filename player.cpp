#include "player.h"

SDL_FRect playerStartState = { 17,14,15,18 };

player::player(char texPath[],float mov_speed ,SDL_FRect plrtransform) : entity(texPath, mov_speed) {
	walkSpeed = 7;
	runSpeed = 14;

	jumpPower = 20;

	position_size = plrtransform;
	player_state = playerStartState;

	animator = new Animator(4, 16, 16, 0.33, true);
}