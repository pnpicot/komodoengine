#ifndef TEXT_H
#define TEXT_H

#include "main.hpp"

namespace ko {
    sf::Text *get_text(t_appdata *adata, std::string id, std::string rtex_id);
    int create_text(t_appdata *adata, std::string id, std::string rtex_id);
    int set_text_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer);
}

#endif