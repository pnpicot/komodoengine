#include "../include/main.hpp"
#include "../include/src_update.hpp"
#include "../include/rtex.hpp"
#include "../include/rect.hpp"
#include "../include/text.hpp"
#include "../include/extern/config.hpp"
#include "../include/extern/player.hpp"

void src_update(t_appdata *adata)
{
    update_player(adata);

    t_gamedata *gamedata = adata->gamedata;
    t_player *player = gamedata->player;
    sf::RenderTexture *main_rtex = ko::get_rtex(adata, MAIN_RTEX);
    sf::View main_view = main_rtex->getView();

    main_view.setCenter(player->physics.position);
    main_rtex->setView(main_view);
}
