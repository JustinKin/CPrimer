#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <iostream>
#include <memory>
using std::shared_ptr;
// #include <vector>
/* using std::vector;
using std::string;
using std::make_shared;
using std::weak_ptr;
using std::initializer_list;
using std::runtime_error;
using std::out_of_range;
 */

class ResultQuery;


class TextQuery
{
friend class ResultQuery;
public:
    void Read(shared_ptr<TextQuery> TQ,const std::string &file_);
    void PushLine(const std::string &s_);
    void PushMap(const std::string &s_, const int &i_);
    const std::vector<std::string>& GetLine() { return  textline; }
private:
    std::vector<std::string> textline;
    std::map<std::string,std::set<int>> wordmap;
};

class ResultQuery
{
public:
    std::string word_query;
    void ShowText(shared_ptr<TextQuery> TQ);
    void FindWord(shared_ptr<ResultQuery> RQ,shared_ptr<TextQuery> TQ);
    void ShowResult(shared_ptr<ResultQuery> RQ,shared_ptr<TextQuery> TQ);
    // const unsigned GetAccount() { return account ;}
    const std::vector<int> GetLineNO() { return lineNO ;}
private:
    // unsigned account = 0;
    std::vector<int> lineNO;


};



inline void TextQuery::PushLine(const std::string &s_)
{
    TextQuery::textline.push_back(s_);
}

inline void TextQuery::PushMap(const std::string &s_, const int &i_)
{
    std::istringstream ss(s_);
    std::string word;
    while (ss>>word)
    {
        TextQuery::wordmap[word].insert({i_});
    }


}


#endif