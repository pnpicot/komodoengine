#include "../include/main.hpp"
#include "../include/asset.hpp"
#include "../include/string_utils.hpp"

namespace ko {
    t_intconf *get_int(t_appdata *adata, std::string key)
    {
        std::vector<t_intconf *> config_ints = adata->config_ints;

        for (auto & keyvalue : config_ints) {
            if (keyvalue->key == key)
                return (keyvalue);
        }

        return (NULL);
    }

    t_floatconf *get_float(t_appdata *adata, std::string key)
    {
        std::vector<t_floatconf *> config_floats = adata->config_floats;

        for (auto & keyvalue : config_floats) {
            if (keyvalue->key == key)
                return (keyvalue);
        }

        return (NULL);
    }

    t_strconf *get_str(t_appdata *adata, std::string key)
    {
        std::vector<t_strconf *> config_strings = adata->config_strings;

        for (auto & keyvalue : config_strings) {
            if (keyvalue->key == key)
                return (keyvalue);
        }

        return (NULL);
    }

    static std::string read_file(const char *filename)
    {
        std::ifstream t(filename);
        std::stringstream buffer;

        buffer << t.rdbuf();

        return (buffer.str());
    }

    static int add_config(t_appdata *adata, std::string type, std::string key, std::string value)
    {
        if (type == "int") {
            t_intconf *int_check = get_int(adata, key);

            if (int_check != NULL) {
                printf("%s\n", DUPLICATE_CONFIGURATION);
                return (CODE_SUCCESS);
            }

            t_intconf *new_config = new t_intconf();

            new_config->key = key;
            new_config->value = std::stoi(value);
            adata->config_ints.push_back(new_config);
        } else if (type == "float") {
            t_floatconf *float_check = get_float(adata, key);

            if (float_check != NULL) {
                printf("%s\n", DUPLICATE_CONFIGURATION);
                return (CODE_SUCCESS);
            }

            t_floatconf *new_config = new t_floatconf();

            new_config->key = key;
            new_config->value = std::atof(value.c_str());
            adata->config_floats.push_back(new_config);
        } else {
            t_strconf *str_check = get_str(adata, key);

            if (str_check != NULL) {
                printf("%s\n", DUPLICATE_CONFIGURATION);
                return (CODE_SUCCESS);
            }

            t_strconf *new_config = new t_strconf();

            new_config->key = key;
            new_config->value = value;
            adata->config_strings.push_back(new_config);
        }

        return (CODE_SUCCESS);
    }

    static int load_configs(t_appdata *adata)
    {
        std::string config_content = read_file("asset/config/default.ko");
        std::vector<std::string> config_lines = ko::str_split(config_content, '\n');

        for (auto & line : config_lines) {
            if (line[0] == '#' || line[0] == '\0')
                continue;

            std::vector<std::string> type_separation = ko::str_split(line, ':');

            if (type_separation.size() < 2) {
                printf("%s\n", INVALID_CONFIGURATION);
                return (CODE_FAILURE);
            }

            std::vector<std::string> value_separation = ko::str_split(type_separation[1], '=');

            if (value_separation.size() < 2) {
                printf("%s\n", INVALID_CONFIGURATION);
                return (CODE_FAILURE);
            }

            int config_code = add_config(adata,
                                         type_separation[0],
                                         value_separation[0],
                                         value_separation[1]);

            if (config_code != CODE_SUCCESS)
                return (config_code);
        }

        return (CODE_SUCCESS);
    }

    int load_assets(t_appdata *adata)
    {
        int config_code = load_configs(adata);

        if (config_code != CODE_SUCCESS)
            return (config_code);

        return (CODE_SUCCESS);
    }
}
