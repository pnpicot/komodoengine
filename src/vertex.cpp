#include "../include/main.hpp"
#include "../include/vertex.hpp"
#include "../include/rtex.hpp"

namespace ko {
    static t_vertex *get_vertex_array_struct(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_vertex *> vertex_arrays = rtex->render_buffer->vertex_arrays;

        for (auto & array : vertex_arrays) {
            if (array->id == id)
                return (array);
        }

        return (NULL);
    }

    sf::VertexArray *get_vertex_array(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_vertex *> vertex_arrays = rtex->render_buffer->vertex_arrays;

        for (auto & array : vertex_arrays) {
            if (array->id == id)
                return (array->array);
        }

        return (NULL);
    }

    int create_vertex_array(t_appdata *adata, std::string id, std::string rtex_id)
    {
        sf::VertexArray *vertex_array = get_vertex_array(adata, id, rtex_id);

        if (vertex_array != NULL) {
            printf("%s\n", DUPLICATE_VERTEX);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);
        t_vertex *new_vertex_array = new t_vertex();

        new_vertex_array->id = id;
        new_vertex_array->layer = 0;
        new_vertex_array->array = new sf::VertexArray();
        rtex->render_buffer->vertex_arrays.push_back(new_vertex_array);

        return (CODE_SUCCESS);
    }

    int set_vertex_array_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer)
    {
        t_vertex *vertex_array = get_vertex_array_struct(adata, id, rtex_id);

        if (vertex_array == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        vertex_array->layer = layer;

        if (layer < rtex->min_layer) rtex->min_layer = layer;
        if (layer > rtex->max_layer) rtex->max_layer = layer;

        return (CODE_SUCCESS);
    }
}