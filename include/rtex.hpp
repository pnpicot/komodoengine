#ifndef RTEX_H
#define RTEX_H

#include "main.hpp"

namespace ko {
    sf::RenderTexture *get_rtex(t_appdata *adata, std::string id);
    int create_rtex(t_appdata *adata, std::string id, bool draw_on_window, sf::Vector2u size);
    int rtex_destroy(t_appdata *adata, std::string id);
    int rtex_target_window(t_appdata *adata, std::string id, bool draw_on_window);
    int set_rtex_clear(t_appdata *adata, std::string id, sf::Color color);
    int set_rtex_shader(t_appdata *adata, std::string id, sf::Shader *shader);
    int set_rtex_blendmode(t_appdata *adata, std::string id, sf::BlendMode mode);
    const sf::Shader *get_rtex_shader(t_appdata *adata, std::string id);
    t_rtex *get_rtex_struct(t_appdata *adata, std::string id);
}

#endif