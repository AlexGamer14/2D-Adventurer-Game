#include "entity.h"

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
}

entity::entity(char texPath[], float movspeed) : game_object(texPath) {
	velocity_x = 0;
	velocity_y = 0;

	movement_speed = movspeed;
}