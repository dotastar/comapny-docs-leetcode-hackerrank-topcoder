#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define DEBUG 0

#if DEBUG
typedef unsigned int Int;
const Int kMax = 100000U;   //will multiply with 20000, so you need reserve some digits
const int kWidth = 5;
#else
typedef unsigned long long Int;
const Int kMax = 100000000000000ULL;
const int kWidth = 14;
#endif

typedef vector<Int> BigInt;

int help(const BigInt & a){
    int r = 0;
    for(size_t i = 0;i < a.size();++i){
        Int v = a[i];
        for(;v;v /= 10)
            r += v % 10;
    }
    return r;
}

int index(int n){
    return (n % 3 ? 1 : n / 3 * 2);
}

void multiply(BigInt & a, int b)
{
    Int r = 0;
    for(size_t i = 0;i < a.size();++i){
        a[i] = a[i] * b + r;
        if(a[i] >= kMax){
            r = a[i] / kMax;
            a[i] %= kMax;
        }else
            r = 0;
    }
    if(r)
        a.push_back(r);
}

void add(BigInt & a, const BigInt & b)
{
    Int r = 0;
    size_t i = 0;
    for(;i < b.size() || r;++i){
        if(i >= a.size())
            a.resize(i + 1);
        a[i] += r;
        if(i < b.size())
            a[i] += b[i];
        if(a[i] >= kMax){
            r = a[i] / kMax;
            a[i] %= kMax;
        }else
            r = 0;
    }
}

void show(const BigInt & a)
{
    cout.fill('0');
    for(int i = a.size() - 1;i >= 0;--i)
        cout<<setw(kWidth)<<a[i];
    cout<<endl;
}

int solve(int n){
    BigInt a, b;
    a.push_back(n > 1 ? 1 : 0);
    b.push_back(index(n));
    while(n-- > 2){
#if DEBUG
cout<<index(n)<<endl;
show(b);
show(a);
#endif
        BigInt t(b);
        multiply(t, index(n));
#if DEBUG
show(t);
#endif
        add(a, t);
        a.swap(b);
#if DEBUG
cout<<"---\n";
#endif
    }
#if DEBUG
cout<<"b = ";
show(b);
#endif
    multiply(b, 2);
    add(a, b);
#if DEBUG
cout<<"a = ";
show(a);
#endif
    return help(a);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
