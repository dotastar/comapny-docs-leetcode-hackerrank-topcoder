#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void printVec(const std::vector<int> & ranges)
{
    assert(!ranges.empty());
    assert((ranges.size() & 1) == 0);
    for(size_t i = 0;i < ranges.size();i += 2)
        std::cout<<"["<<ranges[i]<<", "<<ranges[i + 1]<<"]\n";
}

static void prepare(std::vector<int> & ranges)
{
    //generate bitmap
    int edge = 8000;    //400 / (420 - 400) * 400
    std::vector<bool> vec(edge);
    int mi1, mi2;
    int mi, ma;
    for(int i = 0;300 * i < edge;++i){
        mi1 = 300 * i;
        if(mi1 >= edge)
            break;
        for(int j = 0;400 * j < edge;++j){
            mi2 = mi1 + 400 * j;
            if(mi2 >= edge)
                break;
            for(int k = 0;500 * k < edge;++k){
                mi = mi1 + mi2 + 500 * k;
                if(mi >= edge)
                    break;
                ma = 310 * i + 420 * j + 515 * k;
                for(;mi <= ma && mi < edge;++mi)
                    vec[mi] = true;
                if(ma >= edge)
                    while(vec[edge - 1])
                        --edge;
            }
        }
    }
    //scan for ranges
    ranges.clear();
    bool state = true;
    for(int i = 0;i < edge;++i){
        if(state != vec[i]){
            if(state)
                ranges.push_back(i);
            else
                ranges.push_back(i - 1);
            state = !state;
        }
    }
    if(!state)
        ranges.push_back(edge - 1);
    assert(!ranges.empty());
    assert((ranges.size() & 1) == 0);
    //printVec(ranges);     //show the ranges cannot be generated
}

bool canGet(int min, int max)
{
    static std::vector<int> ranges;
    assert(min <= max);
    if(ranges.empty())
        prepare(ranges);
    //fast check
    if(min < 300)
        return false;
    if(min > ranges.back())
        return true;
    //find index of min
    std::vector<int>::const_iterator wh = std::lower_bound(ranges.begin(), ranges.end(), min);
    if(wh != ranges.end() && *wh == min)
        return false;
    int mi = wh - ranges.begin();
    //find index of max
    wh = std::lower_bound(ranges.begin(), ranges.end(), max);
    if(wh != ranges.end() && *wh == max)
        return false;
    int ma = wh - ranges.begin();
    assert(mi <= ma);
    return (ma == mi && (mi & 1) == 0);
}

int main()
{
    std::cout<<canGet(1871, 1871)<<"\n";
    std::cout<<canGet(1899, 1899)<<"\n";
    std::cout<<canGet(1799, 1870)<<"\n";
    std::cout<<canGet(1800, 1870)<<"\n";
    std::cout<<canGet(1800, 1871)<<"\n";
    std::cout<<canGet(1872, 1898)<<"\n";
}