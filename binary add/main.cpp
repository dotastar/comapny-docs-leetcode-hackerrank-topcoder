#include "../inc.h"

namespace m1{
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
}

namespace m2{
    std::string addBinary(const std::string & x, const std::string & y)
    {
        if(x.empty())
            return y;
        if(y.empty())
            return x;
        string ret;
        int v = 0;
        for(int i = x.size() - 1, j = y.size() - 1;i >= 0 || j >= 0 || v;--i, --j, v >>= 1){
            if(i >= 0)
                v += x[i] - '0';
            if(j >= 0)
                v += y[j] - '0';
            ret.push_back((v & 1) + '0');
        }
        assert(!ret.empty());
        for(size_t i = 0, j = ret.size() - 1;i < j;++i, --j)
            swap(ret[i], ret[j]);
        return ret;
    }
}

int main()
{
    std::cout<<m1::addBinary("100011", "100100")<<"\n";
    std::cout<<m2::addBinary("100011", "100100")<<"\n";
    std::cout<<m2::addBinary("1000111001011011010", "100100")<<"\n";
}

