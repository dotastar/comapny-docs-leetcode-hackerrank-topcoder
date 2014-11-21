#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long Int;

Int powInt(int a, int p){
    Int r = 1;
    for(int i = 0;i < p;++i)
        r *= a;
    return r;
}

Int help(const vector<int> & pp)
{
    const Int kMax = -1;
    if(pp.empty())
        return 1;
    vector<int> p(pp);
    sort(p.begin(), p.end(), greater<int>());
    if(p[0] > 63)
        return 0;
    Int r = 1;
    r *= powInt(2, p[0]);
    double d = r;
    int n = 3;
    for(size_t i = 1;i < p.size();++i, n += 2){
        for(;;n += 2){
            bool yes = true;
            for(int j = 3;j * j <= n;j += 2)
                if(0 == n % j){
                    yes = false;
                    break;
                }
            if(yes)
                break;
        }
        d *= pow(double(n), p[i]);
        if(d > kMax)
            return 0;
        r *= powInt(n, p[i]);
    }
    return r;
}

void help(int n, vector<int> & p, Int & ret)
{
    if(!n){
        const Int r = help(p);
        if(r)
            ret = (ret ? min(ret, r) : r);
        return;
    }
    for(int i = 1;i + i + 1 <= n;++i){
        if(0 == (n - i) % (i + 1)){
            p.push_back(i);
            help((n - i) / (i + 1), p, ret);
            p.pop_back();
        }
    }
    p.push_back(n);
    help(0, p, ret);
    p.pop_back();
}

//calc the minimal number that has n factors
Int solve(int n)
{
    vector<int> p;
    Int ret = 0;
    help(--n, p, ret);
    return ret;
}

//calc No. of factors of s
Int factors(Int s){
    if(!s){
        //cout<<"INF\n";
        return 0;
    }
    //cout<<s<<" = 1";
    map<Int, int> f;
    while(0 == (s & 1)){
        ++f[2];
        s >>= 1;
    }
    for(Int i = 3;s > 1;){
        if(0 == (s % i)){
            ++f[i];
            s /= i;
        }else
            i += 2;
    }
    int c = 0;
    for(map<Int, int>::const_iterator it = f.begin();it != f.end();++it){
        c += c * it->second + it->second;
        //cout<<" * "<<it->first;
        //if(it->second > 1)
            //cout<<'^'<<it->second;
    }
    ++c;
    //cout<<" has "<<c<<" factors\n";
    return c;
}

void test(int n)
{
    factors(solve(n));
}

int main()
{
/*
    int n, f = 0;
    for(int i = 1;i < 2000;++i){
        int c = factors(i);
        if(c > f){
            n = i;
            f = c;
        }
    }
    cout<<"---\n";
    factors(n);
    test(f);
/*/
    for(int i = 1;;++i){
        cout<<i<<' '<<solve(i)<<endl;
        if(0 == i % 100)
            getchar();
    }
//*/
    return 0;
}
