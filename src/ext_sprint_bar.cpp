#include "../include/main.hpp"
#include "../include/extern/player.hpp"
#include "../include/extern/config.hpp"
#include "../include/rtex.hpp"
#include "../include/rect.hpp"
#include "../include/asset.hpp"

void init_sprint_bar(t_appdata *adata)
{
    // MAIN BACKGROUND BAR

    ko::create_rect(adata, SPRINT_BAR, UI_RTEX);

    sf::RectangleShape *bar_background = ko::get_rect(adata, SPRINT_BAR, UI_RTEX);
    sf::Vector2f background_size;

    background_size.x = adata->win_w * 0.6f;
    background_size.y = ko::get_float(adata, "BAR_HEIGHT")->value;

    bar_background->setSize(background_size);
    bar_background->setFillColor(sf::Color(45, 48, 71));
    bar_background->setOutlineThickness(3.0f);
    bar_background->setOutlineColor(sf::Color(80, 85, 124));

    sf::Vector2f background_position;

    background_position.x = (adata->win_w / 2) - (background_size.x / 2);
    background_position.y = adata->win_h - background_size.y - 23.0f;

    bar_background->setPosition(background_position);

    // FILLER BAR

    ko::create_rect(adata, SPRINTE_BAR_SUB, UI_RTEX);

    sf::RectangleShape *bar_filler = ko::get_rect(adata, SPRINTE_BAR_SUB, UI_RTEX);
    sf::Vector2f filler_size;

    filler_size.x = (background_size.x * 0.6f) - 2.0f;
    filler_size.y = background_size.y - 2.0f;

    bar_filler->setSize(filler_size);
    bar_filler->setFillColor(sf::Color(145, 155, 230));
    bar_filler->setPosition(sf::Vector2f(background_position.x + 1.0f, background_position.y + 1.0f));
}
