// Character_7.cpp : Defines the entry point for the console application.
// C++ Primer 第七章 练习题

#include "stdafx.h"
#include <string>
#include "person.h"
#include "sales_data.h"
#include "screen.h"
#include "Debug.h"

// 测试重复定义类型
using Money = std::string;
typedef double MM;
class A {
private:
    using Money = std::string;
    typedef double MM;
public:
    A() = default;
    void f() {
        Money m = "11";
        MM mm = 1;
        std::cout << m << std::endl;
        std::cout << mm << std::endl;
    }
};

class NoDefault {
public:
    NoDefault(const int i) {};
};

struct B
{
    std::string s;
    int b;
    double c;
};

class C {
private:
    NoDefault d;
public:
    C() : d(1) {};
};

int main()
{

/*    Sales_data d1;
    Sales_data d2(std::cin);
    Sales_data d3("123456");
    Sales_data d4("1234", 2, 3);

    Person p1;
    Person p2("bill", "china");
*/

/*    Screen s(5, 5);
    s.set('1').set('2').display(std::cout);
*/

    //Screen s(5, 5, 'X');
    //s.move(4, 0).set('#').display(std::cout);
    //std::cout << std::endl;
    //s.display(std::cout);
    //std::cout << std::endl;

    //Window_mgr mgr;
    //mgr.clear(0);

    //A a;
    //a.f();

    std::vector<C> vec(10);

    std::string null_book = "9-999-99999-9";

    Sales_data item("1234");

    B a = { "",1, 1.1 };

    constexpr Debug dd(true);
    item.combine(null_book);
    if (dd.any())
    {
        std::cout << "true " << std::endl;
    }
    else
    {
        std::cout << "false " << std::endl;
    }
    
    getchar();

    return 0;
}

