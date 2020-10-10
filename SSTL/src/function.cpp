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
#include <random>
#include "SSTL.H"

using namespace std;


vector<int> myrand()
{
    static default_random_engine e(608);
	static uniform_int_distribution<int> u(-100,100);

    vector<int> v;
    for(size_t i = 0; i <10; ++i)
        v.push_back(u(e));

    return v;

}
