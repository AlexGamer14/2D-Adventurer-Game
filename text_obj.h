#pragma once

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
using namespace std;

#include "main.h"

class Text {
private:
	SDL_Color drawColor;
	TTF_Font* font;

	string text;
public:
	void setTextColor(SDL_Color color);
	void setText(string _text);
	void setFont(TTF_Font* _font);


	void draw();
	Text(SDL_Color textColor = {255, 255, 255, 255}, TTF_Font* _font = baseFont, string _text = "Hello, World!");
};