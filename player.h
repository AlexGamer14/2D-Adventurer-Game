#pragma once

#include "game_object.h"

class player : public game_object {
public:
	float walkSpeed;
	float runSpeed;
	
	float jumpPower;

	player(char texPath[]);
};