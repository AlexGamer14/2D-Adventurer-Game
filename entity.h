#pragma once

#include "game_object.h"
#include <SDL3/SDL.h>
#include "utills.h"

class entity : public game_object {
public:
	float movement_speed;

	float velocity_x;
	float velocity_y;


	void physics();
	entity(char texPath[],  float movement_speed);
};