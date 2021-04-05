#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

std::shared_ptr<std::vector<int>> creatVec()
{
    return std::make_shared<std::vector<int>>();
}

void read(std::shared_ptr<std::vector<int>> vec)
{
    std::ifstream in("../../test.txt");
    int t;
    while (in >> t)
    {
        vec->push_back(t);
    }
}

void print(std::shared_ptr<std::vector<int>> vec)
{
    for (auto x : *vec)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    std::shared_ptr<std::vector<int>> vec = creatVec();
    read(vec);
    print(vec);

    return 0;
}