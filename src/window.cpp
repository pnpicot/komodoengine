#include "../include/main.hpp"
#include "../include/window.hpp"
#include "../include/asset.hpp"
#include "../include/rtex.hpp"
#include "../include/update.hpp"
#include "../include/render.hpp"
#include "../include/defaults.hpp"
#include "../include/rect.hpp"
#include "../include/src_init.hpp"
#include "../include/src_update.hpp"
#include "../include/src_render.hpp"
#include "../include/event.hpp"
#include "../include/src_event.hpp"

namespace ko {
    static int window_loop(t_appdata *adata)
    {
        sf::RenderWindow *window = adata->window;

        // Creates a default render texture in case none were created before this point

        if (adata->render_textures.size() < 1)
            create_rtex(adata, DEFAULT_RTEX, true, sf::Vector2u(adata->win_w, adata->win_h));

        while (window->isOpen()) {
            sf::Event event;

            while (window->pollEvent(event)) {
                int event_code = register_event(adata, event);

                if (event_code != CODE_SUCCESS)
                    return (event_code);

                src_register_event(adata, event);
            }

            float delta = adata->app_clock->getElapsedTime().asSeconds();

            if (delta > adata->global_rate) {
                int update_code = update(adata);

                if (update_code != CODE_SUCCESS)
                    return (update_code);

                src_update(adata);

                int render_code = render(adata);

                if (render_code != CODE_SUCCESS)
                    return (render_code);

                src_render(adata);

                adata->app_clock->restart();
            }
        }

        return (CODE_SUCCESS);
    }

    int init_window(t_appdata *adata)
    {
        sf::ContextSettings context_settings;

        if (get_int(adata, "USE_AA")->value == 1)
            context_settings.antialiasingLevel = get_int(adata, "AA_LEVEL")->value;

        sf::RenderWindow *window = new sf::RenderWindow();

        window->create(sf::VideoMode(adata->win_w, adata->win_h), "Komodo Engine", sf::Style::Default, context_settings);
        adata->window = window;

        src_init(adata);

        int loop_code = window_loop(adata);

        if (loop_code != CODE_SUCCESS)
            return (loop_code);

        return (CODE_SUCCESS);
    }
}