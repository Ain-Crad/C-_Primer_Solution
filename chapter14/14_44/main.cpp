#include <iostream>
#include <functional>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;

int add(int x, int y) { return x + y; }

class divide
{
public:
    int operator()(int x, int y)
    {
        return x / y;
    }
};

int main()
{
    std::map<std::string, std::function<int(int, int)>> binops;
    int (*p_add)(int, int) = add;
    std::multiplies<int> mul;
    binops.insert({"+", p_add});
    binops.insert({"-", std::minus<int>()});
    // binops.insert({"*", [](int a, int b) { return a * b; }});
    binops.insert({"*", mul});
    binops.insert({"/", divide()});

    cout << binops["+"](1, 2) << endl;
    cout << binops["-"](1, 2) << endl;
    cout << binops["*"](1, 2) << endl;
    cout << binops["/"](1, 2) << endl;

    return 0;
}