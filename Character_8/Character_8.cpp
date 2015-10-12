// Character_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

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

int main()
{

    //int ival;
    //std::cin >> ival;

    //std::cout << std::cin.rdstate();

    //read(std::cin);

    std::fstream fstrm("C:\\Users\\bill_lv\\Desktop\\vpnup.bat", std::fstream::in,std::fstream::trunc);

    std::string txt;
    std::string buf;
    while (fstrm.good())
    {
        std::getline(fstrm, buf);
        //fstrm >> buf;
        txt += buf + "\r\n";
    }
    std::cout << "txt" << std::ends;
    WCHAR  file_name[1024];
    GetModuleFileName(NULL, file_name,1024);

    std::string file_path;
    for (size_t i = 0; i < 1024; i++)
    {
        if (file_name[i] == 0)
            break;
        file_path += file_name[i];
    }
    std::string::size_type pos = file_path.find_last_of("\\/");
    std::cout << file_path.substr(0,pos) << std::endl;
     system("pause");

    return 0;
}

