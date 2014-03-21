#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1)
            return 1;
        for(int a = 1, b = 1;;){
            if(n-- == 1)
                return b;
            a += b;
            if(n-- == 1)
                return a;
            b += a;
        }
    }
};

int main()
{
    std::cout<<Solution().climbStairs(1)<<"\n";
    std::cout<<Solution().climbStairs(2)<<"\n";
    std::cout<<Solution().climbStairs(3)<<"\n";
    std::cout<<Solution().climbStairs(4)<<"\n";
    std::cout<<Solution().climbStairs(5)<<"\n";
    std::cout<<Solution().climbStairs(6)<<"\n";
    std::cout<<Solution().climbStairs(7)<<"\n";
}

/*
f0 = 1
f1 = f0 = 1
f2 = f1 + f0 = 2
f3 = f2 + f1 = 3
f4 = f3 + f2 = 5
f5 = f4 + f3 = 8
fn = fib(n)
*/
