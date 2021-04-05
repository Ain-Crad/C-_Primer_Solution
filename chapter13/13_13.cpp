#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

struct X
{
    X() { cout << "X()" << endl; }
    X(const X &) { cout << "X(const X &)" << endl; }
    X &operator=(const X &)
    {
        cout << "X& operator=(const X &)" << endl;
        return *this;
    }
    ~X() { cout << "~X()" << endl; }
};

void func1(X element_x) {}
void func2(X &element_x) {}

int main()
{
    X x;
    func1(x);
    func2(x);
    X *dymx = new X;
    std::vector<X> vec;
    vec.push_back(x);
    delete dymx;

    return 0;
}