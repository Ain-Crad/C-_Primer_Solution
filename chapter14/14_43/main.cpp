#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> vec = {2, 3, 4, 5};
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicator = [&](int i) { return mod(input, i) == 0; };
    auto res = std::any_of(vec.begin(), vec.end(), predicator);
    std::cout << (res ? "Yes" : "No") << std::endl;
    return 0;
}