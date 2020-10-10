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
#include <tuple>
#include <regex>
#include <random>

// #include <conio.h>
// #include <windows.h>
#include "SSTL.H"

using namespace std;


int main(int argc, char *avgv[])
{
//=================================================================//
    ostream_iterator<int> out_1(cout," "), out_2(cout,"\n");
    ostream_iterator<string>out_a(cout," "), out_b(cout,"\n");


/* tuple<int,int,int> t(10,20,30);
cout<<get<1>(t);

tuple<string,vector<string>,pair<string,int>> svp;
get<2>(svp) = {"hello", 2020};
cout<<get<2>(svp).first<<" "<<get<2>(svp).second;
cout<<"\n\n";


default_random_engine e;
uniform_int_distribution<unsigned> u(0,100);

cout<<"min: "<<e.min()<<endl<<"max: "<<e.max()<<endl;
for(size_t i = 0; i <10; ++i)
{
    cout<<u(e)<<" ";
}

char s;
while(cin>>s)
{
    if(s =='x')
        break;
    for(const auto &c : myrand())
        cout<<c<<" ";
} */

string pattern("[^c]ei");
pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
regex r(pattern);
smatch results;
string test_str = "receipt freind theif receive";
if(regex_search(test_str,results,r))
    cout << results.str()<<"\n\n\n";

regex r2(pattern,regex::icase);
for(sregex_iterator it(test_str.begin(),test_str.end(),r), end_it; it!=end_it; ++it)
    cout << it->str() <<endl;




//=================================================================//

     system("pause");
    return 0;
}

