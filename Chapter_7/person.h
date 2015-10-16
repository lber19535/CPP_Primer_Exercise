#include <string>

struct Person
{
private:
    std::string name;
    std::string address;

public:
    std::string get_name() const;
    std::string get_address() const;
    void set_name(const std::string &);
    void set_address(const std::string &);
    Person() = default;
    Person(const std::string &name, const std::string &address) : name(name), address(address) {}
};
#pragma once
