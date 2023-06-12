#include "../include/main.hpp"
#include "../include/src_init.hpp"
#include "../include/rtex.hpp"
#include "../include/rect.hpp"
#include "../include/text.hpp"
#include "../include/circle.hpp"
#include "../include/asset.hpp"
#include "../include/extern/config.hpp"
#include "../include/extern/struct.hpp"
#include "../include/extern/player.hpp"
#include "../include/extern/sprint_bar.hpp"

static void init_render_textures(t_appdata *adata)
{
    ko::create_rtex(adata, MAIN_RTEX, true, sf::Vector2u(adata->win_w, adata->win_h));
    ko::create_rtex(adata, UI_RTEX, true, sf::Vector2u(adata->win_w, adata->win_h));
    ko::set_rtex_clear(adata, MAIN_RTEX, sf::Color(10, 10, 10, 255));
    ko::set_rtex_clear(adata, UI_RTEX, sf::Color::Transparent);
    ko::set_rtex_blendmode(adata, UI_RTEX, sf::BlendAlpha);
}

static void init_ingame_elements(t_appdata *adata)
{
    init_player(adata);
}

static void init_ui(t_appdata *adata)
{
    init_sprint_bar(adata);
}

static void init_gamedata(t_appdata *adata)
{
    t_gamedata *gamedata = adata->gamedata;

    gamedata->player = new t_player();
}

void src_init(t_appdata *adata)
{
    init_gamedata(adata);
    init_render_textures(adata);
    init_ingame_elements(adata);
    init_ui(adata);
}
