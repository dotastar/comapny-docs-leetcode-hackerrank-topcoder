#include <iostream>
#include <string>
#include <cassert>

//O(N * 2^K)
bool isKPalinR(const std::string & s, int f, int t, int k)
{
    assert(f <= t && t < int(s.size()));
    while(f < t && s[f] == s[t])
        ++f, --t;
    assert(k >= 0);
    if(f >= t)
        return true;
    if(!k)
        return false;
    return isKPalinR(s, f + 1, t, k - 1) || isKPalinR(s, f, t - 1, k - 1);
}

bool isKPalinSlow(const std::string & s, int k)
{
    if(k >= int(s.size() - 1))
        return true;
    return isKPalinR(s, 0, s.size() - 1, k);
}

//
bool isKPalinPR(const std::string & s, int ls, int le, int rs, int re, int & k, int (&lcnt)[256], int (&rcnt)[256])
{
    for(;ls < le && rs >= re;){
        if(!lcnt[s[ls]]){
            ++ls;
            continue;
        }
        if(!rcnt[s[rs]]){
            --rs;
            continue;
        }
        if(s[ls] == s[rs]){
            --lcnt[s[ls]];
            --rcnt[s[rs]];
            ++ls, --rs;
            continue;
        }
        if(k < 2)
            return false;
        int llcnt[256], rrcnt[256];
        //skip left
        memcpy(llcnt, lcnt, sizeof llcnt);
        memcpy(rrcnt, rcnt, sizeof rrcnt);
        --llcnt[s[ls]];
        int lk = k - 1;
        bool lr = isKPalinPR(s, ls + 1, le, rs, re, lk, llcnt, rrcnt);
        //skip right
        memcpy(llcnt, lcnt, sizeof llcnt);
        memcpy(rrcnt, rcnt, sizeof rrcnt);
        --rrcnt[s[re]];
        int rk = k - 1;
        bool rr = isKPalinPR(s, ls, le, rs, re - 1, rk, llcnt, rrcnt);
        if(!lr && !rr)
            return false;
        if(lr)
            k = lk;
        if(rr && k > rk)
            k = rk;
        return true;
    }
    if(ls < le){
        if(k < le - ls)
            return false;
        k -= le - ls;
    }else if(rs >= re){
        if(k < rs - re + 1)
            return false;
        k -= rs - re + 1;
    }
    return true;
}

bool isKPalinP(const std::string & s, int len, int & k)
{
    //find diff chars
    int lcnt[256] = {0};
    int rcnt[256] = {0};
    for(int i = 0;i < len;++i){
        assert(i < int(s.size()));
        ++lcnt[s[i]];
        ++rcnt[s[s.size() - 1 + i]];
    }
    for(int i = 0;i < 256;++i){
        int d = 0;
        if(lcnt[i] > rcnt[i]){
            d = lcnt[i] - rcnt[i];
            lcnt[i] = rcnt[i];
        }else{
            d = rcnt[i] - lcnt[i];
            rcnt[i] = lcnt[i];
        }
        if(d > k)
            return false;
        k -= d;
    }
    //check the orders
    return isKPalinPR(s, 0, len, s.size() - 1, s.size() - len, k, lcnt, rcnt);
}

bool isKPalin(const std::string & s, int k)
{
    if(k >= int(s.size() - 1))
        return true;
    if(!isKPalinP(s, (s.size() - k) / 2, k))
        return false;



    //TODO
    return false;
}

int main()
{
    std::cout<<isKPalinSlow("abxa", 1)<<"\n";
    std::cout<<isKPalinSlow("abdxa", 1)<<"\n";
    std::string s(20000 - 30, 'a');
    s.append(30, 'b');
    std::cout<<isKPalinSlow(s, 30)<<"\n";
}