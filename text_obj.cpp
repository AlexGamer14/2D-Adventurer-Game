#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "text_obj.h"

Text::Text(SDL_Color textColor, TTF_Font* _font, string _text) {
	drawColor = textColor;
	font = _font;
	text = _text;
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