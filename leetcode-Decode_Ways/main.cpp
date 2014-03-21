#include "../inc.h"

class Solution {
public:
    int numDecodings1(string s) {
        if(s.empty())
            return 0;
        vector<int> r(s.size());
        for(int i = s.size() - 1;i >= 0;--i){
            if('0' == s[i])
                continue;
            if(i + 1 < s.size()){
                r[i] = r[i + 1];
                if('1' == s[i] || ('2' == s[i] && s[i + 1] <= '6'))
                    r[i] += (i + 2 < int(s.size()) ? r[i + 2] : 1);
            }else
                r[i] = 1;
        }
        return r[0];
    }
    int numDecodings2(string s) {
        if(s.empty())
            return 0;
        int n1 = 1, n2 = 0;
        int r = 0, t;
        for(int i = s.size() - 1;i >= 0;--i, n2 = n1, n1 = r){
            t = r;
            switch(s[i]){
                case '0':r = 0;;break;
                case '1':r = n1 + n2;break;
                case '2':
                    if(i + 1 < s.size() && s[i + 1] <= '6'){
                        r = n1 + n2;
                        break;
                    }
                default:r = n1;
            }
        }
        return r;
    }
};

int main()
{
    cout<<Solution().numDecodings2("1101")<<endl;
    cout<<Solution().numDecodings2("10")<<endl;
    cout<<Solution().numDecodings2("101")<<endl;
    cout<<Solution().numDecodings2("12")<<endl;
    cout<<Solution().numDecodings2("0000")<<endl;
    cout<<Solution().numDecodings2("111111")<<endl;
}
