#include "StrBlobPtr_pointer.h"
#include "StrBlob.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    StrBlob b = {"hello", "world"};
    StrBlobPtr p(b);
    StrBlobPtr_pointer sbp(&p);
    cout << sbp->deref() << endl;
    return 0;
}