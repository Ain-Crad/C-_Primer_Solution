#include "Strvec.h"
#include "String.h"
#include "StrBlob.h"
#include <initializer_list>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    StrBlob b1 = {"hello", "world"};
    StrBlob b2 = b1;

    b2[1] = "everyone";
    cout << b2[1];
    StrBlobPtr iter(b2);
    cout << iter[1] << endl;

    return 0;
}