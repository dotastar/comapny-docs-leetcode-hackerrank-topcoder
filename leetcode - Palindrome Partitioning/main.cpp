#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    //I
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ret;
        vector<string> p;
        help(s, p, ret);
        return ret;
    }
    void help(const string & s, vector<string> & p, vector<vector<string> > & ret){
        if(s.empty()){
            ret.push_back(p);
            return;
        }
        size_t old = p.size();
        for(size_t i = 1;i <= s.size();++i){
            p.resize(old);
            if(isPalin(s.substr(0, i))){
                p.push_back(s.substr(0, i));
                help(s.substr(i), p, ret);
            }
        }
    }
    bool isPalin(const string & s){
        assert(!s.empty());
        if(s.size() == 1)
            return true;
        for(size_t i = 0, j = s.size() - 1;i < j;++i, --j)
            if(s[i] != s[j])
                return false;
        return true;
    }

    //II-1
    int minCut1(string s) {
        vector<string> p;
        return help(s, p, s.size()) - 1;
    }
    int help(const string & s, vector<string> & p, int m){
        if(s.empty())
            return p.size();
        int old = p.size();
        if(old < m){
            for(int i = s.size();i > 0;i--){
                p.resize(old);
                if(isPalin2(s.substr(0, i))){
                    p.push_back(s.substr(0, i));
                    int r = help(s.substr(i), p, m);
                    if(r < m)
                        m = r;
                }
            }
        }
        return m;
    }
    bool isPalin2(const string & s){
        assert(!s.empty());
        if(s.size() == 1)
            return true;
        if(hit.count(s))
            return true;
        for(size_t i = 0, j = s.size() - 1;i < j;++i, --j)
            if(s[i] != s[j])
                return false;
        hit.insert(s);
        return true;
    }
    //unordered_set<string> hit;
    set<string> hit;

    //II-2
    typedef map<string, int> __Map;
    //typedef unordered_map<string, int> __Map;
    int minCut2(string s) {
        return help(s, 0, s.size());
    }
    int help(string s, int f, int t){
        if(f >= t - 1 || isPalin(s, f, t))
            return 0;
        int & m = save[s.substr(f, t - f)];
        if(m)
            return m;
        m = t - f - 1;
        for(int i = t - f;i > 0 ;--i){
            int r = 1 + help(s, f, f + i);
            if(r >= m)
                continue;
            r += help(s, f + i, t);
            if(r < m)
                m = r;
        }
        return m;
    }
    bool isPalin(const string & s, int f, int t){
        if(f >= t - 1)
            return true;
        for(--t;f < t;++f, --t)
            if(s[f] != s[t])
                return false;
        return true;
    }
    __Map save;

    //II-3(Accepted)
    int minCut3(string s) {
        map<int, int> save;
        return help(s, 0, s.size() - 1, save);
    }
    int help(const string & s, int f, int m, map<int, int> & save){
        if(isPalin(s, f, s.size()))
            return 0;
        if(m < 1)
            return -1;
        bool calc = false;
        map<int, int>::const_iterator wh = save.find(f);
        if(wh != save.end())
            return wh->second;
        for(int i = s.size() - 1;i > f;--i){
            if(!isPalin(s, f, i))
                continue;
            int r = help(s, i, m - 1, save);
            if(r < 0)
                continue;
            if(++r <= m){
                calc = true;
                m = r;
            }
        }
        if(calc){
            save.insert(make_pair(f, m));
            return m;
        }
        return -1;
    }
};

int main()
{
    cout<<Solution().minCut3("ab")<<endl;
    cout<<Solution().minCut3("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi")<<endl;
    cout<<Solution().minCut3("ltsqjodzeriqdtyewsrpfscozbyrpidadvsmlylqrviuqiynbscgmhulkvdzdicgdwvquigoepiwxjlydogpxdahyfhdnljshgjeprsvgctgnfgqtnfsqizonirdtcvblehcwbzedsmrxtjsipkyxk")<<endl;
    cout<<Solution().minCut3("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
    cout<<Solution().minCut3("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp")<<endl;
}