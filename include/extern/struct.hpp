#ifndef STRUCT_H
#define STRUCT_H

#include "../main.hpp"

typedef struct t_2dphys_t {
    float direction;
    sf::Vector2f position;
    float max_speed;
    float speed;
    float friction;
    float velocity;
} t_2dphys;

typedef struct t_player_t {
    t_2dphys physics;
} t_player;

typedef struct t_gamedata_t {
    t_player *player;
} t_gamedata;

#endif