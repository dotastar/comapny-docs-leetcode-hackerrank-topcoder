#include "../inc.h"

int solveI(const vector<int> & A)
{
    if (A.empty())
        return -1;
    int idx = 0, cnt = 1;
    for (int i = 1;i < int(A.size());++i){
        if (A[idx] < A[i]){
            idx = i;
            cnt = 1;
        } else if (A[idx] == A[i]){
            ++cnt;
            int p = rand() % cnt;
            if (!p)
                idx = i;
        }
    }
    return idx;
}

int solveII(const vector<int> & A)
{
    map<int, pair<int, int>> ret;
    bool found = false;
    int min = 0;
    for (int i = 0; i < int(A.size()); ++i){
        if (found && A[i] < min)
            continue;
        auto & s = ret[A[i]];
        if (!s.second){
            s.first = i;
            s.second = 1;
        } else{
            ++s.second;
            int p = rand() % s.second;
            if (!p)
                s.first = i;
            if (!found || min < A[i]){
                found = true;
                min = A[i];
            }
        }
    }
    for (auto it = ret.rbegin(); it != ret.rend(); ++it)
        if (it->second.second > 1)
            return it->second.first;
    return -1;
}

int main()
{
    srand(unsigned int(time(NULL)));
    {
        vector<int> A{ 9,1, 4, 9, 7, 3, 9, 4, 7, 2, 7, 3, 0, 1, 2, 9, 6, 5, 7, 8, 9 };
        vector<int> r(A.size() + 1, 0);
        for (int i = 0; i < 10000; ++i)
            ++r[solveI(A) + 1];
        print(r);
    }{
        vector<int> A{ 10, 4, 9, 7, 3, 9, 4, 7, 2, 7, 3, 0, 10, 2, 9, 6, 5, 7, 8, 9 };
        vector<int> r(A.size() + 1, 0);
        for (int i = 0; i < 10000; ++i)
            ++r[solveII(A) + 1];
        print(r);
    }{
        vector<int> A{ 10, 4, 9, 7, 3, 9, 4, 7, 2, 7, 3, 0, 11, 2, 9, 6, 5, 7, 8, 9 };
        vector<int> r(A.size() + 1, 0);
        for (int i = 0; i < 10000; ++i)
            ++r[solveII(A) + 1];
        print(r);
    }{
        vector<int> A{ 10, 4, 9, 7, 3, 8, 14, 17, 2, 27, 3, 0, 11, 12, 19, 6, 5, 37, 18, 29 };
        vector<int> r(A.size() + 1, 0);
        for (int i = 0; i < 10000; ++i)
            ++r[solveII(A) + 1];
        print(r);
    }{
        vector<int> A{ 10, 4, 9, 7, 3, 8, 14, 17, 2, 27, 13, 0, 11, 12, 19, 6, 5, 37, 18, 29 };
        vector<int> r(A.size() + 1, 0);
        for (int i = 0; i < 10000; ++i)
            ++r[solveII(A) + 1];
        print(r);
    }
    return 0;
}