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

int main()
{
    std::cout<<my_atoi("    10522545459")
        <<" "<<std::atoi("    10522545459")<<"\n";
    std::cout<<my_atoi("2147483648")
        <<" "<<std::atoi("2147483648")<<"\n";
    std::cout<<my_atoi("-2147483649")
        <<" "<<std::atoi("-2147483649")<<"\n";
}