#include <iostream>
#include <string>

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
    ReadString rs(cin);
    cout << rs() << endl;
    return 0;
}