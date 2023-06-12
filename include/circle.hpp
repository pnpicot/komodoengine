#ifndef CIRCLE_H
#define CIRCLE_H

#include "main.hpp"

namespace ko {
    int create_circle(t_appdata *adata, std::string id, std::string rtex_id);
    sf::CircleShape *get_circle(t_appdata *adata, std::string id, std::string rtex_id);
    int set_circle_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer);
}

#endif