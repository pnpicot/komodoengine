#include "../include/main.hpp"
#include "../include/text.hpp"
#include "../include/rtex.hpp"

namespace ko {
    static t_text *get_text_struct(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_text *> texts = rtex->render_buffer->texts;

        for (auto & text : texts) {
            if (text->id == id)
                return (text);
        }

        return (NULL);
    }

    sf::Text *get_text(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_text *> texts = rtex->render_buffer->texts;

        for (auto & text : texts) {
            if (text->id == id)
                return (text->text);
        }

        return (NULL);
    }

    int create_text(t_appdata *adata, std::string id, std::string rtex_id)
    {
        sf::Text *text = get_text(adata, id, rtex_id);

        if (text != NULL) {
            printf("%s\n", DUPLICATE_TEXT);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);
        t_text *new_text = new t_text();

        new_text->id = id;
        new_text->layer = 0;
        new_text->text = new sf::Text();
        rtex->render_buffer->texts.push_back(new_text);

        return (CODE_SUCCESS);
    }

    int set_text_layer(t_appdata *adata, std::string id, std::string rtex_id, int layer)
    {
        t_text *text = get_text_struct(adata, id, rtex_id);

        if (text == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        text->layer = layer;

        if (layer < rtex->min_layer) rtex->min_layer = layer;
        if (layer > rtex->max_layer) rtex->max_layer = layer;

        return (CODE_SUCCESS);
    }
}