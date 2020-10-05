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

#include "QUOTE.H"

using namespace std;


Quote::Quote(const Quote &q_) : bookNo(q_.bookNo),price(q_.price)
{
   Declaration("Quote Copy Construction");
}

Quote::Quote( Quote &&q_) noexcept : bookNo(std::move(q_.bookNo)),price(std::move(q_.price))
{
   Declaration("Quote Move Construction");
}

Quote& Quote::operator=(const Quote&q_)
{
    bookNo = q_.bookNo;
    price = q_.price;
    Declaration("Quote Assignment Construction");
    return *this;
}


Disc_quote::Disc_quote(const Disc_quote &dq_) : Quote(dq_),quantity(dq_.quantity), discount(dq_.discount)
{
   Declaration("Disc_quote Copy Construction");
}

Disc_quote::Disc_quote(Disc_quote &&dq_) noexcept : Quote(dq_),quantity(std::move(dq_.quantity)),discount(std::move(dq_.price))
{
   Declaration("Disc_quote Move Construction");
}

Disc_quote& Disc_quote::operator=(const Disc_quote &dq_)
{
    Quote::operator=(dq_);
    quantity = dq_.quantity;
    discount = dq_.discount;
    Declaration("Disc_quote Assignment Construction");
    return *this;
}


Bulk_quote::Bulk_quote(const Bulk_quote &bq_) : Disc_quote(bq_),min_qty(bq_.min_qty), discount(bq_.discount)
{
    Declaration("Bulk_quote Copy Construction");
}

Bulk_quote::Bulk_quote( Bulk_quote &&bq_) : Disc_quote(bq_),min_qty(std::move(bq_.min_qty)),discount(std::move(bq_.discount))
{
    Declaration("Bulk_quote Move Construction");
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote &bq_)
{
    Bulk_quote::operator=(bq_);
    min_qty = bq_.min_qty;
    discount = bq_.discount;
    Declaration("Bulk_quote Assignment Construction");
    return *this;
}

double Print_Total(std::ostream &os, const Quote &item,std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: "<<item.isbn() << " # sold: "<< n <<" total due : "<<ret<<endl;

    return ret;
}

Bulk_quote::Bulk_quote(const std::string &book_, double price_, std::size_t min_qty_, double discount_)
    :Disc_quote(book_,price_,min_qty_,discount_)
{

}


double Bulk_quote::net_price(std::size_t n) const
{
    if(n > min_qty)
        return (n * (1-discount))*price ;
    else
        return( n * price);
}

double Limited_quote::net_price(std::size_t n) const
{
    if(n < max_qty)
        return (n * (1-discount))*price ;
    else
        return( (max_qty * (1-discount))*price + (n - max_qty)*price );
}


void Bulk_quote::debug()
{
    cout<<"Bulk_quote::debug"<<endl;
}

void Declaration(const std::string &str_ )
{
    std::cout<<"Copy Control: "<<str_<<"\n\n";
}



