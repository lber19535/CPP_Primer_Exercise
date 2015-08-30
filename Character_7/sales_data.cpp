#include "stdafx.h"
#include "sales_data.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::endl;
using std::cout;

string Sales_data::isbn() const {
	return this->bookNo;
}

double Sales_data::avg_price() const {
	if (units_sold != 0)
	{
		return revenue / units_sold;
	}
	else {
		return 0;
	}
}

Sales_data &Sales_data::combine(const Sales_data & r) {
	this->units_sold += r.units_sold;
	this->revenue += r.revenue;
	return *this;
}

istream &read(istream &in, Sales_data &data) {

	cout << "input isbn number: " << endl;
	in >> data.bookNo;
	cout << "input units sold: " << endl;
	in >> data.units_sold;
	cout << "next!" << endl;
	return in;
}

ostream &print(ostream &out, const Sales_data &data) {
	out << "isbn number is " << data.bookNo << endl;
	out << "units sold is " << data.units_sold << endl;
	return out;
}

Sales_data add(const Sales_data &a, const Sales_data &b) {
	Sales_data sum = a;
	sum.combine(b);
	return sum;
}