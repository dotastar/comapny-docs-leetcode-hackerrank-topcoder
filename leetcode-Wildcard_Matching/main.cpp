#include "../inc.h"

class Solution {
public:
    //TLE
    bool isMatch1(const char *s, const char *p) {
        if(!p)
            return (!s || !*s);
        return help(s, p);
    }
    bool help(const char * s, const char * p){
        assert(p);
        for(int i;;++p){
            switch(*p){
                case '\0':return (!s || !*s);
                case '?':
                    if(!s || !*s)
                        return false;
                    ++s;
                    break;
                case '*':
                    while('*' == *++p);
                    for(;;++s){
                        if(!*p || '?' == *p){
                            if(help(s, p))
                                return true;
                        }else if(*s == *p){
                            if(help(s + 1, p + 1))
                                return true;
                        }
                        if(!s || !*s)
                            return false;
                    }
                    break;
                default:
                    if(!s || *s != *p)
                        return false;
                    ++s;
            }
        }
        return false;
    }
    bool isMatch2(const char *s, const char *p) {
        assert(s && p);
        //parse p & s
        string str;
        vector<string> pstr;
        bool hs = false, ts = false;
        for(;*p;++p){
            if('*' == *p){
                if(!str.empty())
                    pstr.push_back(str);
                str.clear();
                if(pstr.empty())
                    hs = true;
                ts = true;
            }else{
                str.push_back(*p);
                ts = false;
            }
        }
        if(!str.empty())
            pstr.push_back(str);
        str = s;
        //search pstr in str
        if(pstr.empty()){
            if(hs || ts)
                return true;
            return str.empty();
        }
        int f = 0;
        for(size_t i = 0;i < pstr.size();++i){
            f = help(str, f, pstr[i], (hs || i), (ts || i < pstr.size() - 1));
            if(f < 0)
                return false;
        }
        return true;
    }
    int help(string str, int from, string pstr, bool hs, bool ts){
        if(!hs && !ts){
            if(from + pstr.size() != str.size())
                return -1;
            for(size_t i = 0;i < pstr.size();++i)
                if('?' != pstr[i] && pstr[i] != str[from  + i])
                    return -1;;
            return from + pstr.size();
        }else if(!hs){
            if(from + pstr.size() > str.size())
                return -1;
            for(size_t i = 0;i < pstr.size();++i)
                if('?' != pstr[i] && pstr[i] != str[from  + i])
                    return -1;;
            return from + pstr.size();
        }else if(!ts){
            if(from + pstr.size() > str.size())
                return -1;
            from = str.size() - pstr.size();
            for(size_t i = 0;i < pstr.size();++i)
                if('?' != pstr[i] && pstr[i] != str[from  + i])
                    return -1;;
            return from + pstr.size();
        }
        for(;from + pstr.size() <= str.size();++from){
            size_t i = 0;
            for(;i < pstr.size();++i)
                if('?' != pstr[i] && pstr[i] != str[from  + i])
                    break;
            if(i >= pstr.size())
                return from + pstr.size();
        }
        return -1;
    }
};

int main()
{
#define IM  isMatch2

    cout<<Solution().IM("abbb","*a?*b")<<endl;
    cout<<Solution().IM("abbb","*?*")<<endl;
    cout<<Solution().IM("aa","aa")<<endl;
    cout<<Solution().IM("aa","*")<<endl;
    cout<<Solution().IM("aa","a*")<<endl;
    cout<<Solution().IM("ab","?*")<<endl;
    cout<<Solution().IM("","")<<endl;
    cout<<"---\n";
    cout<<Solution().IM("aaab","b**")<<endl;
    cout<<Solution().IM("a","")<<endl;
    cout<<Solution().IM("aa","a")<<endl;
    cout<<Solution().IM("aaa","aa")<<endl;
    cout<<Solution().IM("aab","c*a*b")<<endl;
    cout<<Solution().IM("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba","a*******b")<<endl;

    cout<<Solution().IM(
            "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
            "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")<<endl;
}
