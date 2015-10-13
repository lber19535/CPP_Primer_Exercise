// Character_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "utils.h"

// 练习8.1
std::istream &read(std::istream &in) {

    int ival = 0;
    std::string sval;

    in >> ival;
    auto state = in.rdstate();

    if (in.good())
    {
        std::cout << "read good int" << std::endl;
        std::cout << ival << std::endl;
        read(in);
    }
    else if (in.fail())
    {
        std::cout << "read fail, not int" << std::endl;

        if (in.eof())
        {
            std::cout << "end of stream" << std::endl;
        }
        else
        {
            // 重置流的状态为 good
            in.clear();
            std::cout << "read to string" << std::endl;
            in >> sval;
            std::cout << sval << std::endl;
        }
    }
    else if (in.bad())
    {
        std::cout << "error bit" << std::endl;
    }
    else if(in.eof())
    {
        std::cout << "clear stream state" << std::endl;
        in.clear();
    }
    
    return in;
}

std::string get_project_root_path() {
    WCHAR  file_name[1024];
    GetModuleFileName(NULL, file_name, 1024);

    std::string file_path;
    for (size_t i = 0; i < 1024; i++)
    {
        if (file_name[i] == 0)
            break;
        file_path += file_name[i];
    }
    std::string::size_type pos = file_path.find_last_of("\\/");
    pos = file_path.substr(0, pos).find_last_of("\\/");
    std::string path = file_path.substr(0, pos);
    std::cout << path << std::endl;
    return path;
}

// ex 8.4
void save_in_vec() {
    std::string path = get_project_root_path() + "\\" + "Character_8" + "\\" + "example" + "\\" + "vpnup.bat";

    std::ifstream ifs(path);
    std::vector<std::string> strs;
    std::string buf;
    while (ifs.good())
    {
        std::getline(ifs, buf);
        strs.push_back(buf);
        std::cout << buf << std::ends;
    }
    std::cout << "vector size is " << strs.size() << std::endl;
}

// ex 8.5
void save_word_in_vec() {
    std::string path = get_project_root_path() + "\\" + "Character_8" + "\\" + "example" + "\\" + "vpnup.bat";

    std::ifstream ifs(path);
    std::vector<std::string> strs;
    std::string buf;
    while (ifs.good())
    {
        std::getline(ifs, buf);

        std::size_t start_space = 0;
        std::size_t len = 0;
        for (std::string::size_type i = 0; i < buf.size(); i++)
        {
            if (buf[i] == ' ' && len == 0)
            {
                len = i - start_space;
            }

            if (i == buf.size() - 1) {
                len = buf.size() - start_space;
            }

            if(len != 0)
            {
                std::string item = buf.substr(start_space, len);
                strs.push_back(item);
                start_space = start_space + len;
                len = 0;
            }
           
        }
        
        std::cout << buf << std::ends;
    }
    std::cout << "vector size is " << strs.size() << std::endl;
}

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

// ex 8.13
std::vector<PersonInfo> read_person_info(std::istream &in) {
   

    //std::istream ifstrm(path);
    std::string line;
    std::vector<PersonInfo> infos;
    while (in.good())
    {
        std::getline(in, line);

        std::vector<std::string> str_vec = split(line, ' ');

        PersonInfo info;
        info.name = str_vec[0];

        
        for (auto p = str_vec.begin() + 1; p != str_vec.end(); p++)
        {
            info.phones.push_back(*p);
        }
        infos.push_back(info);
        std::cout << line << std::endl;
    }

    return infos;
}

// ex 8.13
std::vector<PersonInfo> read_person_info_from_file() {
    std::string path = get_project_root_path() + "\\" + "Character_8" + "\\" + "example" + "\\" + "person_info";
    std::ifstream in(path);
    return read_person_info(in);
}

int main(int count, char* args)
{

    //int ival;
    //std::cin >> ival;

    //std::cout << std::cin.rdstate();

    //read(std::cin);

    //save_word_in_vec();
   
    auto vec = read_person_info();

     system("pause");

    return 0;
}

