#include <vector>

#include "String.h"

using std::cin;
using std::cout;
using std::endl;

String baz()
{
    String ret("world");
    return ret;
}

int main()
{
    // std::vector<String> vec;
    // vec.push_back("hello");
    // vec.push_back("world");
    // vec.push_back("qiuqiu");

    String s5 = baz();

    return 0;
}