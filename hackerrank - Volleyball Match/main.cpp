#include "../inc.h"

long long solve(int A, int B)
{
    if (A > B)
        swap(A, B);
    //A <= B
    if (A < 0)
        return 0;
    if (B < 25)
        return 0;
    if (A > B - 2)
        return 0;
    long long ret[25];
    for (int i = 0; i < 25; ++i)
        ret[i] = 1;
    for (int j = 0; j < A && j < 24; ++j){
        for (int i = 1; i < 25; ++i)
            ret[i] += ret[i - 1];
    }
    if (B == 25)
        //return (ret[24] % 1000000007);
        return ret[24];
    return 0;
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;
}