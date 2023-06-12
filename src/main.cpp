#include "../include/main.hpp"
#include "../include/asset.hpp"
#include "../include/window.hpp"

static void init_appdata(t_appdata *adata)
{
    adata->win_w = ko::get_int(adata, "WIN_W")->value;
    adata->win_h = ko::get_int(adata, "WIN_H")->value;
    adata->global_rate = ko::get_float(adata, "GLOBAL_RATE")->value;
    adata->app_clock = new sf::Clock();
    adata->runtime_clock = new sf::Clock();
}

int main(int argc, char **argv)
{
    t_appdata *adata = new t_appdata();
    int assets_code = ko::load_assets(adata);

    if (assets_code != CODE_SUCCESS) {
        printf("[*] Exit code : %d\n", assets_code);
        return (assets_code);
    }

    init_appdata(adata);

    int window_code = ko::init_window(adata);

    if (window_code != CODE_SUCCESS) {
        printf("[*] Exit code : %d\n", window_code);
        return (window_code);
    }

    printf("[*] Exit code : %d\n", CODE_SUCCESS);

    return (CODE_SUCCESS);
}
