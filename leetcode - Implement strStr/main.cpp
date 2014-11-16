#include "..\inc.h"

class Solution {
public:
    char *strStr1(char *haystack, char *needle) {
        if(!haystack || !needle)
            return NULL;
        if(!*haystack)
            return (*needle ? NULL : haystack);
        for(char * s = haystack;*s;++s){
            int i = 0;
            for(;s[i] && needle[i] && s[i] == needle[i];++i);
            if(!needle[i])
                return s;
            if(!s[i])
                break;
        }
        return NULL;
    }
    char *strStr2(char *haystack, char *needle) {
        if(!haystack || !needle)
            return NULL;

        //TODO KMP
    }
};

class Solution2 {
public:
    int strStr(char *haystack, char *needle) {
        if(!haystack)
            return -1;
        if(!needle)
            return 0;
        const int hlen = strlen(haystack), nlen = strlen(needle);
        for(int i = 0;i <= hlen - nlen;++i){
            bool match = true;
            for(int j = 0;j < nlen;++j)
                if(!(match = (needle[j] == haystack[i + j])))
                    break;
            if(match)
                return i;
        }
        return -1;
    }
};

int main()
{
    {
        char * s = "abc";
        char * n = "";
        cout<<Solution().strStr1(s, n)<<endl;
        cout<<strstr(s, n)<<endl;
    }{
        char * s = "abc";
        cout<<(NULL == Solution().strStr1(s, NULL))<<endl;
        //cout<<(NULL == strstr(s, NULL))<<endl;
    }{
        char * s = "abc";
        cout<<(NULL == Solution().strStr1(NULL, s))<<endl;
        //cout<<(NULL == strstr((const char *)NULL, s))<<endl;
    }{
        char * s = "abc";
        char * n = s + 1;
        cout<<Solution().strStr1(s, n)<<endl;
        cout<<strstr(s, n)<<endl;
    }{
        char * s = "";
        char * n = "";
        cout<<Solution().strStr1(s, n)<<endl;
        cout<<strstr(s, n)<<endl;
    }
}