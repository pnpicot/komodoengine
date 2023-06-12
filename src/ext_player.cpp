#include "../include/main.hpp"
#include "../include/extern/player.hpp"
#include "../include/extern/config.hpp"
#include "../include/rtex.hpp"
#include "../include/rect.hpp"
#include "../include/event.hpp"

void init_player(t_appdata *adata)
{
    t_player *player = adata->gamedata->player;

    ko::create_rect(adata, PLAYER, MAIN_RTEX);
    ko::set_rect_layer(adata, PLAYER, MAIN_RTEX, 1);
    ko::create_rect(adata, "tmp", MAIN_RTEX);

    sf::RectangleShape *player_rect = ko::get_rect(adata, PLAYER, MAIN_RTEX);

    player_rect->setPosition(sf::Vector2f(0, 0));
    player_rect->setSize(sf::Vector2f(80.0f, 80.0f));
    player_rect->setOrigin(sf::Vector2f(40.0f, 40.0f));
    player_rect->setFillColor(sf::Color::White);

    sf::RectangleShape *tmp = ko::get_rect(adata, "tmp", MAIN_RTEX);

    tmp->setPosition(sf::Vector2f(-70.0f, 50.0f));
    tmp->setSize(sf::Vector2f(100.0f, 100.0f));
    tmp->setFillColor(sf::Color::Green);

    player->physics.position = sf::Vector2f(0, 0);
    player->physics.direction = 0;
    player->physics.friction = PLAYER_FRICTION_DEFAULT;
    player->physics.max_speed = PLAYER_MAXSPEED_DEFAULT;
    player->physics.velocity = PLAYER_VELOCITY_DEFAULT;
}

static void update_player_friction(t_player *player, float delta)
{
    if (player->physics.speed > 0) {
        player->physics.speed = MAX(player->physics.speed - player->physics.friction * delta, 0);
    }
}

static float shortest_angle(float from, float to)
{
    float max_angle = M_PI * 2;
    float diff = fmod(to - from, max_angle);

    return (fmod(2 * diff, max_angle) - diff);
}

static float lerp_angle(float from, float to, float weight)
{
    return (from + shortest_angle(from, to) * weight);
}

void update_player(t_appdata *adata)
{
    t_gamedata *gamedata = adata->gamedata;
    t_player *player = gamedata->player;
    float delta = adata->app_clock->getElapsedTime().asSeconds();
    sf::RectangleShape *player_rect = ko::get_rect(adata, PLAYER, MAIN_RTEX);
    sf::Vector2f normalized(0, 0);
    bool Z_key = ko::get_key(adata, sf::Keyboard::Z);
    bool S_key = ko::get_key(adata, sf::Keyboard::S);
    bool Q_key = ko::get_key(adata, sf::Keyboard::Q);
    bool D_key = ko::get_key(adata, sf::Keyboard::D);

    update_player_friction(player, delta);

    if (Z_key) normalized.y--;
    if (S_key) normalized.y++;
    if (Q_key) normalized.x--;
    if (D_key) normalized.x++;

    if ((Z_key + S_key == 1) || (Q_key + D_key == 1)) {
        player->physics.speed = MIN(
            player->physics.speed + player->physics.velocity * delta,
            player->physics.max_speed
        );
    }

    float target_rotation = atan2f(normalized.y, normalized.x) * RAD2DEG;
    float turn = delta * PLAYER_TURNSPEED_DEFAULT;
    float rotation_interpolation = lerp_angle(player->physics.direction * DEG2RAD, target_rotation * DEG2RAD, turn) * RAD2DEG;

    player->physics.position.x += player->physics.speed * cos(rotation_interpolation * DEG2RAD);
    player->physics.position.y += player->physics.speed * sin(rotation_interpolation * DEG2RAD);

    bool turning = Z_key || S_key || Q_key || D_key;

    if (turning)
        player->physics.direction = rotation_interpolation;

    player_rect->setPosition(player->physics.position);
    player_rect->setRotation(player->physics.direction + 90.0f);
}
