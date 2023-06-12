#include "../include/main.hpp"
#include "../include/sprite.hpp"
#include "../include/rtex.hpp"

namespace ko {
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
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        sf::Sprite *sprite = get_sprite(adata, id, rtex_id);

        if (sprite != NULL) {
            printf("%s\n", DUPLICATE_SPRITE);
            return (CODE_FAILURE);
        }

        t_sprite *new_sprite = new t_sprite();

        new_sprite->id = id;
        new_sprite->sprite = new sf::Sprite();
        rtex->render_buffer->sprites.push_back(new_sprite);

        return (CODE_SUCCESS);
    }
}