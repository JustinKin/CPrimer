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
#include "MAIL.H"

using namespace std;


int main(int argc, char *avgv[])
{
//=================================================================//
    ostream_iterator<int> out_1(cout," "), out_2(cout,"\n");
    ostream_iterator<string>out_a(cout," "), out_b(cout,"\n");

    TextQuery TQ;
    ResultQuery RQ;
    auto p_tp = make_shared<TextQuery>(TQ);
    auto p_rp = make_shared<ResultQuery>(RQ);
    // cout<<"Please input the file need to query:\n";
    string file;
    // cin >> file;
    file += "data_query.txt";
    p_tp->Read(p_tp,file);
    p_rp->ShowText(p_tp);
    while(1)

    {
        cout<<"Please input the word needed to query, input x to quick:\n";
        cin>>p_rp->word_query;
        if(p_rp->word_query == "x")
        {
            break;
        }
        p_rp->FindWord(p_rp,p_tp);
        p_rp->ShowResult(p_rp,p_tp);
    }




//=================================================================//
     system("pause");
    return 0;
}














