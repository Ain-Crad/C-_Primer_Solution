#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct If_Else
{
    int operator()(bool flag, int a, int b)
    {
        return flag ? a : b;
    }
};

int main()
{
    If_Else if_else;
    cout << if_else(1, 3, 2) << endl;
    return 0;
}