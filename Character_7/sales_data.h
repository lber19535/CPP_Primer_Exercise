#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

struct Sales_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	Sales_data &combine(const Sales_data &);
	double avg_price() const;
	string isbn() const;
}; 

Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &read(istream &, Sales_data &);