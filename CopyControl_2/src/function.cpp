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

#include "STRVEC.H"
#include "MYSTRVEC.H"

using namespace std;


void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    auto data = alloc.allocate( e - b );
    return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
    if(elements)
    {
        for(auto p = first_free; p != elements; )
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap - elements);
    }
}

StrVec::StrVec(const StrVec& s)
{
    auto newdata =alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0; i!=size(); ++i)
        alloc.construct(dest++,std::move(*elem++));
    free();
    elements = newdata;
    first_free =dest;
    cap = elements + newcapacity;
}


void MyStrVec::mpush_back(const std::string& s_ )
{
    mchk_n_alloc();
    malloc.construct(mtail_freehead++,s_);
}

std::pair<std::string*, std::string*> MyStrVec::malloc_n_copy(const std::string* b_, const std::string* e_)
{
    auto data = malloc.allocate(e_ - b_);
    auto end_ = uninitialized_copy(b_,e_,data);
    return { data, end_ };
}

void MyStrVec::mfree()
{
    if(mhead)
    {
        for(auto p = mtail_freehead; p != mhead;)
        {
            malloc.destroy(--p);
        }
        malloc.deallocate(mhead,mcap- mhead);
    }

/*     if(mhead)
    {
        for_each(mhead,mtail_freehead,[this](string& p){ malloc.destroy(&p);});
        malloc.deallocate(mhead,mcap - mhead);

    }
 */}

MyStrVec::MyStrVec(const MyStrVec& msv)
{
    auto newdata = malloc_n_copy(msv.mbegin(),msv.mend());

    mhead = newdata.first;
    mtail_freehead = newdata.second;
    mcap = newdata.second;
}

MyStrVec &MyStrVec::operator=(const MyStrVec& msv)
{
    auto data = malloc_n_copy(msv.mbegin(),msv.mend());
    mfree();
    mhead = data.first;
    mtail_freehead = data.second;
    mcap = data.second;
    return *this;
}

MyStrVec::~MyStrVec()
{
    mfree();
}

void MyStrVec::mreallocate()
{
    auto newcapacity = msize()? 2*msize(): 1;
    auto newdata = malloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = mhead;
    for(size_t i = 0; i != msize(); ++i)
        malloc.construct(dest++,std::move(*elem++));
    mfree();
    mhead = newdata;
    mtail_freehead = dest;
    mcap = mhead + newcapacity;

}