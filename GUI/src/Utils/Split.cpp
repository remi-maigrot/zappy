#include "Utils.hpp"

std::vector<std::string> Zappy::split(std::string str, char separator) {
    int startIndex = 0, endIndex = 0;
    std::vector<std::string> strings;
    for (unsigned long i = 0; i <= str.size(); i++)
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            std::string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    return strings;
}