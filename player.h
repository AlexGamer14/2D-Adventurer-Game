#pragma once

#include "entity.h"

class player : public entity {
public:
	float walkSpeed;
	float runSpeed;
	
	float jumpPower;

	SDL_FRect player_state;

	player(char texPath[],float mov_speed , SDL_FRect plrtransform);
};