#define CUTE_TILED_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS
#include <SDL3_image/SDL_image.h>
#include "map.h"


cute_tiled_map_t* map;
cute_tiled_layer_t* layers;

Texture* texture;

std::vector<std::vector<bool>> map_collision(120, std::vector<bool>(120));
std::vector<SDL_FRect> collision_rects;

void render_map(float offset_x, float offset_y) {
    cute_tiled_layer_t* temp_layer = layers;

    while (temp_layer) {
        if (!temp_layer->data) {
            temp_layer = temp_layer->next;
            continue;
        }

        for (int i = 0; i < map->height; i++) {
            for (int j = 0; j < map->width; j++) {
                int tile_id = temp_layer->data[i * map->width + j];
                if (tile_id == 0) continue;

                Texture* temp_texture = texture;
                Texture* texture_to_use = NULL;

                while (temp_texture) {
                    if (tile_id >= temp_texture->firstgid &&
                        tile_id <= temp_texture->firstgid + temp_texture->tilecount - 1) {
                        texture_to_use = temp_texture;
                        break;
                    }
                    temp_texture = temp_texture->next;
                }

                if (!texture_to_use) {
                    continue;
                }
                
                int tileset_columns = 16 / map->tilewidth;

                SDL_FRect src = {
                  int(tile_id - texture_to_use->firstgid) % 18 * 16,
                  int((tile_id - texture_to_use->firstgid) / 18) * 16,
                  map->tilewidth,
                  map->tileheight
                };

                SDL_FRect dst = {
                  j * 24+ offset_x,
                  i * 24+offset_y,
                  24,
                  24
                };

                SDL_RenderTexture(renderer, texture_to_use->texture, &src, &dst);
            }
        }

        temp_layer = temp_layer->next;
    }
}

