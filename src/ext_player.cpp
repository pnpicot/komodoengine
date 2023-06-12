#include "../include/main.hpp"
#include "../include/extern/player.hpp"
#include "../include/extern/config.hpp"
#include "../include/rtex.hpp"
#include "../include/rect.hpp"
#include "../include/event.hpp"

void init_player(t_appdata *adata)
{
    t_player *player = adata->gamedata->player;

    ko::create_rect(adata, "tmp", MAIN_RTEX);
    ko::create_rect(adata, PLAYER, MAIN_RTEX);

    sf::RectangleShape *player_rect = ko::get_rect(adata, PLAYER, MAIN_RTEX);

    player_rect->setPosition(sf::Vector2f(0, 0));
    player_rect->setSize(sf::Vector2f(80.0f, 80.0f));
    player_rect->setOrigin(sf::Vector2f(40.0f, 40.0f));
    player_rect->setFillColor(sf::Color::White);

    sf::RectangleShape *tmp = ko::get_rect(adata, "tmp", MAIN_RTEX);

    tmp->setPosition(sf::Vector2f(-70.0f, 50.0f));
    tmp->setSize(sf::Vector2f(100.0f, 100.0f));
    tmp->setFillColor(sf::Color::Green);
}

void update_player(t_appdata *adata)
{
    t_gamedata *gamedata = adata->gamedata;
    t_player *player = gamedata->player;
    float delta = adata->app_clock->getElapsedTime().asSeconds();
    sf::RectangleShape *player_rect = ko::get_rect(adata, PLAYER, MAIN_RTEX);
    float speed = 1900.0f;

    if (ko::get_key(adata, sf::Keyboard::Z)) {
        player_rect->move(sf::Vector2f(0, -speed * delta));
        player->position.y -= speed * delta;
    }

    if (ko::get_key(adata, sf::Keyboard::S)) {
        player_rect->move(sf::Vector2f(0, speed * delta));
        player->position.y += speed * delta;
    }

    if (ko::get_key(adata, sf::Keyboard::Q)) {
        player_rect->move(sf::Vector2f(-speed * delta, 0));
        player->position.x -= speed * delta;
    }

    if (ko::get_key(adata, sf::Keyboard::D)) {
        player_rect->move(sf::Vector2f(speed * delta, 0));
        player->position.x += speed * delta;
    }
}
