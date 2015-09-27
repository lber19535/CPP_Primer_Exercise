#pragma once
#include <string>
#include <iostream>

class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
private:
    // isbn
    std::string bookNo;
    // sold number
    unsigned units_sold = 0;
    // price
    double revenue = 0.0;

public:
    // constructor
    //Sales_data() = default;
    Sales_data() : Sales_data("", 0, 0) {};
    //Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {};
    //explicit Sales_data(const std::string &s) : Sales_data(s, 0, 0) {};
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &in) : Sales_data() {
        read(in, *this);
    }
    Sales_data &combine(const Sales_data &);
    //Sales_data &combine(Sales_data &);
    //Sales_data &combine(Sales_data);
    inline double avg_price() const {
        if (units_sold != 0)
        {
            return revenue / units_sold;
        }
        else {
            return 0;
        }
    }
    std::string isbn() const;
};

