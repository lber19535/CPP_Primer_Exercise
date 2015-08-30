#include <string>

using std::string;

struct Person
{
	string name;
	string address;

	string get_name() const;
	string get_address() const;
};
#pragma once
