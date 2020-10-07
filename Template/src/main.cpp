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
// #include <conio.h>
// #include <windows.h>
#include "TEMPLATE.H"

using namespace std;


int main(int argc, char *avgv[])
{
//=================================================================//
    ostream_iterator<int> out_1(cout," "), out_2(cout,"\n");
    ostream_iterator<string>out_a(cout," "), out_b(cout,"\n");

/*  int a = 3 , b = 9;
    string s1 = "my", s2("compare");
    auto result1 = mycompare(a,b);
    auto result2 = mycompare(s1,s2);
    auto result3 = mycompare(sizeof(s1),sizeof(s2));
    auto result4 = mycompare(s1.size(),s2.size());

    out_a = "mycompare(a,b) :"; out_2 = result1;
    out_a = "mycompare(s1,s2):"; out_2 = result2;
    out_a = "mycompare(sizeof(s1),sizeof(s2)):"; out_2 = result3;
    out_a = "mycompare(s1.size(),s2.size()):"; out_2 = result4; */


/*     vector<int> vec{1,2,3,4,5};
    list<string> lst{"my","tem","m","template","nice"};

    auto bg =vec.begin(), ed = vec.end();
    auto r1 = myfind(bg, ed,3) - vec.begin();
    auto r2 = myfind(bg, ed,6)- vec.begin();

    auto bg2 =lst.begin(), ed2 = lst.end();
    auto r3 = myfind(bg2, ed2, "my") ;
    auto r4 = myfind(bg2, ed2, "m") ;

    cout<<"myfind(bg, ed,3): "<<r1<<endl;
    cout<<"myfind(bg, ed,6): "<<r2<<endl;
    cout<<"myfind(bg, ed, \"my\"): "<<*r3<<endl;
    cout<<"myfind(bg, ed, \"m\") "<<*r4<<endl; */



vector<int> vec{1,2,3,4,5};
list<string> lst{"my","tem","m","template","nice"};

printv(vec);
// printv(lst);








//=================================================================//

     system("pause");
    return 0;
}

