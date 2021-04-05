#include "StrBlob.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A
{

public:
    A(int d = 0) : data(d) {}
    int data;
};

int main()
{
    const A a;
    cout << a.data << endl;
    a.data = 1;
    cout << a.data << endl;
    return 0;
}