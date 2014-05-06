#include "../inc.h"

typedef vector<long long>   __Elem;
typedef vector<__Elem>      __Line;

void merge(int digit, __Elem & to, const __Elem & from)
{
    for (size_t i = 0; i < from.size(); ++i)
        to[i | (1 << digit)] += from[i];
}

int main()
{
    __Line cur(10, __Elem(1024));
    //init (1 digit)
    for (int i = 0; i < 10; ++i)
        cur[i][1 << i] = 1;
    //first step (2 digits)
    __Line tmp(10, __Elem(1024));
    merge(0, tmp[0], cur[1]);
    merge(1, tmp[1], cur[2]);
    for (int i = 2; i < 9; ++i){
        merge(i, tmp[i], cur[i - 1]);
        merge(i, tmp[i], cur[i + 1]);
    }
    merge(9, tmp[9], cur[8]);
    tmp.swap(cur);
    //following steps (3 - 40 digits)
    long long ret = 0;
    for (int i = 3; i <= 40; ++i){
        tmp.clear();
        tmp.resize(10, __Elem(1024));
        merge(0, tmp[0], cur[1]);
        for (int j = 1; j < 9; ++j){
            merge(j, tmp[j], cur[j - 1]);
            merge(j, tmp[j], cur[j + 1]);
        }
        merge(9, tmp[9], cur[8]);
        tmp.swap(cur);
        for (auto & e : cur)
            ret += e[1023];
        cout << i << ": " << ret << endl;
    }
    return 0;
}