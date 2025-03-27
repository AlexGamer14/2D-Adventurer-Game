#include <SDL3/SDL.h>

#include <iostream>

#include "const.h"
#include "input_controller.h"
#include "main.h"

using namespace std;

void procces_input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_EVENT_QUIT:
			is_game_running = false;
			break;
		default:
			break;
		}
	}


	Player->velocity_x = 0;
	Player->velocity_y = 0;

	switch (Player->dir)
	{
	case 'u':
		Player->animator->baseFrameOffset = Player->idle_animation_offset_up;
		break;
	case 'd':
		Player->animator->baseFrameOffset = Player->idle_animation_offset_down;
		break;
	case 'l':
		Player->animator->baseFrameOffset = Player->idle_animation_offset_left;
		break;
	case 'r':
		Player->animator->baseFrameOffset = Player->idle_animation_offset_right;
		break;
	default:
		break;
	}

	const bool* keyboard_state = SDL_GetKeyboardState(NULL);

	if (keyboard_state[FORWARDKEY]) {
		Player->velocity_y = -Player->movement_speed;
		Player->animator->baseFrameOffset = Player->walk_animation_offset_up;
		Player->dir = 'u';
	}
	if (keyboard_state[BACKWARDKEY]) {
		Player->velocity_y = Player->movement_speed;
		Player->animator->baseFrameOffset = Player->walk_animation_offset_down;
		Player->dir = 'd';
	}
	if (keyboard_state[LEFTKEY]) {
		Player->velocity_x = -Player->movement_speed;
		Player->animator->baseFrameOffset = Player->walk_animation_offset_left;
		Player->dir = 'l';
	}
	if (keyboard_state[RIGHTKEY]) {
		Player->velocity_x = Player->movement_speed;
		Player->animator->baseFrameOffset = Player->walk_animation_offset_right;
		Player->dir = 'r';
	}

	if (keyboard_state[SDL_SCANCODE_Q]) {
		is_game_running = false;
	}
}