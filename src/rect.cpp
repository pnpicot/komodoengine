#include "../include/main.hpp"
#include "../include/rect.hpp"
#include "../include/rtex.hpp"

namespace ko {
    sf::RectangleShape *get_rect(t_appdata *adata, std::string id, std::string rtex_id)
    {
        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (NULL);
        }

        std::vector<t_rect *> rectangles = rtex->render_buffer->rects;

        for (auto & rect : rectangles) {
            if (rect->id == id)
                return (rect->rect);
        }

        return (NULL);
    }

    int create_rect(t_appdata *adata, std::string id, std::string rtex_id)
    {
        sf::RectangleShape *rect = get_rect(adata, id, rtex_id);

        if (rect != NULL) {
            printf("%s\n", DUPLICATE_RECT);
            return (CODE_FAILURE);
        }

        t_rtex *rtex = get_rtex_struct(adata, rtex_id);

        if (rtex == NULL) {
            printf("%s\n", UNKNOWN_ID);
            return (CODE_FAILURE);
        }

        t_rect *new_rect = new t_rect();

        new_rect->id = id;
        new_rect->rect = new sf::RectangleShape();
        rtex->render_buffer->rects.push_back(new_rect);

        return (CODE_SUCCESS);
    }
}
