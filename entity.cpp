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

	for (int i = 0; i < collision_rects.size(); i++) {
		if (checkCollision(&position_size, &collision_rects[i])) {
			position_size.x -= velocity_x * deltaTime;

			bool runX = false;
			bool runY = false;

			if (checkCollision(&position_size, &collision_rects[i])) {
				runX = true;
			}
			position_size.x += velocity_x * deltaTime;

			position_size.y -= velocity_y * deltaTime;

			if (checkCollision(&position_size, &collision_rects[i])) {
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

entity::entity(char texPath[], float movspeed, bool useCollision) : game_object(texPath) {
	velocity_x = 0;
	velocity_y = 0;

	movement_speed = movspeed;

	use_collision = useCollision;
}