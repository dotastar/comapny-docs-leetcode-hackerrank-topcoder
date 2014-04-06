#include "../inc.h"

// you can also use includes, for example:
// #include <algorithm>
vector<int> solution1(int N, vector<int> &A) {
    // write your code in C++98
    vector<int> ret(N);
    int maxi = 0;
    for (size_t i = 0; i < A.size(); ++i){
        int d = A[i] - 1;
        if (d < 0 || d > N)
            continue;
        if (d < N){
            ++ret[d];
            if (d != maxi && ret[d] > ret[maxi])
                maxi = d;
        } else{
            int v = ret[maxi];
            ret.clear();
            ret.resize(N, v);
        }
    }
    return ret;
}

vector<int> solution2(int N, vector<int> &A) {
    // write your code in C++98
    vector<int> ret(N);
    int maxi = 0, maxv = 0;
    for (size_t i = 0; i < A.size(); ++i){
        int d = A[i] - 1;
        if (d < 0 || d > N)
            continue;
        if (d < N){
            if (ret[d] < maxv)  //ret[d] is not updated since last max_count operation
                ret[d] = maxv;
            ++ret[d];
            if (d != maxi && ret[d] > ret[maxi])
                maxi = d;
        } else
            maxv = ret[maxi];   //just save the maxv
    }
    for (size_t i = 0; i < ret.size(); ++i)
        if (ret[i] < maxv)
            ret[i] = maxv;
    return ret;
}

int main()
{
}
