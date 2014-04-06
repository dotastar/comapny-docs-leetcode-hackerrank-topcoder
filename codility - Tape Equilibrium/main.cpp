#include <iostream>
// you can also use includes, for example:
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++98
    if (A.size() < 2)
        return 0;
    vector<int> hsum(A.size()), tsum(A.size());
    hsum.front() = A[0];
    tsum.back() = A.back();
    for (size_t i = 1; i < A.size(); ++i){
        hsum[i] = hsum[i -1] + A[i];
        tsum[A.size() - 1 - i] = tsum[A.size() - i] + A[A.size() - 1 - i];
    }
    int r = -1;
    for (size_t i = 0; i < A.size() - 1; ++i){
        int v = hsum[i] - tsum[i + 1];
        if (v < 0)
            v = -v;
        r = (r < 0 ? v : min(r, v));
    }
    return r;
}

int main()
{
    {
        vector<int> A{ 3, 1, 2, 4, 3 };
        cout << solution(A) << endl;
    }
}