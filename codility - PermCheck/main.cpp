// you can also use includes, for example:
// #include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++98
    for (size_t i = 0; i < A.size();){
        if (A[i] < i + 1 || A[i] > A.size())
            return 0;
        if (A[i] == i + 1){
            ++i;
            continue;
        } else if (A[i] == A[A[i] - 1])
            return 0;
        else
            swap(A[i], A[A[i] - 1]);
    }
    return 1;
}

int main()
{
}
