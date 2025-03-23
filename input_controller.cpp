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


	const bool* keyboard_state = SDL_GetKeyboardState(NULL);

	if (keyboard_state[FORWARDKEY]) {
		Player->velocity_y = -Player->movement_speed;
	}
	if (keyboard_state[BACKWARDKEY]) {
		Player->velocity_y = Player->movement_speed;
	}
	if (keyboard_state[LEFTKEY]) {
		Player->velocity_x = -Player->movement_speed;
	}
	if (keyboard_state[RIGHTKEY]) {
		Player->velocity_x = Player->movement_speed;
	}

	if (keyboard_state[SDL_SCANCODE_Q]) {
		is_game_running = false;
	}
}