#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "const.h"

#include "input_controller.h"
#include "main.h"
#include "graphics.h"
#include "player.h"
#include "utills.h"
#include "text_obj.h"
#include "map.h"

#include <iostream>
#include <vector>
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* textSurface = nullptr;

player* Player = NULL;
Text* fpsText = NULL;

std::vector<game_object> all_game_objects;

bool is_game_running = false;

SDL_Texture plrTexture;

TTF_Font* baseFont = nullptr;

float averageFPS = 0;
int frameCounter = 0;

int init_win(void) {
	window = SDL_CreateWindow("Pacman", 2560, 1920, SDL_WINDOW_FULLSCREEN);

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
	baseFont = TTF_OpenFont("C:\\Windows\\Fonts\\seguivar.ttf", 24);
	if (!baseFont) {
		fprintf(stderr, "Failed to load font \n");
		return FAIL;
	}

	if (init_win() == FAIL) {
		cout << "Initializing of window failed\n";
		return FAIL;
	}

	if (load_map() == FAIL) {
		fprintf(stderr, "Failed to load map\n");
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
		
		delete Player;

		cleanup();

		return PASS;
	}
	catch (const std::exception&)
	{
		fprintf(stderr, "Unable to succsesfully shut down SDL.%s\n", SDL_GetError());
		return FAIL;
	}
}

void Render() {
	SetScreenColor(255, 255, 255, 255);

	render_map();

	Player->draw(Player->animator->get_src());
	fpsText->draw();

	averageFPS += 1 / deltaTime;
	frameCounter += 1;

	fpsText->setText("Fps: " + to_string(static_cast<int>(std::floor(averageFPS/frameCounter))));

	SDL_RenderPresent(renderer);
}

void update() {
	procces_input();

	Player->animator->update(deltaTime);
	/*if (checkCollision(Player->position_size, )) {
	}*/
	Player->physics();


	Render();
}
   
int main() {
	cout << "Hello, World!\n";

	if (init() == FAIL) {
		fprintf(stderr, "Code go boom boom somewhere\n");
		return FAIL;
	}
	SDL_SetRenderLogicalPresentation(renderer, 640, 360, SDL_LOGICAL_PRESENTATION_LETTERBOX);

	is_game_running = true;

	char plrFilePath[] = ".\\Resources\\Char_Sprites\\char_spritesheet.png";

	SDL_FRect playerStartTransform = { 100, 100, 25, 25 };

	try
	{
		Player = new player(plrFilePath, 100, playerStartTransform);
	}
	catch (const std::exception&)
	{
		cout << "Failed to create player\n";
	}

	fpsText = new Text({ 0,0 }, { 120, 40}, {0,0,0,255});

	Player->animator->play();
	Player->animator->baseFrameOffset = Player->idle_animation_offset_down;

	while (is_game_running) {
		updateDeltaTime();

		update();
	}

	return destroy_all();
}