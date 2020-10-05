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

#include "TextQuery.H"

using namespace std;

void TextQuery::Read(shared_ptr<TextQuery> TQ,const std::string &file_)
{
    ifstream in(file_);
    if(!in)
    {
        throw out_of_range("none of this file");
    }

    string s;
    int i = 1;
    while(getline(in,s))
    {
        TQ->PushLine(s);
        TQ->PushMap(s,i++);
    }

    in.close();

}


void ResultQuery::ShowText(shared_ptr<TextQuery> TQ)
{
    cout<<"the content in the textline :\n";
    for(const auto &c: TQ->GetLine())
        cout << c <<"\n";
    cout<<"\n\n";
    cout<<"the content in the wordmap :\n";
    for(const auto &c: TQ->wordmap)
    {
        cout<<c.first<<" : ";
        for(const auto &d: c.second)
        {
            cout << d << " ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";


}
void ResultQuery::FindWord(shared_ptr<ResultQuery> RQ,shared_ptr<TextQuery> TQ)
{
    auto iter = TQ->wordmap.find(RQ->word_query);
    RQ->lineNO.clear();
    if(iter != TQ->wordmap.end())
    {
        for(const auto &c : iter->second)
            {
                RQ->lineNO.push_back(c);
            }
    }
    else
    {
        cerr<<"none this word : "<<RQ->word_query<<"\n";
    }
}
void ResultQuery::ShowResult(shared_ptr<ResultQuery> RQ,shared_ptr<TextQuery> TQ)
{

    cout<<RQ->word_query<<" occurs "<< RQ->GetLineNO().size()<<" times :\n";
    for(const auto &c : RQ->GetLineNO())
    {
        cout<<"[line "<<c<<"] "<<TQ->textline[c-1]<<"\n";
    }
    cout<<"\n\n";

}
