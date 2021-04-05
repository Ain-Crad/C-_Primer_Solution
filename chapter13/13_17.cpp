#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 13_14
// class numbered
// {
// public:
//     numbered()
//     {
//         mysn = unique++;
//     }

//     int mysn;
//     static int unique;
// };

// int numbered::unique = 10;

// void f(numbered s)
// {
//     std::cout << s.mysn << std::endl;
// }

// 13_15
// class numbered
// {
// public:
//     numbered()
//     {
//         mysn = unique++;
//     }
//     numbered(const numbered &n)
//     {
//         mysn = unique++;
//     }

//     int mysn;
//     static int unique;
// };

// int numbered::unique = 10;

// void f(numbered s)
// {
//     std::cout << s.mysn << std::endl;
// }

// 13_16
class numbered
{
public:
    numbered()
    {
        mysn = unique++;
    }
    numbered(const numbered &n)
    {
        mysn = unique++;
    }

    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(const numbered &s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}