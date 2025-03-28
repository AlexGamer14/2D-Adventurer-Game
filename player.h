#pragma once

#include "entity.h"
#include "animation.h"


class player : public entity {
public:
	float walkSpeed;
	float runSpeed;
	
	float jumpPower;

	Animator* animator;

	SDL_FRect player_state;

	Vector2 idle_animation_offset_down = { 128, 16 };
	Vector2 idle_animation_offset_left = { 128, 32 };
	Vector2 idle_animation_offset_right = { 128, 48 };
	Vector2 idle_animation_offset_up = { 128, 64 };

	Vector2 walk_animation_offset_down = { 16, 16 };
	Vector2 walk_animation_offset_left = { 16, 32 };
	Vector2 walk_animation_offset_right = { 16, 48 };
	Vector2 walk_animation_offset_up = { 16, 64 };

	// d down u up l left r right
	char dir = 'd';

	player(char texPath[],float mov_speed , SDL_FRect plrtransform, bool useCollision);
};