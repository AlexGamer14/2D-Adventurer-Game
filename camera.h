#pragma once

struct Camera {
	float x, y;
	int w, h;
};

extern Camera camera;
void updateCamera(float playerX, float playerY);