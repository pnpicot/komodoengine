#ifndef RTEX_H
#define RTEX_H

#include "main.hpp"

namespace ko {
    sf::RenderTexture *get_rtex(t_appdata *adata, std::string id);
    int create_rtex(t_appdata *adata, std::string id, bool draw_on_window, sf::Vector2u size);
    int rtex_destroy(t_appdata *adata, std::string id);
    int rtex_target_window(t_appdata *adata, std::string id, bool draw_on_window);
    int rtex_set_clear(t_appdata *adata, std::string id, sf::Color color);
}

#endif