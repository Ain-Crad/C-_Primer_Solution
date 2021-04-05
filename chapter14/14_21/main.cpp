#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
    Sales_data sd1("1010-111", 3, 1.0);
    Sales_data sd2("1010-111", 2, 1.5);
    cout << (sd1 += sd2) << endl;
    return 0;
}