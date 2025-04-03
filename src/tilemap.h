#ifndef _TILEMAP__H_
#define _TILEMAP__H_
enum TileType { EMPTY, WALL, FLOOR };

struct Tile {
    enum TileType type;
    int color;
};

struct TileMap {
    struct Tile** tiles;
    int width;
    int height;
};

static struct Tile* initialize_default_tiles();
struct TileMap* initialize_map();

#endif