#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

bool compareIsbn(const Sales_data &d1, const Sales_data &d2)
{
    return d1.isbn() < d2.isbn();
}

int main()
{
    freopen("Sales_data.txt", "r", stdin);
    // Sales_data d1;
    // Sales_data d2("0-201-78345-X");
    // Sales_data d3("0-201-78345-X", 5, 2.5);
    // Sales_data d4(cin);

    // print(cout, d1) << endl;
    // print(cout, d2) << endl;
    // print(cout, d3) << endl;
    // print(cout, d4) << endl;

    // Sales_data total(cin);
    // if (cin)
    // {
    //     Sales_data trans(cin);
    //     while (cin)
    //     {
    //         if (total.isbn() == trans.isbn())
    //         {
    //             total.combine(trans);
    //         }
    //         else
    //         {
    //             print(cout, total) << endl;
    //             total = trans;
    //         }
    //         read(cin, trans);
    //     }
    //     print(cout, total);
    // }
    // else
    // {
    //     std::cerr << "No data?!" << endl;
    //     return -1;
    // }

    std::vector<Sales_data> vec;
    vec.push_back(Sales_data(cin));
    vec.push_back(Sales_data(cin));
    // std::sort(vec.begin(), vec.end(), compareIsbn);
    std::sort(vec.begin(), vec.end(), [](const Sales_data &d1, const Sales_data &d2) { return d1.isbn() < d2.isbn(); });
    cout << vec.at(0).isbn() << endl;
    cout << vec.at(1).isbn() << endl;

    return 0;
}