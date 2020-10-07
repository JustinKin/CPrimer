#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <iostream>
#include <memory>
#include <set>
#include <vector>

// using namespace std;

template <typename T>
int mycompare(const T &v1, const T &v2)
{
    if (v1 < v2)
        return -1;
    if (v2 < v1)
        return 1;
    return 0;
}

template <typename Iter, typename V>
Iter myfind(Iter &bg, Iter &ed, const V &v)
{
    for (; bg != ed; ++bg)
    {
        if (*bg == v)
            return bg;
    }
    return ed;
}

template <typename> class Blobptr;
template <typename> class MyBlob;
template <typename T>
    bool operator ==(const MyBlob<T>&, const MyBlob<T>&);

template <typename T>
class MyBlob
{
    friend class Blobptr<T>;
    friend bool operator==<T> (const MyBlob<T>&, const MyBlob<T>&);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    MyBlob();
    MyBlob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T& t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& front();
    T &back();
    T &operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
void MyBlob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

template <typename T>
T &MyBlob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T &MyBlob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void MyBlob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
MyBlob<T>::MyBlob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
MyBlob<T>::MyBlob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}


template <typename T>
class Blobptr
{
public:
    Blobptr():curr(0) { }
    Blobptr(MyBlob<T>& a, size_t sz = 0):wptr(a.data),curr(sz) { }
    T& operator*()const
    {
        auto p = check(curr , "dereference past end");
        return (*p)[curr];
    }
    Blobptr<T>& operator++();
    Blobptr& operator--();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

/* template <typename T>
Blobptr<T> Blobptr<T>::operator++()
{
    Blobptr ret = *this;
    ++*this;
    return ret;
} */

template <typename T>
void printv(const T& t)
{
    for(size_t i =0; i< t.size(); ++i)
    {
        std::cout<<t[i]<<" ";
    }
/*     for(auto bg = t.begin(); bg != t.end(); ++bg)
    {
        std::cout<<*bg<<" ";
    }
 */    std::cout<<"\n";
}

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr) :os(s) { }
    template <typename T> void operator()(T *P) const
    {
        os<<"deleting unique_ptr"<<std::endl;
        delete p;
    }

private:
    std::ostream &os;
};






#endif