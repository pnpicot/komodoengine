#ifndef EVENT_H
#define EVENT_H

#include "main.hpp"

namespace ko {
    bool get_key(t_appdata *adata, int keycode);
    int register_event(t_appdata *adata, sf::Event event);
}

#endif