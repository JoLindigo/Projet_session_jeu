#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tilemap.h"

static struct Tile* initialize_default_tiles(){
    struct Tile* tiles = calloc(32, sizeof(struct Tile*));
    tiles[0].type = EMPTY;
    tiles[0].color = 0;
    tiles[1].type = WALL;
    tiles[1].color = 1;
    tiles[2].type = FLOOR;
    tiles[2].color = 2;
    return tiles;
}

struct TileMap* initialize_map() {
    struct TileMap* map = malloc(sizeof(struct TileMap));
    map->width = 32;
    map->height = 32;

    //Default tiles
    struct Tile* defaultTiles = initialize_default_tiles();


    map->tiles = calloc(map->width, sizeof(struct Tile**));
    for (int i = 0; i < map->width; i++) {
        map->tiles[i] = calloc(map->width, sizeof(struct Tile*));
        for (int j = 0; j < map->height; j++) {
            struct Tile* tile = malloc(sizeof(struct Tile));
            map->tiles[i][j] = defaultTiles[0];
        }
    }
    
    return map;
}
