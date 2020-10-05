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

   /* Sales_data(std::string aNO_, 
               std::vector<std::string>::iterator alocat_,
               std::vector<std::string> bookNo_,
               std::vector<double> price_,
               std::vector<unsigned> day_sold_,
               std::vector<double> day_revenue_,
               unsigned sum_sold_,
               double sum_revenue_):
               aNO(aNO_), alocat(alocat_), bookNo(bookNo_),price(price_),
               day_sold(day_sold_),day_revenue(day_revenue_),sum_sold(sum_sold_),
               sum_revenue(sum_revenue_) { std::cout<<"call 1 \n";}*/
    //Sales_data():Sales_data("",bookNo.begin(),"",0,0,0,0,0){std::cout<<"call 2 \n";}
   // Sales_data(std::string s_):Sales_data(s_,bookNo.begin(),"",0,0,0,0,0){std::cout<<"call 3 \n";}
}dayTime;


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



#endif