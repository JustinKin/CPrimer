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

#include "Sales_data.h"


void AddData(std::ofstream &out_)
{
    std::cout<<"Please input bookNO., price, amount, input x for quick: \n";
    std::string s;
    int i =1;
    while(std::cin>> s)
    {   if(s == "x")
            goto END;
        out_<<s<<" ";
        if(i==3)
        {   
            out_<<"\n";
            i=0;
        }
        ++i;
    }
    out_<<"\n";
    END:
    ;
}


void SalesData(std::ifstream &in_, Sales_data &dayTime_)
{
   

        while(in_ >> dayTime_.aNO) //if use !eof , will wrong;        
        {   
            //std::cout<<"dayTime.aNO 1: "<<dayTime_.aNO<<"\n";
            double aPrice;
            unsigned aUnits;
            dayTime_.alocat = Find(dayTime_.bookNo, dayTime_.aNO);
            if (dayTime_.alocat == dayTime_.bookNo.end())
            {
                dayTime_.bookNo.push_back(dayTime_.aNO);
                in_ >> aPrice >> aUnits;
                //std::cout<<"aPrice: "<<aPrice<<" aUnits: "<<aUnits<<"\n";
                dayTime_.price.push_back(aPrice);
                dayTime_.day_sold.push_back(aUnits);
                dayTime_.day_revenue.push_back(DayRevenue(aPrice, aUnits));
                //std::cout<<"dayTime.aNO 3: "<<dayTime_.aNO<<"\n";
            }
            else
            { //std::cout<<"get\n";
                int n = dayTime_.alocat - dayTime_.bookNo.begin(); //watch out
                in_ >> aPrice >> aUnits;
                *(dayTime_.day_sold.begin() + n) += aUnits;
                *(dayTime_.day_revenue.begin() + n) += DayRevenue(aPrice, aUnits);
            }
        }        
    
    SumSold(dayTime_.day_sold, dayTime_.sum_sold);
    SumRevenue(dayTime_.day_revenue, dayTime_.sum_revenue);
    Print(dayTime_);



}
