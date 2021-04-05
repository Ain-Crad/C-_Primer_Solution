#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>

#include "exr_12_19.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::ifstream in("in.txt");
    std::string str;
    StrBlob blob;
    while (std::getline(in, str))
    {
        blob.push_back(str);
    }
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
    {
        cout << pbeg.deref() << endl;
    }
    return 0;
}