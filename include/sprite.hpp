#ifndef SPRITE_H
#define SPRITE_H

#include "main.hpp"

namespace ko {
    int create_sprite(t_appdata *adata, std::string id, std::string rtex_id);
    sf::Sprite *get_sprite(t_appdata *adata, std::string id, std::string rtex_id);
    int set_sprite_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer);
}

#endif