#include "..\inc.h"

class Solution1 {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        string t;
        for(size_t i = 0;i < s.size() - 1;++i){
            assert('#' != s[i]);
            t += s[i];
            t += '#';
        }
        t += *s.rbegin();
        vector<int > r(t.size());
        int m = 0;
        for(size_t i = 1;i < t.size();++i){
            if(m + r[m] > int(i)){
                size_t j = 2 * m - i;
                int d = r[m] + j - m;
                if(r[j] >= d){
                    r[i] = d;
                    m = i;
                }else{
                    r[i] = r[j];
                    continue;
                }
            }else
                m = i;
            int j = r[m] + 1;
            for(;j <= m && m + j < int(t.size());++j)
                if(t[m - j] != t[m + j])
                    break;
            r[m] = j - 1;
        }
        m = 0;
        size_t idx = 0;
        for(size_t i = 0;i < r.size();++i){
            int d = (i & 1 ? (r[i] + 1) / 2 * 2 : r[i] / 2 * 2 + 1);
            if(d > m){
                m = d;
                idx = i;
            }
        }
        assert(idx < r.size());
        string ret;
        for(size_t i = idx - r[idx];i <= idx + r[idx];++i)
            if('#' != t[i])
                ret.push_back(t[i]);
        return ret;
    }
};

class Solution2 {
public:
    string longestPalindrome(string p) {
        vector<int> pp(1, 256);
        for (unsigned char c : p){
            pp.push_back(c);
            pp.push_back(256);
        }
        vector<int> s(pp.size(), 1);
        size_t id = 0, mx = id + s[id], idx = id;
        for (size_t i = 1; i < s.size(); ++i){
            s[i] = (i < mx ? min<int>(mx - i, s[2 * id - i]) : s[i]);
            if (mx <= i + s[i]){
                for (; s[i] <= i && i + s[i] < s.size() && pp[i - s[i]] == pp[i + s[i]]; ++s[i]);
                id = i;
                mx = i + s[i];
            }
            idx = (s[i] > s[idx] ? i : idx);
        }
        string ret;
        for (size_t i = 0; i < s[idx]; ++i)
            if (pp[idx - s[idx] + i + 1] < 256)
                ret.push_back(pp[idx - s[idx] + i + 1]);
        for (size_t i = 1; i < s[idx]; ++i)
            if (pp[idx + i] < 256)
                ret.push_back(pp[idx + i]);
        return ret;
    }
};

typedef Solution2 Solution;

int main()
{
    cout<<Solution().longestPalindrome("aaabbbaac")<<endl;
    cout<<Solution().longestPalindrome("a")<<endl;
    cout<<Solution().longestPalindrome("")<<endl;
    cout<<Solution().longestPalindrome("aa")<<endl;
    cout<<Solution().longestPalindrome("ab")<<endl;
}