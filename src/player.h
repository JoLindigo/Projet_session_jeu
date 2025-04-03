#ifndef __PLAYER_H_
#define __PLAYER_H_
struct Player {
    int x;
    int y;
};

struct Player* initialize_player();
void move_player(struct Player*, int, int);
#endif