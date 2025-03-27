#define CUTE_TILED_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS
#include <SDL3_image/SDL_image.h>
#include "map.h"


cute_tiled_map_t* map;
cute_tiled_layer_t* layers;

Texture* texture;

//std::vector<std::vector<int>> map_collision(;

void render_map() {
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
                  j * 24,
                  i * 24,
                  24,
                  24
                };

                SDL_RenderTexture(renderer, texture_to_use->texture, &src, &dst);
            }
        }

        temp_layer = temp_layer->next;
    }
}

int load_map() {
	char map_file[] = "C:\\Users\\alexa\\source\\repos\\Pacman\\Resources\\jsonmap.json";

	map = cute_tiled_load_map_from_file(map_file, NULL);
	if (!map) {
		fprintf(stderr, "Map failed to load\n");
		return FAIL;
	}

	cute_tiled_tileset_t* current_tileset = map->tilesets;
	layers = map->layers;

	texture = new Texture();
	Texture* current_texture = texture;

	std::string basePath = "C:\\Users\\alexa\\source\\repos\\Pacman\\Resources\\";

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

	return PASS;
}

void cleanup() {
	cute_tiled_free_map(map);
	cute_tiled_free_layers(layers, NULL);
}