#include "../inc.h"

class Solution {
public:
    int divide1(int dividend, int divisor) {
        assert(divisor);
        //get abs
        bool m = false;
        if(dividend < 0){
            dividend = -dividend;
            m = !m;
        }
        if(divisor < 0){
            divisor = -divisor;
            m = !m;
        }
        int r = help(dividend, divisor);
        if(m)
            r = -r;
        return r;
    }
    unsigned int help(unsigned int dividend, unsigned int divisor){
        const unsigned int SIGN = 1 << 31;
        //X / 2^N
        int xshift = help(divisor);
        if(0 == (divisor & (divisor - 1)))
            return (dividend >> xshift);
        //others
        unsigned int tmp = 0;
        xshift = help(dividend) - xshift;
        if(xshift >= 0){
            unsigned int tmpvalue = (divisor << xshift);
            unsigned int bsign = ((dividend & SIGN) ^ (tmpvalue & SIGN));
            dividend -= tmpvalue;
            for(bsign ^= (dividend & SIGN);xshift > 0 && dividend;--xshift, bsign = (dividend & SIGN)){
                tmpvalue >>= 1;
                if(bsign)
                    dividend += tmpvalue;
                else{
                    dividend -= tmpvalue;
                    tmp += (1 << xshift);
                }
            }
            if(bsign)
                dividend += tmpvalue;
            else
                tmp += (1 << xshift);
        }
        return tmp;
    }
    int help(unsigned int v){
        int r = 0;
        for(;v > 1;++r, v >>= 1);
        return r;
    }

    int divide2(int dividend, int divisor) {
        assert(divisor);
        //get abs
        bool m = false;
        unsigned long long dd = dividend;
        if(dividend < 0){
            dd = -dividend;
            dd &= 0xFFFFFFFF;
            m = !m;
        }
        unsigned long long di = divisor;
        if(divisor < 0){
            di = -divisor;
            di &= 0xFFFFFFFF;
            m = !m;
        }
        //calc
        int r = 0;
        while(dd >= di){
            int i = 0;
            for(;(di << (i + 1)) <= dd;++i);
            dd -= (di << i);
            r += (1 << i);
        }
        if(m)
            r = -r;
        return r;
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor);
        long long de = dividend, di = divisor;
        bool minus = false;
        if(de < 0){
            minus = !minus;
            de = -de;
        }
        if(di < 0){
            minus = !minus;
            di = -di;
        }
        int r = 0;
        while(di <= de){
            int i = 0;
            for(; (di << (i + 1)) <= de; ++i);
            de -= di << i;
            r += 1 << i;
        }
        return minus ? -r : r;
    }
};

int main()
{
#define ddd divide1
    cout<<Solution().ddd(-2147483648, 1)<<endl;
    cout<<Solution().ddd(-2147483648, 3)<<endl;
    cout<<Solution().ddd(2147483647, 3)<<endl;
    cout<<Solution().ddd(2147483647, 1)<<endl;
    cout<<Solution().ddd(100, 10)<<endl;
    cout<<Solution().ddd(99, 10)<<endl;
    cout<<Solution().ddd(0, 10)<<endl;
    cout<<Solution().ddd(-100, 10)<<endl;
    cout<<Solution().ddd(-99, 10)<<endl;
    cout<<Solution().ddd(100, -10)<<endl;
    cout<<Solution().ddd(99, -10)<<endl;
    cout<<Solution().ddd(0, -10)<<endl;
    cout<<Solution().ddd(-100, -10)<<endl;
    cout<<Solution().ddd(-99, -10)<<endl;
}
