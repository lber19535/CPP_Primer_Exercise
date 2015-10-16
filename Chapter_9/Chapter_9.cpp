// Chapter_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <array>

// ex 9.4
bool check_int(std::vector<int>::iterator &left, std::vector<int>::iterator &right, int &value) {
    for (; left < right; left++)
    {
        if (*left == value) {
            return true;
        }
    }
    return false;
}

// ex 9.5
std::vector<int>::iterator *check_int_value(std::vector<int>::iterator &left, std::vector<int>::iterator &right, int &value) {
    for (; left < right; left++)
    {
        if (*left == value) {
            return &left;
        }
    }
    return nullptr;
}

int main()
{
    //std::list<std::deque<int>> deque_list;
    
    //std::array<std::string, 20> a1;

    getchar();
    return 0;
}

