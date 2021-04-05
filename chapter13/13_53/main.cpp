#include "HasPtr.h"

#include <chrono>

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for (int i = 0; i < 1000000; ++i)
    {
        HasPtr h1("hello");
        HasPtr h2("world");
        h1 = std::move(h2);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000 << "[ms]" << std::endl;

    return 0;
}