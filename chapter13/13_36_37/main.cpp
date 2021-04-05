#include <iostream>
#include <string>
#include <set>

#include "exr_13_36.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Folder f;
    Message m("first message");
    m.save(f);
    Message m2("??????????");
    m2.save(f);
    f.print();
    cout << endl;
    m2.remove(f);
    f.print();

    return 0;
}