void init_collision() {
    // FENCE NEXT TO HOUSE COLLISION
    // Left fence wall collision

	collision_rects.push_back({ 48, 48, 24*6, 24 });

    /*map_collision[4][4] = true;
    map_collision[5][4] = true;
    map_collision[6][4] = true;
    map_collision[7][4] = true;
    map_collision[8][4] = true;
    map_collision[9][4] = true;
    map_collision[10][4] = true;
    map_collision[11][4] = true;
    map_collision[12][4] = true;
    map_collision[13][4] = true;
    map_collision[14][4] = true;
    map_collision[15][4] = true;
    map_collision[16][4] = true;
    map_collision[17][4] = true;
    map_collision[18][4] = true;

    map_collision[4][5] = true;
    map_collision[5][5] = true;
    map_collision[6][5] = true;
    map_collision[7][5] = true;
    map_collision[8][5] = true;
    map_collision[9][5] = true;
    map_collision[10][5] = true;
    map_collision[11][5] = true;
    map_collision[12][5] = true;
    map_collision[13][5] = true;
    map_collision[14][5] = true;
    map_collision[15][5] = true;
    map_collision[16][5] = true;
    map_collision[17][5] = true;
    map_collision[18][5] = true;*/

	//Bottom fence wall collision
    map_collision[18][6] = true;
    map_collision[18][7] = true;
    map_collision[18][8] = true;
	map_collision[18][9] = true;
	map_collision[18][10] = true;

    map_collision[17][6] = true;
    map_collision[17][7] = true;
    map_collision[17][8] = true;
	map_collision[17][9] = true;
	map_collision[17][10] = true;


    map_collision[18][15] = true;
    map_collision[18][16] = true;
    map_collision[18][17] = true;
    map_collision[18][18] = true;
    map_collision[18][19] = true;

    map_collision[17][15] = true;
    map_collision[17][16] = true;
    map_collision[17][17] = true;
    map_collision[17][18] = true;
    map_collision[17][19] = true;

	// Right fence wall collision

    map_collision[4][20] = true;
    map_collision[5][20] = true;
    map_collision[6][20] = true;
    map_collision[7][20] = true;
    map_collision[8][20] = true;
    map_collision[9][20] = true;
    map_collision[10][20] = true;
    map_collision[11][20] = true;
    map_collision[12][20] = true;
    map_collision[13][20] = true;
    map_collision[14][20] = true;
    map_collision[15][20] = true;
    map_collision[16][20] = true;
    map_collision[17][20] = true;
    map_collision[18][20] = true;

    map_collision[4][21] = true;
    map_collision[5][21] = true;
    map_collision[6][21] = true;
    map_collision[7][21] = true;
    map_collision[8][21] = true;
    map_collision[9][21] = true;
    map_collision[10][21] = true;
    map_collision[11][21] = true;
    map_collision[12][21] = true;
    map_collision[13][21] = true;
    map_collision[14][21] = true;
    map_collision[15][21] = true;
    map_collision[16][21] = true;
    map_collision[17][21] = true;
    map_collision[18][21] = true;

	// Top fence wall collision
    map_collision[4][6] = true;
    map_collision[4][7] = true;
    map_collision[4][8] = true;
    map_collision[4][9] = true;
    map_collision[4][10] = true;
    map_collision[4][11] = true;
    map_collision[4][12] = true;
    map_collision[4][13] = true;
    map_collision[4][14] = true;
    map_collision[4][15] = true;
    map_collision[4][16] = true;
    map_collision[4][17] = true;
    map_collision[4][18] = true;
    map_collision[4][19] = true;

    // House collision

    map_collision[8][5] = true;
    map_collision[8][6] = true;
    map_collision[8][7] = true;
    map_collision[8][8] = true;
    map_collision[8][9] = true;
    map_collision[8][10] = true;
    map_collision[8][11] = true;
    map_collision[8][12] = true;
    map_collision[8][13] = true;
    map_collision[8][14] = true;

    map_collision[9][5] = true;
    map_collision[9][6] = true;
    map_collision[9][7] = true;
    map_collision[9][8] = true;
    map_collision[9][9] = true;
    map_collision[9][10] = true;
    map_collision[9][11] = true;
    map_collision[9][12] = true;
    map_collision[9][13] = true;
    map_collision[9][14] = true;
                  
    map_collision[10][5] = true;
    map_collision[10][6] = true;
    map_collision[10][7] = true;
    map_collision[10][8] = true;
    map_collision[10][9] = true;
    map_collision[10][10] = true;
    map_collision[10][11] = true;
    map_collision[10][12] = true;
    map_collision[10][13] = true;
    map_collision[10][14] = true;

    map_collision[11][5] = true;
    map_collision[11][6] = true;
    map_collision[11][7] = true;
    map_collision[11][8] = true;
    map_collision[11][9] = true;
    map_collision[11][10] = true;
    map_collision[11][11] = true;
    map_collision[11][12] = true;
    map_collision[11][13] = true;
    map_collision[11][14] = true;

    map_collision[12][5] = true;
    map_collision[12][6] = true;
    map_collision[12][7] = true;
    map_collision[12][8] = true;
    map_collision[12][9] = true;
    map_collision[12][10] = true;
    map_collision[12][14] = true;
}                 


int load_map() {
	char map_file[] = "./Resources/jsonmap.json";

	map = cute_tiled_load_map_from_file(map_file, NULL);
	if (!map) {
		fprintf(stderr, "Map failed to load\n");
		return FAIL;
	}

	cute_tiled_tileset_t* current_tileset = map->tilesets;
	layers = map->layers;

	texture = new Texture();
	Texture* current_texture = texture;

	std::string basePath = "./Resources/";

	while (current_tileset) {
		
		//printf(basePath.append(current_tileset->image.ptr).append("\n").c_str());
		current_texture->texture = IMG_LoadTexture(renderer, (basePath + std::string(current_tileset->image.ptr)).c_str());
        SDL_SetTextureScaleMode(current_texture->texture, SDL_SCALEMODE_NEAREST);
		current_texture->firstgid = current_tileset->firstgid;
        current_texture->tilecount = current_tileset->tilecount;
		//std::cout << std::to_string(current_texture->texture->w);
		if (!current_texture->texture) {
			fprintf(stderr, "Failed to load tileset%s\n", SDL_GetError());
			return FAIL;
		}

		std::cout << std::string("Loaded spritesheet with path of: ").append((basePath + std::string(current_tileset->image.ptr)).append("\n"));

		
		current_texture->next = new Texture();

		current_tileset = current_tileset->next;
		current_texture=current_texture->next;
	}

	init_collision();

	return PASS;
}

void cleanup() {
	cute_tiled_free_map(map);
	cute_tiled_free_layers(layers, NULL);
}