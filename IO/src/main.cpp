/*
                           _ooOoo_
                          o8888888o
                          88" . "88
                          (| -_- |)
                          O\  =  /O
                       ____/`---'\____
                     .'  \\|     |//  `.
                    /  \\|||  :  |||//  \
                   /  _||||| -:- |||||-  \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
              ."" '<  `.___\_<|>_/___.'  >'"".
             | | :  `- \`.;`\ _ /`;.`/ - ` : | |
             \  \ `-.   \_ __\ /__ _/   .-` /  /
        ======`-.____`-.___\_____/___.-`____.-'======
                           `=---='
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
          一心向善	好运相伴	佛祖保佑	永无BUG
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>

#include "IOtest.h"
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "  Mission Start:  \n\n";
    auto start = chrono::high_resolution_clock::now();
    //=================================================================//


     //IOtest(cin);
     cout << "run with txt file name\n\n";
     string ifile = "data_read.txt", ofile = "data_write.txt";
     ifstream in;//read mode ,read into memory
     ofstream out;//write mode ,frome memory to file

     //in.close();
     in.open(ifile);
     vector<string> data_line,data_word;

     if(in)
     {
          PushLine(in,data_line);
          in.close();
          in.open(ifile);
          PushWord(in,data_word);
     }
     else
     {
          cerr<<"couldn't open1 : " + ifile;
     }

     Show(data_line);
     Show(data_word);
     cout<<"\n\n";
     in.close();

     //run with "sales_data.txt"
     string sales_data_new = "sales_data_new.txt";
     out.open(sales_data_new,ofstream::app);//keep old contents after open and add
     AddData(out);
     out.close();

     for(auto p = argv+1; p != argv + argc; ++p)//read sales_data and count
     {
          in.open(*p);
          if(in)
          {
               cout << string(*p)<<" opened completed!\n\n";
               SalesData(in,dayTime);
               in.close();
          }
          else
          {
               cerr<<"couldn't open2 : " + string(*p)<<"\n";
          }


     }

     string cal = "count.txt";
     out.open(cal);//update, without app
     SaveData(out, dayTime);
     out.close();


string s1="hello windows 10\n";

istringstream strin(s1);
ISTest(strin);
ISTest(cin);

//从文件读取line，存入vector，istringstream从vector挨个word读取
ifstream in2("istreamdata.txt");
string s2;
vector<string> vec1;
while(getline(in2,s2))
{
     vec1.push_back(s2);
}

for(auto c : vec1)
cout<<c<<"\n";
cout << "\n";

auto vbegin = vec1.begin();
int i = 0;
for(; vbegin != vec1.end(); ++vbegin)
{
     string s;
     istringstream is(*(vbegin));
     while(is>>s)
     {
          cout << s <<"-";
     }
     cout << "\n";
}


string line, word;
vector<PersonInfo> people;
PersonInfo info;
while(getline(cin, line))
{
     istringstream record(line);
     record >> info.name;
     while(record >> word)
          info.phones.push_back(word);
     people.push_back(info);
}
cout<<"2"<<"\n";//debug
for(const auto &entry : people)
{
     ostringstream formatted, badNums;
     for(const auto &nums : entry.phones)
     {
          if(nums.empty())
          {
               badNums << " "<< nums;
          }
          else
          formatted <<" " <<Format(nums);
     }
     if(badNums.str().empty())
     cout << entry.name<<" "<<formatted.str()<<endl;
     else
     cerr <<"input error: "<<entry.name<<" invalid number(s) "<<badNums.str()<<endl;
}

i =0;//debug
for(auto c : people)
{
     cout << c.name<<"  " << c.phones[i]<<"\n";
     i++;
}





    //=================================================================//
    cout << "\n\n";
    auto end = chrono::high_resolution_clock::now();
    cout << "Elapsed Time:  " << std::chrono::duration<double>(end - start).count() << " s\n\n"
         << "**Mission Completed !**\n\n\n"
         << "\a";
     system("pause");
    return 0;
}
