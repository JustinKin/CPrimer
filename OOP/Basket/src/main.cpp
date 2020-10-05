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
#include "QUOTE.H"

using namespace std;


int main(int argc, char *avgv[])
{
//=================================================================//
    ostream_iterator<int> out_1(cout," "), out_2(cout,"\n");
    ostream_iterator<string>out_a(cout," "), out_b(cout,"\n");

Quote book1("001",1.1);
Bulk_quote book2("002", 2.3, 3, 0.1);
Print_Total(cout, book1, 3);
Print_Total(cout, book2, 2);
Print_Total(cout, book2, 5);
Quote book3(book1);
Bulk_quote book4(book2);
auto book5 = book1;
auto book6 = book4;

vector<shared_ptr<Quote>> vec;
vec.push_back(make_shared<Quote>(book1));
vec.push_back(make_shared<Bulk_quote>(book2));
vec.push_back(make_shared<Quote>(book3));
float sum = 0.0;
for(const auto &c : vec)
{
    sum += c->net_price(3);
}

cout<<"Total price : "<<sum<<endl;




//=================================================================//

     system("pause");
    return 0;
}

