#include "stdafx.h"
#include "person.h"

std::string Person::get_address() const {
    return address;
}
std::string Person::get_name() const {
    return name;
}
void Person::set_name(const std::string &name) {
    this->name = name;
}
void Person::set_address(const std::string &address) {
    this->address = address;
}
