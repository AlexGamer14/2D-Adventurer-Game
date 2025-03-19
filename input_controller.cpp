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
					cout << "Forward key pressed\n";
					break;
				case BACKWARDKEY:
					cout << "Backward key pressed\n";
					break;
				case LEFTKEY:
					cout << "Left key pressed\n";
					break;
				case RIGHTKEY:
					cout << "Right key pressed\n";
					break;
				case JUMPKEY:
					cout << "Jump key pressed\n";
					break;
				case SDLK_Q:
					is_game_running = false;
					break;
				default:
					break;
			}
			break;
		}
	}
}