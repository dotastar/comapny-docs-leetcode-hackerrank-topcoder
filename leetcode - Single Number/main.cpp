#include <iostream>

class SolutionI {
public:
    int singleNumber(int A[], int n) {
        int r = 0;
        for(int i = 0;i < n;++i)
            r ^= A[i];
        return r;
    }
};

class SolutionII {
public:
    int singleNumber(int A[], int n) {
        int one = 0, two = 0;
        for(int i = 0;i < n;++i){
            two |= one & A[i];
            one ^= A[i];
            //clear 3 occurance bits
            int mask = ~(one & two);
            one &= mask;
            two &= mask;
        }
        return one;
    }
};

//every element appears N times except for one appears M times
class Solution3 {
public:
    int bitAdd(int & bits, int val){
        int r = bits & val;
        bits ^= val;
        return r;
    }
    int gcd(int a, int b){
        //assert(a > 0 && b > 0);
        while(b){
            int t = b;
            b = a % b;
            a = b;
        }
        return a;
    }
    int singleNumber(int A[], int n) {
        const int N = 4;
        const int M = 6;
        int bits[32] = {0};
        for(int i = 0;i < n;++i){
            int p = A[i];
            for(int j = 0;p && j < 32;++j)
                p = bitAdd(bits[j], p);
        }
        int times[32] = {0};
        for(int i = 0;i < 32;++i){
            for(int j = 31;j >= 0;--j){
                times[i] <<= 1;
                if((1 << i) & bits[j])
                    times[i] |= 1;
            }
        }
        int r = 0;
        for(int i = 31;i >= 0;--i){
            r <<= 1;
            if(times[i] % N == M % N)
                r |= 1;
        }
        return r;
    }
    int singleNumber2(int A[], int n) {
        const int N = 4;
        const int M = 6;
        int bc[32] = {0};
        for(int i = 0;i < n;++i)
            for(int j = 0;j < 32;++j)
                if(A[i] & (1 << j))
                    ++bc[j];
        int r = 0;
        for(int i = 31;i >= 0;--i){
            r <<= 1;
            if(bc[i] % N == M % N)
                r |= 1;
        }
        return r;
    }
};

int main()
{
    int A[] = {1,1,1,1, 2,2,2,2,2,2, 3,3,3,3, 4,4,4,4};
    std::cout<<Solution3().singleNumber2(A, sizeof A / sizeof A[0])<<"\n";
}