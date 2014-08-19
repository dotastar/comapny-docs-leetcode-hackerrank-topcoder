#include <iostream>
#include <cctype>
#include <cstdlib>

int my_atoi(const char *str)
{
    if(!str || !*str)
        return 0;
    while(std::isspace(*str))
        ++str;
    bool minus = false;
    if('-' == *str || '+' == *str)
        minus = ('-' == *str++);
    int r = 0;
    for(;*str;++str)
        if('0' <= *str && *str <= '9'){
            int rr = r;
            r = r * 10;
            if(r / 10 != rr)
                return (minus ? 0x80000000 : 0x7fffffff);
            rr = r;
            r += *str - '0';
            if(r < rr)
                return (minus ? 0x80000000 : 0x7fffffff);
        }else
            break;
    return (minus ? -r : r);
}

class Solution {
public:
    int atoi(const char *str) {
        if(!str)
            return 0;
        while(isspace(*str))
            ++str;
        bool minus = false;
        if('-' == *str || '+' == *str){
            minus = '-' == *str;
            ++str;
        }
        long long r = 0;
        while('0' <= *str && *str <= '9'){
            r = r * 10 + *str - '0';
            ++str;
            if(r > INT_MAX)
                break;
        }
        if(minus)
            r = -r;
        if(r > INT_MAX)
            return INT_MAX;
        if(r < INT_MIN)
            return INT_MIN;
        return r;
    }
};

int main()
{
    std::cout<<my_atoi("    10522545459")
        <<" "<<std::atoi("    10522545459")<<"\n";
    std::cout<<my_atoi("2147483648")
        <<" "<<std::atoi("2147483648")<<"\n";
    std::cout<<my_atoi("-2147483649")
        <<" "<<std::atoi("-2147483649")<<"\n";
}