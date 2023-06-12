#include "../include/main.hpp"
#include "../include/sprite.hpp"
#include "../include/rtex.hpp"

namespace ko {
    static t_sprite *get_sprite_struct(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_sprite *> sprites = rtex->render_buffer->sprites;

        for (auto & sprite : sprites) {
            if (sprite->id == id)
                return (sprite);
        }

        return (NULL);
    }

    sf::Sprite *get_sprite(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_sprite *> sprites = rtex->render_buffer->sprites;

        for (auto & sprite : sprites) {
            if (sprite->id == id)
                return (sprite->sprite);
        }

        return (NULL);
    }

    int create_sprite(t_appdata *adata, std::string id, std::string rtex_id)
    {
        sf::Sprite *sprite = get_sprite(adata, id, rtex_id);

        if (sprite != NULL) {
            printf("%s\n", DUPLICATE_SPRITE);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);
        t_sprite *new_sprite = new t_sprite();

        new_sprite->id = id;
        new_sprite->layer = 0;
        new_sprite->sprite = new sf::Sprite();
        rtex->render_buffer->sprites.push_back(new_sprite);

        return (CODE_SUCCESS);
    }

    int set_sprite_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer)
    {
        t_sprite *sprite = get_sprite_struct(adata, id, rtex_id);

        if (sprite == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        sprite->layer = layer;

        if (layer < rtex->min_layer) rtex->min_layer = layer;
        if (layer > rtex->max_layer) rtex->max_layer = layer;

        return (CODE_SUCCESS);
    }
}