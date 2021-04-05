#include <iostream>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

std::vector<int> *creatVec()
{
    return new std::vector<int>();
}

void read(std::vector<int> *vec)
{
    std::ifstream in("../../test.txt");
    int t;
    while (in >> t)
    {
        vec->push_back(t);
    }
}

void print(std::vector<int> *vec)
{
    for (auto x : *vec)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    std::vector<int> *vec = creatVec();
    read(vec);
    print(vec);
    delete vec;
    vec = nullptr;

    return 0;
}