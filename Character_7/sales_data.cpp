#include "stdafx.h"
#include "sales_data.h"
#include <iostream>

// member function
std::string Sales_data::isbn() const {
    return this->bookNo;
}

Sales_data &Sales_data::combine(const Sales_data & r) {
    this->units_sold += r.units_sold;
    this->revenue += r.revenue;
    return *this;
}

std::istream &read(std::istream &in, Sales_data &data) {

    std::cout << "input isbn number: " << std::endl;
    in >> data.bookNo;
    std::cout << "input units sold: " << std::endl;
    in >> data.units_sold;
    std::cout << "next!" << std::endl;
    return in;
}

std::ostream &print(std::ostream &out, const Sales_data &data) {
    out << "isbn number is " << data.bookNo << std::endl;
    out << "units sold is " << data.units_sold << std::endl;
    return out;
}

Sales_data add(const Sales_data &a, const Sales_data &b) {
    Sales_data sum = a;
    sum.combine(b);
    return sum;
}