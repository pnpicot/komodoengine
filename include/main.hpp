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
#include "extern/struct.hpp"

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

typedef struct t_rect_t {
    std::string id;
    sf::RectangleShape *rect;
    int layer;
} t_rect;

typedef struct t_text_t {
    std::string id;
    sf::Text *text;
    int layer;
} t_text;

typedef struct t_circle_t {
    std::string id;
    sf::CircleShape *circle;
    int layer;
} t_circle;

typedef struct t_sprite_t {
    std::string id;
    sf::Sprite *sprite;
    int layer;
} t_sprite;

typedef struct t_vertex_t {
    std::string id;
    sf::VertexArray *array;
    int layer;
} t_vertex;

typedef struct t_render_t {
    std::vector<t_rect *> rects;
    std::vector<t_circle *> circles;
    std::vector<t_sprite *> sprites;
    std::vector<t_text *> texts;
    std::vector<t_vertex *> vertex_arrays;
} t_render;

typedef struct t_rtex_t {
    std::string id;
    sf::RenderTexture *texture;
    sf::Sprite *sprite;
    sf::RenderStates *state;
    bool draw_on_window;
    sf::Color clear_color;
    t_render *render_buffer;
    int min_layer;
    int max_layer;
} t_rtex;

typedef struct t_shader_t {
    std::string id;
    sf::Shader *shader;
} t_shader;

typedef struct t_texture_t {
    std::string id;
    sf::Texture *texture;
} t_texture;

typedef struct t_font_t {
    std::string id;
    sf::Font *font;
} t_font;

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
    std::vector<t_shader *> shaders;
    std::vector<t_texture *> textures;
    std::vector<t_font *> fonts;
    bool keys[25];
    t_gamedata *gamedata;
} t_appdata;

// Macros

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define RANGE(v, min, max) (v < min ? min : (v > max ? max : v))
#define LERP(a, b, f) (a * (1.0 - f) + (b * f))
#define F_ABS(a) (a < 0 ? -1 * a : a)
#define SHORTEST_ANGLE(a, b) ((((b - a) % 360) + 540) % 360) - 180

#endif