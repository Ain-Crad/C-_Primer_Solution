#include <iostream>

#include "exr_13_40.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    StrVec vec;
    vec.push_back("yes");
    cout << vec.at(0) << endl;

    StrVec vec2 = {"god", "bless", "you"};
    for (auto it = vec2.begin(); it != vec2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}