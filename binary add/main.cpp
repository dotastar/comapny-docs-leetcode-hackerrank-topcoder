#include <iostream>
#include <string>
#include <cassert>

int s2i(const std::string & s)
{
    int r = 0;
    for(size_t i = 0;i < s.size();++i){
        assert('0' == s[i] || '1' == s[i]);
        r <<= 1;
        r += s[i] - '0';
    }
    return r;
}

std::string i2s(int i)
{
    char buf[32];
    int j = sizeof buf;
    do{
        buf[--j] = '0' + (i & 1);
        i >>= 1;
    }while(i);
    return std::string(buf + j, buf + sizeof buf);
}

std::string addBinary(const std::string & x, const std::string & y)
{
    return i2s(s2i(x) + s2i(y));
}

int main()
{
    std::cout<<addBinary("100011", "100100")<<"\n";
}