#pragma once
#include <string>
class Date {
public:
    std::string day = "1900";
    std::string mounth = "1";
    std::string year = "1";

    Date() = default;
    Date(const std::string date_str);
private:
    void set_date(const std::string &d, const std::string &m, const std::string &y);
};

class DateFormat {

};