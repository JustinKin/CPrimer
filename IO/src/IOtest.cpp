#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "IOtest.h"

std::istream &IOtest(std::istream &input)
{
    std::string str1;
    //    while(!=iput.eof())

    while(input>>str1 && str1 != "exit")
        {

            std::cout<<str1<<std::flush;
        }
    input.clear();

    return input;
}

void PushLine(std::ifstream &in_, std::vector<std::string> &data_line_)
{
    std::string str;
    while(!in_.eof())
    {
        getline(in_,str);//watch out, read with a line in once
        data_line_.push_back(str);
    }

}

void PushWord(std::ifstream &in_, std::vector<std::string> &data_word_)
{
    std::string str;
    while(in_>>str)//watch out
    {
        //in_>>str;//watch out, read with a word in once
        data_word_.push_back(str);
    }

}

void Show(std::vector<std::string> &vec_)
{
    for(auto c : vec_)
        std::cout<<c<<"\n";
}

std::istream& ISTest(std::istream &is_)
{
     std::string str;
     std::cout<<"\n x for quick: \n";
     while(getline(is_,str) && str!="x")
     {
          std::cout << str<<"\n";
     }
     is_.clear();

     return is_;
}


std::string Format(const std::string &s_)
{
     std::string tmp;
     for(int i = 0; i<s_.size(); ++i)
     {
          if(i==2 || i==6)
               tmp = tmp + s_[i]+"-";
          else
               tmp += s_[i];
     }

     return tmp;
}

