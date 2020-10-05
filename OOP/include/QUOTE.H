#ifndef __QUOTE_H__
#define __QUOTE_H__

#include <iostream>
#include <memory>
#include <set>



class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) { }
    Quote(const Quote &q_);
    Quote( Quote &&q_) noexcept;
    Quote& operator=(const Quote&q_);

    std::string isbn() const { return bookNo ; }
    virtual double net_price(std::size_t n) const { return n* price; }
    virtual void debug() { std::cout << "";}
    virtual Quote* clone() const & { return new Quote(*this);}
    virtual Quote* clone() const && { return new Quote(std::move(*this));}

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};


class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book_, double price_, std::size_t qty_, double discount_)
        :Quote(book_, price_),quantity(qty_),discount(discount_) { }
    Disc_quote(const Disc_quote &dq_);
    Disc_quote(Disc_quote &&dq_) noexcept;
    Disc_quote& operator=(const Disc_quote &dq_);

    double net_price(std::size_t n_) const = 0;
private:
    std::size_t quantity = 0;
    double discount = 0.0;
};


class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    Bulk_quote(const Bulk_quote &bq_);
    Bulk_quote( Bulk_quote &&bq_);
    Bulk_quote& operator=(const Bulk_quote &bq_);


    double net_price(std::size_t ) const override ;
    void debug() override;
    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() const && { return new Bulk_quote(std::move(*this)); }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};


class Limited_quote : public Disc_quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string  &book_, double price_, std::size_t qty_, double discount_)
        :Disc_quote(book_, price_, qty_, discount_){ }
    double net_price(std::size_t ) const override ;

private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

double Print_Total(std::ostream &os, const Quote &item,std::size_t n);

void Declaration(const std::string &str_ );


class Basket
{
public:
    void add_item(const Quote& sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(const Quote&& sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream& os) const
    {
        float sum = 0.0;
        for(auto iter = items.cbegin();
                iter != items.cend();
                iter = items.upper_bound(*iter))
        {
            sum += Print_Total(os, **iter, items.count(*iter));
        }
        os<<"Total Sale: "<<sum <<"\n\n";
        return sum;
    }


private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
                    items{compare};
};





#endif