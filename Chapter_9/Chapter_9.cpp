// Chapter_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
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

// ex 9.24
const std::string get_first(const std::vector<std::string> &vec) {
    if (vec.empty()) {
        std::cout << "the vector is empty" << std::endl;
        return "";
    }
    else
    {
        return *vec.begin();
    }
}

// ex 9.26 9.27
void ease_list() {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec;
    std::list<int> li;
    std::forward_list<int> fl;
    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(ia[i]);
        li.push_back(ia[i]);
        fl.push_front(ia[i]);
    }

    auto vec_beg = vec.begin();
    while (vec_beg != vec.end())
    {
        if (*vec_beg % 2 == 0)
        {
            vec_beg = vec.erase(vec_beg);
        }
        else
        {
            vec_beg++;
        }
    }

    auto li_beg = li.begin();
    while (li_beg != li.end())
    {
        if (*li_beg % 2 != 0)
        {
            li_beg = li.erase(li_beg);
        }
        else
        {
            li_beg++;
        }
    }

    auto fl_beg = fl.begin();
    auto fl_prev = fl.before_begin();
    while (fl_beg != fl.end())
    {
        if (*fl_beg % 2 != 0)
        {
            fl_beg = fl.erase_after(fl_prev);
        }
        else
        {
            fl_prev = fl_beg;
            fl_beg++;
        }
    }
    return;
}

std::size_t find(std::string &s, const std::string &str) {
    auto beg = s.begin();
    auto str_beg = str.begin();
    auto index = 0;
    auto start_index = 0;
    for (; beg != s.end(); beg++)
    {
        if (*beg != *str_beg)
        {
            str_beg = str.begin();
        }else {
            str_beg++;
            // 是否到目标字符串
            if (str_beg == str.end())
            {
                return index - str.length() + 1;
            }
        }
        index++;
    }
    return s.length() - 1;
}

// ex 9.43 9.44
void replace_old(std::string &s, const std::string &oldVal, const std::string &newVal) {
    
    while (true)
    {
        auto index = find(s, oldVal);
       
        if (index == s.length() - 1)
        {
            break;
        }
        else
        {
            // 9.43
            //s.erase(index, oldVal.length());
            //s.insert(index, newVal);
            // 

            // 9.44
            s.replace(index, oldVal.length(), newVal);
            //

            std::cout << s << std::endl;
        }
    }

    std::cout << s << std::endl;
}

// ex 9.45
std::string rename(std::string name, const  std::string &pre, const std::string &suffix) {
    name.insert(0, " ");
    name.insert(0, pre);
    name.append(" ");
    name.append(suffix);
    return name;
}

void find_fitler(const std::string &s, const std::string &filter) {
    std::size_t pos = 0;
    while ((pos = s.find_first_of(filter, pos)) != std::string::npos)
    {
        std::cout << "value is " << s[pos];
        std::cout << " position is " << pos << std::endl;
        pos++;
    }
}

// ex 9.47
void find_number(const std::string &s) {
    const std::string target = "1234567890";
    find_fitler(s, target);
}

void find_word(const std::string &s) {
    std::string target = "";
    for (size_t i = 65; i <= 90; i++)
    {
        char c = i;
        target.push_back(c);
    }
    for (size_t i = 97; i <= 122; i++)
    {
        char c = i;
        target.push_back(c);
    }
    find_fitler(s, target);
}


int main()
{
    //std::list<std::deque<int>> deque_list;
    
    //std::array<std::string, 20> a1;

 /*   std::vector<std::string> vec;

    auto elem = get_first(vec);

    std::cout << elem << std::endl;*/

    //ease_list();

    //std::string s = "i thk something";
    //replace_old(s, "thk", "think");

    //auto r = rename("Bill", "Mr.", "III");
    //std::cout << r << std::endl;

    //find_number("ei12qey12q8qwoeh");
    //find_word("ei12qey12q8qwoeh");

    getchar();
    return 0;
}

