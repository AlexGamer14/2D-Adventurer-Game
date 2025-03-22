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
		case SDL_EVENT_KEY_DOWN:
			switch (event.key.key) {
				case FORWARDKEY:
					Player->velocity_y = -Player->movement_speed;

					cout << "Forward key pressed\n";
					break;
				case BACKWARDKEY:
					Player->velocity_y = Player->movement_speed;
					cout << "Backward key pressed\n";
					break;
				case LEFTKEY:
					Player->velocity_x = -Player->movement_speed;

					cout << "Left key pressed\n";
					break;
				case RIGHTKEY:
					Player->velocity_x = Player->movement_speed;

					cout << "Right key pressed\n";
					break;
				case SDLK_Q:
					is_game_running = false;
					break;
				default:
					break;
			}
			break;
		default:
			Player->velocity_x = 0;
			Player->velocity_y = 0;
			break;
		}
	}
}