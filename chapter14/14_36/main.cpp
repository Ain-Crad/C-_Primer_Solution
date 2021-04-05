#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

struct ReadString
{
    ReadString(std::istream &is_ = cin) : is(is_) {}

    std::string operator()()
    {
        getline(is, str);
        if (is)
            return str;
        else
            return std::string("");
    }
    std::istream &is;
    std::string str;
};

int main()
{
    std::vector<std::string> vec;
    ReadString rs(cin);
    for (std::string tmp; !(tmp = rs()).empty();)
        vec.push_back(tmp);
    for (auto x : vec)
    {
        cout << x << endl;
    }
    return 0;
}