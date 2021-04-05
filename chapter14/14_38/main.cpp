#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Test
{
public:
    Test(size_t lb_, size_t ub_) : lb(lb_), ub(ub_) {}
    bool operator()(const std::string &s) const
    {
        if (s.size() >= lb && s.size() <= ub)
            return true;
        else
            return false;
    }

private:
    size_t lb, ub;
};

int main()
{
    Test test(1, 10);
    std::ifstream in("in.txt");
    std::string s;
    size_t cnt = 0;
    while (in >> s)
    {
        if (test(s))
            ++cnt;
    }
    cout << cnt << endl;

    return 0;
}