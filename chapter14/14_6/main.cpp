#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data item("00-11-22", 3, 1.0);
    cout << item << endl;
    return 0;
}