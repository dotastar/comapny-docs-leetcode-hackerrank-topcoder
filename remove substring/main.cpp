#include <iostream>
#include <cassert>
#include <cstring>

int rmSub(char * str, const char * sub)
{
    if(!sub || !*sub)
        return 0;
    if(!str || !*str)
        return -1;
    for(char * s = str;*s;++s)
        if(*s == *sub){
            char * i = s + 1;
            const char * e = sub + 1;
            while(*e && *i && *i == *e)
                i++, e++;
            if(!*e){
                //strcpy(s, i); //avoid warning
                return 0;
            }
        }
    return -1;
}

int main()
{
    const char * sub = "ABC";
    {
        char str[] = "aABC123";
        if(0 == rmSub(str, sub))
            std::cout<<str<<"\n";
    }{
        char str[] = "ABC123";
        if(0 == rmSub(str, sub))
            std::cout<<str<<"\n";
    }{
        char str[] = "aABC";
        if(0 == rmSub(str, sub))
            std::cout<<str<<"\n";
    }{
        char str[] = "ABC";
        if(0 == rmSub(str, sub))
            std::cout<<str<<"\n";
    }{
        char str[] = "aABc123";
        if(0 == rmSub(str, sub))
            std::cout<<str<<"\n";
        else
            std::cout<<"-1\n";
    }{
        char str[] = "AB";
        if(0 == rmSub(str, sub))
            std::cout<<str<<"\n";
        else
            std::cout<<"-1\n";
    }
}