#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r;
        if(rowIndex < 0)
            return r;
        for(int i = 0;i <= rowIndex;++i)
            r.push_back(int(C(i, rowIndex)));
        return r;
    }
    unsigned long long C(unsigned long long a, unsigned long long n){
        unsigned long long x = 1, y = 1;
        for(int i = 1;i <= a;++i){
            x *= n - a + i;
            y *= i;
            unsigned long long d = gcd(x, y);
            x /= d;
            y /= d;
        }
        return x / y;
    }
    unsigned long long gcd(unsigned long long a, unsigned long long b){
        while(b){
            unsigned long long c = b;
            b = a % b;
            a = c;
        }
        return a;
    }
};

int main(){}