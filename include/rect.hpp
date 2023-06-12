#ifndef RECT_H
#define RECT_H

#include "main.hpp"

namespace ko {
    sf::RectangleShape *get_rect(t_appdata *adata, std::string id, std::string rtex_id);
    int create_rect(t_appdata *adata, std::string id, std::string rtex_id);
    int set_rect_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer);
}

#endif