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