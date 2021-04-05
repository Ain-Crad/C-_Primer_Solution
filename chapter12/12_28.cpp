#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;

std::vector<std::string> text;
std::map<std::string, std::set<int>> mp;

void init(std::istream &in)
{
    int lineNum = 0;
    std::string line;
    while (std::getline(in, line))
    {
        lineNum++;
        text.push_back(line);
        std::istringstream sstr(line);
        std::string word;
        while (sstr >> word)
        {
            mp[word].insert(lineNum);
        }
    }
}

bool query(const std::string &s)
{
    auto it = mp.find(s);
    if (it == mp.end())
        return false;
    else
        return true;
}

int main()
{
    std::ifstream in("in.txt");
    init(in);
    while (true)
    {
        cout << "Please enter the word that you want to query.\nOr enter 'q' to quit.\n";
        std::string s;
        if (!(cin >> s) || s == "q")
        {
            break;
        }
        bool state = query(s);
        if (!state)
        {
            cout << "Couldn't find " << s << endl;
        }
        else
        {
            auto st = mp[s];
            for (auto x : st)
            {
                cout << "("
                     << "line" << x << ") " << text.at(x - 1) << endl;
            }
        }
    }

    return 0;
}