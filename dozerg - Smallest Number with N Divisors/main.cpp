#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

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
Int factors(Int s, bool print = false){
    if(!s){
		if (print)
			cout << "INF\n";
        return 0;
    }
	if (print)
		cout << s << " = 1";
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
		if (print)
			cout << " * " << it->first;
		if (print && it->second > 1)
            cout<<'^'<<it->second;
    }
    ++c;
	if (print)
		cout << " has " << c << " factors\n";
    return c;
}

void test(int n)
{
    factors(solve(n));
}

/*
compute Highly composite numbers
https://oeis.org/A002182
1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520,
5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360
*/
void proc1()
{
	int m = 0;
	for (Int i = 1;m < 100; ++i){
		int n = factors(i);
		if (n > m){
			m = n;
			cout << i << ", ";
		}
	}
}

//Numbers that have more than 10w divisors
void proc2()
{
	for (int i = 100000, j = 0; j < 3; ++i){
		Int r = solve(i);
		if (r > 0){
			factors(r);
			//getchar();
			++j;
		}
	}
}

//https://oeis.org/A002182
void proc3()
{
	cout << "The number under 2^64 that has most divisors is:\n";
	factors(18401055938125660800ULL, true);
	//factors(27601583907188491200ULL, true);
}

int main()
{
	proc3();
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

//*/
	system("pause");
    return 0;
}
