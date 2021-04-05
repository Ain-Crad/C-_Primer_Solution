#ifndef _EXR_12_30_H
#define _EXR_12_30_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

using std::ifstream;

using std::istringstream;

using std::string;

using std::vector;

using std::shared_ptr;

using std::map;

using std::set;

class QueryResult;

class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

ostream &print(ostream &, const QueryResult &);

class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

public:
    using line_no = vector<string>::size_type;
    QueryResult(const string &s,
                shared_ptr<vector<string>> f,
                shared_ptr<set<line_no>> ls)
        : sought(s), file(f), lines(ls) {}

private:
    string sought;
    shared_ptr<vector<string>> file;
    shared_ptr<set<line_no>> lines;
};

#endif