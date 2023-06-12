#include "../include/main.hpp"
#include "../include/circle.hpp"
#include "../include/rtex.hpp"

namespace ko {
    static t_circle *get_circle_struct(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_circle *> circles = rtex->render_buffer->circles;

        for (auto & circle : circles) {
            if (circle->id == id)
                return (circle);
        }

        return (NULL);
    }

    sf::CircleShape *get_circle(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_circle *> circles = rtex->render_buffer->circles;

        for (auto & circle : circles) {
            if (circle->id == id)
                return (circle->circle);
        }

        return (NULL);
    }

    int create_circle(t_appdata *adata, std::string id, std::string rtex_id)
    {
        sf::CircleShape *circle = get_circle(adata, id, rtex_id);

        if (circle != NULL) {
            printf("%s\n", DUPLICATE_CIRCLE);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);
        t_circle *new_circle = new t_circle();

        new_circle->id = id;
        new_circle->layer = 0;
        new_circle->circle = new sf::CircleShape();
        rtex->render_buffer->circles.push_back(new_circle);

        return (CODE_SUCCESS);
    }

    int set_circle_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer)
    {
        t_circle *circle = get_circle_struct(adata, id, rtex_id);

        if (circle == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        circle->layer = layer;

        if (layer < rtex->min_layer) rtex->min_layer = layer;
        if (layer > rtex->max_layer) rtex->max_layer = layer;

        return (CODE_SUCCESS);
    }
}