#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "text_obj.h"
#include "main.h"

Text::Text(Vector2 _position, Vector2 _size, SDL_Color textColor, TTF_Font* _font, string _text) {
	drawColor = textColor;
	font = _font;
	text = _text;

	position = _position;
	text_size = _size;
}

Text::~Text() {
	TTF_CloseFont(font);
}

void Text::draw() {
	SDL_Surface* surface_msg = TTF_RenderText_Solid(font, text.c_str(), text.length(), drawColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface_msg);

	SDL_FRect render_rect = { position.x, position.y, text_size.x, text_size.y };

	SDL_RenderTexture(renderer, message, NULL, &render_rect);

	SDL_DestroySurface(surface_msg);
	SDL_DestroyTexture(message);
}

void Text::setTextColor(SDL_Color color) {
	drawColor = color;
};

void Text::setText(string _text) {
	text = _text;
};
void Text::setFont(TTF_Font* _font) {
	font = _font;
};