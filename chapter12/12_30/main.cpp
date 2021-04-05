#include "exr_12_30.h"

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        QueryResult qr(tq.query(s));
        print(cout, qr) << endl;
    }
}

int main()
{
    ifstream in("in.txt");
    runQueries(in);

    return 0;
}