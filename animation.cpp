#include "animation.h"

void Animator::update(float dt) {
	if (this->playing && !this->paused) {
		this->currentFrameTime += dt;
		if (this->currentFrameTime >= this->frameDuration) {
			this->currentFrameTime = 0;
			this->currentFrameIndex++;
			if (this->currentFrameIndex >= this->frameCount) {
				if (this->loop) {
					this->currentFrameIndex = 0;
				}
				else {
					this->currentFrameIndex = this->frameCount - 1;
					this->playing = false;
					this->finished = true;
				}
			}
		}
	}
}


void Animator::stop() {
	this->playing = false;
	this->paused = false;
	this->finished = false;
	this->currentFrameIndex = 0;
	this->currentFrameTime = 0;
}

void Animator::pause() {
	this->paused = true;
}

void Animator::play() {
	this->playing = true;
	this->paused = false;
	this->finished = false;
}

SDL_FRect Animator::get_src() {
	SDL_FRect src = { baseFrameOffset.x + this->currentFrameIndex * this->frameWidth, baseFrameOffset.y + 0, this->frameWidth, this->frameHeight };
	//printf(std::to_string(src.x).append(std::to_string(src.y)).append(std::to_string(src.w)))
	return src;
}