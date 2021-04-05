#include <iostream>
#include <string>
#include <memory>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    size_t n = 3;
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;

    std::string s;
    std::ifstream in("in.txt");
    while (in >> s)
    {
        alloc.construct(q, s);
        cout << *(q++) << endl;
    }

    while (q != p)
    {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);
    in.close();

    return 0;
}