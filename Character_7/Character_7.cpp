// Character_7.cpp : Defines the entry point for the console application.
// C++ Primer µÚÆßÕÂ Á·Ï°Ìâ

#include "stdafx.h"
#include <string>
#include "person.h"
#include "sales_data.h"

using std::string;
using std::initializer_list;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	Sales_data d1;
	read(cin, d1);

	print(cout, d1) << endl;

	getchar();

    return 0;
}

