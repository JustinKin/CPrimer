#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <iostream>
#include <memory>
#include <set>
#include <vector>

template<typename T>
int mycompare(const T& v1, const T& v2)
{
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}


template<typename Iter, typename V>
Iter myfind( Iter& bg, Iter& ed, const V& v)
{
    for( ; bg != ed; ++bg)
    {
        if(*bg == v)
            return bg;
    }
    return ed;
}


















#endif