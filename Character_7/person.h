#include <string>

struct Person
{
	std::string name;
	std::string address;

	std::string get_name() const;
	std::string get_address() const;

	Person() = default;
	Person(const std::string &name, const std::string &address) : name(name), address(address) {

	}
};
#pragma once
