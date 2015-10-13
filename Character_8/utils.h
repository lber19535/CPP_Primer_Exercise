#pragma once
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, const char &c) {

    std::size_t start_space = 0;
    std::size_t len = 0;
    std::vector<std::string> str_vec;

    for (std::string::size_type i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' && len == 0)
        {
            len = i - start_space;
        }

        if (i == str.size() - 1) {
            len = str.size() - start_space;
        }

        if (len != 0)
        {
            std::string item = str.substr(start_space, len);
            str_vec.push_back(item);
            start_space = start_space + len;
            len = 0;
        }
    }
    return str_vec;
}