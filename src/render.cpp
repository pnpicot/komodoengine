#include "../include/main.hpp"
#include "../include/render.hpp"

namespace ko {
    static void clear_render_textures(std::vector<t_rtex *> &render_textures)
    {
        for (auto & rtex : render_textures) {
            rtex->texture->clear(rtex->clear_color);
        }
    }

    int render(t_appdata *adata)
    {
        sf::RenderWindow *window = adata->window;
        std::vector<t_rtex *> render_textures = adata->render_textures;
        size_t count = render_textures.size();

        window->clear();
        clear_render_textures(render_textures);

        for (size_t i = 0; i < count; i++) {
            t_rtex *rtex = render_textures[i];

            // TODO: draw stuff on render texture

            rtex->texture->display();

            sf::Texture texture = rtex->texture->getTexture();

            rtex->sprite->setTexture(texture);

            if (!rtex->draw_on_window && i < count - 1) {
                render_textures[i + 1]->texture->draw(*rtex->sprite, *rtex->state);
                continue;
            }

            window->draw(*rtex->sprite, *rtex->state);
        }

        window->display();

        return (CODE_SUCCESS);
    }
}
