#ifndef VERTEX_H
#define VERTEX_H

#include "main.hpp"

namespace ko {
    sf::VertexArray *get_vertex_array(t_appdata *adata, std::string id, std::string rtex_id);
    int create_vertex_array(t_appdata *adata, std::string id, std::string rtex_id);
}

#endif