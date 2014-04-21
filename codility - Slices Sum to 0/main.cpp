#include "../inc.h"

namespace m1{
    //O(N^2)
    int solution(vector<int> &A) {
        // write your code in C++98
        int r = 0;
        for (size_t i = 0; i < A.size(); ++i){
            int s = 0;
            for (size_t j = i; j < A.size(); ++j){
                s += A[j];
                if (!s){
                    if (++r > 1000000000)
                        return -1;
                }
            }
        }
        return r;
    }
}

namespace m2{
    //O(NlogN)
    int solution(vector<int> &A) {
        for (size_t i = 1; i < A.size(); ++i)
            A[i] += A[i - 1];
        sort(A.begin(), A.end());
        //print(A);
        long long ret = (!A[0] ? 1 : 0);
        int repeat = 1;
        for (size_t i = 1; i < A.size(); ++i){
            if (!A[i])
                ++ret;
            if (A[i] == A[i - 1])
                ++repeat;
            else if (repeat > 1){
                ret += long long(repeat - 1) * repeat / 2;
                repeat = 1;
                if (ret > 1000000000)
                    return -1;
            }
        }
        if (repeat > 1){
            ret += long long(repeat - 1) * repeat;
            if (ret > 1000000000)
                return -1;
        }
        return int(ret);
    }
}

int main()
{
    srand(time(NULL));
    {
        vector<int> A{ 2, -2, 3, 0, 4, -7 };
        cout << m1::solution(A) << endl;
        cout << m2::solution(A) << endl;
    }{
        vector<int> A;
        genArray(A, 100, -100, 100);
        print(A);
        cout << m1::solution(A) << endl;
        cout << m2::solution(A) << endl;
    }{
        vector<int> A;
        genArray(A, 100000, -1, 1);
        //print(A);
        //cout << m1::solution(A) << endl;
        cout << m2::solution(A) << endl;
    }{
        vector<int> A;
        genArray(A, 100000, 0, 0);
        //print(A);
        //cout << m1::solution(A) << endl;
        cout << m2::solution(A) << endl;
    }
}