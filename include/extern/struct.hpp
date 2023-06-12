#ifndef STRUCT_H
#define STRUCT_H

#include "../main.hpp"

typedef struct t_player_t {
    sf::Vector2f position;
    float rotation;
} t_player;

typedef struct t_gamedata_t {
    t_player *player;
} t_gamedata;

#endif