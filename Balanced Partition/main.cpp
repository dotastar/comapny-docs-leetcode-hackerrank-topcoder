#include "../inc.h"

int solve(const vector<int> & A)
{
    if (A.size() < 2)
        return (A.empty() ? 0 : A[0]);
    vector<bool> s(1, true);
    int sum = 0;
    for (size_t i = 0; i < A.size(); ++i){
        sum += A[i];
        s.resize(sum + 1);
        for (int j = s.size() - 1; A[i] <= j; --j){
            if (s[j - A[i]])
                s[j] = true;
        }
    }
    int i = 0;
    for (size_t j = sum / 2; i <= int(j) && i + j < s.size(); ++i){
        if (s[j + i]){
            i += j;
            break;
        }
        if (s[j - i]){
            i = j - i;
            break;
        }
    }
    int j = sum - i;
    i -= j;
    return (i < 0 ? -i : i);
}

int main()
{
    {
        vector<int> A;
        genArray(A, 10, 0, 5);
        print(A);
        cout << solve(A) << endl;
    }
}