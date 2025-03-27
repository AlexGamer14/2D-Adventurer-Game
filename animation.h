#pragma once

#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "const.h"

class Animator {
public:
	SDL_Rect currentFrame;

	int frameCount;
	int frameWidth;
	int frameHeight;
	float frameDuration;
	int currentFrameIndex;
	float currentFrameTime;

	Vector2 baseFrameOffset;

	bool loop;
	bool playing;
	bool paused;
	bool finished;

	// Constructor
	Animator(int frameCount, int frameWidth, int frameHeight, float frameDuration, bool loop) {
		this->frameCount = frameCount;
		this->frameWidth = frameWidth;
		this->frameHeight = frameHeight;
		this->frameDuration = frameDuration;
		this->loop = loop;
		this->playing = false;
		this->paused = false;
		this->finished = false;
		this->currentFrameIndex = 0;
		this->currentFrameTime = 0;
		this->currentFrame = { 0, 0, frameWidth, frameHeight };

		this->baseFrameOffset = { 16, 16 };
	}

	// Play the animation
	void play();

	// Pause the animation
	void pause();

	// Stop the animation
	void stop();

	// Update the animation
	void update(float dt);

	SDL_FRect get_src();
};