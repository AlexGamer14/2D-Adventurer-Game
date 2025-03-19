#include <SDL3/SDL.h>
#include "const.h"

#include "input_controller.h"
#include "main.h"

#include <iostream>
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool is_game_running = false;

int init_win(void) {
	window = SDL_CreateWindow("Pacman", 1920, 1080, SDL_WINDOW_RESIZABLE);

	if (!window) {
		fprintf(stderr, "Window go boom boom\n");
		return FAIL;
	}

	renderer = SDL_CreateRenderer(window, NULL);
	if (!renderer) {
		fprintf(stderr, "Boom theres goes you renderer, watch it burn, feel the power\n");
		return FAIL;
	}

	return PASS;
}




int init() {
	if (SDL_Init(SDL_INIT_ALL_SUBSYSTEMS) == PASS) {
		fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
		return FAIL;
	}

	if (init_win() == FAIL) {
		cout << "Initializing of window failed";
		return FAIL;
	}

	return PASS;
}


int destroy_all() {
	try
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();

		return PASS;
	}
	catch (const std::exception&)
	{
		fprintf(stderr, "Unable to succsesfully shut down SDL.%s\n", SDL_GetError());
		return FAIL;
	}
}


int main() {
	cout << "Hello, World!";

	if (init() == FAIL) {
		fprintf(stderr, "Code go boom boom somewhere\n");
		return FAIL;
	}

	is_game_running = true;

	while (is_game_running) {
		procces_input();
	}

	return destroy_all();
}