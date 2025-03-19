#include <SDL3/SDL.h>
#include "const.h"

#include "input_controller.h"
#include "main.h"
#include "graphics.h"
#include "player.h"

#include <iostream>
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

player* Player = NULL;

bool is_game_running = false;

SDL_Texture plrTexture;

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

		renderer = NULL;
		window = NULL;

		SDL_Quit();

		return PASS;
	}
	catch (const std::exception&)
	{
		fprintf(stderr, "Unable to succsesfully shut down SDL.%s\n", SDL_GetError());
		return FAIL;
	}
}

void update() {
	SetScreenColor(255, 255, 255, 255);
	Player->draw();
	SDL_RenderPresent(renderer);
	procces_input();
}

int main() {
	cout << "Hello, World!";

	if (init() == FAIL) {
		fprintf(stderr, "Code go boom boom somewhere\n");
		return FAIL;
	}

	is_game_running = true;

	char plrFilePath[] = "C:\\Users\\alexa\\source\\repos\\Pacman\\Top_Down_Adventure_Pack_v.1.0\\Char_Sprites\\char_spritesheet.png";

	try
	{
		Player = new player(plrFilePath);
	}
	catch (const std::exception&)
	{
		cout << "Failed to create player";
	}


	while (is_game_running) {
		update();
	}

	return destroy_all();
}