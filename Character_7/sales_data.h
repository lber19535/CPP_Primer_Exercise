#include <string>
#include <iostream>

struct Sales_data
{
	// isbn
	std::string bookNo;
	// sold number
	unsigned units_sold = 0;
	// price
	double revenue = 0.0;

	Sales_data &combine(const Sales_data &);
	double avg_price() const;
	std::string isbn() const;

	// constructor
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {

	}
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {

	}
	Sales_data(std::istream &in) {
		read(in, *this);
	}
}; 

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);