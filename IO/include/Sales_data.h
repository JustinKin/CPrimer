#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <vector>
#include <algorithm>



static struct Sales_data//watch out ,need static
{   
    std::string aNO;
    std::vector<std::string>::iterator alocat;
    std::vector<std::string> bookNo;
    std::vector<double> price;
    std::vector<unsigned> day_sold;
    std::vector<double> day_revenue;
    unsigned sum_sold = 0;
    double sum_revenue = 0;

}dayTime;

void AddData(std::ofstream &);

void SalesData(std::ifstream &, Sales_data &);

void PushMem(Sales_data &);//watch out ,need to  pass parameters


inline std::vector<std::string>::iterator Find(std::vector<std::string> &v_ , std::string s_)//内联函数，引用实现容器传参，可以修改容器元素
{   
    return (find(v_.begin(), v_.end(), s_));
}


void CountMem(Sales_data &);


inline double DayRevenue(double &price_, unsigned &units_sold_ )
{
    return (price_ * units_sold_);
}


inline void SumSold(std::vector<unsigned> &day_sold_, unsigned &sum_sold_)
{
    for(auto c : day_sold_)
        sum_sold_ += c;
}


inline void SumRevenue(std::vector<double> &day_revenue_,double &sum_revenue_)
{
    for(auto c : day_revenue_)
        sum_revenue_ += c;
}


void Print(Sales_data &dayTime_);


void SaveData(std::ofstream &, Sales_data &);


#endif