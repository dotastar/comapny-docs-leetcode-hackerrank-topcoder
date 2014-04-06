// you can also use includes, for example:
// #include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++98
    int sum = 0;
    for (size_t i = 0; i < A.size(); ++i)
        sum += A[i];
    return (A.size() + 1) - (sum - A.size() * (A.size() + 1) / 2);
}

int main()
{
}