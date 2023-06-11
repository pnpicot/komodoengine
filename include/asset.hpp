#ifndef ASSET_H
#define ASSET_H

#include "main.hpp"

namespace ko {
    t_intconf *get_int(t_appdata *adata, std::string key);
    t_floatconf *get_float(t_appdata *adata, std::string key);
    t_strconf *get_str(t_appdata *adata, std::string key);
    int load_assets(t_appdata *adata);
}

#endif