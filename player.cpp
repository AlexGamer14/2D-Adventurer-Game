#include "game_object.h"
#include "player.h"

player::player(char texPath[]) : game_object(texPath) {
	walkSpeed = 7;
	runSpeed = 14;

	jumpPower = 20;
}