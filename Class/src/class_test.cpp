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
#include <algorithm>

#include "Sales_data.h"
#include "FuckScreen.h"

using namespace std;

//TODO:global struct,sort vector 
int main(int argc, char *argv[])
{
    cout << "  Mission Start:  \n\n";
    auto start = chrono::high_resolution_clock::now();
    //=================================================================//

    cout << "Please input bookNO., price, amount, input x for finished: "
         << "\n";
    while (1)
    {

        cin >> dayTime.aNO; //cout <<"\n";
        if (dayTime.aNO == "x")
            break;
        else
        {
            //cout<<"dayTime.aNO 1: "<<dayTime.aNO<<"\n";
            dayTime.alocat = Find(dayTime.bookNo, dayTime.aNO);
            if (dayTime.alocat == dayTime.bookNo.end())
            {
                PushMem(dayTime);
                //cout<<"dayTime.aNO 3: "<<dayTime.aNO<<"\n";
            }
            else
            { //cout<<"get\n";
                CountMem(dayTime);
            }
        }
    }
    SumSold(dayTime.day_sold, dayTime.sum_sold);
    SumRevenue(dayTime.day_revenue, dayTime.sum_revenue);
    Print(dayTime);



    FuckScreen MyScreen(8, 8, '0');
    MyScreen.Move(6 ,6).SetContents('X').Display(cout);
    cout << "\n";
    MyScreen.Display(cout);
    cout << "\n";

    //=================================================================//
    cout << "\n\n";
    auto end = chrono::high_resolution_clock::now();
    cout << "Elapsed Time:  " << std::chrono::duration<double>(end - start).count() << " s\n\n"
         << "**Mission Completed !**\n\n\n"
         << "\a";
    return 0;
}
