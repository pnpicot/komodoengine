#include "../include/main.hpp"
#include "../include/render.hpp"

namespace ko {
    static void clear_render_textures(std::vector<t_rtex *> &render_textures)
    {
        for (auto & rtex : render_textures) {
            rtex->texture->clear(rtex->clear_color);
        }
    }

    static void draw_rtex_content(t_rtex *rtex)
    {
        // Rectangles

        std::vector<t_rect *> rectangles = rtex->render_buffer->rects;

        for (auto & rect : rectangles) {
            rtex->texture->draw(*rect->rect);
        }

        // Circles

        std::vector<t_circle *> circles = rtex->render_buffer->circles;

        for (auto & circle : circles) {
            rtex->texture->draw(*circle->circle);
        }

        // Sprites

        std::vector<t_sprite *> sprites = rtex->render_buffer->sprites;

        for (auto & sprite : sprites) {
            rtex->texture->draw(*sprite->sprite);
        }

        // Vertex arrays

        std::vector<t_vertex *> vertex_arrays = rtex->render_buffer->vertex_arrays;

        for (auto & array : vertex_arrays) {
            rtex->texture->draw(*array->array);
        }

        // Texts

        std::vector<t_text *> texts = rtex->render_buffer->texts;

        for (auto & text : texts) {
            rtex->texture->draw(*text->text);
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

            draw_rtex_content(rtex);
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
