#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long Int;

Int solve(Int n){
    Int r = 2; 
    while(0 == (n & 1))
        n >>= 1;
    Int f = 3;
    while(1 < n && f * f <= n){
        if(0 == n % f){
            n /= f;
            r = f;
        }else 
            f += 2;
    }
    return max(r, n);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        Int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
