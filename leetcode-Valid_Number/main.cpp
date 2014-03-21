#include "../inc.h"

class Solution {
public:
    bool isNumber(const char *s) {
        if(!s || !*s)
            return false;
        for(;issp(*s);++s);
        s = parseDouble(s);
        if(!s)
            return false;
        if('e' == *s || 'E' == *s){
            s = parseInteger(++s);
            if(!s)
                return false;
        }
        for(;issp(*s);++s);
        return !*s;
    }
    const char * parseDouble(const char * s){
        assert(s);
        for(int t = 0;;++s){
            switch(t){
                case 0:
                    if('+' == *s || '-' == *s)
                        t = 1;
                    else if('0' <= *s && *s <= '9')
                        t = 2;
                    else if('.' == *s)
                        t = 3;
                    else
                        return NULL;
                    break;
                case 1:
                    if('0' <= *s && *s <= '9')
                        t = 2;
                    else if('.' == *s)
                        t = 3;
                    else
                        return NULL;
                    break;
                case 2:
                    if('0' <= *s && *s <= '9')
                        ;
                    else if('.' == *s)
                        t = 4;
                    else
                        return s;
                    break;
                case 3:
                    if('0' <= *s && *s <= '9')
                        t = 4;
                    else
                        return NULL;
                    break;
                case 4:
                    if('0' <= *s && *s <= '9')
                        ;
                    else
                        return s;
                    break;
                default:return NULL;
            }
        }
        return NULL;
    }
    const char * parseInteger(const char * s){
        assert(s);
        for(int t = 0;;++s){
            switch(t){
                case 0:
                    if('+' == *s || '-' == *s)
                        t = 1;
                    else if('0' <= *s && *s <= '9')
                        t = 2;
                    else
                        return NULL;
                    break;
                case 1:
                    if('0' <= *s && *s <= '9')
                        t = 2;
                    else
                        return NULL;
                    break;
                case 2:
                    if('0' <= *s && *s <= '9')
                        ;
                    else
                        return s;
                    break;
                default:return NULL;
            }
        }
        return NULL;
    }
    bool issp(char c){
        return (' ' == c || '\t' == c || '\n' == c || '\r' == c);
    }
};

int main()
{
    cout<<Solution().isNumber("0")<<endl;
    cout<<Solution().isNumber("  0.1   ")<<endl;
    cout<<Solution().isNumber("  0.1e1   ")<<endl;
    cout<<Solution().isNumber("  +0.1e-1   ")<<endl;
    cout<<Solution().isNumber("  -0.1e+1   ")<<endl;
    cout<<"---\n";
    cout<<Solution().isNumber("  .1e.1   ")<<endl;
    cout<<Solution().isNumber("  1.e.1   ")<<endl;
    cout<<Solution().isNumber("  +.1e+.1   ")<<endl;
    cout<<Solution().isNumber("  -.1e-.1   ")<<endl;
    cout<<Solution().isNumber("  -.1E+.1   ")<<endl;
    cout<<Solution().isNumber("  0.1e.1   ")<<endl;
    cout<<Solution().isNumber("  0.1e 1   ")<<endl;
    cout<<Solution().isNumber("  -.1E +1   ")<<endl;
    cout<<Solution().isNumber("  .e.1   ")<<endl;
    cout<<Solution().isNumber("  1.e.   ")<<endl;
    cout<<Solution().isNumber("  -1.e-.   ")<<endl;
    cout<<Solution().isNumber("  +.e+.1   ")<<endl;
    cout<<Solution().isNumber("  1e+1e1  ")<<endl;
}
