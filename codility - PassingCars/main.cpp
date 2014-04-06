#include "../inc.h"

// you can also use includes, for example:
// #include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++98
    if (A.empty())
        return 0;
    int r = 0;
    for (size_t i = A.size() - 1, s = 0; i < A.size(); --i){
        if (A[i])
            ++s;
        else{
            r += s;
            if (r < 0 || r > 1000000000)
                return -1;
        }
    }
    return r;
}

int main(){}