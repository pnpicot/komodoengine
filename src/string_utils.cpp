#include "../include/main.hpp"
#include "../include/string_utils.hpp"

namespace ko {
    std::vector<std::string> str_split(std::string str, char delimiter)
    {
        std::vector<std::string> array;
        std::string current = "";

        for (int i = 0; i < str.size(); i++) {
            if (str[i] != delimiter) current.push_back(str[i]);

            if (str[i] == delimiter || i == str.size() - 1) {
                array.push_back(current);
                current = "";
            }
        }

        return (array);
    }
}