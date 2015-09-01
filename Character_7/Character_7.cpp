// Character_7.cpp : Defines the entry point for the console application.
// C++ Primer µÚÆßÕÂ Á·Ï°Ìâ

#include "stdafx.h"
#include <string>
#include "person.h"
#include "sales_data.h"

int main()
{
	Sales_data d1;
	Sales_data d2(std::cin);
	Sales_data d3("123456");
	Sales_data d4("1234", 2, 3);

	Person p1;
	Person p2("bill", "china");

	getchar();

    return 0;
}

