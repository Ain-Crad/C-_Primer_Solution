#include <iostream>
#include <vector>
#include <algorithm>

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    std::vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());

    return ret;
}

// Foo Foo::sorted() const &
// {
//     Foo ret(*this);
//     return ret.sorted();
// }

int main()
{
    Foo().sorted();
    Foo f;
    f.sorted();
    return 0;
}