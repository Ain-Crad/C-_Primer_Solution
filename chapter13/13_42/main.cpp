#include <iostream>
#include <fstream>

#include "exr_12_30.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::ifstream in("in.txt");
    TextQuery tq(in);
    print(cout, tq.query("you")) << endl;
    print(cout, tq.query("hey")) << endl;
    print(cout, tq.query("nonono")) << endl;

    return 0;
}