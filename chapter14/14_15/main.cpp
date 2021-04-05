#include "Book.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Book bk1, bk2;
    bk2 = bk1;
    cin >> bk1 >> bk2;
    if (bk1 == bk2)
    {
        cout << bk1 + bk2 << endl;
    }
    return 0;
}