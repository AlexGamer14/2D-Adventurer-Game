#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "const.h"

#include "input_controller.h"
#include "main.h"
#include "graphics.h"
#include "player.h"
#include "utills.h"

#include <iostream>
#include <vector>
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* textSurface = nullptr;

player* Player = NULL;

std::vector<game_object> all_game_objects;

bool is_game_running = false;

SDL_Texture plrTexture;

TTF_Font* baseFont = nullptr;

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

	if (TTF_Init() == PASS) {
		std::cerr << "Failed to initialize SDL_ttf: " << SDL_GetError() << std::endl;
		return FAIL;
	}
	baseFont = TTF_OpenFont("seguivar.ttf", 24);
	if (!baseFont) {
		fprintf(stderr, "Failed to load font \n");
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
		SDL_DestroySurface(textSurface);

		TTF_CloseFont(baseFont);

		renderer = NULL;
		window = NULL;

		for (game_object g_object : all_game_objects)
		{
			SDL_DestroyTexture(g_object.texture);
		}

		TTF_Quit();
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

	Player->physics();

	Player->draw(Player->player_state);
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

	SDL_FRect playerStartTransform = { 500, 500, 100, 100 };

	try
	{
		Player = new player(plrFilePath, 300, playerStartTransform);
	}
	catch (const std::exception&)
	{
		cout << "Failed to create player";
	}


	while (is_game_running) {
		updateDeltaTime();

		update();
	}

	return destroy_all();
}