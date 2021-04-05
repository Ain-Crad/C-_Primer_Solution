#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct Equal_Test
{
    Equal_Test(int v) : value(v) {}

    bool operator()(int a)
    {
        if (a == value)
            return true;
        else
            return false;
    }
    int value;
};

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Equal_Test et(3);
    std::replace_if(vec.begin(), vec.end(), et, 5);
    for (auto x : vec)
        cout << x << " ";
    cout << endl;
    return 0;
}