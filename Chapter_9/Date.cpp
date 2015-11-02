#include "Date.h"

Date::Date(const std::string date_str)
{

}

void Date::set_date(const std::string & d, const std::string & m, const std::string & y)
{
    day = d;
    mounth = m;
    year = y;
}
