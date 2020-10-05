#ifndef __MYSTRVEC_H__
#define __MYSTRVEC_H__

#include <iostream>
#include <memory>

class MyStrVec
{
public:
    MyStrVec() : mhead(nullptr),mtail_freehead(nullptr),mcap(nullptr) { }
    MyStrVec(const MyStrVec&);
    MyStrVec &operator=(const MyStrVec&);
    ~MyStrVec();

    void mpush_back(const std::string&);
    size_t msize() const { return mtail_freehead - mhead ;}
    size_t mcapacity() const { return mcap - mhead ;}
    std::string* mbegin() const { return mhead; }
    std::string* mend() const { return mtail_freehead; }
private:
    static std::allocator<std::string> malloc;
    void mchk_n_alloc()
    {
        if(msize() == mcapacity())
            mreallocate();
    }
    std::pair<std::string*, std::string*> malloc_n_copy(const std::string*, const std::string*);
    void mfree();
    void mreallocate();
    void mresize(const size_t &);
    void mreserve(const size_t &);
    std::string* mhead;
    std::string* mtail_freehead;
    std::string* mcap;
};
















#endif /* __MYSTRVEC_H__ */