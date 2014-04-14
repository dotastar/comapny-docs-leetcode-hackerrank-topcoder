#include "../inc.h"

vector<pair<long long, long long> > save;

void prepare()
{
    cout << "0, 1, 1";
    long long c = 3;
    for (long long a = 1, b = 1; b <= 10000000000LL; c += 2){
        a += b;
        cout << ", " << a;
        b += a;
        cout << ", " << b;
    }
    cout <<endl<< c;
}

bool solve(long long v)
{
    const long long kFib[] = {
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
        1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
        196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887,
        9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141,
        267914296, 433494437, 701408733, 1134903170, 1836311903LL, 2971215073LL,
        4807526976LL, 7778742049LL, 12586269025LL
    };
    for (size_t i = 0; i < sizeof kFib / sizeof kFib[0]; ++i){
        if (kFib[i] == v)
            return true;
    }
    return false;
}


int main()
{
    int t;
    cin >> t;
    int m = 0;
    for (int i = 0; i < t; ++i){
        long long v;
        cin >> v;
        cout << (solve(v) ? "IsFibo" : "IsNotFibo") << endl;
    }
    return 0;
}