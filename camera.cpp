#include "camera.h"
#include "const.h"

Camera camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

void updateCamera(float playerX, float playerY) {
    // Center camera on player
    camera.x = playerX - (camera.w / 2);
    camera.y = playerY - (camera.h / 2);

    // Clamp the camera to stay within map bounds
    if (camera.x < 0) camera.x = 0;
    if (camera.y < 0) camera.y = 0;
}
