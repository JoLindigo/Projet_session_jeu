#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

struct Player* initialize_player(){
    struct Player* player = malloc(sizeof(struct Player));
    player->x = 0;
    player->y = 0;
    return player;
}

void move_player(struct Player* player, int x, int y) {
    player->x += x;
    player->y += y;
}
