#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>

//O(2^N * N^2)
template<int N>
void printPowerSet1(const int (&a)[N])
{
    assert(N <= 10);
    std::vector<std::vector<int> > vv;
    for(int b = 0;b < (2 << N);++b){
        std::vector<int> v;
        for(int i = 0;i < N;++i)
            if(b & (1 << i))
                v.push_back(a[i]);
        std::sort(v.begin(), v.end());
        if(std::find(vv.begin(), vv.end(), v) == vv.end())
            vv.push_back(v);
    }
    for(size_t i = 0;i < vv.size();++i){
        std::cout<<"{";
        for(size_t j = 0;j < vv[i].size();++j){
            if(j)
                std::cout<<",";
            std::cout<<vv[i][j];
        }
        std::cout<<"}\n";
    }
}

//O(2^N * N * log N)
template<class Iter, int N>
void printPowerSetR(Iter it, Iter last, int (&s)[N], int idx)
{
    if(it == last){
        std::cout<<"{";
        for(int i = 0;i < idx;++i){
            if(i)
                std::cout<<",";
            std::cout<<s[i];
        }
        std::cout<<"}\n";
    }else{
        Iter t = it++;
        for(int i = 0;i <= t->second;++i){
            printPowerSetR(it, last, s, idx + i);
            if(idx + i < N)
                s[idx + i] = t->first;
        }
    }
}

template<int N>
void printPowerSet2(const int (&a)[N])
{
    std::map<int, int> m;
    for(int i = 0;i < N;++i)
        ++m[a[i]];
    int s[N];
    printPowerSetR(m.begin(), m.end(), s, 0);
}

#include "1.h"

int main()
{
    const int a[] = {1,2,3,2,1};
    printPowerSet1(a);
    std::cout<<"---\n";
    printPowerSet2(a);
    std::cout<<"---\n";
    int b[sizeof a / sizeof a[0]];
    memcpy(b, a, sizeof b);
    PowerSet(b, sizeof b / sizeof b[0]);
}