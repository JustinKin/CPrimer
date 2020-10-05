#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Sales_data.h"

using namespace std;


void PushMem(Sales_data &dayTime_)
{
    double aPrice;
    unsigned aUnits;

    //cout<<"dayTime.aNO 2: "<<aNO_<<"\n";
    dayTime_.bookNo.push_back(dayTime_.aNO);
    cin >> aPrice >> aUnits;
    dayTime_.price.push_back(aPrice);
    dayTime_.day_sold.push_back(aUnits);
    dayTime_.day_revenue.push_back(DayRevenue(aPrice, aUnits));
}

void CountMem(Sales_data &dayTime_)
{
    double aPrice;
    unsigned aUnits;

    int n = dayTime_.alocat - dayTime_.bookNo.begin(); //watch out
    cin >> aPrice >> aUnits;
    *(dayTime_.day_sold.begin() + n) += aUnits;
    *(dayTime_.day_revenue.begin() + n) += DayRevenue(aPrice, aUnits);
}

void Print(Sales_data &dayTime_)
{
    auto a = dayTime_.bookNo.begin();
    auto b = dayTime_.day_sold.begin();
    auto c = dayTime_.day_revenue.begin();

    for(; a != dayTime_.bookNo.end(); ++a,++b,++c)
        {
             cout<<"Book Number  : "<<*a<<"\n";
             cout<<"Book Sold    : "<<*b<<"\n";
             cout<<"Book revenue : "<<*c<<"\n";
             cout<<"\n";
        }
    cout<<"SumSold = "<<dayTime_.sum_sold<<'\n';
    cout<<"SumRevenue = "<<dayTime_.sum_revenue<<"\n";


}

void SaveData(std::ofstream &out_, Sales_data &dayTime_)
{
    auto a = dayTime_.bookNo.begin();
    auto b = dayTime_.day_sold.begin();
    auto c = dayTime_.day_revenue.begin();

    for(; a != dayTime_.bookNo.end(); ++a,++b,++c)
        {
             out_<<"Book Number  : "<<*a<<"\n";
             out_<<"Book Sold    : "<<*b<<"\n";
             out_<<"Book revenue : "<<*c<<"\n";
             out_<<"\n";
        }
    std::cout<<"finished";
    out_<<"SumSold = "<<dayTime_.sum_sold<<'\n';
    out_<<"SumRevenue = "<<dayTime_.sum_revenue<<"\n\n";
}