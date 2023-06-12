#include "../include/main.hpp"
#include "../include/event.hpp"

namespace ko {
    bool get_key(t_appdata *adata, int keycode)
    {
        return (adata->keys[keycode]);
    }

    int register_event(t_appdata *adata, sf::Event event)
    {
        if (event.type == sf::Event::Closed) {
            adata->window->close();
            return (CODE_SUCCESS);
        }

        if (event.type == sf::Event::KeyPressed && event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {
            adata->keys[event.key.code] = true;
            return (CODE_SUCCESS);
        }

        if (event.type == sf::Event::KeyReleased && event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) {
            adata->keys[event.key.code] = false;
            return (CODE_SUCCESS);
        }

        return (CODE_SUCCESS);
    }
}