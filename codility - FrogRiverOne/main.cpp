#include "../inc.h"

// you can also use includes, for example:
// #include <algorithm>
int solution(int X, vector<int> &A) {
    // write your code in C++98
    vector<bool> fall(X);
    size_t i = 0, c = 0;
    for (; i < A.size() && c < X; ++i){
        if (A[i] < 1 || A[i] > X || fall[A[i] - 1])
            continue;
        fall[A[i] - 1] = true;
        ++c;
    }
    return (c < X ? -1 : i - 1);
}

int main()
{

}