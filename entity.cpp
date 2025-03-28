#include "entity.h"
#include "map.h"

void entity::physics()
{
	if (position_size.x <= 0) {
		velocity_x = fmaxf(0, velocity_x);
	}
	if (position_size.y <= 0) {
		velocity_y = fmaxf(0, velocity_y);
	}

	position_size.x += velocity_x*deltaTime;
	position_size.y += velocity_y*deltaTime;

	if (!use_collision) return;

	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			if (map_collision[i][j]) {
				SDL_FRect temp = { j * 24, i * 24, 24, 24 };
				if (checkCollision(&position_size, &temp)) {
					position_size.x -= velocity_x * deltaTime;

					bool runX = false;
					bool runY = false;

					if (checkCollision(&position_size, &temp)) {
						runX = true;
					}
					position_size.x += velocity_x * deltaTime;

					position_size.y -= velocity_y * deltaTime;

					if (checkCollision(&position_size, &temp)) {
						runY = true;
					}

					position_size.x -= velocity_x * deltaTime;

					if (runX) {
						position_size.x += velocity_x * deltaTime;
					}
					if (runY) {
						position_size.y += velocity_y * deltaTime;
					}
				}
			}
		}
	}
}

entity::entity(char texPath[], float movspeed, bool useCollision) : game_object(texPath) {
	velocity_x = 0;
	velocity_y = 0;

	movement_speed = movspeed;

	use_collision = useCollision;
}