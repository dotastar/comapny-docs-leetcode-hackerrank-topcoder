#include "../inc.h"

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        if(s.size() < 2)
            return s.size();
        vector<int> v(s.size());
        v[0] = 1;
        int r = 1;
        for(size_t i = 1;i < s.size();++i)
            for(size_t j = 1;j <= i;++j)
                if(int(j) > v[i - 1] || s[i] == s[i - j]){
                    v[i] = min(int(j), v[i - 1] + 1);
                    if(r < v[i])
                        r = v[i];
                    break;
                }else if(1 == v[i - j]){
                    v[i] = v[i - 1] + 1;
                    if(r < v[i])
                        r = v[i];
                    break;
                }
#if 0
        for(size_t i = 0;i < v.size();++i)
            cout<<v[i]<<" ";
        cout<<"\n";
#endif
        return r;
    }
    int lengthOfLongestSubstring2(string s) {
        if(s.size() < 2)
            return s.size();
        int r = 1;
        vector<int> p(256, -1);
        int st = 0;
        for(size_t i = 0;i < s.size();++i){
            if(p[s[i]] >= st)
                st = p[s[i]] + 1;
            r = max(int(i - st + 1), r);
            p[s[i]] = i;
        }
        return r;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int cnt[256] = {0};
        bool mode = false;
        for(size_t i = 0, len = 0;i + len < s.size();){
            if(mode){
                if(--cnt[s[i++]] == 1)
                    mode = false;
                --len;
            }else if(++cnt[s[i + len++]] > 1)
                mode = true;
            else
                r = max<int>(r, len);
        }
        return r;
    }
};

int main()
{
    cout<<Solution().lengthOfLongestSubstring2("hchzvfrkmlnozjk")<<endl;
    cout<<Solution().lengthOfLongestSubstring2("abcccba")<<endl;
    cout<<Solution().lengthOfLongestSubstring2("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco")<<endl;
}

/*
w l r b b m q b h c d a r z o  w  k  k y h i d d q s c d x r j m o w  f  r xsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco
1 2 3 4 1 2 3 3 4 5 6 7 8 9 10 11 12 1 2 3 4 5 1 2 3 4 4 5 6 7 8 9 10 11 6

h c h z v f r k m l n  o  z  j  k
1 2 2 3 4 5 6 7 8 9 10 11 9  10 7
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
s s     s       s
*/
