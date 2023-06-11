#include "../include/main.hpp"
#include "../include/rtex.hpp"

namespace ko {
    sf::RenderTexture *get_rtex(t_appdata *adata, std::string id)
    {
        std::vector<t_rtex *> render_textures = adata->render_textures;

        for (auto & rtex : render_textures) {
            if (rtex->id == id)
                return (rtex->texture);
        }

        return (NULL);
    }

    static t_rtex *get_rtex_struct(t_appdata *adata, std::string id)
    {
        std::vector<t_rtex *> render_textures = adata->render_textures;

        for (auto & rtex : render_textures) {
            if (rtex->id == id)
                return (rtex);
        }

        return (NULL);
    }

    int create_rtex(t_appdata *adata, std::string id, bool draw_on_window, sf::Vector2u size)
    {
        sf::RenderTexture *rtex = get_rtex(adata, id);

        if (rtex != NULL) {
            printf("%s\n", DUPLICATE_RTEX);
            return (CODE_FAILURE);
        }

        t_rtex *new_rtex = new t_rtex();

        new_rtex->draw_on_window = draw_on_window;
        new_rtex->id = id;
        new_rtex->texture = new sf::RenderTexture();
        new_rtex->sprite = new sf::Sprite();
        new_rtex->state = new sf::RenderStates();
        new_rtex->clear_color = sf::Color::Black;

        bool rtex_code = new_rtex->texture->create(size.x, size.y);

        if (!rtex_code) {
            printf("%s\n", RTEX_FAIL);
            return (CODE_FAILURE);
        }

        adata->render_textures.push_back(new_rtex);

        return (CODE_SUCCESS);
    }

    int rtex_destroy(t_appdata *adata, std::string id)
    {
        t_rtex *rtex = get_rtex_struct(adata, id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        std::vector<t_rtex *> render_textures = adata->render_textures;
        size_t count = render_textures.size();
        size_t iterator = 0;

        for (; iterator < count; iterator++) {
            if (render_textures[iterator]->id == id)
                break;
        }

        adata->render_textures.erase(adata->render_textures.begin() + iterator);

        return (CODE_SUCCESS);
    }

    int rtex_target_window(t_appdata *adata, std::string id, bool draw_on_window)
    {
        t_rtex *rtex = get_rtex_struct(adata, id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        rtex->draw_on_window = draw_on_window;

        return (CODE_SUCCESS);
    }

    int set_rtex_clear(t_appdata *adata, std::string id, sf::Color color)
    {
        t_rtex *rtex = get_rtex_struct(adata, id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        rtex->clear_color = color;

        return (CODE_SUCCESS);
    }

    int set_rtex_shader(t_appdata *adata, std::string id, sf::Shader *shader)
    {
        t_rtex *rtex = get_rtex_struct(adata, id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        rtex->state->shader = shader;

        return (CODE_SUCCESS);
    }

    int set_rtex_blendmode(t_appdata *adata, std::string id, sf::BlendMode mode)
    {
        t_rtex *rtex = get_rtex_struct(adata, id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        rtex->state->blendMode = mode;

        return (CODE_SUCCESS);
    }

    const sf::Shader *get_rtex_shader(t_appdata *adata, std::string id)
    {
        t_rtex *rtex = get_rtex_struct(adata, id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        return (rtex->state->shader);
    }
}