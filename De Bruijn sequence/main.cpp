#include "..\inc.h"

int pow(int v, int e)
{
    assert(v >= 0 && e >= 0);
    if(v < 2)
        return v;
    if(!e)
        return 1;
    int r = v;
    for(;e > 1;--e)
        r *= v;
    return r;
}

bool ok(int len, int digits, const vector<int> & seq)
{
    set<int> s;
    for(size_t i = 0;i < seq.size();++i){
        int k = seq[i];
        for(int j = 1;j < len;++j){
            int idx = i + j;
            if(idx >= int(seq.size()))
                idx %= seq.size();
            k = k * 10 + seq[idx];
        }
        if(!s.insert(k).second)
            return false;
    }
    return true;
}

bool test(int len, int digits, bool all = false)
{
    assert(len > 0 && digits > 0 && digits <= 10);
    int c = pow(digits, len - 1);
    vector<int> seq(c, 0);
    for(int d = 1;d < digits;++d)
        seq.resize(seq.size() + c, d);
    bool ret = false;
    if(seq.size() < 3){
        if(ok(len, digits, seq)){
            print(seq);
            ret = true;
        }
        return ret;
    }
    sort(seq.begin() + 1, seq.end());
    for(;;){
        if(ok(len, digits, seq)){
            print(seq);
            ret = true;
            if(!all)
                break;
        }
        if(!next_permutation(seq.begin() + 1, seq.end()))
            break;
    }
    return ret;
}

//from http://en.wikipedia.org/wiki/De_Bruijn_sequence
void db(int t, int p, int k, int n, vector<int> & a, vector<int> & seq)
{
    if(t > n){
        if(0 == n % p)
            for(int j = 1;j < p + 1;++j)
                seq.push_back(a[j]);
    }else{
        a[t] = a[t - p];
        db(t + 1, p, k, n, a, seq);
        for(int j = a[t - p] + 1;j < k;++j){
            a[t] = j;
            db(t + 1, t, k, n, a, seq);
        }
    }
}

void solve(int len, int digits)
{
    assert(len > 0 && digits > 0 && digits <= 10);
    vector<int> a(digits * len), seq;
    db(1, 1, digits, len, a, seq);
    print(seq);
}


int main()
{
    //test(1, 10);
    //test(2, 4);
    //test(3, 2);
    //test(4, 2);
    //test(5, 2);

    solve(3, 3);
    solve(4, 10);
}
