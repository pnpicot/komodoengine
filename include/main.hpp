#ifndef MAIN_H
#define MAIN_H

// Header includes

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "errors.hpp"

// Structures definition

typedef struct t_intconf_t {
    std::string key;
    int value;
} t_intconf;

typedef struct t_floatconf_t {
    std::string key;
    float value;
} t_floatconf;

typedef struct t_strconf_t {
    std::string key;
    std::string value;
} t_strconf;

typedef struct t_rtex_t {
    std::string id;
    sf::RenderTexture *texture;
    sf::Sprite *sprite;
    sf::RenderStates *state;
    bool draw_on_window;
    sf::Color clear_color;
} t_rtex;

typedef struct t_appdata_t {
    std::vector<t_intconf *> config_ints;
    std::vector<t_floatconf *> config_floats;
    std::vector<t_strconf *> config_strings;
    int win_w;
    int win_h;
    float global_rate;
    sf::RenderWindow *window;
    sf::Clock *app_clock;
    sf::Clock *runtime_clock;
    std::vector<t_rtex *> render_textures;
} t_appdata;

#endif