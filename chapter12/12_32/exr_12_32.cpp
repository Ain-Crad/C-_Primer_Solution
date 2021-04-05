#include "exr_12_32.h"

TextQuery::TextQuery(ifstream &is) : file(new StrBlob())
{
    string text;
    line_no lineNum = 0;
    while (getline(is, text))
    {
        file->push_back(text);
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
            {
                lines.reset(new set<line_no>);
            }
            lines->insert(lineNum);
        }
        ++lineNum;
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto found = wm.find(sought);
    if (found == wm.end())
        // return QueryResult(sought, file, shared_ptr<set<line_no>>(new set<line_no>));
        return QueryResult(sought, file, nodata);
    else
        return QueryResult(sought, file, found->second);
}

string make_plural(size_t ctr, const string &word,
                   const string &ending)
{
    if (ctr > 1)
        return word + ending;
    else
        return word;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs" << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    for (auto num : *(qr.lines))
    {
        os << "\t(line " << num + 1 << ") ";
        StrBlobPtr sbp = qr.file->begin();
        for (QueryResult::line_no i = 0; i < num; ++i)
        {
            sbp.incr();
        }
        os << sbp.deref() << endl;
    }
    return os;
}