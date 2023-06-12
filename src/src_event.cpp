#include "../include/main.hpp"
#include "../include/src_event.hpp"
#include "../include/rtex.hpp"
#include "../include/rect.hpp"

void src_register_event(t_appdata *adata, sf::Event event)
{
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        adata->window->close();
}
