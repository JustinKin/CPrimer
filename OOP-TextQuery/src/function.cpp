#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <utility>
#include <memory>

#include "TEXTQUERY.H"

using namespace std;

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
            {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
    {
        return QueryResult(sought, nodata, file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       //    << make_plural(qr.lines->size(), "time", "s") <<endl;
       << qr.lines->size() << "times" << endl;
    for (auto num : *qr.lines)
    {
        os << "\t(line" << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text);
    auto left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text);
    auto left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (beg == end || *beg != n)
        {
            ret_lines->insert(n);
        }
        else if (beg != end)
        {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

shared_ptr<vector<string>> QueryResult::get_file()
{
    return make_shared<vector<string>>(file);
}
// string make_plural(const QueryResult &qr, const string &s1, const string &s2)
// {
//     string str=s1;
//     if(qr.lines->size()>1)
//     {
//         str += s2;
//     }
//     return str;
// }