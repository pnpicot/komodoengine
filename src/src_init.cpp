#include "../include/main.hpp"
#include "../include/src_init.hpp"
#include "../include/rtex.hpp"
#include "../include/rect.hpp"
#include "../include/text.hpp"
#include "../include/circle.hpp"
#include "../include/asset.hpp"

void src_init(t_appdata *adata)
{
    const std::string RTEX = "id_rtex";
    const std::string TEXT = "id_text";
    const std::string RECT = "id_rect";

    ko::create_rtex(adata, RTEX, true, sf::Vector2u(adata->win_w, adata->win_h));
    ko::create_text(adata, TEXT, RTEX);

    sf::Text *text = ko::get_text(adata, TEXT, RTEX);

    text->setCharacterSize(24);
    text->setFillColor(sf::Color::White);
    text->setFont(*ko::get_font(adata, "roboto"));
    text->setString(L"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam nec molestie ligula. Fusce eget eros et metus \nelementum lobortis. Nulla commodo congue turpis eget facilisis. Curabitur a maximus neque. Pellentesque et \nnisl vel orci semper elementum. Curabitur accumsan a lectus vel semper. Praesent vehicula urna vel nisi \nsemper egestas. Morbi volutpat ipsum ac nisi rhoncus, convallis suscipit ante tempus.");

    sf::FloatRect text_rect = text->getGlobalBounds();
    sf::Vector2f position;

    position.x = (adata->win_w / 2) - (text_rect.width / 2);
    position.y = (adata->win_h / 2) - (text_rect.height / 2) - 24.0f;

    text->setPosition(position);

    ko::create_rect(adata, RECT, RTEX);

    sf::RectangleShape *rect = ko::get_rect(adata, RECT, RTEX);
    text_rect = text->getGlobalBounds();

    rect->setSize(sf::Vector2f(text_rect.width + 40.0f, text_rect.height + 40.0f));
    rect->setPosition(sf::Vector2f(text_rect.left - 20.0f, text_rect.top - 20.0f));
    rect->setFillColor(sf::Color(255, 255, 255, 20));

    std::string CIRCLE = "id_circle";

    ko::create_circle(adata, CIRCLE, RTEX);

    sf::CircleShape *circle = ko::get_circle(adata, CIRCLE, RTEX);

    circle->setPosition(sf::Vector2f(text_rect.left - 30.0f, text_rect.top + 10.0f));
    circle->setRadius(10.0f);
    circle->setFillColor(sf::Color(220, 30, 50));
}
